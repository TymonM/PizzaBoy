#ifndef DTS_91896_ORDER_LIST_H
#define DTS_91896_ORDER_LIST_H

#include "order.h"

#include <list>

/**
 * @brief The OrderList class manages a collection of Order objects.
 *
 * This class uses a std::list to store orders, allowing for efficient insertion
 * and deletion of orders. It provides methods to add, remove, find orders within the list,
 * and manage orders through file import/export functionalities.
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
     * @brief Construct a new Order List object from a file.
     * This constructor initializes the list by importing orders from the specified file,
     * effectively loading a list of orders at creation.
     *
     * @param filename The name of the file to read orders from.
     */
    explicit OrderList(const std::string& filename);

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
     * This method removes an order from the list based on the provided iterator.
     * If the iterator points to the end of the list, a std::invalid_argument exception is thrown.
     *
     * @param it An iterator pointing to the order to erase.
     * @throws std::invalid_argument If the provided iterator is end().
     */
    void erase(std::list<Order>::iterator it);

    /**
     * @brief Find the first order that matches a given keyphrase.
     * This method searches the descriptions of the orders for the given keyphrase
     * and returns an iterator to the first matching order. If no order matches, end() is returned.
     *
     * @param keyphrase The keyphrase to search for.
     * @return std::list<Order>::iterator An iterator to the found order, or end() if not found.
     */
    std::list<Order>::iterator find(const std::string& keyphrase);

    /**
     * @brief Export the list of orders to a file.
     * This method writes the descriptions of all orders in the list to a file, with each order
     * description being sanitized and written on a separate line to ensure proper formatting.
     *
     * @param filename The name of the file to write orders to.
     */
    void exportOrders(const std::string& filename) const;

    /**
     * @brief Import a list of orders from a file.
     * This method reads descriptions of orders from a file, desanitizing each line as necessary,
     * and adds them to the list as individual orders.
     *
     * @param filename The name of the file to read orders from.
     * @throws std::invalid_argument If the file cannot be opened.
     */
    void importOrders(const std::string& filename);
};

#endif //DTS_91896_ORDER_LIST_H