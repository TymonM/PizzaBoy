#include "macros.cpp"

#include "../src/menu_parser.h"
#include "../src/order_parser.h"

#include <fstream>

OrderList buildSampleList();

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
    ASSERT(exported["description"] == "For Mike, delivered to 1 Elm Ave.");
    ASSERT(exported["items"].size() == 2);
    ASSERT(exported["items"][0]["item"]["name"] == "Classic Pepperoni Pizza");
    ASSERT(exported["items"][0]["item"]["price"] == 10.0);
    ASSERT(exported["items"][0]["quantity"] == 2);
    ASSERT(exported["items"][1]["item"]["name"] == "Classic Margherita Pizza");
    ASSERT(exported["items"][1]["item"]["price"] == 9.0);
    ASSERT(exported["items"][1]["quantity"] == 1);
}

void TEST_export_order_with_special_chars() {
    MenuItem pepperoni("Classic Pepperoni Pizza", 10.0);
    Order order("One peppero\\ni pizza for \"Mike\",\ndelivered to \\1 Elm Ave.\"\\");
    order.addItem(OrderItem(pepperoni, 1));

    auto exported = OrderParser::exportOrder(order);
    ASSERT(exported["description"] == "One peppero\\ni pizza for \"Mike\",\ndelivered to \\1 Elm Ave.\"\\");
    ASSERT(exported["items"].size() == 1);
    ASSERT(exported["items"][0]["item"]["name"] == "Classic Pepperoni Pizza");
    ASSERT(exported["items"][0]["item"]["price"] == 10.0);
    ASSERT(exported["items"][0]["quantity"] == 1);
}

void TEST_export_order_list() {
    OrderList list = buildSampleList();
    auto exported = OrderParser::exportOrderList(list);
    ASSERT(exported["orders"].size() == 2);
    ASSERT(exported["orders"][0]["description"] == "For Mike, delivered to 1 Elm Ave.");
    ASSERT(exported["orders"][0]["items"].size() == 1);
    ASSERT(exported["orders"][0]["items"][0]["item"]["name"] == "Classic Pepperoni Pizza");
    ASSERT(exported["orders"][0]["items"][0]["item"]["price"] == 10.0);
    ASSERT(exported["orders"][0]["items"][0]["quantity"] == 1);
    ASSERT(exported["orders"][1]["description"] == "For Alice, delivered to 3 Arch Ave.");
    ASSERT(exported["orders"][1]["items"].size() == 1);
    ASSERT(exported["orders"][1]["items"][0]["item"]["name"] == "Classic Pepperoni Pizza");
    ASSERT(exported["orders"][1]["items"][0]["item"]["price"] == 10.0);
    ASSERT(exported["orders"][1]["items"][0]["quantity"] == 2);
}

void TEST_export_order_list_to_file() {
    OrderList list = buildSampleList();
    list.exportOrders("test_export_orders.json");

    std::ifstream file("test_export_orders.json");
    ASSERT(file.is_open());
    std::stringstream buffer;
    buffer << file.rdbuf();
    ASSERT(buffer.str() == R"({
  "orders": [
    {
      "description": "For Mike, delivered to 1 Elm Ave.",
      "items": [
        {
          "item": {
            "name": "Classic Pepperoni Pizza",
            "price": 10.0
          },
          "quantity": 1
        }
      ]
    },
    {
      "description": "For Alice, delivered to 3 Arch Ave.",
      "items": [
        {
          "item": {
            "name": "Classic Pepperoni Pizza",
            "price": 10.0
          },
          "quantity": 2
        }
      ]
    }
  ]
})");

    // remove the file
    std::remove("test_export_orders.json");
}

void TEST_import_order_list() {
    {
        OrderList writeList = buildSampleList();
        writeList.exportOrders("test_import_orders.json");
    } // writeList goes out of scope and is destroyed
    OrderList readList{};
    readList.importOrders("test_import_orders.json");
    ASSERT(readList.size() == 2);
    auto it = readList.getOrders().begin();
    ASSERT(it->getDescription() == "For Mike, delivered to 1 Elm Ave.");
    ASSERT(it->getItems().size() == 1);
    ASSERT(it->getItems().begin()->getItem().getName() == "Classic Pepperoni Pizza");
    ASSERT(it->getItems().begin()->getItem().getPrice() == 10.0);
    ASSERT(it->getItems().begin()->getQuantity() == 1);
    it++;
    ASSERT(it->getDescription() == "For Alice, delivered to 3 Arch Ave.");
    ASSERT(it->getItems().size() == 1);
    ASSERT(it->getItems().begin()->getItem().getName() == "Classic Pepperoni Pizza");
    ASSERT(it->getItems().begin()->getItem().getPrice() == 10.0);
    ASSERT(it->getItems().begin()->getQuantity() == 2);

    // remove the file
    std::remove("test_import_orders.json");
}

void TEST_import_order_list_constructor() {
    {
        OrderList writeList = buildSampleList();
        writeList.exportOrders("test_import_orders_constructor.json");
    } // writeList goes out of scope and is destroyed
    OrderList readList("test_import_orders_constructor.json");
    ASSERT(readList.size() == 2);
    auto it = readList.getOrders().begin();
    ASSERT(it->getDescription() == "For Mike, delivered to 1 Elm Ave.");
    ASSERT(it->getItems().size() == 1);
    ASSERT(it->getItems().begin()->getItem().getName() == "Classic Pepperoni Pizza");
    ASSERT(it->getItems().begin()->getItem().getPrice() == 10.0);
    ASSERT(it->getItems().begin()->getQuantity() == 1);
    it++;
    ASSERT(it->getDescription() == "For Alice, delivered to 3 Arch Ave.");
    ASSERT(it->getItems().size() == 1);
    ASSERT(it->getItems().begin()->getItem().getName() == "Classic Pepperoni Pizza");
    ASSERT(it->getItems().begin()->getItem().getPrice() == 10.0);
    ASSERT(it->getItems().begin()->getQuantity() == 2);

    // remove the file
    std::remove("test_import_orders_constructor.json");
}

void TEST_export_order_list_with_special_chars_to_file() {
    {
        OrderList writeList{};
        MenuItem pepperoni(R"(Classic "Peppero\ni" Pizza
Yum)", 10.0);
        Order order(R"(One peppero\ni pizza for "Mike",
delivered to \1 Elm Ave.\"\\)");
        order.addItem(OrderItem(pepperoni, 1));
        writeList.pushOrder(order);
        writeList.exportOrders("test_export_orders_special_chars.json");
    } // writeList goes out of scope and is destroyed

    OrderList readList("test_export_orders_special_chars.json");
    ASSERT(readList.size() == 1);
    auto it = readList.getOrders().begin();
    ASSERT(it->getDescription() == R"(One peppero\ni pizza for "Mike",
delivered to \1 Elm Ave.\"\\)");
    ASSERT(it->getItems().size() == 1);
    ASSERT(it->getItems().begin()->getItem().getName() == R"(Classic "Peppero\ni" Pizza
Yum)");
    ASSERT(it->getItems().begin()->getItem().getPrice() == 10.0);
    ASSERT(it->getItems().begin()->getQuantity() == 1);

    // remove the file
    std::remove("test_export_orders_special_chars.json");
}

int main() {
    TEST_export_menu_item();
    TEST_export_order_item();
    TEST_export_whole_order();
    TEST_export_order_with_special_chars();
    TEST_export_order_list();
    TEST_export_order_list_to_file();
    TEST_import_order_list();
    TEST_import_order_list_constructor();
    TEST_export_order_list_with_special_chars_to_file();

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
