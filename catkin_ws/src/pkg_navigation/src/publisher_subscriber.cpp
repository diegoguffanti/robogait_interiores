#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <iostream>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include "geometry_msgs/msg/twist.hpp"
using namespace std;
using namespace rclcpp;
using namespace std::chrono_literals;
using std::placeholders::_1;


class generic : public rclcpp::Node
{

Publisher<std_msgs::msg::String>::SharedPtr publisher1;
Publisher<nav_msgs::msg::Odometry>::SharedPtr publisher2;
Subscription<geometry_msgs::msg::Twist>::SharedPtr subscription_;
nav_msgs::msg::Odometry odom_msg;
TimerBase::SharedPtr timer_;
thread pub;
int count=0;
    
  
//Contructor del nodo------------------------------------------------------------------
public:
	generic() : Node("publisher_subscriber")
	    {
		publisher1 = this->create_publisher<std_msgs::msg::String>("topic", 10);
		publisher2 = this->create_publisher<nav_msgs::msg::Odometry>("myOdom", 10);
		subscription_ = this->create_subscription<geometry_msgs::msg::Twist>("cmd_vel",10, std::bind(&generic::topic_callback, this, _1));
		timer_ = this->create_wall_timer(10ms, std::bind(&generic::loop, this));
		//This timer is for controlling the ros_rate, comment for maximum rate but add a while(1){ } in the loop() function
		pub = thread(&generic::loop, this);
		
	    }
    
//Funciones miembro------------------------------------------------------------------
private:
	    void topic_callback(const geometry_msgs::msg::Twist::SharedPtr msg) 
	    {
	      cout << msg->linear.x << endl;
	    }
	    void loop()
	    {
	      //while (1)
	      //{
		      //cout << "Hola" << endl;
		      std_msgs::msg::String message;
		      message.data = "Hello, world! "+ std::to_string(count++);
		      cout<< message.data <<endl;
		      publisher1->publish(message);
		      
		      
		      odom_msg.pose.pose.position.x=10;
		      odom_msg.pose.pose.position.y=20;
		      odom_msg.pose.pose.position.z=30;
		      publisher2->publish(odom_msg);
	      //}
	        
	    }

};

int main(int argc, char * argv[])
{
  init(argc, argv);
  spin(std::make_shared<generic>());
  shutdown();
  return 0;
}
