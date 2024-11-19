cmake_minimum_required(VERSION 3.28)
project(PerlinNoise)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/b514bdc898e2951020cbdca1304b75f5950d1f59.zip # Version 1.15.2
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include_directories(${PROJECT_NAME}/include/${PROJECT_NAME}/)

file(GLOB HEADERS
    ${PROJECT_NAME}/include/${PROJECT_NAME}/*.h
)

file(GLOB SOURCES
    ${PROJECT_NAME}/src/*.cpp
)

add_executable(
    ${PROJECT_NAME}
    ${PROJECT_NAME}/main.cpp
    ${SOURCES} 
    ${HEADERS}
)

target_compile_definitions(${PROJECT_NAME} PRIVATE PROJECT_SOURCE_DIR="${CMAKE_SOURCE_DIR}")

enable_testing()

add_executable(
    Test_${PROJECT_NAME}
    ${SOURCES}
    ${HEADERS}
    Tests/${PROJECT_NAME}/Test_${PROJECT_NAME}.cpp
)
target_link_libraries(
    Test_${PROJECT_NAME} 
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(Test_${PROJECT_NAME})

target_compile_definitions(Test_${PROJECT_NAME} PRIVATE PROJECT_SOURCE_DIR="${CMAKE_SOURCE_DIR}")
