#include "tui.h"

#include "kitchen_ui.h"

#include <ftxui/component/screen_interactive.hpp>

Tui::Tui() = default;

void Tui::postScreenUpdate() {
    if (this->screen == nullptr) {
        return;
    }
    this->screen->PostEvent(ftxui::Event::Custom);
}

void Tui::start(const std::string& kitchenFilepath) {
    auto _screen = ftxui::ScreenInteractive::Fullscreen();
    this->screen = &_screen;

    auto kitchenUi = KitchenUi(kitchenFilepath);

    auto window_renderer = kitchenUi.getRenderer();
    _screen.Loop(window_renderer);
    this->screen = nullptr;
}