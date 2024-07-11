#ifndef DTS_91896_ORDER_PARSER_H
#define DTS_91896_ORDER_PARSER_H

#include "order_list.h"

#include <nlohmann/json.hpp>

class OrderParser {
public:
    static nlohmann::json exportOrderItem(const OrderItem &item);
    static nlohmann::json exportOrder(const Order &order);
    static nlohmann::json exportOrderList(const OrderList &orderList);
};


#endif //DTS_91896_ORDER_PARSER_H
