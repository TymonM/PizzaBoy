#include "order.h"

Order::Order(const std::string &description) {
    this->description = description;
}

const std::string &Order::getDescription() const {
    return description;
}

const std::vector<MenuItem> &Order::getItems() const {
    return items;
}

void Order::addItem(const MenuItem &item) {
    items.push_back(item);
}
