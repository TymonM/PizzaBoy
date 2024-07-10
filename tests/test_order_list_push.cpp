#include "macros.cpp"

#include "../src/order.h"
#include "../src/order_list.h"

void push_orders() {
    OrderList list{};
    ASSERT(list.size() == 0);
    Order mikeOrder("For Mike");
    Order aliceOrder("For Alice");

    MenuItem pepperoni("Classic Pepperoni Pizza", 10.0);
    mikeOrder.addItem(pepperoni);
    aliceOrder.addItem(pepperoni);

    list.pushOrder(mikeOrder);
    list.pushOrder(aliceOrder);
    ASSERT(list.size() == 2);
    auto it = list.getOrders().begin();
    ASSERT(it->getDescription() == "For Mike"
        && it++->getItems().begin()->getName() == "Classic Pepperoni Pizza");
    ASSERT(it->getDescription() == "For Alice"
        && it++->getItems().begin()->getName() == "Classic Pepperoni Pizza");
}

void push_empty_order() {
    OrderList list{};
    // Order must contain at least one item
    ASSERT_THROWS(list.pushOrder(Order("For Mike")), std::invalid_argument);
}

int main() {
    push_orders();
    push_empty_order();

    return 0;
}
