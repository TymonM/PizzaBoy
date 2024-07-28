#ifndef DTS_91896_KITCHENUI_H
#define DTS_91896_KITCHENUI_H

#include "core/order_list.h"

#include <ftxui/component/component.hpp>

class KitchenUi {
public:
    static ftxui::Component renderOrderItem(const OrderItem& orderItem);
    static ftxui::Component renderOrder(const Order& order, OrderList& orderList, bool selected);
    static ftxui::Component renderOrderList(OrderList& orderList);
};


#endif //DTS_91896_KITCHENUI_H
