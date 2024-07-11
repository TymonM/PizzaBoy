#ifndef DTS_91896_MENU_PARSER_H
#define DTS_91896_MENU_PARSER_H

#include "menu_item.h"

#include <nlohmann/json.hpp>

/**
 * @brief The MenuParser class is responsible for converting MenuItem objects to and from a JSON format.
 *
 * Currently, this class provides functionality to export MenuItem objects to a JSON representation,
 * allowing for easy serialization of menu items. Future implementations will include importing capabilities
 * to construct MenuItem objects from JSON data.
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
};


#endif //DTS_91896_MENU_PARSER_H