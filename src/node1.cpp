#include "executor_learn/node1.hpp"
namespace my_namespace{
    Node1::Node1(const std::string& node_name) : Node(node_name)
    // Node1::Node1(const rclcpp::NodeOptions &options) : Node("node1",options)
    {
        timer_1 = this->create_wall_timer(std::chrono::milliseconds(1000), std::bind(&Node1::timer_callback1, this));
        timer_2 = this->create_wall_timer(std::chrono::milliseconds(1000), std::bind(&Node1::timer_callback2, this));
    }

    void Node1::timer_callback1()
    {
        RCLCPP_INFO(this->get_logger(), "timer callback 1");
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    }
    void Node1::timer_callback2()
    {
        RCLCPP_INFO(this->get_logger(), "timer callback 2");
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    }
}// namespace my_namespace

// #include "rclcpp_components/register_node_macro.hpp"
// RCLCPP_COMPONENTS_REGISTER_NODE(my_namespace::Node1)