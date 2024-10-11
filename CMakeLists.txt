cmake_minimum_required(VERSION 3.10)
project(MyProject)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)

# Include directories
include_directories(include)

# Automatically add all .cpp files in the src directory
file(GLOB SOURCES "src/*.cpp")

# Add the executable target using the collected sources
add_executable(my_project ${SOURCES})
