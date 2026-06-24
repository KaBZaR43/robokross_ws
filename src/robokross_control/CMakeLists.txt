cmake_minimum_required(VERSION 3.8)
project(robokross_control)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Поиск зависимостей
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)

# Добавление исполняемого файла
add_executable(stm32_bridge_node src/stm32_bridge_node.cpp)
ament_target_dependencies(stm32_bridge_node rclcpp std_msgs geometry_msgs)

add_executable(vehicle_mode_manager_node src/vehicle_mode_manager_node.cpp)
ament_target_dependencies(vehicle_mode_manager_node rclcpp std_msgs)

# Установка исполняемых файлов
install(TARGETS
  stm32_bridge_node
  vehicle_mode_manager_node
  DESTINATION lib/${PROJECT_NAME}
)

# Установка директорий (опционально)
install(DIRECTORY
  launch/
  DESTINATION share/${PROJECT_NAME}/launch
)

install(DIRECTORY
  config/
  DESTINATION share/${PROJECT_NAME}/config
  OPTIONAL
)

# Тестирование
if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()