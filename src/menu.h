#ifndef DTS_91896_MENU_H
#define DTS_91896_MENU_H

#include "menu_item.h"

#include <string>
#include <vector>

class Menu {
private:
    static const size_t EXPORT_INDENT = 2; ///< The indentation level for exporting the menu.
    std::vector<MenuItem> items; ///< The list of menu items.

public:
    Menu();
    Menu(const std::string &filename);
    const std::vector<MenuItem> &getItems() const;
    size_t size() const;
    void addItem(const MenuItem &item);
    void removeItem(std::vector<MenuItem>::iterator it);
    void exportMenu(const std::string &filename) const;
    void importMenu(const std::string &filename);
};


#endif //DTS_91896_MENU_H
