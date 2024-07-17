#include "utils.h"

#include <iomanip>
#include <sstream>

std::string utils::formatPrice(double price) {
    std::ostringstream stream;
    stream << std::fixed << std::setprecision(2) << "$" << price;
    return stream.str();
}