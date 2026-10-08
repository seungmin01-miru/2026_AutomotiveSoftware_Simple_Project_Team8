cmake_minimum_required(VERSION 3.8)
project(hmi)

if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()


if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
# -------------------TODO - find other dependencies--------------------
find_package(turtlesim REQUIRED)
find_package(my_msgs REQUIRED)
find_package(visualization_msgs REQUIRED)
# -------------------------------------------------------------------------------


include_directories(
  include
)

# -------------------TODO - add executable visualizer.cpp--------------------
add_executable(${PROJECT_NAME}
  src/visualizer.cpp
)
# -------------------------------------------------------------------------------

## Add dependencies to the executable
ament_target_dependencies(${PROJECT_NAME}
  rclcpp
  # -------------------TODO - add other dependencies--------------------
  turtlesim
  my_msgs
  visualization_msgs
  # -------------------------------------------------------------------------------
)


# -------------------TODO - install the executable--------------------
install(TARGETS
  ${PROJECT_NAME}
  DESTINATION lib/${PROJECT_NAME}
)
# -------------------------------------------------------------------------------


ament_package()
