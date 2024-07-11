#ifndef DTS_91896_MENU_PARSER_H
#define DTS_91896_MENU_PARSER_H

#include "menu.h"

#include <nlohmann/json.hpp>

/**
 * @brief The MenuParser class is responsible for converting Menu and MenuItem objects to and from
 * a JSON format.
 *
 * This class provides functionality to export Menu and MenuItem objects to a JSON representation
 * and back, allowing for easy serialization and deserialization of menus.
 */
class MenuParser {
public:
    /**
     * @brief Exports a MenuItem object to a JSON representation.
     *
     * This method takes a MenuItem object and converts it into a JSON object. The JSON object
     * contains all relevant information of the MenuItem, such as its name and price, making it
     * suitable for storage or transmission.
     *
     * @param item The MenuItem object to be exported.
     * @return nlohmann::json A JSON representation of the MenuItem object.
     */
    static nlohmann::json exportMenuItem(const MenuItem &item);

    /**
     * @brief Exports a Menu object to a JSON representation.
     *
     * This method takes a Menu object and converts it into a JSON array. Each element of the array
     * is a JSON object representing an individual menu item within the list. This facilitates the
     * serialization of multiple menu items at once, making the data suitable for storage or transmission.
     *
     * @param menu The Menu object to be exported.
     * @return nlohmann::json A JSON representation of the Menu object.
     */
    static nlohmann::json exportMenu(const Menu &menu);

    /**
     * @brief Imports a MenuItem object from a JSON representation.
     *
     * This method takes a JSON object representing a MenuItem and constructs a MenuItem object
     * from the data. The JSON object should contain the name and price of the menu item.
     *
     * @param j The JSON object representing the MenuItem.
     * @return MenuItem The MenuItem object constructed from the JSON data.
     */
    static MenuItem importMenuItem(const nlohmann::json &j);

    /**
     * @brief Imports a Menu object from a JSON representation.
     *
     * This method takes a JSON array representing a list of menu items and constructs a Menu object
     * from the data. Each element of the array should be a JSON object representing a menu item.
     *
     * @param j The JSON array representing the list of menu items.
     * @return Menu The Menu object constructed from the JSON data.
     */
    static Menu importMenu(const nlohmann::json &j);
};


#endif //DTS_91896_MENU_PARSER_H