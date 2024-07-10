#ifndef DTS_91896_MENU_PARSER_H
#define DTS_91896_MENU_PARSER_H

#include <nlohmann/json.hpp>
#include "menu_item.h"

class MenuParser {
public:
    static nlohmann::json exportMenuItem(const MenuItem &item);
};


#endif //DTS_91896_MENU_PARSER_H
