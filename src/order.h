#ifndef DTS_91896_ORDER_H
#define DTS_91896_ORDER_H

#include <string>

/**
 * @brief The Order class represents a single order in the pizza ordering system.
 *
 * This class stores the description of an order, which includes details such as
 * the type of pizza, quantity, and any special instructions.
 */
class Order {
private:
    std::string description; ///< The description of the order.

public:
    /**
     * @brief Construct a new Order object with a given description.
     *
     * @param description The description of the order.
     */
    Order(const std::string &description);

    /**
     * @brief Get the description of the order.
     *
     * @return const std::string& The description of the order.
     */
    const std::string& getDescription() const;
};

#endif //DTS_91896_ORDER_H