#ifndef DTS_91896_ORDER_H
#define DTS_91896_ORDER_H

#include "menu_item.h"

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
    std::string description; ///< The general description of the order.
    std::vector<MenuItem> items; ///< The specific items included in the order.

public:
    /**
     * @brief Construct a new Order object with a given description.
     *
     * @param description The general description of the order.
     */
    Order(const std::string &description);

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
    const std::vector<MenuItem>& getItems() const;

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
     * @brief Add a menu item to the order.
     *
     * This method allows for the dynamic addition of items to an order, facilitating
     * the customization of orders according to customer preferences.
     *
     * @param item The menu item to add to the order.
     */
    void addItem(const MenuItem& item);
};

#endif //DTS_91896_ORDER_H