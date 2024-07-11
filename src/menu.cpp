#include "menu.h"

Menu::Menu() = default;

const std::vector<MenuItem> &Menu::getItems() const {
    return items;
}

void Menu::addItem(const MenuItem &item) {
    items.push_back(item);
}

void Menu::removeItem(std::vector<MenuItem>::iterator it) {
    items.erase(it);
}
