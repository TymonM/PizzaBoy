#include "macros.cpp"

#include "core/order.h"
#include "core/order_list.h"

OrderList buildSampleList();

void TEST_find_order() {
    OrderList list = buildSampleList();
    auto it = list.find("Mike");
    ASSERT(it == list.getOrders().begin());
}

void TEST_doesnt_exist() {
    OrderList list = buildSampleList();
    auto it = list.find("Bob");
    ASSERT(it == list.getOrders().end());
}

int main() {
    TEST_find_order();
    TEST_doesnt_exist();

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