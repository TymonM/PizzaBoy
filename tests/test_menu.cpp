#include "macros.cpp"

#include "../src/menu.h"
#include "../src/order.h"

void TEST_create_menu() {
    Menu menu;
    MenuItem pepperoni("Classic Pepperoni Pizza", 10.0);
    MenuItem margherita("Margherita Pizza", 9.0);
    MenuItem hawaiian("Hawaiian Pizza", 12.0);

    menu.addItem(pepperoni);
    menu.addItem(margherita);
    menu.addItem(hawaiian);

    auto items = menu.getItems();
    auto it = items.begin();
    ASSERT(it->getName() == "Classic Pepperoni Pizza"
        && it++->getPrice() == 10.0);
    ASSERT(it->getName() == "Margherita Pizza"
        && it++->getPrice() == 9.0);
    ASSERT(it->getName() == "Hawaiian Pizza"
        && it++->getPrice() == 12.0);
}

void TEST_use_menu() {
    Menu menu;
    MenuItem pepperoni("Classic Pepperoni Pizza", 10.0);
    MenuItem margherita("Margherita Pizza", 9.0);
    MenuItem hawaiian("Hawaiian Pizza", 12.0);

    menu.addItem(pepperoni);
    menu.addItem(margherita);
    menu.addItem(hawaiian);

    Order order("For Mike");
    order.addItem(OrderItem(*menu.getItems().begin(), 1));
    order.addItem(OrderItem(*(menu.getItems().begin() + 1), 2));

    ASSERT(order.calculateTotalPrice() == 28.0);
}

void TEST_empty_name() {
    Menu menu;
    MenuItem nothing("", 10.0);
    ASSERT_THROWS(menu.addItem(nothing), std::invalid_argument);
}

void TEST_negative_price() {
    Menu menu;
    MenuItem cheap_pepperoni("Classic Pepperoni Pizza", -10.0);
    ASSERT_THROWS(menu.addItem(cheap_pepperoni), std::invalid_argument);
}

int main() {
    TEST_create_menu();
    TEST_use_menu();
    TEST_empty_name();
    TEST_negative_price();

    return 0;
}
