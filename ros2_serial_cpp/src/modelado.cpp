#include <iostream>
#include <fstream>
#include <memory>


#include "rclcpp/rclcpp.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "body_tracker_msgs/msg/spine_bottom.hpp"

using namespace std;
using namespace rclcpp;
using namespace std::chrono_literals;
using std::placeholders::_1;

fstream file;

class MinimalSubscriber : public rclcpp::Node
{
public:
	MinimalSubscriber() : Node("subscriber")
  	{
    		subscription_odom = this->create_subscription<nav_msgs::msg::Odometry>("odom", 10, std::bind(&MinimalSubscriber::topic_callback_odom, this, _1));
    		subscription_cmd_vel = this->create_subscription<geometry_msgs::msg::Twist>("cmd_vel", 10, bind(&MinimalSubscriber::topic_callback_cmd_vel, this, _1));
    		subscription_spine_bottom = this->create_subscription<body_tracker_msgs::msg::SpineBottom>("body_tracker_simplified", 10, bind(&MinimalSubscriber::topic_callback_spine_bottom, this, _1));
    		
    		//timer_ = this->create_wall_timer(5ms, std::bind(&MinimalSubscriber::loop, this));
    		//pub = thread(&MinimalSubscriber::loop, this);
		file.open("modelX.csv", fstream::out);
  	}

private:
  	void topic_callback_spine_bottom(const body_tracker_msgs::msg::SpineBottom::SharedPtr msg)
  	{
		
		distance_person= msg->joint_position_spine_bottom.z;
		
  	}
  	void topic_callback_odom(const nav_msgs::msg::Odometry::SharedPtr msg)
  	{
		
		robot_pos_x= msg->pose.pose.position.x;
		robot_vel_x= msg->twist.twist.linear.x;
		rclcpp::Time time_now = this->get_clock()->now();
		rclcpp::Duration time_spent = time_now -start_time;
		file << time_spent.seconds()<<"," << linear_cmd_vel << "," <<robot_vel_x<< "," << robot_pos_x << "," << distance_person<<endl;
  	}
  	void topic_callback_cmd_vel(const geometry_msgs::msg::Twist::SharedPtr msg)
  	{
		linear_cmd_vel= msg->linear.x;
		rclcpp::Time time_now = this->get_clock()->now();
		rclcpp::Duration time_spent = time_now -start_time;
		file << time_spent.seconds()<<"," << linear_cmd_vel << "," <<robot_vel_x<< "," << robot_pos_x << "," << distance_person<<endl;
  	}
  	//void loop()
	//{
	      //while (1)
	      //{
		      //cout << "Hola" << endl;
		      //rclcpp::Time time_now = this->get_clock()->now();
		      //rclcpp::Duration time_spent = time_now -start_time;
		      //RCLCPP_INFO_STREAM(this->get_logger(), " now (s): " << time_spent.seconds());
		      //file << time_spent.seconds()<<"," << linear_cmd_vel << "," <<robot_vel_x<< "," << robot_pos_x << "," << distance_person<<endl;
		      
		      
	      //}
	        
	//}
	    

	rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr subscription_odom;
	rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr subscription_cmd_vel;
	rclcpp::Subscription<body_tracker_msgs::msg::SpineBottom>::SharedPtr subscription_spine_bottom;
	TimerBase::SharedPtr timer_;
	float robot_pos_x, robot_vel_x, linear_cmd_vel, distance_person;
	rclcpp::Time start_time = this->get_clock()->now();
	thread pub;
};

int main(int argc, char * argv[])
{
	rclcpp::init(argc, argv);
	rclcpp::spin(std::make_shared<MinimalSubscriber>());
	rclcpp::shutdown();
	return 0;
}
