#ifndef DTS_91896_ORDER_PARSER_H
#define DTS_91896_ORDER_PARSER_H

#include "order_list.h"
#include <nlohmann/json.hpp>

/**
 * @brief The OrderParser class is responsible for converting Order and OrderList objects to and from a JSON format.
 *
 * This class provides functionality to export Order, OrderItem, and OrderList objects to a JSON representation
 * and back, facilitating the serialization and deserialization of order data for storage or transmission.
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

    /**
     * @brief Imports an OrderItem object from a JSON representation.
     *
     * This method takes a JSON object representing an OrderItem and constructs an OrderItem object
     * from the data. The JSON object should contain the menu item details and quantity of the order item.
     *
     * @param j The JSON object representing the OrderItem.
     * @return OrderItem The OrderItem object constructed from the JSON data.
     */
    static OrderItem importOrderItem(const nlohmann::json &j);

    /**
     * @brief Imports an Order object from a JSON representation.
     *
     * This method takes a JSON object representing an Order and constructs an Order object from the data.
     * The JSON object should include the order's description and a list of its items, each represented as a JSON object.
     *
     * @param j The JSON object representing the Order.
     * @return Order The Order object constructed from the JSON data.
     */
    static Order importOrder(const nlohmann::json &j);

    /**
     * @brief Imports an OrderList object from a JSON representation.
     *
     * This method takes a JSON object representing an OrderList and constructs an OrderList object from the data.
     * The JSON object should contain an array of JSON objects, each representing an individual order within the list.
     *
     * @param j The JSON object representing the OrderList.
     * @return OrderList The OrderList object constructed from the JSON data.
     */
    static OrderList importOrderList(const nlohmann::json &j);
};

#endif //DTS_91896_ORDER_PARSER_H