cmake_minimum_required(VERSION 3.8)
project(gkv2_motor_bridge)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic -O3)
endif()

# 1. Поиск зависимостей
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(Boost REQUIRED COMPONENTS system)
find_package(rosidl_default_generators REQUIRED)

# 2. Генерация кастомных сообщений
rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/GKV2Status.msg"
  "msg/NavigationStatus.msg"
  DEPENDENCIES std_msgs
)

# 3. ПОЛУЧЕНИЕ ТАРГЕТА ДЛЯ ЛИНКОВКИ 
rosidl_get_typesupport_target(cpp_typesupport_target ${PROJECT_NAME} "rosidl_typesupport_cpp")

# 4. Узел 1: Драйвер входящего канала (CMD_BUD от ПДУ)
add_executable(gkv2_driver_node src/gkv2_driver_node.cpp)
ament_target_dependencies(gkv2_driver_node rclcpp geometry_msgs sensor_msgs std_msgs)
target_link_libraries(gkv2_driver_node Boost::system)

# 5. Узел 2: Мост управления моторами
add_executable(cmd_vel_bridge_node src/cmd_vel_bridge_node.cpp)
ament_target_dependencies(cmd_vel_bridge_node rclcpp geometry_msgs std_msgs)
target_link_libraries(cmd_vel_bridge_node Boost::system)

# 6. Узел 3: Парсер навигации ГКВ2 (использует GKV2Status.msg)
add_executable(gkv2_nav_parser_node src/gkv2_nav_parser_node.cpp)
ament_target_dependencies(gkv2_nav_parser_node rclcpp geometry_msgs sensor_msgs std_msgs)
# Линковка Boost и кастомных сообщений
target_link_libraries(gkv2_nav_parser_node Boost::system "${cpp_typesupport_target}")

# 7. Узел 4: Навигационный контроллер
add_executable(navigation_controller_node src/navigation_controller_node.cpp)
ament_target_dependencies(navigation_controller_node rclcpp geometry_msgs)

# 8. Узел 5: Слияние навигационных данных (использует GKV2Status.msg и NavigationStatus.msg)
add_executable(navigation_fusion_node src/navigation_fusion_node.cpp)
ament_target_dependencies(navigation_fusion_node rclcpp geometry_msgs sensor_msgs nav_msgs std_msgs)
# Линковка кастомных сообщений
target_link_libraries(navigation_fusion_node "${cpp_typesupport_target}")

# 9. Установка исполняемых файлов
install(TARGETS
  gkv2_driver_node
  cmd_vel_bridge_node
  gkv2_nav_parser_node
  navigation_controller_node  
  navigation_fusion_node  
  DESTINATION lib/${PROJECT_NAME}
)

# 10. Установка launch и config файлов
install(DIRECTORY launch/
  DESTINATION share/${PROJECT_NAME}/launch
)
install(DIRECTORY config/
  DESTINATION share/${PROJECT_NAME}/config
)

ament_package()