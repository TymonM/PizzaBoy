#include "kitchen_ui.h"

#include "utils/utils.h"

const ftxui::Color COLOR = ftxui::Color::RGB(0xCC, 0xCC, 0xCC);
const ftxui::Color SELECTED_COLOR = ftxui::Color::RGB(0x66, 0x00, 0x00);

ftxui::Component KitchenUi::renderOrderItem(const OrderItem &orderItem) {
    return ftxui::Renderer([&] {
        return ftxui::hbox({
           ftxui::text(std::to_string(orderItem.getQuantity()) + "x "),
           ftxui::text(orderItem.getItem().getName()) | ftxui::flex,
           ftxui::text(utils::formatPrice(orderItem.calculatePrice())),
       });
    });
}

ftxui::Component KitchenUi::renderOrder(const Order &order, bool orderSelected) {
    auto deleteButton = ftxui::Button("Delete", [order, this] {
        orderList->erase(orderList->find(order.getDescription()));
        orderList->exportOrders(filepath);
        *selected = std::max(0, *selected - 1);
    }, ftxui::ButtonOption::Ascii());
    if (orderSelected) {
        deleteButton |= ftxui::bgcolor(SELECTED_COLOR);
    }

    return ftxui::Renderer(deleteButton, [=] {
        ftxui::Elements orderItems;
        for (const auto& item : order.getItems()) {
            orderItems.push_back(renderOrderItem(item)->Render());
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

ftxui::Component KitchenUi::renderOrderList() {
    selected = std::make_shared<int>(0);
    auto container = ftxui::Container::Horizontal({}, &*selected);

    return ftxui::Renderer(container, [container, this] {
        container->DetachAllChildren();
        int current = 0;
        for (const auto& order : orderList->getOrders()) {
            container->Add(renderOrder(order, current++ == *selected));
        }

        ftxui::Elements orders;
        for (size_t i = 0; i < container->ChildCount(); ++i) {
            orders.push_back(container->ChildAt(i)->Render());
        }
        return ftxui::hflow(orders);
    }) | ftxui::border | ftxui::color(COLOR);
}

KitchenUi::KitchenUi(const std::string& filepath) : filepath(filepath) {
    orderList = std::make_shared<OrderList>(filepath);
}

void KitchenUi::setFilepath(const std::string &filepath) {
    this->filepath = filepath;
    orderList->importOrders(filepath);
}

ftxui::Component KitchenUi::getRenderer() {
    auto listRenderer = renderOrderList();
    auto windowRenderer = ftxui::Renderer(listRenderer, [listRenderer, this] {
        orderList->importOrders(filepath);
        return listRenderer->Render();
    });

    return windowRenderer;
}