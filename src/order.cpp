#include "order.h"

Order::Order(const std::string &description) {
    this->description = description;
}

const std::string &Order::getDescription() const {
    return description;
}
