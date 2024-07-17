#include "order_renderer.h"

#include "order_item_renderer.h"

ftxui::Component OrderRenderer::getRenderer(const Order& order) {
    return ftxui::Renderer([&] {
        std::vector<ftxui::Element> orderItems;
        for (const auto& item : order.getItems()) {
            orderItems.push_back(OrderItemRenderer::getRenderer(item)->Render());
        }

        return ftxui::vbox({
            ftxui::text("Order: " + order.getDescription()),
            ftxui::separator(),
            ftxui::vbox(orderItems) | ftxui::flex,
            ftxui::separator(),
            ftxui::text("Total: $" + std::to_string(order.calculateTotalPrice())),
        });
    }) | ftxui::border;
}
