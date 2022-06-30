#include <geometry_msgs/msg/transform_stamped.hpp>

#include <rclcpp/rclcpp.hpp>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2_ros/transform_broadcaster.h>
#include <turtlesim/msg/pose.hpp>
#include <nav_msgs/msg/odometry.hpp>
#include <std_msgs/msg/float32.hpp>

#include <memory>
#include <string>

//Math

using std::placeholders::_1;

class FramePublisher : public rclcpp::Node
{
public:
  FramePublisher() : Node("tf2_frame_publisher_camera")
  {
    // Declare and acquire `turtlename` parameter
    /*this->declare_parameter<std::string>("turtlename", "turtle");
    this->get_parameter("turtlename", turtlename_);*/

    // Initialize the transform broadcaster
    tf_broadcaster_ =
      std::make_unique<tf2_ros::TransformBroadcaster>(*this);

    // Subscribe to a /pose topic and call handle_robot_pose callback function on each message
     subscription_ = this->create_subscription<std_msgs::msg::Float32>("/camera_position", 10,std::bind(&FramePublisher::handle_camera_pose, this, _1));
  }

private:
  void handle_camera_pose(const std::shared_ptr<std_msgs::msg::Float32> msg)
  {
    rclcpp::Time now = this->get_clock()->now();
    geometry_msgs::msg::TransformStamped t;

    // Read message content and assign it to
    // corresponding tf variables
    t.header.stamp = now;
    t.header.frame_id = "base_footprint";
    t.child_frame_id = "camera_link";

    // Turtle only exists in 2D, thus we get x and y translation
    // coordinates from the message and set the z coordinate to 0
    t.transform.translation.x = 0.0;
    t.transform.translation.y = 0.0;
    t.transform.translation.z = 0.35;

    // For the same reason, turtle can only rotate around one axis
    // and this why we set rotation in x and y to 0 and obtain
    // rotation in z axis from the message
    
    tf2::Quaternion q_camera;
    float camera_yaw=msg->data;
    q_camera.setRPY( 0, 0, camera_yaw+M_PI); 
    
    t.transform.rotation.x = q_camera.getX();
    t.transform.rotation.y = q_camera.getY();
    t.transform.rotation.z = q_camera.getZ();
    t.transform.rotation.w = q_camera.getW();

    // Send the transformation
    tf_broadcaster_->sendTransform(t);
  }
  rclcpp::Subscription<std_msgs::msg::Float32>::SharedPtr subscription_;
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
