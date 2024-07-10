#include "macros.cpp"

#include "../src/order.h"

void TEST_create_single_order() {
    Order order("One pepperoni pizza for Mike, delivered to 1 Elm Ave.");

    ASSERT(order.getDescription() == "One pepperoni pizza for Mike, delivered to 1 Elm Ave.");
}

void TEST_add_menu_items() {
    Order mikeOrder("For Mike");
    Order aliceOrder("For Alice");

    MenuItem pepperoni("Classic Pepperoni Pizza", 10.0);
    MenuItem margherita("Margherita Pizza", 9.0);
    MenuItem hawaiian("Hawaiian Pizza", 12.0);

    mikeOrder.addItem(OrderItem(pepperoni, 1));
    mikeOrder.addItem(OrderItem(margherita, 1));

    aliceOrder.addItem(OrderItem(pepperoni, 1));
    aliceOrder.addItem(OrderItem(hawaiian, 1));

    auto mikeItems = mikeOrder.getItems();
    auto it = mikeItems.begin();
    ASSERT(it->getItem().getName() == "Classic Pepperoni Pizza"
        && it++->getItem().getPrice() == 10.0);
    ASSERT(it->getItem().getName() == "Margherita Pizza"
        && it++->getItem().getPrice() == 9.0);

    auto aliceItems = aliceOrder.getItems();
    it = aliceItems.begin();
    ASSERT(it->getItem().getName() == "Classic Pepperoni Pizza"
        && it++->getItem().getPrice() == 10.0);
    ASSERT(it->getItem().getName() == "Hawaiian Pizza"
        && it++->getItem().getPrice() == 12.0);
}

int main() {
    TEST_create_single_order();
    TEST_add_menu_items();

    return 0;
}