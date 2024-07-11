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

int main() {
    TEST_export_menu_item();
    TEST_export_order_item();

    return 0;
}
