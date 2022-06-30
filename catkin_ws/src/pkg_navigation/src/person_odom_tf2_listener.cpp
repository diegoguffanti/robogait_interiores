// Copyright 2021 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <chrono>
#include <memory>
#include <string>

#include <rclcpp/rclcpp.hpp>
#include <tf2/exceptions.h>
#include <tf2_ros/transform_listener.h>
#include <tf2_ros/buffer.h>
#include <geometry_msgs/msg/transform_stamped.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <nav_msgs/msg/odometry.hpp>


using std::placeholders::_1;
using namespace std::chrono_literals;



class FrameListener : public rclcpp::Node
{
public:
  FrameListener()  : Node("person_odom_tf2_listener")
  {
    // Declare and acquire `target_frame` parameter
    this->declare_parameter<std::string>("target_frame", "person_link");
    this->get_parameter("target_frame", target_frame_);

    tf_buffer_ = std::make_unique<tf2_ros::Buffer>(this->get_clock());
    transform_listener_ = std::make_shared<tf2_ros::TransformListener>(*tf_buffer_);

  
    publisher_robot_odom_filtered= this->create_publisher<nav_msgs::msg::Odometry>("/person_odom", 1);
    timer_ = this->create_wall_timer(10ms, std::bind(&FrameListener::on_timer, this));
  }

private:
  void on_timer()
  {
    // Store frame names in variables that will be used to
    // compute transformations
    std::string fromFrameRel = target_frame_.c_str();
    std::string toFrameRel = "map";
    geometry_msgs::msg::TransformStamped transformStamped;

        // Look up for the transformation between target_frame and reference_frame 
        try {
          transformStamped = tf_buffer_->lookupTransform(
            toFrameRel, fromFrameRel,
            tf2::TimePointZero);
        } catch (tf2::TransformException & ex) {
          RCLCPP_INFO(
            this->get_logger(), "Could not transform %s to %s: %s",
            toFrameRel.c_str(), fromFrameRel.c_str(), ex.what());
          return;
        }

        odom_msg.pose.pose.position.x=transformStamped.transform.translation.x;
        odom_msg.pose.pose.position.y=transformStamped.transform.translation.y;
        odom_msg.pose.pose.position.z=transformStamped.transform.translation.z;
        odom_msg.pose.pose.orientation.x=transformStamped.transform.rotation.x;
        odom_msg.pose.pose.orientation.y=transformStamped.transform.rotation.y;
        odom_msg.pose.pose.orientation.z=transformStamped.transform.rotation.z;
        odom_msg.pose.pose.orientation.w=transformStamped.transform.rotation.w;
        
        publisher_robot_odom_filtered->publish(odom_msg);
      
    
  }
  
 
  nav_msgs::msg::Odometry odom_msg;
  rclcpp::TimerBase::SharedPtr timer_{nullptr};
  rclcpp::Publisher<nav_msgs::msg::Odometry>::SharedPtr publisher_robot_odom_filtered{nullptr};
  std::shared_ptr<tf2_ros::TransformListener> transform_listener_{nullptr};
  std::unique_ptr<tf2_ros::Buffer> tf_buffer_;
  std::string target_frame_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<FrameListener>());
  rclcpp::shutdown();
  return 0;
}
