project(gtesting CXX)

add_executable(${PROJECT_NAME} test_swap.cc)
target_link_libraries(${PROJECT_NAME} ${CONAN_LIBS_GTEST})
target_include_directories(${PROJECT_NAME} PUBLIC ../include/)

add_test(
  NAME ${PROJECT_NAME}
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/bin
  COMMAND ${PROJECT_NAME}
)
