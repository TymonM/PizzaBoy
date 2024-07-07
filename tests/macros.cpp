#ifndef DTS_91896_TEST_MACROS
#define DTS_91896_TEST_MACROS

#include <string>

// A custom macro to assert a condition is true
#define ASSERT_TRUE(condition)                                                  \
    if (!(condition)) {                                                         \
        throw std::runtime_error(std::string("\nAssertion failed in function ") \
        + std::string(__PRETTY_FUNCTION__)                                      \
        + std::string(" in file ")                                              \
        + std::string(__FILE__)                                                 \
        + std::string(" at line ")                                              \
        + std::to_string(__LINE__)                                              \
        );                                                                      \
    }

// A custom macro to assert that two strings are equal
#define ASSERT_EQUAL_STR(got,expect)                                            \
    if (!(got == expect)) {                                                     \
        throw std::runtime_error(std::string("\nAssertion failed in function ") \
        + std::string(__PRETTY_FUNCTION__)                                      \
        + std::string(" in file ")                                              \
        + std::string(__FILE__)                                                 \
        + std::string(" at line ")                                              \
        + std::to_string(__LINE__)                                              \
        + std::string("\nExpected \"")                                          \
        + expect                                                                \
        + std::string("\" but got \"")                                          \
        + got                                                                   \
        + std::string("\"")                                                     \
        );                                                                      \
}

#endif //DTS_91896_TEST_MACROS
