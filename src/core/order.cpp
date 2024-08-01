#include "order.h"

Order::Order(const std::string& description) : description(description) {}

size_t Order::getId() const {
    return id;
}

void Order::setId(size_t id) {
    Order::id = id;
}

const std::string &Order::getDescription() const {
    return description;
}

const std::vector<OrderItem> &Order::getItems() const {
    return items;
}

double Order::calculateTotalPrice() const {
    double total = 0;
    for (const auto &item : items) {
        total += item.calculatePrice();
    }
    return total;
}

void Order::addItem(const OrderItem& item) {
    items.push_back(item);
}
