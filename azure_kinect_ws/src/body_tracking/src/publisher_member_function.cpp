#include <chrono>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "body_tracking/msg/hip_coordinates.hpp"
#include "std_msgs/msg/float64.hpp"

using namespace std::chrono_literals;

class MinimalPublisher : public rclcpp::Node
{
public:
  MinimalPublisher()
  : Node("minimal_publisher")//, count_(0)
  {
    publisher_ = this->create_publisher<body_tracking::msg::HipCoordinates>("topic", 10);
    timer_ = this->create_wall_timer(
      500ms, std::bind(&MinimalPublisher::timer_callback, this));
  }

private:
  void timer_callback()
  {
    auto message = body_tracking::msg::HipCoordinates();
    message.x = 1;
    message.y = 1;
    message.z = 1;
    RCLCPP_INFO(this->get_logger(), "Publishing hip coordinates: x->'%f' ; y->'%f' ; z->'%f'", message.x, message.y, message.z);
    //RCLCPP_INFO(this->get_logger(), "Publishing hip coordinates: x->'%f'", message.x);
    publisher_->publish(message);
  }
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<body_tracking::msg::HipCoordinates>::SharedPtr publisher_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalPublisher>());
  rclcpp::shutdown();
  return 0;
}
