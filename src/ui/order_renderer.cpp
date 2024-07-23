#include "order_renderer.h"

#include "order_item_renderer.h"
#include "utils/utils.h"

#include <ftxui/component/component.hpp>

const ftxui::Color SELECTED_COLOR = ftxui::Color::RGB(0x66, 0x00, 0x00);

ftxui::Component OrderRenderer::getRenderer(const Order& order, OrderList& orderList, bool selected) {
    auto deleteButton = ftxui::Button("Delete", [order, &orderList] {
        orderList.erase(orderList.find(order.getDescription()));
    }, ftxui::ButtonOption::Ascii());
    if (selected) {
        deleteButton |= ftxui::bgcolor(SELECTED_COLOR);
    }

    return ftxui::Renderer(deleteButton, [=] {
        ftxui::Elements orderItems;
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
            }),
            ftxui::separator(),
            deleteButton->Render(),
        }) | ftxui::border;
    });
}
