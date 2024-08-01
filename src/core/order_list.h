#ifndef DTS_91896_ORDER_LIST_H
#define DTS_91896_ORDER_LIST_H

#include "order.h"

#include <list>
#include <mutex>

/**
 * @brief Manages a collection of Order objects in a thread-safe manner.
 *
 * Utilizes a std::list to store orders, facilitating efficient insertion
 * and deletion. Offers methods for adding, removing, and finding orders,
 * alongside managing orders through file import/export functionalities.
 */
class OrderList {
private:
    static const size_t EXPORT_INDENT = 2; ///< Number of spaces for JSON export indentation.

    std::list<Order> orders; ///< List of orders.
    std::mutex mutex; ///< Mutex for thread-safe access to the orders list.

public:
    /**
     * @brief Constructs a new Order List object.
     */
    OrderList();

    /**
     * @brief Constructs a new Order List object from a file.
     * Initializes the list by importing orders from the specified file,
     * effectively loading a list of orders upon creation.
     *
     * @param filename Name of the file from which to read orders.
     */
    explicit OrderList(const std::string& filename);

    /**
     * @brief Copy constructor.
     * Copies the orders of the other OrderList object, but keeps the local mutex.
     *
     * @param other The OrderList object to copy.
     */
    OrderList(const OrderList& other);

    /**
     * @brief Clears all orders from the list.
     */
    void clear();

    /**
     * @brief Adds a new order to the list, assigning it a unique ID.
     * The generated id is the lowest id (starting from 0) which doesn't already exist in the list.
     * Throws std::invalid_argument if the order contains no items.
     *
     * @param order The order to add.
     * @throws std::invalid_argument If the order is empty.
     */
    void pushOrder(Order& order);

    /**
     * @brief Returns the number of orders in the list.
     *
     * @return size_t The number of orders.
     */
    size_t size();

    /**
     * @brief Retrieves a copy of the list of orders.
     *
     * @return std::list<Order> A copy of the orders list.
     */
    std::list<Order> getOrders();

    /**
     * @brief Erases an order from the list based on the provided iterator.
     * Throws std::invalid_argument if the iterator points to the end of the list.
     *
     * @param it Iterator pointing to the order to erase.
     * @throws std::invalid_argument If the iterator is at the end of the list.
     */
    void erase(std::list<Order>::iterator it);

    /**
     * @brief Finds the first order matching a given keyphrase in its description.
     * Returns an iterator to the first matching order, or end() if no match is found.
     *
     * @param keyphrase The keyphrase to search for.
     * @return std::list<Order>::iterator Iterator to the found order, or end() if not found.
     */
    std::list<Order>::iterator find(const std::string& keyphrase);

    /**
     * @brief Exports the list of orders to a file in JSON format.
     * Throws std::invalid_argument if the file cannot be opened for writing.
     *
     * @param filename The name of the file to write the orders to.
     * @throws std::invalid_argument If the file cannot be opened.
     */
    void exportOrders(const std::string& filename);

    /**
     * @brief Imports a list of orders from a file in JSON format.
     * Throws std::invalid_argument if the file cannot be opened for reading.
     *
     * @param filename The name of the file from which to read orders.
     * @throws std::invalid_argument If the file cannot be opened.
     */
    void importOrders(const std::string& filename);
};

#endif //DTS_91896_ORDER_LIST_H