#include "color_changer.hpp"


ColorChanger::ColorChanger(const std::string& node_name, const double& loop_rate)
    : Node(node_name)  {
    
    auto qos_profile = rclcpp::QoS(rclcpp::KeepLast(10));
    
    // -------------------TODO - define publisher and subscriber--------------------
    p_turtle_color_ = this->create_publisher<my_msgs::msg::TurtleColor>(
        "/turtle_color", qos_profile);

    s_turtle_pose_ = this->create_subscription<turtlesim::msg::Pose>(
        "/turtle1/pose", qos_profile,
        std::bind(&ColorChanger::CallbackTurtlePose, this, std::placeholders::_1));
    // ~~~
    // -------------------------------------------------------------------------------

    // parameter client to change the background color parameters of the turtlesim node
    param_client_ = std::make_shared<rclcpp::AsyncParametersClient>(this, "/turtlesim");

    t_run_node_ = this->create_wall_timer(
            std::chrono::microseconds((int64_t)(1e6 / loop_rate)),
            [this]()
            { this->Run(this->now()); });
}


void ColorChanger::Run(const rclcpp::Time &current_time) {
    int background_r = 0;   // 0 ~ 255
    int background_g = 0;
    int background_b = 0;

    // -------------------TODO - set background_r/g/b and o_turtle_color_ according to the turtle's yaw angle--------------------
    double theta_deg = i_turtle_pose_.theta * 180.0 / M_PI;
    while (theta_deg >= 180.0)  theta_deg -= 360.0;
    while (theta_deg < -180.0)  theta_deg += 360.0;

    if (theta_deg >= 0.0 && theta_deg < 90.0) {
        background_r = 255; background_g = 255; background_b = 255;
        o_turtle_color_.r = 1.0; o_turtle_color_.g = 1.0; o_turtle_color_.b = 1.0;
    }
    else if (theta_deg >= 90.0 && theta_deg < 180.0) {
        background_r = 255; background_g = 0;   background_b = 0;
        o_turtle_color_.r = 1.0; o_turtle_color_.g = 0.0; o_turtle_color_.b = 0.0;
    }
    else if (theta_deg >= -180.0 && theta_deg < -90.0) {
        background_r = 0;   background_g = 255; background_b = 0;
        o_turtle_color_.r = 0.0; o_turtle_color_.g = 1.0; o_turtle_color_.b = 0.0;
    }
    else {
        background_r = 0;   background_g = 0;   background_b = 255;
        o_turtle_color_.r = 0.0; o_turtle_color_.g = 0.0; o_turtle_color_.b = 1.0;
    }
    // ~~~
    // -------------------------------------------------------------------------------

    // set the background color parameters of the turtlesim node
    params_.clear();
    params_.push_back(rclcpp::Parameter("background_r", background_r));
    params_.push_back(rclcpp::Parameter("background_g", background_g));
    params_.push_back(rclcpp::Parameter("background_b", background_b));
    param_client_->set_parameters(params_);

    Publish(current_time);
}

void ColorChanger::Publish(const rclcpp::Time &current_time) {
    p_turtle_color_->publish(o_turtle_color_);
}


int main(int argc, char *argv[]) {
    std::string node_name = "color_changer";
    double loop_rate = 10.0;

    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<ColorChanger>(node_name, loop_rate));
    rclcpp::shutdown();
    return 0;
}
