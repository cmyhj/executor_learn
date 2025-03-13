cmake_minimum_required(VERSION 3.8)
project(executor_learn)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)

find_package(rclcpp_components REQUIRED)

include_directories(
        include
)

add_executable(executor_learn src/executor_learn.cpp src/node1.cpp src/node2.cpp)
ament_target_dependencies(executor_learn rclcpp )
install(TARGETS
        executor_learn
        DESTINATION lib/${PROJECT_NAME})
# add_library(executor_component SHARED src/node1.cpp)
# ament_target_dependencies(executor_component rclcpp rclcpp_components)
# rclcpp_components_register_nodes(executor_component "my_namespace::Node1")
# install(TARGETS
#        executor_component
#        ARCHIVE DESTINATION lib
#        LIBRARY DESTINATION lib
#        RUNTIME DESTINATION bin)
# install(DIRECTORY launch 
#         DESTINATION share/${PROJECT_NAME})




ament_package()