cmake_minimum_required(VERSION 3.5)

project(benchtest CXX)

# -g allows for gdb debugging
# turn on -03 for best performance
add_definitions(-std=c++17)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS "${CXX_FLAGS}")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(${PROJECT_NAME} src/bench.cc)
target_link_libraries(${PROJECT_NAME} ${CONAN_LIBS})
