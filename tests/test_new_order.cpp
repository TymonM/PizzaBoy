#include "macros.cpp"

#include "../src/order.h"

int main() {
    Order order("One pepperoni pizza for Mike, delivered to 1 Elm Ave.");

    ASSERT(order.getDescription() == "One pepperoni pizza for Mie, delivered to 1 Elm Ave.");

    return 0;
}