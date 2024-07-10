#ifndef DTS_91896_TEST_MACROS
#define DTS_91896_TEST_MACROS

#include <sstream>
#include <stdexcept>

// A custom exception to throw when an assertion fails
struct AssertionFailed : std::runtime_error {
    explicit AssertionFailed(const std::string& message) : std::runtime_error(message) {}
};

// A custom macro to assert a condition is true
#define ASSERT( ... )                                                 \
do {                                                                  \
    if( !( __VA_ARGS__ ) ) {                                          \
        std::stringstream ss;                                         \
        ss << "\nUnit test assert [ " << #__VA_ARGS__                 \
           << " ] failed in line [ " << __LINE__                      \
           << " ] file [ " << __FILE__ << " ]";                       \
        throw AssertionFailed(ss.str());                              \
    }                                                                 \
} while( false )

// A custom macro to assert that a call throws the expected exception
#define ASSERT_THROWS( expression, exception )                        \
do {                                                                  \
    try {                                                             \
        expression;                                                   \
        std::stringstream ss;                                         \
        ss << "\nUnit test assert_throws [ " << #expression           \
           << " ] failed in line [ " << __LINE__                      \
           << " ] file [ " << __FILE__ << " ]: No exception";         \
        throw AssertionFailed(ss.str());                              \
    } catch (const exception& e) {                                    \
        /* Expected exception */                                      \
    } catch (const AssertionFailed& e) {                              \
        throw;                                                        \
    } catch (...) {                                                   \
        std::stringstream ss;                                         \
        ss << "\nUnit test assert_throws [ " << #expression           \
           << " ] failed in line [ " << __LINE__                      \
           << " ] file [ " << __FILE__ << " ]: Unexpected exception"; \
        throw AssertionFailed(ss.str());                              \
    }                                                                 \
} while( false )

#endif //DTS_91896_TEST_MACROS