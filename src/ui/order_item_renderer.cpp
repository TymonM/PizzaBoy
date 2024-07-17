#include "order_item_renderer.h"

ftxui::Component OrderItemRenderer::getRenderer(const OrderItem& orderItem) {
    return ftxui::Renderer([&] {
        return ftxui::hbox({
            ftxui::text(std::to_string(orderItem.getQuantity()) + "x "),
            ftxui::text(orderItem.getItem().getName()) | ftxui::flex,
            ftxui::text("$" + std::to_string(orderItem.calculatePrice())),
        });
    });
}
