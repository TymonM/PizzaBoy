#include "macros.cpp"

#include "../src/order.h"
#include "../src/order_list.h"

void find_order() {
    OrderList list{};
    list.pushOrder(Order("One pepperoni pizza for Mike, delivered to 1 Elm Ave."));
    list.pushOrder(Order("Two pepperoni pizzas for Alice, delivered to 3 Arch Ave."));
    auto it = list.find("Mike");
    ASSERT(it == list.getOrders().begin());
}

void doesnt_exist() {
    OrderList list{};
    list.pushOrder(Order("One pepperoni pizza for Mike, delivered to 1 Elm Ave."));
    list.pushOrder(Order("Two pepperoni pizzas for Alice, delivered to 3 Arch Ave."));
    auto it = list.find("Bob");
    ASSERT(it == list.getOrders().end());
}

int main() {
    find_order();
    doesnt_exist();

    return 0;
}