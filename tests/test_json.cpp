#include "macros.cpp"

#include "../src/menu_item.h"
#include "../src/menu_parser.h"

void TEST_export_menu_item() {
    MenuItem pepperoni("Classic Pepperoni Pizza", 10.0);
    auto exported = MenuParser::exportMenuItem(pepperoni);
    ASSERT(exported["name"] == "Classic Pepperoni Pizza");
    ASSERT(exported["price"] == 10.0);
}

int main() {
    TEST_export_menu_item();

    return 0;
}
