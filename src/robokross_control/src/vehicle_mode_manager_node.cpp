#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/u_int8.hpp>
#include <std_msgs/msg/bool.hpp>
#include <std_msgs/msg/u_int16.hpp>

class VehicleModeManager : public rclcpp::Node {
public:
    VehicleModeManager() : Node("vehicle_mode_manager") {
        // Подписка на команды от оператора (ПДУ)
        mode_cmd_sub_ = this->create_subscription<std_msgs::msg::UInt8>(
            "/mode/command", 10,
            std::bind(&VehicleModeManager::mode_command_callback, this, std::placeholders::_1));

        // Издатели для управления подсистемами
        brake_pub_ = this->create_publisher<std_msgs::msg::Bool>("/brake/control", 10);
        lights_pub_ = this->create_publisher<std_msgs::msg::UInt16>("/lights/control", 10);
        horn_pub_ = this->create_publisher<std_msgs::msg::Bool>("/horn/control", 10);
        mode_status_pub_ = this->create_publisher<std_msgs::msg::UInt8>("/mode/status", 10);

        current_mode_ = MODE_OFF;
        RCLCPP_INFO(this->get_logger(), "Vehicle Mode Manager initialized. Current mode: OFF");
    }

private:
    void mode_command_callback(const std_msgs::msg::UInt8::SharedPtr msg) {
        uint8_t requested_mode = msg->data;
        
        if (can_transition(current_mode_, requested_mode)) {
            current_mode_ = requested_mode;
            apply_mode(current_mode_);
            
            std::string mode_name;
            switch(current_mode_) {
                case MODE_OFF: mode_name = "ВЫКЛЮЧЕНО"; break;
                case MODE_PAUSE: mode_name = "ПАУЗА"; break;
                case MODE_DRIVE: mode_name = "ДВИЖЕНИЕ"; break;
                case MODE_STOP: mode_name = "СТОП"; break;
                default: mode_name = "НЕИЗВЕСТНО"; break;
            }
            RCLCPP_INFO(this->get_logger(), "Mode changed to: %s", mode_name.c_str());
        } else {
            RCLCPP_WARN(this->get_logger(), "Invalid transition from %d to %d", current_mode_, requested_mode);
        }
    }

    bool can_transition(uint8_t from, uint8_t to) {
        // Согласно п. 8.3 Регламента "Дюна" и п. 7.11-7.13 "Трасса"
        switch (to) {
            case MODE_PAUSE:
                return (from == MODE_OFF || from == MODE_DRIVE || from == MODE_STOP);
            case MODE_DRIVE:
                return (from == MODE_PAUSE); // ДВИЖЕНИЕ только из ПАУЗЫ
            case MODE_STOP:
                return true; // СТОП можно включить из любого режима (аварийная кнопка)
            case MODE_OFF:
                return (from == MODE_STOP || from == MODE_PAUSE);
            default:
                return false;
        }
    }

    void apply_mode(uint8_t mode) {
        std_msgs::msg::Bool brake_cmd;
        std_msgs::msg::UInt16 lights_cmd;
        std_msgs::msg::Bool horn_cmd;

        // Битовая маска огней (см. stm32_bridge_node):
        // Бит 0: ПАУЗА, Бит 1: ДВИЖЕНИЕ, Бит 2: СТОП
        // Бит 3: Ходовые, Бит 4: Задние, Бит 5: Задний ход, Бит 6: Маяк

        switch (mode) {
            case MODE_OFF:
                brake_cmd.data = false;
                lights_cmd.data = 0x0000; // Всё выключено
                horn_cmd.data = false;
                break;

            case MODE_PAUSE:
                brake_cmd.data = true; // Тормоз удерживает ТС
                lights_cmd.data = (1 << 0) | (1 << 3) | (1 << 6); // Лампа ПАУЗА + Ходовые + Маяк
                horn_cmd.data = false;
                break;

            case MODE_DRIVE:
                brake_cmd.data = false; // Тормоз отпущен
                lights_cmd.data = (1 << 1) | (1 << 3) | (1 << 4) | (1 << 6); // ДВИЖЕНИЕ + Ходовые + Задние + Маяк
                horn_cmd.data = true; // Звуковой сигнал при движении
                break;

            case MODE_STOP:
                brake_cmd.data = true; // Аварийное торможение
                lights_cmd.data = (1 << 2) | (1 << 4) | (1 << 6); // СТОП + Задние + Маяк
                horn_cmd.data = false;
                break;
        }

        brake_pub_->publish(brake_cmd);
        lights_pub_->publish(lights_cmd);
        horn_pub_->publish(horn_cmd);

        std_msgs::msg::UInt8 status_msg;
        status_msg.data = mode;
        mode_status_pub_->publish(status_msg);
    }

    // Константы режимов
    static const uint8_t MODE_OFF = 0;
    static const uint8_t MODE_PAUSE = 1;
    static const uint8_t MODE_DRIVE = 2;
    static const uint8_t MODE_STOP = 3;

    uint8_t current_mode_;

    rclcpp::Subscription<std_msgs::msg::UInt8>::SharedPtr mode_cmd_sub_;
    rclcpp::Publisher<std_msgs::msg::Bool>::SharedPtr brake_pub_;
    rclcpp::Publisher<std_msgs::msg::UInt16>::SharedPtr lights_pub_;
    rclcpp::Publisher<std_msgs::msg::Bool>::SharedPtr horn_pub_;
    rclcpp::Publisher<std_msgs::msg::UInt8>::SharedPtr mode_status_pub_;
};

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<VehicleModeManager>());
    rclcpp::shutdown();
    return 0;
}