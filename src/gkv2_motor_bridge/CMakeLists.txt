cmake_minimum_required(VERSION 3.8)
project(gkv2_motor_bridge)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic -O3)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(Boost REQUIRED COMPONENTS system)
find_package(rosidl_default_generators REQUIRED)

# Генерация кастомного сообщения GKV2Status
rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/GKV2Status.msg"
  DEPENDENCIES std_msgs
)

# Узел 1: Драйвер входящего канала (CMD_BUD от ПДУ)
add_executable(gkv2_driver_node src/gkv2_driver_node.cpp)
ament_target_dependencies(gkv2_driver_node rclcpp geometry_msgs sensor_msgs std_msgs)
target_link_libraries(gkv2_driver_node Boost::system)
target_include_directories(gkv2_driver_node PUBLIC ${Boost_INCLUDE_DIRS})

# Узел 2: Мост управления моторами
add_executable(cmd_vel_bridge_node src/cmd_vel_bridge_node.cpp)
ament_target_dependencies(cmd_vel_bridge_node rclcpp geometry_msgs std_msgs)
target_link_libraries(cmd_vel_bridge_node Boost::system)
target_include_directories(cmd_vel_bridge_node PUBLIC ${Boost_INCLUDE_DIRS})

# Узел 3: Парсер навигации ГКВ2
add_executable(gkv2_nav_parser_node src/gkv2_nav_parser_node.cpp)
ament_target_dependencies(gkv2_nav_parser_node rclcpp geometry_msgs sensor_msgs std_msgs)
target_link_libraries(gkv2_nav_parser_node Boost::system)
target_include_directories(gkv2_nav_parser_node PUBLIC ${Boost_INCLUDE_DIRS})

# Линковка кастомного сообщения для gkv2_nav_parser_node
rosidl_get_typesupport_target(cpp_typesupport_target ${PROJECT_NAME} "rosidl_typesupport_cpp")
target_link_libraries(gkv2_nav_parser_node "${cpp_typesupport_target}")

# Установка исполняемых файлов
install(TARGETS
  gkv2_driver_node
  cmd_vel_bridge_node
  gkv2_nav_parser_node
  DESTINATION lib/${PROJECT_NAME}
)

# Установка launch и config файлов
install(DIRECTORY launch/
  DESTINATION share/${PROJECT_NAME}/launch
)
install(DIRECTORY config/
  DESTINATION share/${PROJECT_NAME}/config
)

ament_package()