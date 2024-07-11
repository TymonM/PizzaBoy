#ifndef DTS_91896_MENU_H
#define DTS_91896_MENU_H

#include "menu_item.h"

#include <vector>

class Menu {
private:
    std::vector<MenuItem> items; ///< The list of menu items.

public:
    Menu();
    const std::vector<MenuItem> &getItems() const;
    void addItem(const MenuItem &item);
    void removeItem(std::vector<MenuItem>::iterator it);
};


#endif //DTS_91896_MENU_H
