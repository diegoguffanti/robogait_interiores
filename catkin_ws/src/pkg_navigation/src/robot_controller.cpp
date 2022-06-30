#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <iostream>
#include <iomanip>
//ROS
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "std_msgs/msg/float32.hpp"

#include "geometry_msgs/msg/twist.hpp"
#include "nav_msgs/msg/path.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "nav_msgs/msg/odometry.hpp"
//Math
#include <vector>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2/LinearMath/Matrix3x3.h>


using namespace std;
using namespace rclcpp;
using namespace std::chrono_literals;
using std::placeholders::_1;

int count=0;
int flag_local_plan=0;

class generic : public rclcpp::Node
{
Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_cmd_vel;
Subscription<geometry_msgs::msg::Twist>::SharedPtr subscription_keyboard;
Subscription<geometry_msgs::msg::Twist>::SharedPtr subscription_control_nav;

Subscription<nav_msgs::msg::Path>::SharedPtr subscription_local_plan;
Subscription<nav_msgs::msg::Path>::SharedPtr subscription_global_plan;
Subscription<geometry_msgs::msg::PoseStamped>::SharedPtr subscription_goal;
Subscription<nav_msgs::msg::Odometry>::SharedPtr subscription_robot_odom_filtered;



geometry_msgs::msg::Twist cmd_velrobot_msg;
geometry_msgs::msg::Twist cmd_keyboard_msg;
nav_msgs::msg::Path path_local;
nav_msgs::msg::Odometry odom_robot;

TimerBase::SharedPtr timer_;
thread pub;


//Contructor del nodo------------------------------------------------------------------
public:
	generic() : Node("robot_controller")
	    {
		publisher_cmd_vel = this->create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 10);
		subscription_keyboard= this->create_subscription<geometry_msgs::msg::Twist>("remaped_cmd_vel",10, std::bind(&generic::callback_keyboard, this, _1));
		subscription_control_nav= this->create_subscription<geometry_msgs::msg::Twist>("cmd_vel_remap",10, std::bind(&generic::callback_control_nav, this, _1));
		subscription_local_plan = this->create_subscription<nav_msgs::msg::Path>("local_plan",10, std::bind(&generic::callback_local_plan, this, _1));
		
		//subscription_global_plan = this->create_subscription<nav_msgs::msg::Path>("global_plan",10, std::bind(&generic::callback_global_plan, this, _1));
		//subscription_goal= this->create_subscription<geometry_msgs::msg::PoseStamped>("goal_pose",10, std::bind(&generic::callback_goal_pose, this, _1));
		subscription_robot_odom_filtered= this->create_subscription<nav_msgs::msg::Odometry>("odom_filtered",10, std::bind(&generic::callback_odom_filtered, this, _1));
		timer_ = this->create_wall_timer(10ms, std::bind(&generic::loop, this));
		//This timer is for controlling the ros_rate, comment for maximum rate but add a while(1){ } in the loop() function
		pub = thread(&generic::loop, this);
		
	    }
    
