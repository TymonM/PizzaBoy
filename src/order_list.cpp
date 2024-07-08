#include "order_list.h"

OrderList::OrderList() = default;
void OrderList::pushOrder(const Order &order) {
    orders.push_back(order);
}

size_t OrderList::size() const {
    return orders.size();
}

const Order& OrderList::getOrder(size_t index) const {
    return orders.at(index);
}

const std::vector<Order>& OrderList::getOrders() const {
    return orders;
}

void OrderList::erase(size_t index) {
    orders.erase(orders.begin() + index);
}
