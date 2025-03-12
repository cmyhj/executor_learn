#include "rclcpp/rclcpp.hpp"
#include <chrono>
#include <thread>

class Node1 : public rclcpp::Node
{
public:
    Node1(const std::string &node_name);

private:
    rclcpp::TimerBase::SharedPtr timer_1;
    rclcpp::TimerBase::SharedPtr timer_2;
    void timer_callback1();
    void timer_callback2();
};

