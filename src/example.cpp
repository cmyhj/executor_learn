#include "rclcpp/rclcpp.hpp"
#include <chrono>
#include <thread>

class Node1 : public rclcpp::Node
{
public:
    Node1(const std::string &node_name) : Node("node1"),node_name(node_name)
    {
        timer_1 = this->create_wall_timer(std::chrono::milliseconds(1000), std::bind(&Node1::timer_callback1, this));
        timer_2 = this->create_wall_timer(std::chrono::milliseconds(2000), std::bind(&Node1::timer_callback2, this));
    }

private:
    std::string node_name;
    rclcpp::TimerBase::SharedPtr timer_1;
    rclcpp::TimerBase::SharedPtr timer_2;
    void timer_callback1()
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        RCLCPP_INFO(this->get_logger(), "%s timer callback 1", node_name.c_str());
    }
    void timer_callback2()
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(3000));
        RCLCPP_INFO(this->get_logger(), "%s timer callback 2", node_name.c_str());
    }
};
int main (int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node1 = std::make_shared<Node1>("node1");
    rclcpp::spin(node1);
    rclcpp::shutdown();
    return 0;
}
// int main(int argc, char **argv)
// {
//     rclcpp::init(argc, argv);
//     auto node1 = std::make_shared<Node1>("node1");
//     rclcpp::executors::SingleThreadedExecutor executor;
//     executor.add_node(node1);
//     executor.spin();
//     rclcpp::shutdown();
//     return 0;
// }
// int main(int argc, char **argv)
// {
//     rclcpp::init(argc, argv);
//     auto node11 = std::make_shared<Node1>("node11");
//     auto node12 = std::make_shared<Node1>("node12");
//     rclcpp::executors::SingleThreadedExecutor executor;
//     executor.add_node(node11);
//     executor.add_node(node12);
//     executor.spin();
//     rclcpp::shutdown();
//     return 0;
// }
