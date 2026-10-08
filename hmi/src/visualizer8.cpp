#include "visualizer.hpp"


Visualizer::Visualizer(const std::string& node_name, const double& loop_rate)
    : Node(node_name)  {
    
    auto qos_profile = rclcpp::QoS(rclcpp::KeepLast(10));

    // -------------------TODO - define publisher and subscriber--------------------
    // publisher : cube marker -> RViz
    p_turtle_marker_ = this->create_publisher<visualization_msgs::msg::Marker>(
        "/hmi/turtle_marker", qos_profile);

    // subscriber : turtle pose <- turtlesim node
    s_turtle_pose_ = this->create_subscription<turtlesim::msg::Pose>(
        "/turtle1/pose", qos_profile,
        std::bind(&Visualizer::CallbackTurtlePose, this, std::placeholders::_1));

    // subscriber : background color (custom message) <- color_changer node
    s_turtle_color_ = this->create_subscription<my_msgs::msg::TurtleColor>(
        "/turtle_color", qos_profile,
        std::bind(&Visualizer::CallbackTurtleColor, this, std::placeholders::_1));
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
    marker_msg.header.frame_id = "map";
    marker_msg.header.stamp = current_time;
    marker_msg.ns = "basic_shapes";
    marker_msg.id = 0;
    marker_msg.type = visualization_msgs::msg::Marker::CUBE;
    marker_msg.action = visualization_msgs::msg::Marker::ADD;

    marker_msg.pose.position.x = turtle_pose.x;
    marker_msg.pose.position.y = turtle_pose.y;
    marker_msg.pose.position.z = 0.0;
    marker_msg.pose.orientation.x = 0.0;
    marker_msg.pose.orientation.y = 0.0;
    marker_msg.pose.orientation.z = 0.0;
    marker_msg.pose.orientation.w = 1.0;

    marker_msg.scale.x = 1.0;
    marker_msg.scale.y = 1.0;
    marker_msg.scale.z = 1.0;

    marker_msg.color.r = turtle_color.r;
    marker_msg.color.g = turtle_color.g;
    marker_msg.color.b = turtle_color.b;
    marker_msg.color.a = 1.0;
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
