cmake_minimum_required(VERSION 2.8.3)
project(auto_trax_sensors)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  nav_msgs
  sensor_msgs
)

catkin_package(
  INCLUDE_DIRS include
)

include_directories(
  ${catkin_INCLUDE_DIRS}
  ${roscpp_INCLUDE_DIRS}
  include
)

## Declare a C++ executable
add_executable(dead_reckoning src/dead_reckoning.cpp)

## Specify libraries to link a library or executable target against
target_link_libraries(dead_reckoning ${catkin_LIBRARIES} ${roslib_LIBRARIES})