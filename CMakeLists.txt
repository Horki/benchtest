cmake_minimum_required(VERSION 3.5)

project(prog CXX)

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

if (NOT CMAKE_BUILD_TYPE)
  message(STATUS "Set build type to: Release")
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall -Werror")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# Conan
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

# Test
enable_testing()
add_subdirectory(test)

# Bench
add_subdirectory(bench)

add_executable(${PROJECT_NAME} src/main.cc)
target_include_directories(${PROJECT_NAME} PUBLIC include/)
