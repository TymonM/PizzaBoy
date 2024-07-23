#ifndef DTS_91896_ORDER_RENDERER_H
#define DTS_91896_ORDER_RENDERER_H

#include "core/order_list.h"

#include <ftxui/component/component.hpp>

/**
 * @brief The OrderRenderer class is responsible for rendering an Order object.
 *
 * This class provides functionality to render an Order object as a ftxui::Component.
 */
class OrderRenderer {
public:
    /**
     * @brief Get a renderer for an Order object.
     * The Order is copied, so the renderer will NOT update automatically when the Order
     * object changes. The OrderList is also passed by reference to allow for deletion of the order.
     * The selected parameter is used to determine if the order is currently selected, if so, it is
     * rendered differently.
     *
     * @return The renderable ftxui::Component for the Order object.
     */
    static ftxui::Component getRenderer(const Order& order, OrderList& orderList, bool selected);
};


#endif //DTS_91896_ORDER_RENDERER_H
