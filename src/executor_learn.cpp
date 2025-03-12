#include "rclcpp/rclcpp.hpp"
#include "executor_learn/node1.hpp"
#include "executor_learn/node2.hpp"

//int main (int argc, char **argv)
//{
//    rclcpp::init(argc, argv);
//    auto node1 = std::make_shared<Node1>("node1");
//    rclcpp::spin(node1);
//    rclcpp::shutdown();
//    return 0;
//}


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
//     auto node2 = std::make_shared<Node2>("node2");
//     rclcpp::executors::MultiThreadedExecutor executor;
//     executor.add_node(node2);
//     executor.spin();
//     rclcpp::shutdown();
//     return 0;
// }


// int main(int argc, char **argv)//单线程手动组件
// {
//     rclcpp::init(argc, argv);
//     auto node11 = std::make_shared<Node1>("node11");
//     auto node12 = std::make_shared<Node1>("node12");
//     auto node21 = std::make_shared<Node2>("node21");
//     auto node22 = std::make_shared<Node2>("node22");
//
//     rclcpp::executors::SingleThreadedExecutor executor;
//     executor.add_node(node11);
//     executor.add_node(node12);
//     executor.add_node(node21);
//     executor.add_node(node22);
//
//     executor.spin();
//     rclcpp::shutdown();
//     return 0;
// }


 int main(int argc, char **argv)//多线程手动组件
 {
     rclcpp::init(argc, argv);
     auto node11 = std::make_shared<Node1>("node11");
     auto node12 = std::make_shared<Node1>("node12");
     auto node21 = std::make_shared<Node2>("node21");
     auto node22 = std::make_shared<Node2>("node22");
     rclcpp::executors::MultiThreadedExecutor executor;
     executor.add_node(node11);
     executor.add_node(node12);
     executor.add_node(node21);
     executor.add_node(node22);
     executor.spin();
     rclcpp::shutdown();
     return 0;
 }