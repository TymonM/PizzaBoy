#ifndef DTS_91896_ORDER_H
#define DTS_91896_ORDER_H

#include "order_item.h"

#include <string>
#include <vector>

/**
 * @brief The Order class represents a single order in the pizza ordering system.
 *
 * This class encapsulates the details of an order, including a description (e.g., type of pizza,
 * quantity, special instructions) and the specific items that make up the order. It allows for
 * the addition of menu items to the order, enabling dynamic composition of an order.
 */
class Order {
private:
    size_t id = 0; ///< The unique identifier of the order.
    std::string description; ///< The general description of the order.
    std::vector<OrderItem> items; ///< The specific items included in the order.

public:
    /**
     * @brief Construct a new Order object with a given description.
     *
     * @param description The general description of the order.
     */
    Order(const std::string& description);

    /**
     * @brief Get the unique identifier of the order.
     *
     * @return size_t The unique identifier of the order.
     */
    size_t getId() const;

    /**
     * @brief Set the unique identifier of the order.
     *
     * @param id The new unique identifier of the order.
     */
    void setId(size_t id);

    /**
     * @brief Get the general description of the order.
     *
     * @return const std::string& The general description of the order.
     */
    const std::string& getDescription() const;

    /**
     * @brief Get the specific items included in the order.
     *
     * @return const std::vector<MenuItem>& The items included in the order.
     */
    const std::vector<OrderItem>& getItems() const;

    /**
     * @brief Calculate the total price of the order.
     *
     * This method calculates the total price of the order by summing the prices of all the items
     * included in the order.
     *
     * @return double The total price of the order.
     */
    double calculateTotalPrice() const;

    /**
     * @brief Add a order item to the order.
     *
     * This method allows for the dynamic addition of items to an order, facilitating
     * the customization of orders according to customer preferences.
     *
     * @param item The order item to add to the order.
     */
    void addItem(const OrderItem& item);
};

#endif //DTS_91896_ORDER_H