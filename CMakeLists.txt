cmake_minimum_required(VERSION 3.25)
project(DTS_91896)

set(CMAKE_CXX_STANDARD 23)

add_library(DTS_91896_lib STATIC src/order.cpp)

add_executable(main src/main.cpp)
target_link_libraries(main DTS_91896_lib)

# Testing
enable_testing()
add_subdirectory(tests)
