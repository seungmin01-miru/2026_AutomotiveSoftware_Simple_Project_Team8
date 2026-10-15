cmake_minimum_required(VERSION 3.8)
project(color_changer)

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
# ~~~
# -------------------------------------------------------------------------------

include_directories(
  include
)

# -------------------TODO - add executable color_changer.cpp--------------------
add_executable(${PROJECT_NAME} src/color_changer.cpp)
# ~~~
# -------------------------------------------------------------------------------

# -------------------TODO - add executable change_color_oneshot.cpp--------------------
add_executable(change_color_oneshot src/change_color_oneshot.cpp)
# ~~~
# -------------------------------------------------------------------------------


## Add dependencies to the color_changer executable
ament_target_dependencies(${PROJECT_NAME}
  rclcpp
  # -------------------TODO - add other dependencies--------------------
  turtlesim
  my_msgs
  # ~~~
  # -------------------------------------------------------------------------------
)

# -------------------TODO - add dependencies to the change_color_oneshot executable--------------------
ament_target_dependencies(change_color_oneshot
  rclcpp
)
# ~~~
# -------------------------------------------------------------------------------

# -------------------TODO - install the executables--------------------
install(TARGETS
  ${PROJECT_NAME}
  change_color_oneshot
  DESTINATION lib/${PROJECT_NAME}
)
# ~~~
# -------------------------------------------------------------------------------

ament_package()


