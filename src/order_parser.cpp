#include "order_parser.h"

#include "menu_parser.h"

nlohmann::json OrderParser::exportOrderItem(const OrderItem &item) {
    nlohmann::json j;
    j["item"] = MenuParser::exportMenuItem(item.getItem());
    j["quantity"] = item.getQuantity();
    return j;
}

nlohmann::json OrderParser::exportOrder(const Order &order) {
    nlohmann::json j;
    j["description"] = order.getDescription();
    j["items"] = nlohmann::json::array();
    for (const auto &item : order.getItems()) {
        j["items"].push_back(exportOrderItem(item));
    }
    return j;
}

nlohmann::json OrderParser::exportOrderList(const OrderList &orderList) {
    nlohmann::json j;
    j["orders"] = nlohmann::json::array();
    for (const auto &order : orderList.getOrders()) {
        j["orders"].push_back(exportOrder(order));
    }
    return j;
}
