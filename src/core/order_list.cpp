#include "order_list.h"

#include "order_parser.h"

#include <fstream>
#include <algorithm>

OrderList::OrderList() = default;
void OrderList::pushOrder(const Order &order) {
    if (order.getItems().empty()) {
        throw std::invalid_argument("Order must contain at least one item");
    }
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
    *this = OrderParser::importOrderList(j);
}