#include "menu_parser.h"

nlohmann::json MenuParser::exportMenuItem(const MenuItem &item) {
    nlohmann::json j;
    j["name"] = item.getName();
    j["price"] = item.getPrice();
    return j;
}

MenuItem MenuParser::importMenuItem(const nlohmann::json &j) {
    std::string name = j["name"];
    double price = j["price"];
    return MenuItem(name, price);
}
