cmake_minimum_required(VERSION 3.8)
project(executor_learn)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)

include_directories(
        include
)

add_executable(executor_learn src/executor_learn.cpp src/node1.cpp src/node2.cpp)
# add_executable(executor_learn src/executor_learn.cpp)

ament_target_dependencies(executor_learn rclcpp)

install(TARGETS
        executor_learn
        DESTINATION lib/${PROJECT_NAME})

ament_package()