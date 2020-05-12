project(gtesting CXX)

add_executable(${PROJECT_NAME}_swap test_swap.cc)
target_link_libraries(${PROJECT_NAME}_swap ${CONAN_LIBS_GTEST})
target_include_directories(${PROJECT_NAME}_swap PUBLIC ../include/)

add_test(
  NAME ${PROJECT_NAME}_swap
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/bin
  COMMAND ${PROJECT_NAME}_swap
)

add_executable(${PROJECT_NAME}_caches test_caches.cc)
target_link_libraries(${PROJECT_NAME}_caches ${CONAN_LIBS_GTEST})
target_include_directories(${PROJECT_NAME}_caches PUBLIC ../include/)

add_test(
        NAME ${PROJECT_NAME}_caches
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/bin
        COMMAND ${PROJECT_NAME}_caches
)
