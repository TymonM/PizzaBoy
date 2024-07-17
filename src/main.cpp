#include "ui/tui.h"

#include <atomic>
#include <thread>

Order sampleMikeOrder();
Order sampleAliceOrder();

int main() {
    Tui tui{};

    Order mikeOrder = sampleMikeOrder();
    Order aliceOrder = sampleAliceOrder();

    tui.setOrder(mikeOrder);

    // Every 5 seconds, swap which order is displayed
    std::atomic<bool> running = true;
    std::thread swapper([&] {
        while (running) {
            std::this_thread::sleep_for(std::chrono::seconds(5));
            tui.setOrder(aliceOrder);
            std::this_thread::sleep_for(std::chrono::seconds(5));
            tui.setOrder(mikeOrder);
        }
    });

    tui.start();
    running = false;
    swapper.join();

    return 0;
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
    MenuItem margherita("Margherita Pizza", 8.0);

    order.addItem(OrderItem(pepperoni, 2));
    order.addItem(OrderItem(margherita, 1));

    return order;
}