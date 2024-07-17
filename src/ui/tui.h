#ifndef DTS_91896_TUI_H
#define DTS_91896_TUI_H

#include "core/order_list.h"

/**
 * @brief The Tui class is responsible for handling the text-based user interface.
 *
 * This class provides functionality to interact with the user through the console,
 * displaying menus and receiving input to manage the pizza ordering system.
 */
class Tui {
private:
    Order order;
public:
    /**
     * @brief Construct a new Tui object.
     */
    Tui();

    /**
     * @brief Set the Order object to be displayed by the Tui.
     *
     * @param order The Order object to be displayed by the Tui.
     */
    void setOrder(const Order& order);

    /**
     * @brief Start the text-based user interface.
     *
     * Initiates the TUI, which runs an infinite loop until the program is explicitly closed by the user.
     */
    void start();
};


#endif //DTS_91896_TUI_H
