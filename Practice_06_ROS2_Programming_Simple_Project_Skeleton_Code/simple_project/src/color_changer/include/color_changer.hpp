/**
 * @file      moving_turtle.hpp
 * @brief     background color changes by turtle's yaw
 * 
 * @date      2024-09-24 created by Seounghoon Park (sunghoon8585@gmail.com)
 */

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

#include "rclcpp/rclcpp.hpp"

// -------------------TODO - include the message header files used in this node--------------------
#include "turtlesim/msg/pose.hpp"
#include "my_msgs/msg/turtle_color.hpp"
// ~~~
// -------------------------------------------------------------------------------


class ColorChanger : public rclcpp::Node   {
    public:
        ColorChanger(const std::string& node_name, const double& loop_rate);

    private:
        // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
        // Functions   
        inline void CallbackTurtlePose(const turtlesim::msg::Pose::SharedPtr msg) {            
            i_turtle_pose_ = *msg;
        }

        void Run(const rclcpp::Time &current_time);
        void Publish(const rclcpp::Time &current_time);
        
        // Publisher 
        // -------------------TODO - declare a publisher for the turtle color--------------------
        rclcpp::Publisher<my_msgs::msg::TurtleColor>::SharedPtr p_turtle_color_;
        // ~~~
        // -------------------------------------------------------------------------------

        // Subscriber
        // -------------------TODO - declare a subscriber for the turtle pose--------------------
        rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr s_turtle_pose_;
        // ~~~
        // -------------------------------------------------------------------------------

        // Timer
        rclcpp::TimerBase::SharedPtr t_run_node_;

        // Inputs
        turtlesim::msg::Pose i_turtle_pose_;

        // Outputs
        my_msgs::msg::TurtleColor o_turtle_color_;

        std::shared_ptr<rclcpp::AsyncParametersClient> param_client_;

        // Algorithm Variables
        std::vector<rclcpp::Parameter> params_;

};