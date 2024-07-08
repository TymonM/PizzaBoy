#ifndef DTS_91896_ORDER_LIST_H
#define DTS_91896_ORDER_LIST_H

#include "order.h"
#include <list>

/**
 * @brief The OrderList class manages a collection of Order objects.
 *
 * This class uses a std::list to store orders, allowing for efficient insertion
 * and deletion of orders. It provides methods to add, remove, and find orders
 * within the list.
 */
class OrderList {
private:
    std::list<Order> orders; ///< The list of orders.

public:
    /**
     * @brief Construct a new Order List object.
     */
    OrderList();

    /**
     * @brief Add a new order to the list.
     *
     * @param order The order to add.
     */
    void pushOrder(const Order& order);

    /**
     * @brief Get the number of orders in the list.
     *
     * @return size_t The number of orders.
     */
    size_t size() const;

    /**
     * @brief Get a constant reference to the list of orders.
     *
     * @return const std::list<Order>& The list of orders.
     */
    const std::list<Order>& getOrders() const;

    /**
     * @brief Erase an order from the list.
     *
     * @param it An iterator pointing to the order to erase.
     * @throws std::invalid_argument If the provided iterator is end().
     */
    void erase(std::list<Order>::iterator it);

    /**
     * @brief Find the first order that matches a given keyphrase.
     *
     * This method searches the descriptions of the orders for the given keyphrase
     * and returns an iterator to the first matching order.
     *
     * @param keyphrase The keyphrase to search for.
     * @return std::list<Order>::iterator An iterator to the found order, or end() if not found.
     */
    std::list<Order>::iterator find(const std::string& keyphrase);
};

#endif //DTS_91896_ORDER_LIST_H