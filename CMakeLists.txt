cmake_minimum_required(VERSION 3.10)

# Set your project name
project(CoordinateConversion)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(CoordinateConversion main.cpp)

# Find GeographicLib package (assuming it is installed in a standard location)
set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};/usr/share/cmake/geographiclib")
find_package(GeographicLib REQUIRED)

# Include directories from GeographicLib
# print the value of GeographicLib_INCLUDE_DIRS
message(STATUS "GeographicLib_INCLUDE_DIRS: ${GeographicLib_INCLUDE_DIRS}")
include_directories(${GeographicLib_INCLUDE_DIRS})

# Link against GeographicLib
target_link_libraries(CoordinateConversion ${GeographicLib_LIBRARIES})


