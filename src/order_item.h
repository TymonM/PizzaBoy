#ifndef DTS_91896_ORDER_ITEM_H
#define DTS_91896_ORDER_ITEM_H

#include "menu_item.h"

/**
 * @brief The OrderItem class represents a single item in an order.
 *
 * This class encapsulates the details of an item in an order, including the menu item itself
 * and the quantity of that item. It allows for the calculation of the total price of the item
 * based on the quantity and the price of the menu item.
 */
class OrderItem {
private:
    MenuItem item; ///< The menu item.
    size_t quantity; ///< The quantity of the menu item.

public:
    /**
     * @brief Construct a new Order Item object with a given menu item and quantity.
     *
     * @param item The menu item.
     * @param quantity The quantity of the menu item.
     */
    OrderItem(const MenuItem& item, size_t quantity);

    /**
     * @brief Get the menu item.
     *
     * @return const MenuItem& The menu item.
     */
    const MenuItem& getItem() const;

    /**
     * @brief Get the quantity of the menu item.
     *
     * @return size_t The quantity of the menu item.
     */
    size_t getQuantity() const;

    /**
     * @brief Calculate the total price of the order item.
     *
     * This method calculates the total price of the order item by multiplying the price
     * of the menu item by the quantity.
     *
     * @return double The total price of the order item.
     */
    double calculatePrice() const;
};


#endif //DTS_91896_ORDER_ITEM_H
