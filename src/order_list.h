#ifndef DTS_91896_ORDER_LIST_H
#define DTS_91896_ORDER_LIST_H

#include "order.h"

#include <list>

class OrderList {
private:
    std::list<Order> orders{};
public:
    OrderList();
    void pushOrder(const Order& order);
    size_t size() const;
    const std::list<Order>& getOrders() const;
    void erase(std::list<Order>::iterator it);
    std::list<Order>::iterator find(const std::string& keyphrase);
};


#endif //DTS_91896_ORDER_LIST_H
