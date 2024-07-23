#include "order_list_renderer.h"

#include "order_renderer.h"

const ftxui::Color COLOR = ftxui::Color::RGB(0xCC, 0xCC, 0xCC);

ftxui::Component OrderListRenderer::getRenderer(OrderList& orderList) {
    int selected = 0;
    auto container = ftxui::Container::Horizontal({}, &selected);

    return ftxui::Renderer(container, [&orderList, container, &selected] {
        container->DetachAllChildren();
        int current = 0;
        for (const auto& order : orderList.getOrders()) {
            container->Add(OrderRenderer::getRenderer(order, orderList, current++ == selected));
        }

        ftxui::Elements orders;
        for (size_t i = 0; i < container->ChildCount(); ++i) {
            orders.push_back(container->ChildAt(i)->Render());
        }
        return ftxui::hflow(orders);
    }) | ftxui::border | ftxui::color(COLOR);
}