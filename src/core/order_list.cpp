#include "order_list.h"

#include "order_parser.h"

#include <fstream>
#include <algorithm>

OrderList::OrderList() = default;

void OrderList::clear() {
    std::scoped_lock lock(mutex);
    orders.clear();
}

OrderList::OrderList(const std::string &filename) {
    importOrders(filename);
}

OrderList::OrderList(const OrderList &other) {
    std::scoped_lock lock(mutex);
    orders = other.orders;
}

void OrderList::pushOrder(Order &order) {
    if (order.getItems().empty()) {
        throw std::invalid_argument("Order must contain at least one item");
    }

    // todo: hashmap
    // generate an id for the order, lowest id which doesn't already exist
    // insert it into the std::list sorted by id
    // note: this will not prioritise the oldest orders, so some customers may be waiting indefinitely
    std::scoped_lock lock(mutex);
    size_t id = 0;
    auto it = orders.begin();
    while (it != orders.end() && it->getId() == id) {
        it++;
        id++;
    }
    order.setId(id);
    orders.insert(it, order);
}

size_t OrderList::size() {
    std::scoped_lock lock(mutex);
    return orders.size();
}

std::list<Order> OrderList::getOrders() {
    std::scoped_lock lock(mutex);
    return orders;
}

void OrderList::erase(std::list<Order>::iterator it) {
    std::scoped_lock lock(mutex);
    if (it != orders.end()) {
        orders.erase(it);
    } else {
        // todo: custom exception
        throw std::invalid_argument("Order not found");
    }
}

std::list<Order>::iterator OrderList::find(const std::string &keyphrase) {
    std::scoped_lock lock(mutex);
    return std::find_if(orders.begin(), orders.end(), [&keyphrase](const Order& order) {
        return order.getDescription().find(keyphrase) != std::string::npos;
    });
}

void OrderList::exportOrders(const std::string &filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::invalid_argument("Could not open file for writing");
    }
    file << OrderParser::exportOrderList(*this).dump(EXPORT_INDENT);
}

void OrderList::importOrders(const std::string &filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::invalid_argument("Could not open file for reading");
    }
    nlohmann::json j;
    file >> j;
    OrderParser::importOrderList(*this, j);
}