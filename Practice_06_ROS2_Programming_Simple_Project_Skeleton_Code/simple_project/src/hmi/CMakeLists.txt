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
# ~~~
# -------------------------------------------------------------------------------


include_directories(
  include
)

# -------------------TODO - add executable visualizer.cpp--------------------
# ~~~
# -------------------------------------------------------------------------------

## Add dependencies to the executable
ament_target_dependencies(${PROJECT_NAME}
  rclcpp
  # -------------------TODO - add other dependencies--------------------
  # ~~~
  # -------------------------------------------------------------------------------
)


# -------------------TODO - install the executable--------------------
# ~~~
# -------------------------------------------------------------------------------


ament_package()
