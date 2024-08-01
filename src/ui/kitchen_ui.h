#ifndef DTS_91896_KITCHENUI_H
#define DTS_91896_KITCHENUI_H

#include "core/order_list.h"

#include <ftxui/component/component.hpp>

/**
 * @brief The KitchenUi class is responsible for rendering the kitchen user interface.
 *
 * This class provides functionality to render the kitchen user interface, displaying the list of orders
 * and allowing the kitchen staff to interact with the orders.
 */
class KitchenUi {
private:
    std::string filepath; ///< The filepath to the kitchen's list of orders.
    std::shared_ptr<OrderList> orderList; ///< A local copy of the list of orders.
    std::shared_ptr<int> selected; ///< The index of the currently selected order.

    /**
     * @brief Renders an order item.
     *
     * @param orderItem The order item to render.
     * @return The ftxui::Component for the order item.
     */
    static ftxui::Component renderOrderItem(const OrderItem& orderItem);

    /**
     * @brief Renders an order.
     *
     * @param order The order to render.
     * @param orderSelected Whether or not the order is selected.
     * @return The ftxui::Component for the order.
     */
    ftxui::Component renderOrder(const Order& order, bool orderSelected);

    /**
     * @brief Renders the list of orders.
     *
     * @return The ftxui::Component to display the list of orders.
     */
    ftxui::Component renderOrderList();
public:
    /**
     * @brief Construct a new KitchenUi object.
     *
     * @param filepath The filepath to the kitchen's list of orders.
     */
    explicit KitchenUi(const std::string& filepath);

    /**
     * @brief Set the filepath to the kitchen's list of orders.
     *
     * @param filepath The filepath to the kitchen's list of orders.
     */
    void setFilepath(const std::string& filepath);

    /**
     * @brief Get the renderer for the kitchen user interface.
     *
     * @return The ftxui::Component for the kitchen user interface.
     */
    ftxui::Component getRenderer();
};


#endif //DTS_91896_KITCHENUI_H
