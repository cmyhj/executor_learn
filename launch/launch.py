from launch import LaunchDescription
from launch_ros.actions import ComposableNodeContainer
from launch_ros.descriptions import ComposableNode


def generate_launch_description():
    ld = LaunchDescription()
    ld.add_action(ComposableNodeContainer(
        name='my_container',
        namespace='',
        package='rclcpp_components',
        executable='component_container',
        composable_node_descriptions=[
            ComposableNode(
                package='executor_learn',
                plugin='my_namespace::Node1',
                name='Node11',
                extra_arguments=[
                    # 启用进程内通信
                    {'use_intra_process_comms': True},
                    # 启用日志级别管理服务
                    {'enable_logger_service': True},
                    # 禁用参数事件发布器
                    {'start_parameter_event_publisher': False}
                ],
            ),
            ComposableNode(
                package='executor_learn',
                plugin='my_namespace::Node1',
                name='Node12',
                extra_arguments=[
                    # 是否启用专用的时钟线程
                    {'use_clock_thread': True},
                    # 启用主题统计信息发布器
                    {'enable_topic_statistics': True},
                    # 禁用 rosout 主题发布器
                    {'enable_rosout': False}
                ],
            ),
        ]
    ))
    return ld