#include "rclcpp/rclcpp.hpp"
#include <chrono>
#include <thread>

class Node2 : public rclcpp::Node
{

public:
    Node2(const std::string& node_name) : Node("node2"),node_name(node_name)
    {
        mutually_exclusive_callback_group = this->create_callback_group(rclcpp::CallbackGroupType::MutuallyExclusive);
        reetrant_callback_group = this->create_callback_group(rclcpp::CallbackGroupType::Reentrant);
        timer_1 = this->create_wall_timer(std::chrono::milliseconds(1000), std::bind(&Node2::timer_callback1, this),mutually_exclusive_callback_group);
        timer_2 = this->create_wall_timer(std::chrono::milliseconds(1000), std::bind(&Node2::timer_callback2, this),mutually_exclusive_callback_group);
        timer_3 = this->create_wall_timer(std::chrono::milliseconds(1000), std::bind(&Node2::timer_callback3, this),reetrant_callback_group);
        timer_4 = this->create_wall_timer(std::chrono::milliseconds(1000), std::bind(&Node2::timer_callback4, this),reetrant_callback_group);
        timer_5 = this->create_wall_timer(std::chrono::milliseconds(1000), std::bind(&Node2::timer_callback5, this),reetrant_callback_group);
    }

private:
    std::string node_name;
    rclcpp::TimerBase::SharedPtr timer_1;
    rclcpp::TimerBase::SharedPtr timer_2;
    rclcpp::TimerBase::SharedPtr timer_3;
    rclcpp::TimerBase::SharedPtr timer_4;
    rclcpp::TimerBase::SharedPtr timer_5;
    
    rclcpp::CallbackGroup::SharedPtr mutually_exclusive_callback_group;
    rclcpp::CallbackGroup::SharedPtr reetrant_callback_group;
    void timer_callback1()
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        RCLCPP_INFO(this->get_logger(), "%s timer MutuallyExclusive callback1",node_name.c_str());
    }
    void timer_callback2()
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        RCLCPP_INFO(this->get_logger(), "%s timer MutuallyExclusive callback2",node_name.c_str());
    }
    void timer_callback3()
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        RCLCPP_INFO(this->get_logger(), "%s timer Reentrant callback3",node_name.c_str());
    }
    void timer_callback4()
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        RCLCPP_INFO(this->get_logger(), "%s timer Reentrant callback4",node_name.c_str());
    }
    void timer_callback5()
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        RCLCPP_INFO(this->get_logger(), "%s timer Reentrant callback5",node_name.c_str());
    }
};
int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node21 = std::make_shared<Node2>("node21");
    auto node22 = std::make_shared<Node2>("node22");
    rclcpp::executors::MultiThreadedExecutor executor;
    executor.add_node(node21);
    executor.add_node(node22);
    executor.spin();
    rclcpp::shutdown();
    return 0;
}