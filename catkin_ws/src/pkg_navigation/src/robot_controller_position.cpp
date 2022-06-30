#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <iostream>
#include <iomanip>


#include <fstream>

//ROS
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "nav_msgs/msg/path.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "nav_msgs/msg/odometry.hpp"
//Math
#include <vector>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2/LinearMath/Matrix3x3.h>

#include "body_tracker_msgs/msg/spine_bottom.hpp"


using namespace std;
using namespace rclcpp;
using namespace std::chrono_literals;
using std::placeholders::_1;

int count=0;
int flag_local_plan=0;

class generic : public rclcpp::Node
{
Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_cmd_vel;
//Subscription<geometry_msgs::msg::Twist>::SharedPtr subscription_keyboard;
//Subscription<nav_msgs::msg::Path>::SharedPtr subscription_local_plan;
//Subscription<nav_msgs::msg::Path>::SharedPtr subscription_global_plan;
//Subscription<geometry_msgs::msg::PoseStamped>::SharedPtr subscription_goal;
Subscription<nav_msgs::msg::Odometry>::SharedPtr subscription_robot_odom;
Subscription<body_tracker_msgs::msg::SpineBottom>::SharedPtr subscription_spine_bottom;
geometry_msgs::msg::Twist cmd_velrobot_msg;

//nav_msgs::msg::Path path_local;
//nav_msgs::msg::Odometry odom_robot;

TimerBase::SharedPtr timer_;
thread pub;

//Contructor del nodo------------------------------------------------------------------
public:
	generic() : Node("robot_controller_position")
	    {
		
		//subscription_keyboard= this->create_subscription<geometry_msgs::msg::Twist>("keyboard_cmd_vel",10, std::bind(&generic::callback_keyboard, this, _1));
		//subscription_local_plan = this->create_subscription<nav_msgs::msg::Path>("local_plan",10, std::bind(&generic::callback_local_plan, this, _1));
		//subscription_global_plan = this->create_subscription<nav_msgs::msg::Path>("global_plan",10, std::bind(&generic::callback_global_plan, this, _1));
		//subscription_goal= this->create_subscription<geometry_msgs::msg::PoseStamped>("goal_pose",10, std::bind(&generic::callback_goal_pose, this, _1));
		
		subscription_robot_odom= this->create_subscription<nav_msgs::msg::Odometry>("odom",10, std::bind(&generic::callback_odom, this, _1));
		publisher_cmd_vel = this->create_publisher<geometry_msgs::msg::Twist>("remaped_cmd_vel", 10);
		subscription_spine_bottom = this->create_subscription<body_tracker_msgs::msg::SpineBottom>("body_tracker_simplified", 10, bind(&generic::topic_callback_spine_bottom, this, _1));
		
		
		//timer_ = this->create_wall_timer(10ms, std::bind(&generic::loop, this));
		//This timer is for controlling the ros_rate, comment for maximum rate but add a while(1){ } in the loop() function
		//pub = thread(&generic::loop, this);
		
	    }
    
//Funciones miembro------------------------------------------------------------------
private:
	    
	    //void callback_keyboard(const geometry_msgs::msg::Twist::SharedPtr msg) 
	    //{
	      //cout << "Keyboard_x_vel: "<<msg->linear.x << endl;
	      //cmd_velrobot_msg.linear.x = msg->linear.x;
	      //cmd_keyboard_msg.angular.z=msg->angular.z;
	    //}
	    
	    void callback_odom(const nav_msgs::msg::Odometry::SharedPtr msg)
	    {
	        robot_pos_x=msg->pose.pose.position.x;
	        robot_vel_x=msg->twist.twist.linear.x;
	        
	    	
	      
	    }
	    void topic_callback_spine_bottom(const body_tracker_msgs::msg::SpineBottom::SharedPtr msg)
  	    {
	      float data= msg->joint_position_spine_bottom.z;
	      data=data/1000;
	      distance_person=data;
	      //distance_person=mean_filter(data);
	      cout<< "Person detected at: "<<distance_person<<endl;
	      controller();
	      
  	    }
  	    void controller()
  	    {
  	      if(distance_person<4.0){
  	      
		      rclcpp::Time time_now = this->get_clock()->now();
	      	      rclcpp::Duration t_spent = time_now -ant_time;
	              float time_spent= (float)t_spent.seconds();
	              cout<< "Tiempo azure:"<<time_spent<<endl;
	              
		      error_p=2.50-distance_person;
		      
		      error_actual=error_p;
		      
		      error_d=(error_actual-error_ant)/time_spent;
		      
		      error_i=error_i+(error_actual*time_spent);
		      
		      //if(fabs(error_actual)<1.00 && fabs(error_actual)>0.10)
		      //{
		        //error_d=(error_actual-error_ant)/time_spent;
		        //error_i=error_i+(error_actual*time_spent);
		        
		        //cout<<"Entra a corregir parte integral y derivativa/////////////////////////////////////"<<endl;
		      //}
		      
		      		      
		      float Kp=1.4;
		      float Kd=0.1;
		      float Ki=0.4;
		      
		      
		      //float Kp=1.4;
		      //float Kd=0.2;
		      //float Ki=0.4;
		      
		      cout<< "kd*error_d"<<Kd*error_d<<endl;
		      cout<< "ki*error_i"<<Ki*error_i<<endl;
		      
		      float control=Kp*error_p+Kd*error_d+Ki*error_i;
		      
		      
		      if(control>max_speed){
		      	control=max_speed;
		      }
		      if(control<-max_speed){
		      	control=-max_speed;
		      	
		      }
		      
		      ant_time=time_now;
		      error_ant=error_actual;
		      
		      cmd_velrobot_msg.linear.x=control;
		      publisher_cmd_vel->publish(cmd_velrobot_msg);
		      cout<< "Control: "<<control<<" Error: "<<error_actual<<" Distance_person: "<<distance_person<<endl;
		}
  	    }
  	    
  	    //void callback_keyboard(const geometry_msgs::msg::Twist::SharedPtr msg) 
	    //{
	      //cout << msg->linear.x << endl;
	      //float vel_x=msg->linear.x;
	      //float avg_filtered=mean_filter(vel_x);
	      //cout<<"Promedio: "<<avg_filtered<<endl;
	      
	      
	     //}
	     
	     float mean_filter(float new_data)
	     {
	     
	      int size;
	      size = sizeof(array) / sizeof(array[0]);
	      
	      memmove(&array[0], &array[1], (size - 1) * sizeof(array[0]));
	      array[size - 1] = new_data;
	      
	      for (const auto& e : array) {
    		std::cout << e << std::endl;
		}
	      
	      float sum, avg;
	      sum = 0;
	      avg = 0;
	      for(int i = 0; i < size; i++){
		sum += array[i];
	      }
	      avg = sum / size;
	      return avg;
	     
	      }
  	    
  	    float distance_person,person_vel,distance_person_ant;
  	    float robot_pos_x, robot_vel_x;
  	    float array[5];
  	    rclcpp::Time ant_time = this->get_clock()->now();
  	    float error_p,error_actual, error_ant,error_d, error_i;
  	    float max_speed=1.5386;//1.5386;
  	    //rclcpp::Duration time_spent;
  	    int counter_distances=0;

};

int main(int argc, char * argv[])
{
  init(argc, argv);
  spin(std::make_shared<generic>());
  shutdown();
  return 0;
}
