#include "macros.cpp"

#include "core/menu_parser.h"

#include <fstream>

Menu buildSampleMenu();

void TEST_export_menu_item() {
    MenuItem pepperoni("Classic Pepperoni Pizza", 10.0);
    auto exported = MenuParser::exportMenuItem(pepperoni);
    ASSERT(exported["name"] == "Classic Pepperoni Pizza");
    ASSERT(exported["price"] == 10.0);
}

void TEST_export_whole_menu() {
    Menu menu = buildSampleMenu();

    auto exported = MenuParser::exportMenu(menu);
    ASSERT(exported["items"].size() == 4);
    ASSERT(exported["items"][0]["name"] == "Classic Pepperoni Pizza");
    ASSERT(exported["items"][0]["price"] == 10.0);
    ASSERT(exported["items"][1]["name"] == "Classic Margherita Pizza");
    ASSERT(exported["items"][1]["price"] == 9.0);
    ASSERT(exported["items"][2]["name"] == "Hawaiian Pizza");
    ASSERT(exported["items"][2]["price"] == 12.0);
    ASSERT(exported["items"][3]["name"] == "Veggie Pizza");
    ASSERT(exported["items"][3]["price"] == 11.0);
}

void TEST_export_menu_to_file() {
    Menu menu = buildSampleMenu();
    menu.exportMenu("test_export_menu.json");

    std::ifstream file("test_export_menu.json");
    ASSERT(file.is_open());
    std::stringstream buffer;
    buffer << file.rdbuf();
    ASSERT(buffer.str() == R"({
  "items": [
    {
      "name": "Classic Pepperoni Pizza",
      "price": 10.0
    },
    {
      "name": "Classic Margherita Pizza",
      "price": 9.0
    },
    {
      "name": "Hawaiian Pizza",
      "price": 12.0
    },
    {
      "name": "Veggie Pizza",
      "price": 11.0
    }
  ]
})");

    // remove the file
    std::remove("test_export_menu.json");
}

void TEST_import_menu() {
    {
        Menu writeMenu = buildSampleMenu();
        writeMenu.exportMenu("test_import_menu.json");
    } // writeMenu goes out of scope and is destroyed
    Menu readMenu{};
    readMenu.importMenu("test_import_menu.json");
    ASSERT(readMenu.size() == 4);
    auto it = readMenu.getItems().begin();
    ASSERT(it->getName() == "Classic Pepperoni Pizza");
    ASSERT(it++->getPrice() == 10.0);
    ASSERT(it->getName() == "Classic Margherita Pizza");
    ASSERT(it++->getPrice() == 9.0);
    ASSERT(it->getName() == "Hawaiian Pizza");
    ASSERT(it++->getPrice() == 12.0);
    ASSERT(it->getName() == "Veggie Pizza");
    ASSERT(it++->getPrice() == 11.0);

    // remove the file
    std::remove("test_import_menu.json");
}

void TEST_import_menu_constructor() {
    {
        Menu writeMenu = buildSampleMenu();
        writeMenu.exportMenu("test_import_menu_constructor.json");
    } // writeMenu goes out of scope and is destroyed
    Menu readMenu("test_import_menu_constructor.json");
    ASSERT(readMenu.size() == 4);
    auto it = readMenu.getItems().begin();
    ASSERT(it->getName() == "Classic Pepperoni Pizza");
    ASSERT(it++->getPrice() == 10.0);
    ASSERT(it->getName() == "Classic Margherita Pizza");
    ASSERT(it++->getPrice() == 9.0);
    ASSERT(it->getName() == "Hawaiian Pizza");
    ASSERT(it++->getPrice() == 12.0);
    ASSERT(it->getName() == "Veggie Pizza");
    ASSERT(it++->getPrice() == 11.0);

    // remove the file
    std::remove("test_import_menu_constructor.json");
}

void TEST_export_menu_with_special_chars_to_file() {
    {
        Menu writeMenu{};
        MenuItem pepperoni("Classic Peppero\\ni Pizza", 10.0);
        MenuItem margherita("Classic \"Margherita\" Pizza", 9.0);
        MenuItem hawaiian("Hawaiian\n\n Pizza", 12.0);
        MenuItem veggie("Veggie Pizza\n\n\\n", 11.5134516789823);

        writeMenu.addItem(pepperoni);
        writeMenu.addItem(margherita);
        writeMenu.addItem(hawaiian);
        writeMenu.addItem(veggie);

        writeMenu.exportMenu("test_export_menu_special_chars.json");
    } // writeMenu goes out of scope and is destroyed
    Menu readMenu("test_export_menu_special_chars.json");
    ASSERT(readMenu.size() == 4);
    auto it = readMenu.getItems().begin();
    ASSERT(it->getName() == "Classic Peppero\\ni Pizza");
    ASSERT(it++->getPrice() == 10.0);
    ASSERT(it->getName() == "Classic \"Margherita\" Pizza");
    ASSERT(it++->getPrice() == 9.0);
    ASSERT(it->getName() == "Hawaiian\n\n Pizza");
    ASSERT(it++->getPrice() == 12.0);
    ASSERT(it->getName() == "Veggie Pizza\n\n\\n");
    ASSERT(it++->getPrice() == 11.5134516789823);

    // remove the file
    std::remove("test_export_menu_special_chars.json");
}

int main() {
    TEST_export_menu_item();
    TEST_export_whole_menu();
    TEST_export_menu_to_file();
    TEST_import_menu();
    TEST_import_menu_constructor();
    TEST_export_menu_with_special_chars_to_file();

    return 0;
}

Menu buildSampleMenu() {
    Menu menu{};
    MenuItem pepperoni("Classic Pepperoni Pizza", 10.0);
    MenuItem margherita("Classic Margherita Pizza", 9.0);
    MenuItem hawaiian("Hawaiian Pizza", 12.0);
    MenuItem veggie("Veggie Pizza", 11.0);

    menu.addItem(pepperoni);
    menu.addItem(margherita);
    menu.addItem(hawaiian);
    menu.addItem(veggie);

    return menu;
}
