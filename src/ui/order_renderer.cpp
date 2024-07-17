#include "order_renderer.h"

#include <iostream>

ftxui::Component OrderRenderer::getRenderer(const Order& order) {
    return ftxui::Renderer([&] {
        return ftxui::vbox({
            ftxui::text("Order: " + order.getDescription()),
            ftxui::separator(),
            // todo: render actual order items
            ftxui::text("Ordered some items...") | ftxui::flex,
            ftxui::separator(),
            ftxui::text("Total: $" + std::to_string(order.calculateTotalPrice())),
        });
    }) | ftxui::border;
}
