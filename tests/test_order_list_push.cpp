#include "macros.cpp"

#include "core/order.h"
#include "core/order_list.h"

void TEST_push_orders() {
    OrderList list{};
    ASSERT(list.size() == 0);
    Order mikeOrder("For Mike");
    Order aliceOrder("For Alice");

    MenuItem pepperoni("Classic Pepperoni Pizza", 10.0);
    mikeOrder.addItem(OrderItem(pepperoni, 1));
    aliceOrder.addItem(OrderItem(pepperoni, 2));

    list.pushOrder(mikeOrder);
    list.pushOrder(aliceOrder);
    ASSERT(list.size() == 2);
    auto orders = list.getOrders();
    auto it = orders.begin();
    ASSERT(it->getDescription() == "For Mike"
        && it++->getItems().begin()->getItem().getName() == "Classic Pepperoni Pizza");
    ASSERT(it->getDescription() == "For Alice"
        && it++->getItems().begin()->getItem().getName() == "Classic Pepperoni Pizza");
}

void TEST_push_empty_order() {
    OrderList list{};
    // Order must contain at least one item
    ASSERT_THROWS(list.pushOrder(Order("For Mike")), std::invalid_argument);
}

int main() {
    TEST_push_orders();
    TEST_push_empty_order();

    return 0;
}
