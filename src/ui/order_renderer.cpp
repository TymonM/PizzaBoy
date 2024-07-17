#include "order_renderer.h"

#include "order_item_renderer.h"
#include "utils/utils.h"

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
            ftxui::hbox({
                ftxui::text("Total: ") | ftxui::flex,
                ftxui::text(utils::formatPrice(order.calculateTotalPrice()))
            })
        });
    }) | ftxui::border;
}
