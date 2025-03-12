#include "rclcpp/rclcpp.hpp"
#include <chrono>
#include <thread>

class Node2 : public rclcpp::Node
{

public:
    Node2(const std::string& node_name);

private:
    rclcpp::TimerBase::SharedPtr timer_1;
    rclcpp::TimerBase::SharedPtr timer_2;
    rclcpp::TimerBase::SharedPtr timer_3;
    rclcpp::TimerBase::SharedPtr timer_4;
    rclcpp::TimerBase::SharedPtr timer_5;
    
    rclcpp::CallbackGroup::SharedPtr mutually_exclusive_callback_group;
    rclcpp::CallbackGroup::SharedPtr reetrant_callback_group;
    void timer_callback1();
    void timer_callback2();
    void timer_callback3();
    void timer_callback4();
    void timer_callback5();
};
