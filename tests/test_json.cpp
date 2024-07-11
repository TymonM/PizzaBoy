#include "macros.cpp"

#include "../src/menu_item.h"
#include "../src/menu_parser.h"
#include "../src/order_item.h"
#include "../src/order_parser.h"

void TEST_export_menu_item() {
    MenuItem pepperoni("Classic Pepperoni Pizza", 10.0);
    auto exported = MenuParser::exportMenuItem(pepperoni);
    ASSERT(exported["name"] == "Classic Pepperoni Pizza");
    ASSERT(exported["price"] == 10.0);
}

void TEST_export_order_item() {
    MenuItem pepperoni("Classic Pepperoni Pizza", 10.0);
    OrderItem item(pepperoni, 2);
    auto exported = OrderParser::exportOrderItem(item);
    ASSERT(exported["item"]["name"] == "Classic Pepperoni Pizza");
    ASSERT(exported["item"]["price"] == 10.0);
    ASSERT(exported["quantity"] == 2);
}

void TEST_export_whole_order() {
    MenuItem pepperoni("Classic Pepperoni Pizza", 10.0);
    MenuItem margherita("Classic Margherita Pizza", 9.0);

    Order order("For Mike, delivered to 1 Elm Ave.");
    order.addItem(OrderItem(pepperoni, 2));
    order.addItem(OrderItem(margherita, 1));

    auto exported = OrderParser::exportOrder(order);
    ASSERT(exported["items"].size() == 2);
    ASSERT(exported["items"][0]["item"]["name"] == "Classic Pepperoni Pizza");
    ASSERT(exported["items"][0]["item"]["price"] == 10.0);
    ASSERT(exported["items"][0]["quantity"] == 2);
    ASSERT(exported["items"][1]["item"]["name"] == "Classic Margherita Pizza");
    ASSERT(exported["items"][1]["item"]["price"] == 9.0);
    ASSERT(exported["items"][1]["quantity"] == 1);
}

int main() {
    TEST_export_menu_item();
    TEST_export_order_item();
    TEST_export_whole_order();

    return 0;
}
