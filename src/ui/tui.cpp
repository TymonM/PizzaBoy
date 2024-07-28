#include "tui.h"

#include "kitchen_ui.h"

#include <ftxui/component/screen_interactive.hpp>

Tui::Tui() = default;

void Tui::setOrderList(std::shared_ptr<OrderList> orderList) {
    this->orderList = orderList;
    postScreenUpdate();
}

void Tui::postScreenUpdate() {
    if (this->screen == nullptr) {
        return;
    }
    this->screen->PostEvent(ftxui::Event::Custom);
}

void Tui::start() {
    auto _screen = ftxui::ScreenInteractive::Fullscreen();
    this->screen = &_screen;

    auto window_renderer = KitchenUi::renderOrderList(*orderList);
    _screen.Loop(window_renderer);
    this->screen = nullptr;
}