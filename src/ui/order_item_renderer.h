#ifndef DTS_91896_ORDER_ITEM_RENDERER_H
#define DTS_91896_ORDER_ITEM_RENDERER_H

#include "core/order_item.h"

#include <ftxui/component/component.hpp>

/**
 * @brief The OrderItemRenderer class is responsible for rendering an OrderItem object.
 *
 * This class provides functionality to render an OrderItem object as a ftxui::Component.
 */
class OrderItemRenderer {
public:
    /**
     * @brief Get a renderer for an OrderItem object.
     * Since the OrderItem is passed by reference, the renderer will update automatically when the
     * OrderItem object changes.
     *
     * @return The renderable ftxui::Component for the OrderItem object.
     */
    static ftxui::Component getRenderer(const OrderItem& orderItem);
};


#endif //DTS_91896_ORDER_ITEM_RENDERER_H
