#include "executor_learn/node2.hpp"

Node2::Node2(const std::string& node_name) : Node(node_name)
{
    mutually_exclusive_callback_group = this->create_callback_group(rclcpp::CallbackGroupType::MutuallyExclusive);
    reetrant_callback_group = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
    timer_1 = this->create_wall_timer(std::chrono::milliseconds(1000), std::bind(&Node2::timer_callback1, this),mutually_exclusive_callback_group);
    timer_2 = this->create_wall_timer(std::chrono::milliseconds(1000), std::bind(&Node2::timer_callback2, this),mutually_exclusive_callback_group);
    timer_3 = this->create_wall_timer(std::chrono::milliseconds(1000), std::bind(&Node2::timer_callback3, this),reetrant_callback_group);
    timer_4 = this->create_wall_timer(std::chrono::milliseconds(1000), std::bind(&Node2::timer_callback4, this),reetrant_callback_group);
    timer_5 = this->create_wall_timer(std::chrono::milliseconds(1000), std::bind(&Node2::timer_callback5, this),reetrant_callback_group);
}


void Node2::timer_callback1()
{
    RCLCPP_INFO(this->get_logger(), "timer callback1 MutuallyExclusive");
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
}
void Node2::timer_callback2()
{
    RCLCPP_INFO(this->get_logger(), "timer callback2 MutuallyExclusive");
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
}
void Node2::timer_callback3()
{
    RCLCPP_INFO(this->get_logger(), "timer callback3 Reentrant");
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
}
void Node2::timer_callback4()
{
    RCLCPP_INFO(this->get_logger(), "timer callback4 Reentrant");
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
}
void Node2::timer_callback5()
{
    RCLCPP_INFO(this->get_logger(), "timer callback5 Reentrant");
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
}
