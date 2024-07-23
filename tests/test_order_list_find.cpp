#include "macros.cpp"

#include "core/order.h"
#include "core/order_list.h"

OrderList buildSampleList();

void TEST_find_order() {
    OrderList list = buildSampleList();
    auto order = list.find("Mike");
    ASSERT(order->getDescription() == "For Mike, delivered to 1 Elm Ave.");
    ASSERT(order->getItems().size() == 1);
    ASSERT(order->getItems().begin()->getItem().getName() == "Classic Pepperoni Pizza");
    ASSERT(order->getItems().begin()->getItem().getPrice() == 10.0);
    ASSERT(order->getItems().begin()->getQuantity() == 1);
}

int main() {
    TEST_find_order();

    return 0;
}

OrderList buildSampleList() {
    OrderList list{};
    Order mikeOrder("For Mike, delivered to 1 Elm Ave.");
    Order aliceOrder("For Alice, delivered to 3 Arch Ave.");

    MenuItem pepperoni("Classic Pepperoni Pizza", 10.0);

    mikeOrder.addItem(OrderItem(pepperoni, 1));
    aliceOrder.addItem(OrderItem(pepperoni, 2));

    list.pushOrder(mikeOrder);
    list.pushOrder(aliceOrder);

    return list;
}