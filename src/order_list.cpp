#include "order_list.h"

OrderList::OrderList() = default;
void OrderList::pushOrder(const Order &order) {
    orders.push_back(order);
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
