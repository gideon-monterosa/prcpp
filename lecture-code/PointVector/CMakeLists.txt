cmake_minimum_required(VERSION 3.16)

project(point_vector)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

file(GLOB_RECURSE SRC_FILES "./*.cpp")
file(GLOB_RECURSE HEADER_FILES "./*.h")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_executable(point_vector ${SRC_FILES})

add_custom_target(run
    COMMAND point_vector
    DEPENDS point_vector
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)
