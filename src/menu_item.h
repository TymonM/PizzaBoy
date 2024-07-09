#ifndef DTS_91896_MENU_ITEM_H
#define DTS_91896_MENU_ITEM_H

#include <string>

class MenuItem {
private:
    std::string name; ///< The name of the menu item.
    double price; ///< The price of the menu item.

public:
    /**
     * @brief Construct a new Menu Item object with a given name and price.
     *
     * @param name The name of the menu item.
     * @param price The price of the menu item.
     */
    MenuItem(const std::string &name, double price);

    /**
     * @brief Get the name of the menu item.
     *
     * @return const std::string& The name of the menu item.
     */
    const std::string &getName() const;

    /**
     * @brief Get the price of the menu item.
     *
     * @return double The price of the menu item.
     */
    double getPrice() const;
};


#endif //DTS_91896_MENU_ITEM_H
