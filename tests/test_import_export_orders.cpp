#include "macros.cpp"

#include "../src/order.h"
#include "../src/order_list.h"

#include <fstream>

void export_list() {
    OrderList list{};
    list.pushOrder(Order("One pepperoni pizza for Mike, delivered to 1 Elm Ave."));
    list.pushOrder(Order("Two pepperoni pizzas for Alice, delivered to 3 Arch Ave."));

    list.exportOrders("test_export_orders.txt");

    // make sure the file was indeed created and contains the expected data
    std::ifstream file("test_export_orders.txt");
    ASSERT(file.is_open());
    std::string line;
    std::getline(file, line);
    ASSERT(line == "One pepperoni pizza for Mike, delivered to 1 Elm Ave.");
    std::getline(file, line);
    ASSERT(line == "Two pepperoni pizzas for Alice, delivered to 3 Arch Ave.");

    // remove the file
    std::remove("test_export_orders.txt");
}

void import_list() {
    {
        OrderList writeList{};
        writeList.pushOrder(Order("One pepperoni pizza for Mike, delivered to 1 Elm Ave."));
        writeList.pushOrder(Order("Two pepperoni pizzas for Alice, delivered to 3 Arch Ave."));
        writeList.exportOrders("test_import_orders.txt");
    } // writeList goes out of scope and is destroyed
    OrderList readList{};
    readList.importOrders("test_import_orders.txt");
    ASSERT(readList.size() == 2);
    auto it = readList.getOrders().begin();
    ASSERT(it++->getDescription() == "One pepperoni pizza for Mike, delivered to 1 Elm Ave.");
    ASSERT(it++->getDescription() == "Two pepperoni pizzas for Alice, delivered to 3 Arch Ave.");

    // remove the file
    std::remove("test_import_orders.txt");
}

void import_constructor() {
    {
        OrderList writeList{};
        writeList.pushOrder(Order("One pepperoni pizza for Mike, delivered to 1 Elm Ave."));
        writeList.pushOrder(Order("Two pepperoni pizzas for Alice, delivered to 3 Arch Ave."));
        writeList.exportOrders("test_import_constructor.txt");
    } // writeList goes out of scope and is destroyed
    OrderList readList("test_import_constructor.txt");
    ASSERT(readList.size() == 2);
    auto it = readList.getOrders().begin();
    ASSERT(it++->getDescription() == "One pepperoni pizza for Mike, delivered to 1 Elm Ave.");
    ASSERT(it++->getDescription() == "Two pepperoni pizzas for Alice, delivered to 3 Arch Ave.");

    // remove the file
    std::remove("test_import_constructor.txt");
}

void import_nonexistent_file() {
    OrderList list{};
    ASSERT_THROWS(list.importOrders("nonexistent_file.txt"), std::invalid_argument);
}

int main() {
    export_list();
    import_list();
    import_constructor();
    import_nonexistent_file();

    return 0;
}
