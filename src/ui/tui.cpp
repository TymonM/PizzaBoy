#include "tui.h"

#include "order_renderer.h"

#include <ftxui/component/screen_interactive.hpp>

//Tui::Tui() = default;
Tui::Tui() : order(Order("N/A")), screen(nullptr) {}

void Tui::setOrder(const Order& order) {
    this->order = order;
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

    auto window_renderer = OrderRenderer::getRenderer(order);
    _screen.Loop(window_renderer);
    this->screen = nullptr;
}