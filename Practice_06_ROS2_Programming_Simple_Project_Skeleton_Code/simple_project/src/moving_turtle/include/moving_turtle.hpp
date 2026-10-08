/**
 * @file      moving_turtle.hpp
 * @brief     turtlesim moving
 * 
 * @date      2024-09-24 created by Seounghoon Park (sunghoon8585@gmail.com)
 */

#include <iostream>
#include <string>

#include "rclcpp/rclcpp.hpp"  

// -------------------TODO - include the message header file used in this node--------------------
// ~~~
// -------------------------------------------------------------------------------


class MovingTurtle : public rclcpp::Node   {
    public:
        MovingTurtle(const std::string& node_name, const double& loop_rate);

    private:
        
        void Run(const rclcpp::Time &current_time);
        void Publish(const rclcpp::Time& current_time);
        
        // Publisher
        // -------------------TODO - declare a publisher for the turtle velocity command--------------------
        // ~~~
        // -------------------------------------------------------------------------------

        // Timer
        rclcpp::TimerBase::SharedPtr t_run_node_;

        // Outputs
        geometry_msgs::msg::Twist o_turtle_cmd_;

        // Algorithm Variables
        unsigned int loop_count_ = 0;

};