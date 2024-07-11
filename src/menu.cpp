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
