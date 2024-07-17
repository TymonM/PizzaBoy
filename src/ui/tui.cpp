#include "tui.h"

#include "order_renderer.h"

#include <ftxui/component/screen_interactive.hpp>

Order sampleMikeOrder();
Order sampleAliceOrder();

//Tui::Tui() = default;
Tui::Tui() : order(sampleMikeOrder()) {}

void Tui::setOrder(const Order& order) {
    this->order = order;
}

void Tui::start() {
    auto screen = ftxui::ScreenInteractive::Fullscreen();

    auto window_renderer = OrderRenderer::getRenderer(order);

    Order mikeOrder = sampleMikeOrder();
    Order aliceOrder = sampleAliceOrder();

    // Every 5 seconds, swap which order is displayed
    std::atomic<bool> running = true;
    std::thread swapper([&] {
        while (running) {
            std::this_thread::sleep_for(std::chrono::seconds(5));
            setOrder(aliceOrder);
            screen.PostEvent(ftxui::Event::Custom);
            std::this_thread::sleep_for(std::chrono::seconds(5));
            setOrder(mikeOrder);
            screen.PostEvent(ftxui::Event::Custom);
        }
    });

    screen.Loop(window_renderer);
    running = false;
    swapper.join();
}

Order sampleMikeOrder() {
    Order order("For Mike, delivered to 1 Elm Ave.");
    MenuItem pepperoni("Classic Pepperoni Pizza", 10.0);
    order.addItem(OrderItem(pepperoni, 1));

    return order;
}

Order sampleAliceOrder() {
    Order order("For Alice, delivered to 3 Arch Ave.");
    MenuItem pepperoni("Classic Pepperoni Pizza", 10.0);
    order.addItem(OrderItem(pepperoni, 2));

    return order;
}