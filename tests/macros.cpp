#ifndef DTS_91896_TEST_MACROS
#define DTS_91896_TEST_MACROS

#include <string>

// A custom exception to throw when an assertion fails
struct AssertionFailed : std::runtime_error {
explicit AssertionFailed(const std::string& message) : std::runtime_error(message) {}
};

// A custom macro to assert a condition is true
#define ASSERT( ... )                                                 \
do {                                                                  \
    if( !( __VA_ARGS__ ) ) {                                          \
        throw AssertionFailed(std::string("\nUnit test assert [ ") \
        + std::string( #__VA_ARGS__ )                                 \
        + std::string(" ] failed in line [ ")                         \
        + std::to_string(__LINE__)                                    \
        + std::string(" ] file [ ")                                   \
        + std::string(__FILE__)                                       \
        + std::string(" ]")                                           \
        );                                                            \
    }                                                                 \
} while( false )

// A custom macro to assert that a call throws the expected exception
#define ASSERT_THROWS( expression, exception ) \
do { \
    try { \
        expression; \
        throw AssertionFailed(std::string("\nUnit test assert_throws [ ") \
        + std::string( #expression )                                  \
        + std::string(" ] failed in line [ ")                         \
        + std::to_string(__LINE__)                                    \
        + std::string(" ] file [ ")                                   \
        + std::string(__FILE__)                                       \
        + std::string(" ]: No exception")                             \
        );                                                            \
    } catch (const exception& e) {                                    \
        /* Expected exception */                                      \
    } catch (const AssertionFailed& e) {                              \
        throw e;                                                      \
    } catch (...) {                                                   \
        throw AssertionFailed(std::string("\nUnit test assert_throws [ ") \
        + std::string( #expression )                                  \
        + std::string(" ] failed in line [ ")                         \
        + std::to_string(__LINE__)                                    \
        + std::string(" ] file [ ")                                   \
        + std::string(__FILE__)                                       \
        + std::string(" ]: Unexpected exception")                     \
        ); \
    } \
} while( false )

#endif //DTS_91896_TEST_MACROS
