#include "rclcpp/rclcpp.hpp"
#include <chrono>
#include <thread>

class Node1 : public rclcpp::Node {
public:
    Node1(const std::string &node_name);
    //Node1(const std::string &node_name, const rclcpp::NodeOptions &options);
private:
    rclcpp::TimerBase::SharedPtr timer_1;
    rclcpp::TimerBase::SharedPtr timer_2;

    void timer_callback1();
    void timer_callback2();
};


