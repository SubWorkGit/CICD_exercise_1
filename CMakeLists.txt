# Minimum CMake version required
cmake_minimum_required(VERSION 3.14)

# Define project name and version
project(CICD_exercise_1 VERSION 1.0 DESCRIPTION "CI/CD Exercise for Circular Buffer Testing")

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# FetchContent setup for GoogleTest
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# Ensure shared CRT for Windows
if(WIN32)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif()

# Make GoogleTest available
FetchContent_MakeAvailable(googletest)

# Enable testing
enable_testing()

# Add the main executable
add_executable(
    cicd_exercise_1
    tests/test_circular_buffer.cpp
)

# Add include directory for the project
target_include_directories(cicd_exercise_1 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Link GoogleTest libraries
target_link_libraries(
    cicd_exercise_1
    GTest::gtest_main
)

# Include GoogleTest and auto-discover tests
include(GoogleTest)
gtest_discover_tests(cicd_exercise_1)


