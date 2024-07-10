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

double Order::calculateTotalPrice() const {
    double total = 0;
    for (const auto &item : items) {
        total += item.getPrice();
    }
    return total;
}

void Order::addItem(const MenuItem &item) {
    items.push_back(item);
}
