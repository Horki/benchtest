project(bench CXX)

add_executable(${PROJECT_NAME} bench.cc)
target_link_libraries(${PROJECT_NAME} ${CONAN_LIBS_BENCHMARK})
target_include_directories(${PROJECT_NAME} PUBLIC ../include/)

add_executable(${PROJECT_NAME}_fac bench_fac.cc)
target_link_libraries(${PROJECT_NAME}_fac ${CONAN_LIBS_BENCHMARK})
target_include_directories(${PROJECT_NAME}_fac PUBLIC ../include/)

add_executable(${PROJECT_NAME}_caches bench_caches.cc)
target_link_libraries(${PROJECT_NAME}_caches ${CONAN_LIBS_BENCHMARK})
target_include_directories(${PROJECT_NAME}_caches PUBLIC ../include/)


add_executable(${PROJECT_NAME}_rhomb bench_rhomb.cc)
target_link_libraries(${PROJECT_NAME}_rhomb ${CONAN_LIBS_BENCHMARK})
target_include_directories(${PROJECT_NAME}_rhomb PUBLIC ../include/)