#ifndef DTS_91896_ORDER_PARSER_H
#define DTS_91896_ORDER_PARSER_H

#include "order.h"

#include <nlohmann/json.hpp>

class OrderParser {
public:
    static nlohmann::json exportOrderItem(const OrderItem &item);
    static nlohmann::json exportOrder(const Order &order);
};


#endif //DTS_91896_ORDER_PARSER_H
