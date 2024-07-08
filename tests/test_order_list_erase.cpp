#include "macros.cpp"

#include "../src/order.h"
#include "../src/order_list.h"

void erase_order() {
    OrderList list{};
    list.pushOrder(Order("One pepperoni pizza for Mike, delivered to 1 Elm Ave."));
    list.pushOrder(Order("Two pepperoni pizzas for Alice, delivered to 3 Arch Ave."));

    list.erase(list.find("Mike"));
    ASSERT(list.size() == 1);
    ASSERT(list.getOrders().begin()->getDescription() == "Two pepperoni pizzas for Alice, delivered to 3 Arch Ave.");
}

void doesnt_exist() {
    OrderList list{};
    list.pushOrder(Order("One pepperoni pizza for Mike, delivered to 1 Elm Ave."));
    list.pushOrder(Order("Two pepperoni pizzas for Alice, delivered to 3 Arch Ave."));
    ASSERT_THROWS(list.erase(list.find("Bob")), std::invalid_argument);
}

int main() {
    erase_order();
    doesnt_exist();

    return 0;
}