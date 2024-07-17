#include "macros.cpp"

#include "utils/utils.h"

void TEST_price_formatting() {
    ASSERT(utils::formatPrice(10.0) == "$10.00");
    ASSERT(utils::formatPrice(10.5) == "$10.50");
    ASSERT(utils::formatPrice(10.55) == "$10.55");
}

int main() {
    TEST_price_formatting();

    return 0;
}
