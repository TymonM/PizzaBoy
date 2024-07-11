#ifndef DTS_91896_ORDER_PARSER_H
#define DTS_91896_ORDER_PARSER_H

#include "order_item.h"

#include <nlohmann/json.hpp>

class OrderParser {
public:
    static nlohmann::json exportOrderItem(const OrderItem &item);
};


#endif //DTS_91896_ORDER_PARSER_H
