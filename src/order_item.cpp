#include "order_item.h"

OrderItem::OrderItem(const MenuItem& item, size_t quantity) : item(item), quantity(quantity) {}

const MenuItem &OrderItem::getItem() const {
    return item;
}

size_t OrderItem::getQuantity() const {
    return quantity;
}

double OrderItem::calculatePrice() const {
    return item.getPrice() * quantity;
}
