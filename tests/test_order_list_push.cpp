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
    Order order("For Mike");
    // Order must contain at least one item
    ASSERT_THROWS(list.pushOrder(order), std::invalid_argument);
}

void TEST_assign_ids() {
    OrderList list{};
    Order mikeOrder("For Mike");
    Order aliceOrder("For Alice");

    MenuItem pepperoni("Classic Pepperoni Pizza", 10.0);
    mikeOrder.addItem(OrderItem(pepperoni, 1));
    aliceOrder.addItem(OrderItem(pepperoni, 2));

    list.pushOrder(mikeOrder);
    list.pushOrder(aliceOrder);
    auto orders = list.getOrders();
    auto it = orders.begin();
    ASSERT(it->getId() == 0 && (++it)->getId() == 1);

    list.erase(list.find("For Mike"));
    ASSERT(list.getOrders().begin()->getId() == 1);

    Order bobOrder("For Bob");
    bobOrder.addItem(OrderItem(pepperoni, 3));
    list.pushOrder(bobOrder);
    ASSERT(list.getOrders().begin()->getId() == 0);
}

int main() {
    TEST_push_orders();
    TEST_push_empty_order();
    TEST_assign_ids();

    return 0;
}
