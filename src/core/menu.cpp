#include "menu.h"

#include "menu_parser.h"

#include <fstream>

Menu::Menu() = default;

Menu::Menu(const std::string &filename) {
    importMenu(filename);
}

const std::vector<MenuItem> &Menu::getItems() const {
    return items;
}

size_t Menu::size() const {
    return items.size();
}

void Menu::addItem(const MenuItem &item) {
    if (std::find_if(items.begin(), items.end(), [&item](const MenuItem &i) {
        return i.getName() == item.getName();
    }) != items.end()) {
        throw std::invalid_argument("Item with the same name already exists");
    }
    if (item.getName().empty()) {
        throw std::invalid_argument("Item name cannot be empty");
    }
    if (item.getPrice() < 0) {
        throw std::invalid_argument("Item price cannot be negative");
    }

    items.push_back(item);
}

void Menu::removeItem(std::vector<MenuItem>::iterator it) {
    items.erase(it);
}

void Menu::exportMenu(const std::string &filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::invalid_argument("Could not open file for writing");
    }
    file << MenuParser::exportMenu(*this).dump(EXPORT_INDENT);
}

void Menu::importMenu(const std::string &filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::invalid_argument("Could not open file for reading");
    }
    nlohmann::json j;
    file >> j;
    *this = MenuParser::importMenu(j);
}
