#include "macros.cpp"

#include "../src/order.h"

void calculate_total_price() {
    Order order("For Mike");
    MenuItem pepperoni("Classic Pepperoni Pizza", 10.0);
    MenuItem margherita("Margherita Pizza", 9.0);

    order.addItem(pepperoni);
    order.addItem(margherita);

    ASSERT(order.calculateTotalPrice() == 19.0);
}

int main() {
    calculate_total_price();
}
