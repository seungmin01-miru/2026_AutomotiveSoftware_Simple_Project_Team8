#include "visualizer.hpp"


Visualizer::Visualizer(const std::string& node_name, const double& loop_rate)
    : Node(node_name)  {
    
    auto qos_profile = rclcpp::QoS(rclcpp::KeepLast(10));

    // -------------------TODO - define publisher and subscriber--------------------
    // ~~~
    // -------------------------------------------------------------------------------

    t_run_node_ = this->create_wall_timer(
            std::chrono::microseconds((int64_t)(1e6 / loop_rate)),
            [this]()
            { this->Run(this->now()); });
}


void Visualizer::Run(const rclcpp::Time &current_time) {
    
    
    UpdateMarker(current_time, i_turtle_pose_, i_turtle_color_);
    Publish(current_time);

}


void Visualizer::Publish(const rclcpp::Time& current_time) {
    p_turtle_marker_->publish(o_turtle_marker_);
}


void Visualizer::UpdateMarker(  const rclcpp::Time& current_time,
                                const turtlesim::msg::Pose& turtle_pose,
                                const my_msgs::msg::TurtleColor& turtle_color) {

    visualization_msgs::msg::Marker marker_msg;

    // -------------------TODO - fill in the marker field values (header, type, action, pose, scale, color)--------------------
    marker_msg.header.frame_id = /* ~~~ */;
    marker_msg.header.stamp = /* ~~~ */;
    marker_msg.ns = "basic_shapes";
    marker_msg.id = 0;
    marker_msg.type = /* ~~~ */;
    marker_msg.action = /* ~~~ */;

    marker_msg.pose.position.x = /* ~~~ */;
    marker_msg.pose.position.y = /* ~~~ */;
    marker_msg.pose.position.z = /* ~~~ */;
    marker_msg.pose.orientation.x = /* ~~~ */;
    marker_msg.pose.orientation.y = /* ~~~ */;
    marker_msg.pose.orientation.z = /* ~~~ */;
    marker_msg.pose.orientation.w = /* ~~~ */;

    marker_msg.scale.x = /* ~~~ */;
    marker_msg.scale.y = /* ~~~ */;
    marker_msg.scale.z = /* ~~~ */;

    marker_msg.color.r = /* ~~~ */;
    marker_msg.color.g = /* ~~~ */;
    marker_msg.color.b = /* ~~~ */;
    marker_msg.color.a = /* ~~~ */;
    // -------------------------------------------------------------------------------
    
    o_turtle_marker_ = marker_msg;
}


int main(int argc, char *argv[]) {
    std::string node_name = "hmi";
    double loop_rate = 60.0;

    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Visualizer>(node_name, loop_rate));
    rclcpp::shutdown();
    return 0;
}
