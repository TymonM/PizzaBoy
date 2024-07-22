#ifndef DTS_91896_TUI_H
#define DTS_91896_TUI_H

#include "core/order_list.h"

#include <ftxui/component/screen_interactive.hpp>

/**
 * @brief The Tui class is responsible for handling the text-based user interface.
 *
 * This class provides functionality to interact with the user through the console,
 * displaying menus and receiving input to manage the pizza ordering system.
 */
class Tui {
private:
    ftxui::ScreenInteractive* screen{};
    std::shared_ptr<OrderList> orderList;
public:
    /**
     * @brief Construct a new Tui object.
     */
    Tui();

    /**
     * @brief Set the OrderList object to be displayed by the Tui.
     * Since the OrderList object is passed as a std::shared_ptr, the Tui will automatically update
     * when the OrderList changes, such as when orders are added or removed (at the next screen update).
     *
     * @param orderList A shared_ptr to the OrderList object to be displayed by the Tui.
     */
    void setOrderList(std::shared_ptr<OrderList> orderList);

    /**
     * @brief Update the screen, if there is one.
     * For multi-threading purposes, this function is used to update the screen from a different thread.
     */
    void postScreenUpdate();

    /**
     * @brief Start the text-based user interface.
     *
     * Initiates the TUI, which runs an infinite loop until the program is explicitly closed by the user.
     */
    void start();
};


#endif //DTS_91896_TUI_H
