#include "order_parser.h"

#include "menu_parser.h"

nlohmann::json OrderParser::exportOrderItem(const OrderItem &item) {
    nlohmann::json j;
    j["item"] = MenuParser::exportMenuItem(item.getItem());
    j["quantity"] = item.getQuantity();
    return j;
}
