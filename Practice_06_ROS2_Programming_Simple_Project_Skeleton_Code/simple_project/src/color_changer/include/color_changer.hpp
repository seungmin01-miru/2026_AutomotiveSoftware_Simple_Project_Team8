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
        // ~~~
        // -------------------------------------------------------------------------------

        // Subscriber
        // -------------------TODO - declare a subscriber for the turtle pose--------------------
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