#ifndef DTS_91896_ORDER_PARSER_H
#define DTS_91896_ORDER_PARSER_H

#include "order_list.h"
#include <nlohmann/json.hpp>

/**
 * @brief The OrderParser class is responsible for converting Order and OrderList objects to and from a JSON format.
 *
 * This class provides functionality to export Order, OrderItem, and OrderList objects to a JSON representation,
 * facilitating the serialization of order data for storage or transmission. Future implementations will include
 * importing capabilities to reconstruct these objects from JSON data.
 */
class OrderParser {
public:
    /**
     * @brief Exports an OrderItem object to a JSON representation.
     *
     * This method takes an OrderItem object and converts it into a JSON object. The JSON object
     * contains all relevant information of the OrderItem, such as the menu item details and quantity,
     * making it suitable for storage or transmission.
     *
     * @param item The OrderItem object to be exported.
     * @return nlohmann::json A JSON representation of the OrderItem object.
     */
    static nlohmann::json exportOrderItem(const OrderItem &item);

    /**
     * @brief Exports an Order object to a JSON representation.
     *
     * This method takes an Order object and converts it into a JSON object. The JSON object
     * includes the order's description and a list of its items, each represented as a JSON object,
     * thereby encapsulating the complete order details in a format suitable for storage or transmission.
     *
     * @param order The Order object to be exported.
     * @return nlohmann::json A JSON representation of the Order object.
     */
    static nlohmann::json exportOrder(const Order &order);

    /**
     * @brief Exports an OrderList object to a JSON representation.
     *
     * This method takes an OrderList object and converts it into a JSON array. Each element of the array
     * is a JSON object representing an individual order within the list. This facilitates the serialization
     * of multiple orders at once, making the data suitable for storage or transmission.
     *
     * @param orderList The OrderList object to be exported.
     * @return nlohmann::json A JSON representation of the OrderList object.
     */
    static nlohmann::json exportOrderList(const OrderList &orderList);
};

#endif //DTS_91896_ORDER_PARSER_H