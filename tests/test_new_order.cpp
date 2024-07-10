#include "macros.cpp"

#include "../src/order.h"

void create_single_order() {
    Order order("One pepperoni pizza for Mike, delivered to 1 Elm Ave.");

    ASSERT(order.getDescription() == "One pepperoni pizza for Mike, delivered to 1 Elm Ave.");
}

void add_menu_items() {
    Order mikeOrder("For Mike");
    Order aliceOrder("For Alice");

    MenuItem pepperoni("Classic Pepperoni Pizza", 10.0);
    MenuItem margherita("Margherita Pizza", 9.0);
    MenuItem hawaiian("Hawaiian Pizza", 12.0);

    mikeOrder.addItem(pepperoni);
    mikeOrder.addItem(margherita);

    aliceOrder.addItem(pepperoni);
    aliceOrder.addItem(hawaiian);

    auto mikeItems = mikeOrder.getItems();
    auto it = mikeItems.begin();
    ASSERT(it->getName() == "Classic Pepperoni Pizza"
        && it++->getPrice() == 10.0);
    ASSERT(it->getName() == "Margherita Pizza"
        && it++->getPrice() == 9.0);

    auto aliceItems = aliceOrder.getItems();
    it = aliceItems.begin();
    ASSERT(it->getName() == "Classic Pepperoni Pizza"
        && it++->getPrice() == 10.0);
    ASSERT(it->getName() == "Hawaiian Pizza"
        && it++->getPrice() == 12.0);
}

int main() {
    create_single_order();
    add_menu_items();

    return 0;
}