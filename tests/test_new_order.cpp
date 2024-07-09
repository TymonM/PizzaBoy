#include "macros.cpp"

#include "../src/order.h"
#include "../src/order_list.h"

void create_single_order() {
    Order order("One pepperoni pizza for Mike, delivered to 1 Elm Ave.");

    ASSERT(order.getDescription() == "One pepperoni pizza for Mike, delivered to 1 Elm Ave.");
}

void create_order_list() {
    OrderList list{};
    ASSERT(list.size() == 0);
    Order order1("One pepperoni pizza for Mike, delivered to 1 Elm Ave.");
    Order order2("Two pepperoni pizzas for Alice, delivered to 3 Arch Ave.");

    list.pushOrder(order1);
    list.pushOrder(order2);
    ASSERT(list.size() == 2);
    auto it = list.getOrders().begin();
    ASSERT(it++->getDescription() == "One pepperoni pizza for Mike, delivered to 1 Elm Ave.");
    ASSERT(it++->getDescription() == "Two pepperoni pizzas for Alice, delivered to 3 Arch Ave.");
}

void add_menu_items() {
    Order mike_order("For Mike");
    Order alice_order("For Alice");

    MenuItem pepperoni("Classic Pepperoni Pizza", 10.0);
    MenuItem margherita("Margherita Pizza", 9.0);
    MenuItem hawaiian("Hawaiian Pizza", 12.0);

    mike_order.addItem(pepperoni);
    mike_order.addItem(margherita);

    alice_order.addItem(pepperoni);
    alice_order.addItem(hawaiian);

    auto mike_items = mike_order.getItems();
    auto it = mike_items.begin();
    ASSERT(it->getName() == "Classic Pepperoni Pizza"
        && it++->getPrice() == 10.0);
    ASSERT(it->getName() == "Margherita Pizza"
        && it++->getPrice() == 9.0);

    auto alice_items = alice_order.getItems();
    it = alice_items.begin();
    ASSERT(it->getName() == "Classic Pepperoni Pizza"
        && it++->getPrice() == 10.0);
    ASSERT(it->getName() == "Hawaiian Pizza"
        && it++->getPrice() == 12.0);
}

int main() {
    create_single_order();
    create_order_list();
    add_menu_items();

    return 0;
}