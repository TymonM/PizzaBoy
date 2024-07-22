#ifndef DTS_91896_ORDER_LIST_RENDERER_H
#define DTS_91896_ORDER_LIST_RENDERER_H

#include "core/order_list.h"

#include <ftxui/component/component.hpp>

/**
 * @brief The OrderListRenderer class is responsible for rendering an OrderList object.
 *
 * This class provides functionality to render an OrderList object as a ftxui::Component.
 */
class OrderListRenderer {
public:
    /**
     * @brief Get a renderer for an OrderList object.
     * Since the OrderList is passed by reference, the renderer will update automatically when the
     * OrderList object changes, such as when orders are added or removed.
     *
     * @return The renderable ftxui::Component for the OrderList object.
     */
    static ftxui::Component getRenderer(const OrderList& orderList);
};


#endif //DTS_91896_ORDER_LIST_RENDERER_H
