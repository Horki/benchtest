project(gtesting CXX)

add_executable(test_swap test_swap.cc)
target_link_libraries(test_swap ${CONAN_LIBS_GTEST})
target_include_directories(test_swap PUBLIC ../include/)

add_test(
  NAME test_swap
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/bin
  COMMAND test_swap
)

add_executable(test_caches test_caches.cc)
target_link_libraries(test_caches ${CONAN_LIBS_GTEST})
target_include_directories(test_caches PUBLIC ../include/)

add_test(
        NAME test_caches
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/bin
        COMMAND test_caches
)
