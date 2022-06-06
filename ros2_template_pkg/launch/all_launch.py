import platform

import launch
import launch.actions
import launch.substitutions
import launch_ros.actions

env_var_name = 'USER' if platform.system() != 'Windows' else 'USERNAME'

def generate_launch_description():
    return launch.LaunchDescription([
        launch.actions.DeclareLaunchArgument(
            'node_prefix',
            default_value=[launch.substitutions.EnvironmentVariable(env_var_name), '_'],
            description='Prefix for node names'),
        launch_ros.actions.Node(
            package='multi_node_launcher', executable='talker', output='screen',
            name=[launch.substitutions.LaunchConfiguration('node_prefix'), 'talker']),
        launch_ros.actions.Node(
            package='multi_node_launcher', executable='listener', output='screen',
            name=[launch.substitutions.LaunchConfiguration('node_prefix'), 'listener']),
        launch_ros.actions.Node(
            package='multi_node_launcher', executable='timer', output='screen',
            name=[launch.substitutions.LaunchConfiguration('node_prefix'), 'timer'])         
    ])