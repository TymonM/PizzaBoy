#include "menu_parser.h"

nlohmann::json MenuParser::exportMenuItem(const MenuItem &item) {
    nlohmann::json j;
    j["name"] = item.getName();
    j["price"] = item.getPrice();
    return j;
}

nlohmann::json MenuParser::exportMenu(const Menu &menu) {
    nlohmann::json j;
    j["items"] = nlohmann::json::array();
    for (const auto &item : menu.getItems()) {
        j["items"].push_back(exportMenuItem(item));
    }
    return j;
}

MenuItem MenuParser::importMenuItem(const nlohmann::json &j) {
    std::string name = j["name"];
    double price = j["price"];
    return MenuItem(name, price);
}

Menu MenuParser::importMenu(const nlohmann::json &j) {
    Menu menu;
    for (const auto &item : j["items"]) {
        menu.addItem(importMenuItem(item));
    }
    return menu;
}
