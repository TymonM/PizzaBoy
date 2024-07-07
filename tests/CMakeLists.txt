add_library(macros_lib STATIC macros.cpp)

add_executable(test_new_order test_new_order.cpp)
target_link_libraries(test_new_order DTS_91896_lib macros_lib)

add_test(NAME test_new_order COMMAND test_new_order)