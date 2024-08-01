#ifndef DTS_91896_KITCHENUI_H
#define DTS_91896_KITCHENUI_H

#include "core/order_list.h"

#include <ftxui/component/component.hpp>

class KitchenUi {
private:
    std::string filepath;
    std::shared_ptr<OrderList> orderList;
    std::shared_ptr<int> selected;

    static ftxui::Component renderOrderItem(const OrderItem& orderItem);
    ftxui::Component renderOrder(const Order& order, bool orderSelected);
    ftxui::Component renderOrderList();
public:
    explicit KitchenUi(const std::string& filepath);

    void setFilepath(const std::string& filepath);

    ftxui::Component getRenderer();
};


#endif //DTS_91896_KITCHENUI_H
