#include "macros.cpp"

#include "../src/order.h"

void TEST_calculate_total_price() {
    Order order("For Mike");
    MenuItem pepperoni("Classic Pepperoni Pizza", 10.0);
    MenuItem margherita("Margherita Pizza", 9.0);

    order.addItem(pepperoni);
    order.addItem(margherita);

    ASSERT(order.calculateTotalPrice() == 19.0);
}

int main() {
    TEST_calculate_total_price();
}
