cmake_minimum_required(VERSION 3.25)
project(DTS_91896)

set(CMAKE_CXX_STANDARD 23)

# Dependencies
include(FetchContent)
FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz)
FetchContent_MakeAvailable(json)
include_directories(${json_SOURCE_DIR}/include)

FetchContent_Declare(ftxui
        GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
        GIT_TAG v5.0.0
        )
FetchContent_MakeAvailable(ftxui)

# Libraries and executable
add_library(DTS_91896_core STATIC
        src/core/order.cpp
        src/core/order_list.cpp
        src/core/menu_item.cpp
        src/core/order_item.cpp
        src/core/menu_parser.cpp
        src/core/order_parser.cpp
        src/core/menu.cpp
        )
add_library(DTS_91896_ui STATIC
        src/ui/tui.cpp
        )
target_link_libraries(DTS_91896_ui
        PRIVATE ftxui::screen
        PRIVATE ftxui::dom
        PRIVATE ftxui::component
        )
include_directories(src)

add_executable(main src/main.cpp)
target_link_libraries(main
        PRIVATE DTS_91896_core
        PRIVATE DTS_91896_ui
        )

# Testing
enable_testing()
add_subdirectory(tests)
