cmake_minimum_required(VERSION 3.8)
project(robokross_navigation)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

include_directories(include)

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(nav_msgs REQUIRED)



add_executable(nav_parser_udp_node src/nav_parser_udp_node.cpp)
ament_target_dependencies(nav_parser_udp_node rclcpp std_msgs geometry_msgs sensor_msgs nav_msgs)

add_executable(nav_logger_node src/nav_logger_node.cpp)
ament_target_dependencies(nav_logger_node rclcpp std_msgs geometry_msgs sensor_msgs nav_msgs)
target_include_directories(nav_parser_udp_node PRIVATE include)

install(TARGETS
  nav_parser_udp_node
  nav_logger_node
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY
  DESTINATION share/${PROJECT_NAME}/logs
)

install(PROGRAMS
  scripts/mock_nav_publisher.py
  scripts/mock_nav_udp_publisher.py
  DESTINATION lib/${PROJECT_NAME}
)


install(DIRECTORY
  launch/
  DESTINATION share/${PROJECT_NAME}/launch
)
if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
