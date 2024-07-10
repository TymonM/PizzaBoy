#include "menu_parser.h"

nlohmann::json MenuParser::exportMenuItem(const MenuItem &item) {
    nlohmann::json j;
    j["name"] = item.getName();
    j["price"] = item.getPrice();
    return j;
}
