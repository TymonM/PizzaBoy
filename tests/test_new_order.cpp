#include "macros.cpp"

#include "../src/order.h"
#include "../src/order_list.h"

void create_single_order() {
    Order order("One pepperoni pizza for Mike, delivered to 1 Elm Ave.");

    ASSERT(order.getDescription() == "One pepperoni pizza for Mike, delivered to 1 Elm Ave.");
}

void create_order_list() {
    OrderList list{};
    ASSERT(list.size() == 0);
    Order order1("One pepperoni pizza for Mike, delivered to 1 Elm Ave.");
    Order order2("Two pepperoni pizzas for Alice, delivered to 3 Arch Ave.");

    list.pushOrder(order1);
    list.pushOrder(order2);
    ASSERT(list.size() == 2);
    auto it = list.getOrders().begin();
    ASSERT(it++->getDescription() == "One pepperoni pizza for Mike, delivered to 1 Elm Ave.");
    ASSERT(it++->getDescription() == "Two pepperoni pizzas for Alice, delivered to 3 Arch Ave.");
}

int main() {
    create_single_order();
    create_order_list();

    return 0;
}