#include "order_list_renderer.h"

#include "order_renderer.h"

#include <ftxui/dom/flexbox_config.hpp>

ftxui::Component OrderListRenderer::getRenderer(const OrderList& orderList) {
    return ftxui::Renderer([&] {
        std::vector<ftxui::Element> orderRenderers;
        for (const auto& order : orderList.getOrders()) {
            orderRenderers.push_back(OrderRenderer::getRenderer(order)->Render());
        }

        ftxui::FlexboxConfig cfg{};
        cfg.wrap = ftxui::FlexboxConfig::Wrap::Wrap;

        return ftxui::flexbox(orderRenderers, cfg);
    }) | ftxui::border;
}