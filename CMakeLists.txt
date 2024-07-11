cmake_minimum_required(VERSION 3.25)
project(DTS_91896)

set(CMAKE_CXX_STANDARD 23)

include(FetchContent)
FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz)
FetchContent_MakeAvailable(json)

include_directories(${json_SOURCE_DIR}/include)

add_library(DTS_91896_lib STATIC
        src/order.cpp
        src/order_list.cpp
        src/menu_item.cpp
        src/order_item.cpp
        src/menu_parser.cpp
        src/order_parser.cpp
        )

add_executable(main src/main.cpp)
target_link_libraries(main DTS_91896_lib)

# Testing
enable_testing()
add_subdirectory(tests)
