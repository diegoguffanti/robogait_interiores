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
#include "std_msgs/msg/float32.hpp"
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
Publisher<std_msgs::msg::Float32>::SharedPtr publisher_cmd_camera;
Subscription<std_msgs::msg::Float32>::SharedPtr subscription_camera_position;
Subscription<body_tracker_msgs::msg::SpineBottom>::SharedPtr subscription_spine_bottom;


TimerBase::SharedPtr timer_;
thread pub;

//Contructor del nodo------------------------------------------------------------------
public:
	generic() : Node("camera_controller")
	    {
		
		subscription_camera_position= this->create_subscription<std_msgs::msg::Float32>("camera_position",10, std::bind(&generic::callback_camera_position, this, _1));
		publisher_cmd_camera = this->create_publisher<std_msgs::msg::Float32>("cmd_camera", 10);
		subscription_spine_bottom = this->create_subscription<body_tracker_msgs::msg::SpineBottom>("body_tracker_simplified", 10, bind(&generic::topic_callback_spine_bottom, this, _1));
		
		
		timer_ = this->create_wall_timer(5ms, std::bind(&generic::controller, this));
		//This timer is for controlling the ros_rate, comment for maximum rate but add a while(1){ } in the loop() function
		pub = thread(&generic::controller, this);
		
	    }
    
//Funciones miembro------------------------------------------------------------------
private:
	    
	    void callback_camera_position(const std_msgs::msg::Float32::SharedPtr msg)
	    {
	        camera_position=msg->data;
	        //cout<<"camera_position"<<camera_position<<endl;
	        //controller();
	      
	    }
	    void topic_callback_spine_bottom(const body_tracker_msgs::msg::SpineBottom::SharedPtr msg)
  	    {
	      personz= msg->joint_position_spine_bottom.z/1000.0;
	      personx= msg->joint_position_spine_bottom.x/1000.0;
	      //personx=mean_filter(msg->joint_position_spine_bottom.x/1000.0);
	      if((personz>0) && (personz<4.0)){
	      	angle_person=atan(personx/personz);
	        cout<< "Person detected at: "<<"x: "<<personx<<"z: "<<personz<<"Angle:"<<angle_person*(180/M_PI)<<endl;
	        
	      }
	      
	      
	      
  	    }
  	    void controller()
  	    {
  	                    
		      
		      if((fabs(personx)>0.3) && (fabs(personx)<0.5)){
		      
		      if(personx>0){
		      control=control-(0.08*(M_PI/180));
		      }else{
		      control=control+(0.08*(M_PI/180));
		      }
		      }
		      
		      if((fabs(personx)>=0.5) && (fabs(personx)<=1.0)){
		      if(personx>0){
		      control=control-(0.15*(M_PI/180));
		      }else{
		      control=control+(0.15*(M_PI/180));
		      }
		      }
		      
		      
		      if(control>M_PI/2){
		      	control=M_PI/2;
		      }
		      if(control<-M_PI/2){
		      	control=-M_PI/2;
		      }
		      camera_msg.data=control;
		      publisher_cmd_camera->publish(camera_msg);
		      
		
  	    }
  	    
  	    
  	      
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
  	    
  	    float array[2];
  	    float angle_person;
  	    float camera_position;
  	    float control, personz, personx;
  	    std_msgs::msg::Float32 camera_msg;

};

int main(int argc, char * argv[])
{
  init(argc, argv);
  spin(std::make_shared<generic>());
  shutdown();
  return 0;
}
