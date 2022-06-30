#include <geometry_msgs/msg/transform_stamped.hpp>

#include <rclcpp/rclcpp.hpp>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2_ros/transform_broadcaster.h>
#include <turtlesim/msg/pose.hpp>
#include <turtlesim/msg/pose.hpp>
#include <nav_msgs/msg/odometry.hpp>
#include "body_tracker_msgs/msg/spine_bottom.hpp"

#include <memory>
#include <string>

using std::placeholders::_1;

class FramePublisher : public rclcpp::Node
{
public:
  FramePublisher() : Node("tf2_broadcaster_person")
  {
    // Declare and acquire `turtlename` parameter
    /*this->declare_parameter<std::string>("turtlename", "turtle");
    this->get_parameter("turtlename", turtlename_);*/

    // Initialize the transform broadcaster
    tf_broadcaster_ =
      std::make_unique<tf2_ros::TransformBroadcaster>(*this);

    // Subscribe to a /pose topic and call handle_robot_pose callback function on each message
     subscription_spine_bottom = this->create_subscription<body_tracker_msgs::msg::SpineBottom>("body_tracker_simplified", 10, bind(&FramePublisher::handle_person_pose, this,_1));     
  }

private:
  void handle_person_pose(const std::shared_ptr<body_tracker_msgs::msg::SpineBottom> msg)
  {
    float dist=(msg->joint_position_spine_bottom.z)/1000.0;
    if(dist<4){
    
    rclcpp::Time now = this->get_clock()->now();
    geometry_msgs::msg::TransformStamped t;

    // Read message content and assign it to
    // corresponding tf variables
    t.header.stamp = now;
    t.header.frame_id = "camera_link";
    t.child_frame_id = "person_link";

    // Turtle only exists in 2D, thus we get x and y translation
    // coordinates from the message and set the z coordinate to 0
    
    t.transform.translation.x = (msg->joint_position_spine_bottom.z)/1000.0;
    t.transform.translation.y = -(msg->joint_position_spine_bottom.x)/1000.0;
    t.transform.translation.z = 0.0;
    

    // For the same reason, turtle can only rotate around one axis
    // and this why we set rotation in x and y to 0 and obtain
    // rotation in z axis from the message
    
    //t.transform.rotation.x = msg->pose.pose.orientation.x;
    //t.transform.rotation.y = msg->pose.pose.orientation.y;
    //t.transform.rotation.z = msg->pose.pose.orientation.z;
    //t.transform.rotation.w = msg->pose.pose.orientation.w;

    // Send the transformation
    tf_broadcaster_->sendTransform(t);
    }
  }
  rclcpp::Subscription<body_tracker_msgs::msg::SpineBottom>::SharedPtr subscription_spine_bottom;
  std::unique_ptr<tf2_ros::TransformBroadcaster> tf_broadcaster_;
  std::string turtlename_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<FramePublisher>());
  rclcpp::shutdown();
  return 0;
}
