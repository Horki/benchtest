cmake_minimum_required(VERSION 3.5)

project(benchtest CXX)

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

if (NOT CMAKE_BUILD_TYPE)
  message(STATUS "Set build type to: Release")
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall -Werror")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

enable_testing()
add_subdirectory(test)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(prog src/main.cc)
target_include_directories(prog PUBLIC include/)

add_executable(${PROJECT_NAME} bench/bench.cc)
target_link_libraries(${PROJECT_NAME} ${CONAN_LIBS_BENCHMARK})
target_include_directories(${PROJECT_NAME} PUBLIC include/)
