#include "macros.cpp"

#include "../src/order.h"
#include "../src/order_list.h"

OrderList buildSampleList();

void find_order() {
    OrderList list = buildSampleList();
    auto it = list.find("Mike");
    ASSERT(it == list.getOrders().begin());
}

void doesnt_exist() {
    OrderList list = buildSampleList();
    auto it = list.find("Bob");
    ASSERT(it == list.getOrders().end());
}

int main() {
    find_order();
    doesnt_exist();

    return 0;
}

OrderList buildSampleList() {
    OrderList list{};
    Order mikeOrder("For Mike, delivered to 1 Elm Ave.");
    Order aliceOrder("For Alice, delivered to 3 Arch Ave.");

    MenuItem pepperoni("Classic Pepperoni Pizza", 10.0);

    mikeOrder.addItem(pepperoni);
    aliceOrder.addItem(pepperoni);
    aliceOrder.addItem(pepperoni);

    list.pushOrder(mikeOrder);
    list.pushOrder(aliceOrder);

    return list;
}