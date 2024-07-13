#include "macros.cpp"

#include "core/order.h"

void TEST_calculate_total_price() {
    Order order("For Mike");
    MenuItem pepperoni("Classic Pepperoni Pizza", 10.0);
    MenuItem margherita("Margherita Pizza", 9.0);

    order.addItem(OrderItem(pepperoni, 1));
    order.addItem(OrderItem(margherita, 1));

    ASSERT(order.calculateTotalPrice() == 19.0);
}

void TEST_higher_quantity() {
    Order order("For Mike");
    MenuItem pepperoni("Classic Pepperoni Pizza", 10.0);
    MenuItem margherita("Margherita Pizza", 9.0);

    order.addItem(OrderItem(pepperoni, 2));
    order.addItem(OrderItem(margherita, 1));

    ASSERT(order.calculateTotalPrice() == 29.0);
}

int main() {
    TEST_calculate_total_price();
    TEST_higher_quantity();

    return 0;
}
