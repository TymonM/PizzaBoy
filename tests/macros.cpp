#ifndef DTS_91896_TEST_MACROS
#define DTS_91896_TEST_MACROS

#include <string>

// A custom macro to assert a condition is true
#define ASSERT( ... )                                                 \
do {                                                                  \
    if( !( __VA_ARGS__ ) ) {                                          \
        throw std::runtime_error(std::string("\nUnit test assert [ ") \
        + std::string( #__VA_ARGS__ )                                 \
        + std::string(" ] failed in line [ ")                         \
        + std::to_string(__LINE__)                                    \
        + std::string(" ] file [ ")                                   \
        + std::string(__FILE__)                                       \
        + std::string(" ]")                                           \
        );                                                            \
    }                                                                 \
} while( false )

#endif //DTS_91896_TEST_MACROS
