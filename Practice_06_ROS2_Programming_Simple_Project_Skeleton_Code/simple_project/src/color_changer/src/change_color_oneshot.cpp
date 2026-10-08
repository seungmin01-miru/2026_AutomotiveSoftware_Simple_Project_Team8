#include <iostream>
#include <string>
#include <vector>
#include <cmath>


#include "rclcpp/rclcpp.hpp"

class ColorChanger : public rclcpp::Node   {
    public:
        ColorChanger(const std::string& node_name, const double& loop_rate): Node(node_name)  {
            // setting parameters
            param_client_ = std::make_shared<rclcpp::AsyncParametersClient>(this, "/turtlesim");
            
            t_run_node_ = this->create_wall_timer(
            std::chrono::milliseconds((int64_t)(1000 / loop_rate)),
            [this]()
            { this->Run(); });
        }



    private:
        rclcpp::TimerBase::SharedPtr t_run_node_;

        std::shared_ptr<rclcpp::AsyncParametersClient> param_client_;
        std::vector<rclcpp::Parameter> params_;

        void Run() {         
            params_.clear();
            params_.push_back(rclcpp::Parameter("background_r", 255));  
            params_.push_back(rclcpp::Parameter("background_g", 100));    
            params_.push_back(rclcpp::Parameter("background_b", 0));  
            param_client_->set_parameters(params_);
        }
};


int main(int argc, char *argv[]) {
    std::string node_name = "color_changer";
    double loop_rate = 10.0;

    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<ColorChanger>(node_name, loop_rate));
    rclcpp::shutdown();
    return 0;
}