//Funciones miembro------------------------------------------------------------------
private:
	    
	    
	    void callback_keyboard(const geometry_msgs::msg::Twist::SharedPtr msg) 
	    {
	      //cout << "Keyboard_x_vel: "<<msg->linear.x << endl;
	      if((msg->linear.x==0) && (msg->angular.z==0)){
	      	stop_condition=1;
	      	cout<<"entra a stop_condition........."<<endl;
	      }
	      linear_vel = msg->linear.x;
	      cout<<"callback_keyboard: "<<linear_vel<<endl;
	      //angular_vel= msg->angular.z;
	      
	    }
	    void callback_control_nav(const geometry_msgs::msg::Twist::SharedPtr msg) 
	    {
	      //cmd_velrobot_msg.angular.z = msg->angular.z;
	      //cmd_keyboard_msg.angular.z=msg->angular.z;
	      angular_vel=msg->angular.z;
	      //cout<<"callback_control_nav"<<endl;
	      
	    }
	    
	    void callback_local_plan(const nav_msgs::msg::Path::SharedPtr msg) 
	    {
	      path_local=*msg;
	      flag_local_plan=1;
	      //cout << (path_local.poses[path_local.poses.size()].pose.position.x) << endl;
	      //cout << path_local.poses.size() << endl;
	    }
	    void callback_odom_filtered(const nav_msgs::msg::Odometry::SharedPtr msg)
	    {
	      odom_robot=*msg;
	    }
	    
	    void lane_controller()
	    {
	      int use_pose=path_local.poses.size()-1;
	      if(path_local.poses.size()>3){
	         use_pose=3;
	      }
	      cout<<path_local.poses.size()<<endl;
	      tf2::Quaternion q_goal(
	      		path_local.poses[use_pose].pose.orientation.x,
	      		path_local.poses[use_pose].pose.orientation.y,
	      		path_local.poses[use_pose].pose.orientation.z,
	      		path_local.poses[use_pose].pose.orientation.w);
	      tf2::Quaternion q_robot(
	      		odom_robot.pose.pose.orientation.x,
	      		odom_robot.pose.pose.orientation.y,
	      		odom_robot.pose.pose.orientation.z,
	      		odom_robot.pose.pose.orientation.w);
	      		
	      float yaw_error= (float)calculate_yaw_error(q_goal,q_robot);
	      
	      
	      rclcpp::Time time_now = this->get_clock()->now();
	      rclcpp::Duration t_spent = time_now -ant_time;
	      float time_spent= (float)t_spent.seconds();
	      cout<< "Time controller:"<<time_spent<<endl;
	              
	      error_p=yaw_error;
		      
	      error_actual=error_p;
		      
	      error_d=(error_actual-error_ant)/time_spent;
		      
	      error_i=error_i+(error_actual*time_spent);
		      
	      float Kp=3.0;
	      float Kd=0.0;
	      float Ki=0.3;
		      
	      cout<< "kp*error_p: "<<Kp*error_p<<"kd*error_d: "<<Kd*error_d<<"ki*error_i: "<<Ki*error_i<<endl;
		      
	      float control_yaw=Kp*error_p+Kd*error_d+Ki*error_i;
		      
		      
	      if(control_yaw>max_angular_speed){
	      	control_yaw=max_angular_speed;
	      }
	      if(control_yaw<-max_angular_speed){
	      	control_yaw=-max_angular_speed;
	      }
		      
	      ant_time=time_now;
	      error_ant=error_actual;
	      //angular_vel=control_yaw;
	      
	      //Actualizacion del Control de orientacion 
	      //float kp_yaw=2.0;
	      //float control_yaw=kp_yaw*yaw_error;
	       cout << "yaw_error: "<<yaw_error << " Control_angular: "<<control_yaw << endl;
	       
	      //angular_vel=control_yaw;
	      
	      if(stop_condition==0)
	      {
	      	cmd_velrobot_msg.linear.x=linear_vel;
	      	cmd_velrobot_msg.angular.z=angular_vel;
	      }else{
	      	cmd_velrobot_msg.linear.x=0;
	      	cmd_velrobot_msg.angular.z=0;
	      }
	      publisher_cmd_vel->publish(cmd_velrobot_msg);
	    }
	    
	    double calculate_yaw_error(tf2::Quaternion q_goal, tf2::Quaternion q_robot)
	    {
	      tf2::Quaternion q_error;
	      q_error = q_goal * q_robot.inverse();
	      q_error.normalize();
	      tf2::Matrix3x3 m(q_error);
	      double roll, pitch, yaw;
	      m.getRPY(roll, pitch, yaw);
	      return yaw;	    
	    }
	    
	    void loop()
	    {
	      //while (1)
	      //{
		      
		      
		      
		      if(flag_local_plan==1){
		      		lane_controller();
		      }
		      
		      //cout<<"Angle goal: "<<angle_goal<<" yaw_robot: "<<yaw_robot*(180/3.14159)<<" yaw_error: "<<yaw_error*(180/3.14159)<<endl;
	      	      
		      
		      //cout << size(path_local.poses) << endl;
		      //cout << path_local.poses[1].pose.position.x << endl;
		      
	      //}
	        
	    }
	    
	    
	    float angle_goal;
	    float stop_condition;
	    float linear_vel, angular_vel;
	    float error_p,error_actual, error_ant,error_d, error_i;
	    rclcpp::Time ant_time = this->get_clock()->now();
  	    float max_angular_speed=10.0;
	    


};

int main(int argc, char * argv[])
{
  init(argc, argv);
  spin(std::make_shared<generic>());
  shutdown();
  return 0;
}
