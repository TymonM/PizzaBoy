#ifndef DTS_91896_ORDER_RENDERER_H
#define DTS_91896_ORDER_RENDERER_H

#include "core/order.h"

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
     * Since the Order is passed by reference, the renderer will update automatically when the
     * Order object changes.
     *
     * @return The renderable ftxui::Component for the Order object.
     */
    static ftxui::Component getRenderer(const Order& order);
};


#endif //DTS_91896_ORDER_RENDERER_H
