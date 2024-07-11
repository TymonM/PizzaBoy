#ifndef DTS_91896_MENU_H
#define DTS_91896_MENU_H

#include "menu_item.h"

#include <string>
#include <vector>

/**
 * @brief The Menu class represents a collection of predefined menu items.
 *
 * This class provides functionalities to manage a collection of MenuItem objects. It allows
 * adding and removing items from the menu, as well as importing and exporting the menu
 * to and from a JSON file. The class ensures that each menu item is unique based on its
 * name and provides methods to access the menu items and the total number of items.
 */
class Menu {
private:
    static const size_t EXPORT_INDENT = 2; ///< The indentation level for exporting the menu.
    std::vector<MenuItem> items; ///< The list of menu items.

public:
    /**
     * @brief Constructs a new Menu object.
     */
    Menu();

    /**
     * @brief Constructs a new Menu object and initializes it with items from a file.
     *
     * @param filename The name of the file from which to import the menu items.
     */
    Menu(const std::string &filename);

    /**
     * @brief Gets the list of menu items.
     *
     * @return const std::vector<MenuItem>& The list of menu items.
     */
    const std::vector<MenuItem> &getItems() const;

    /**
     * @brief Gets the number of items in the menu.
     *
     * @return size_t The number of items in the menu.
     */
    size_t size() const;

    /**
     * @brief Adds a new item to the menu.
     *
     * This method adds a new MenuItem to the menu. If an item with the same name already exists,
     * an exception is thrown. It also validates that the item name is not empty and the price is not negative.
     *
     * @param item The MenuItem to add to the menu.
     * @throws std::invalid_argument if the item name is empty, the price is negative, or an item with the same
     * name already exists.
     */
    void addItem(const MenuItem &item);

    /**
     * @brief Removes an item from the menu.
     *
     * This method removes an item from the menu based on an iterator pointing to the item in the list.
     *
     * @param it An iterator pointing to the MenuItem to be removed.
     */
    void removeItem(std::vector<MenuItem>::iterator it);

    /**
     * @brief Exports the menu to a file.
     *
     * This method exports the current state of the menu to a JSON file.
     *
     * @param filename The path to the file to which the menu should be exported.
     */
    void exportMenu(const std::string &filename) const;

    /**
     * @brief Imports menu items from a file.
     *
     * This method initializes the menu with items imported from a file. If the menu is not empty,
     * the existing items in the menu are replaced with the items from the file.
     *
     * @param filename The name of the file from which to import the menu items.
     */
    void importMenu(const std::string &filename);
};

#endif //DTS_91896_MENU_H