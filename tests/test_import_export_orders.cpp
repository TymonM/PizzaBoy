#include "macros.cpp"

#include "../src/order.h"
#include "../src/order_list.h"

#include <fstream>

OrderList buildSampleList();

void TEST_export_list() {
    OrderList list = buildSampleList();

    list.exportOrders("test_export_orders.txt");

    // make sure the file was indeed created and contains the expected data
    std::ifstream file("test_export_orders.txt");
    ASSERT(file.is_open());
    std::string line;
    std::getline(file, line);
    ASSERT(line == "For Mike, delivered to 1 Elm Ave.");
    std::getline(file, line);
    ASSERT(line == "For Alice, delivered to 3 Arch Ave.");

    // remove the file
    std::remove("test_export_orders.txt");
}

void TEST_import_list() {
    {
        OrderList writeList = buildSampleList();
        writeList.exportOrders("test_import_orders.txt");
    } // writeList goes out of scope and is destroyed
    OrderList readList{};
    readList.importOrders("test_import_orders.txt");
    ASSERT(readList.size() == 2);
    auto it = readList.getOrders().begin();
    ASSERT(it++->getDescription() == "For Mike, delivered to 1 Elm Ave.");
    ASSERT(it++->getDescription() == "For Alice, delivered to 3 Arch Ave.");

    // remove the file
    std::remove("test_import_orders.txt");
}

void TEST_import_constructor() {
    {
        OrderList writeList = buildSampleList();
        writeList.exportOrders("test_import_constructor.txt");
    } // writeList goes out of scope and is destroyed
    OrderList readList("test_import_constructor.txt");
    ASSERT(readList.size() == 2);
    auto it = readList.getOrders().begin();
    ASSERT(it++->getDescription() == "For Mike, delivered to 1 Elm Ave.");
    ASSERT(it++->getDescription() == "For Alice, delivered to 3 Arch Ave.");

    // remove the file
    std::remove("test_import_constructor.txt");
}

void TEST_import_nonexistent_file() {
    OrderList list{};
    ASSERT_THROWS(list.importOrders("nonexistent_file.txt"), std::invalid_argument);
}

void TEST_sanitize_export() {
    {
        OrderList writeList{};

        Order mikeOrder("One peppero\\ni pizza for Mike,\ndelivered to \\1 Elm Ave.\"\\");
        Order aliceOrder("Two pepperoni \n\npizzas for \"Alice\", delivered to 3 Arch Ave.");

        MenuItem pepperoni("Classic Pepperoni Pizza", 10.0);
        mikeOrder.addItem(pepperoni);
        aliceOrder.addItem(pepperoni);
        aliceOrder.addItem(pepperoni);

        writeList.pushOrder(mikeOrder);
        writeList.pushOrder(aliceOrder);
        writeList.exportOrders("test_sanitize_export.txt");
    } // writeList goes out of scope and is destroyed
    OrderList readList("test_sanitize_export.txt");
    ASSERT(readList.size() == 2);
    auto it = readList.getOrders().begin();
    ASSERT(it++->getDescription() == "One peppero\\ni pizza for Mike,\ndelivered to \\1 Elm Ave.\"\\");
    ASSERT(it++->getDescription() == "Two pepperoni \n\npizzas for \"Alice\", delivered to 3 Arch Ave.");

    // remove the file
    std::remove("test_sanitize_export.txt");
}

int main() {
    TEST_export_list();
    TEST_import_list();
    TEST_import_constructor();
    TEST_import_nonexistent_file();
    TEST_sanitize_export();

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
