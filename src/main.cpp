#include "ui/tui.h"

#include <atomic>
#include <thread>

std::shared_ptr<OrderList> buildSampleList();

int main() {
    Tui tui{};

    auto list = buildSampleList();

    tui.setOrderList(list);

    // Every 5 seconds, change the list
    std::atomic<bool> running = true;
    std::thread swapper([&] {
        while (running) {
            std::this_thread::sleep_for(std::chrono::seconds(5));
            Order bobOrder("For Bob, delivered to 5 Elm Ave.");
            MenuItem cheese("Cheese Pizza", 8.0);
            bobOrder.addItem(OrderItem(cheese, 1));
            list->pushOrder(bobOrder);
            tui.postScreenUpdate();

            std::this_thread::sleep_for(std::chrono::seconds(5));
            list->erase(list->find("Bob"));
            tui.postScreenUpdate();
        }
    });

    tui.start();
    running = false;
    swapper.join();

    return 0;
}

std::shared_ptr<OrderList> buildSampleList() {
    auto list = std::make_shared<OrderList>();
    Order mikeOrder("For Mike, delivered to 1 Elm Ave.");
    Order aliceOrder("For Alice, delivered to 3 Arch Ave.");

    MenuItem pepperoni("Classic Pepperoni Pizza", 10.0);
    MenuItem hawaiian("Hawaiian Pizza", 12.0);

    mikeOrder.addItem(OrderItem(pepperoni, 1));
    mikeOrder.addItem(OrderItem(hawaiian, 1));
    aliceOrder.addItem(OrderItem(pepperoni, 2));

    list->pushOrder(mikeOrder);
    list->pushOrder(aliceOrder);

    return list;
}