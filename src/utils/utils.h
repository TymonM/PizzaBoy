#ifndef UTILS_H
#define UTILS_H

#include <string>

namespace utils {
    /**
     * @brief Format a price in the form $X.XX.
     *
     * @param price The price to format.
     * @return The formatted price as a string.
     */
    std::string formatPrice(double price);
}

#endif // UTILS_H