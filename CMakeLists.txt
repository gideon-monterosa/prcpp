cmake_minimum_required(VERSION 3.16)

project(prcpp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

file(GLOB_RECURSE SRC_FILES "src/*.cpp")
file(GLOB_RECURSE HEADER_FILES "include/*.h")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_executable(prcpp ${SRC_FILES})

add_custom_target(run
    COMMAND prcpp
    DEPENDS prcpp
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)
