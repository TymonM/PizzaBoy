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
    ftxui::ScreenInteractive* screen{}; ///< The current screen object for the TUI.
public:
    /**
     * @brief Construct a new Tui object.
     */
    Tui();

    /**
     * @brief Update the screen, if there is one.
     * For multi-threading purposes, this function is used to update the screen from a different thread.
     */
    void postScreenUpdate();

    /**
     * @brief Start the text-based user interface.
     *
     * Initiates the TUI, which runs an infinite loop until the program is explicitly closed by the user.
     * This function initializes the screen and the kitchen UI, rendering the kitchen UI on the screen.
     *
     * @param kitchenFilepath The filepath to the kitchen's list of orders.
     */
    void start(const std::string& kitchenFilepath);
};


#endif //DTS_91896_TUI_H
