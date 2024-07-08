#ifndef DTS_91896_ORDER_LIST_H
#define DTS_91896_ORDER_LIST_H

#include "order.h"

#include <vector>

class OrderList {
private:
    std::vector<Order> orders{};
public:
    OrderList();
    void pushOrder(const Order& order);
    size_t size() const;
    const Order& getOrder(size_t index) const;
    const std::vector<Order>& getOrders() const;
    void erase(size_t index);
};


#endif //DTS_91896_ORDER_LIST_H
