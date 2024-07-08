#include "order_list.h"

#include <fstream>
#include <algorithm>

OrderList::OrderList() = default;
void OrderList::pushOrder(const Order &order) {
    orders.push_back(order);
}

OrderList::OrderList(const std::string &filename) {
    importOrders(filename);
}

size_t OrderList::size() const {
    return orders.size();
}

const std::list<Order>& OrderList::getOrders() const {
    return orders;
}

void OrderList::erase(std::list<Order>::iterator it) {
    if (it != orders.end()) {
        orders.erase(it);
    } else {
        // todo: custom exception
        throw std::invalid_argument("Order not found");
    }
}

std::list<Order>::iterator OrderList::find(const std::string &keyphrase) {
    return std::find_if(orders.begin(), orders.end(), [&keyphrase](const Order& order) {
        return order.getDescription().find(keyphrase) != std::string::npos;
    });
}

void OrderList::exportOrders(const std::string &filename) const {
    std::ofstream file(filename);
    // todo: make this format better, sanitize input
    for (const auto& order : orders) {
        file << order.getDescription() << std::endl;
    }
}

void OrderList::importOrders(const std::string &filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::invalid_argument("File not found");
    }
    std::string line;
    while (std::getline(file, line)) {
        pushOrder(Order(line));
    }
}
