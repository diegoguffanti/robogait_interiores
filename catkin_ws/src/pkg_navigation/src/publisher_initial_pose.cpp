#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <iostream>

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/pose_with_covariance_stamped.hpp"

using namespace std;
using namespace rclcpp;
using namespace std::chrono_literals;
using std::placeholders::_1;


class generic : public rclcpp::Node
{

Publisher<geometry_msgs::msg::PoseWithCovarianceStamped>::SharedPtr publisher1;

    
  
//Contructor del nodo------------------------------------------------------------------
public:
	generic() : Node("publisher_initial_pose")
	    {
		publisher1 = this->create_publisher<geometry_msgs::msg::PoseWithCovarianceStamped>("/initialpose", 10);
		geometry_msgs::msg::PoseWithCovarianceStamped initialpose;
		initialpose.header.frame_id="map";
		initialpose.pose.pose.position.x=0;
		initialpose.pose.pose.position.y=0;
		initialpose.pose.pose.orientation.x=0;
		initialpose.pose.pose.orientation.y=0;
		initialpose.pose.pose.orientation.z=0;
		initialpose.pose.pose.orientation.w=1;
		publisher1->publish(initialpose);
		
	    }
    

};

int main(int argc, char * argv[])
{
  init(argc, argv);
  spin(std::make_shared<generic>());
  shutdown();
  return 0;
}
