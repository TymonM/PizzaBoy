#ifndef DTS_91896_MENU_PARSER_H
#define DTS_91896_MENU_PARSER_H

#include "menu_item.h"

#include <nlohmann/json.hpp>

/**
 * @brief The MenuParser class is responsible for converting MenuItem objects to and from a JSON format.
 *
 * This class provides functionality to export MenuItem objects to a JSON representation and back,
 * allowing for easy serialization and deserialization of menu items.
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
     * @brief Imports a MenuItem object from a JSON representation.
     *
     * This method takes a JSON object representing a MenuItem and constructs a MenuItem object
     * from the data. The JSON object should contain the name and price of the menu item.
     *
     * @param j The JSON object representing the MenuItem.
     * @return MenuItem The MenuItem object constructed from the JSON data.
     */
    static MenuItem importMenuItem(const nlohmann::json &j);
};


#endif //DTS_91896_MENU_PARSER_H