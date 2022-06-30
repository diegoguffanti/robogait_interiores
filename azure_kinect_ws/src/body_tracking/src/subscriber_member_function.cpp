#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "body_tracking/msg/hip_coordinates.hpp"
#include "std_msgs/msg/float64.hpp"

using std::placeholders::_1;

class MinimalSubscriber : public rclcpp::Node
{
public:
  MinimalSubscriber()
  : Node("minimal_subscriber")
  {
    subscription_ = this->create_subscription<body_tracking::msg::HipCoordinates>(
      "topic", 10, std::bind(&MinimalSubscriber::topic_callback, this, _1));
  }

private:
  void topic_callback(const body_tracking::msg::HipCoordinates::SharedPtr msg) const
  {
    RCLCPP_INFO(this->get_logger(), "I heard hip coordinates: x->'%f' ; y->'%f' ; z->'%f'", msg->x, msg->y, msg->z);
    //RCLCPP_INFO(this->get_logger(), "I heard hip coordinates: x->'%f'", msg->x);
  }
  rclcpp::Subscription<body_tracking::msg::HipCoordinates>::SharedPtr subscription_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalSubscriber>());
  rclcpp::shutdown();
  return 0;
}
