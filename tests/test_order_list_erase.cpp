#include "macros.cpp"

#include "../src/order.h"
#include "../src/order_list.h"

OrderList buildSampleList();

void erase_order() {
    OrderList list = buildSampleList();

    list.erase(list.find("Mike"));
    ASSERT(list.size() == 1);
    ASSERT(list.getOrders().begin()->getDescription() == "For Alice, delivered to 3 Arch Ave."
        && list.getOrders().begin()->getItems().begin()->getName() == "Classic Pepperoni Pizza");
}

void doesnt_exist() {
    OrderList list = buildSampleList();
    ASSERT_THROWS(list.erase(list.find("Bob")), std::invalid_argument);
}

int main() {
    erase_order();
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