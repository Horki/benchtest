project(bench CXX)

add_executable(${PROJECT_NAME} bench.cc)
target_link_libraries(${PROJECT_NAME} ${CONAN_LIBS_BENCHMARK})
target_include_directories(${PROJECT_NAME} PUBLIC ../include/)
