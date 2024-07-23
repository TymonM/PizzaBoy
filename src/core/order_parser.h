#ifndef DTS_91896_ORDER_PARSER_H
#define DTS_91896_ORDER_PARSER_H

#include "order_list.h"
#include "nlohmann/json.hpp"

/**
 * @brief The OrderParser class provides serialization and deserialization functionalities for Order, OrderItem, and OrderList objects to and from JSON format.
 *
 * It facilitates the conversion of Order-related objects into a JSON representation for storage or transmission purposes and vice versa. This class leverages the nlohmann::json library for JSON processing, ensuring high compatibility and ease of use in JSON manipulation.
 */
class OrderParser {
public:
    /**
     * @brief Serializes an OrderItem object into a JSON representation.
     *
     * Converts an OrderItem object into a JSON object, encapsulating the item's details and quantity. This method is useful for storing or transmitting individual order items in a structured format.
     *
     * @param item The OrderItem object to serialize.
     * @return nlohmann::json A JSON object representing the serialized OrderItem.
     */
    static nlohmann::json exportOrderItem(const OrderItem &item);

    /**
     * @brief Serializes an Order object into a JSON representation.
     *
     * Converts an Order object into a JSON object, including the order's description and its items, each as a serialized JSON object. This method is ideal for representing complete orders in a structured, easily transmissible format.
     *
     * @param order The Order object to serialize.
     * @return nlohmann::json A JSON object representing the serialized Order.
     */
    static nlohmann::json exportOrder(const Order &order);

    /**
     * @brief Serializes an OrderList object into a JSON representation.
     *
     * Converts an entire OrderList into a JSON array, with each order within the list serialized into a JSON object. This method supports the bulk serialization of orders, facilitating their storage or transmission as a cohesive collection.
     *
     * @param orderList The OrderList object to serialize.
     * @return nlohmann::json A JSON array representing the serialized OrderList.
     */
    static nlohmann::json exportOrderList(OrderList &orderList);

    /**
     * @brief Deserializes an OrderItem object from a JSON representation.
     *
     * Constructs an OrderItem object from its JSON representation, including details such as the menu item and quantity. This method allows for the reconstruction of order items from structured JSON data.
     *
     * @param j The JSON object representing an OrderItem.
     * @return OrderItem The deserialized OrderItem object.
     */
    static OrderItem importOrderItem(const nlohmann::json &j);

    /**
     * @brief Deserializes an Order object from a JSON representation.
     *
     * Constructs an Order object from its JSON representation, including the order's description and a list of its items, each deserialized from JSON objects. This method enables the reconstruction of complete orders from structured JSON data.
     *
     * @param j The JSON object representing an Order.
     * @return Order The deserialized Order object.
     */
    static Order importOrder(const nlohmann::json &j);

    /**
     * @brief Deserializes an OrderList object from a JSON representation.
     *
     * Constructs an OrderList object from its JSON representation, which should be a JSON array of orders, each represented as a JSON object. This method allows for the bulk reconstruction of orders from structured JSON data, populating an OrderList with the deserialized orders.
     *
     * @param list The OrderList object to populate with deserialized orders.
     * @param j The JSON object representing an OrderList.
     */
    static void importOrderList(OrderList& list, const nlohmann::json &j);
};

#endif //DTS_91896_ORDER_PARSER_H