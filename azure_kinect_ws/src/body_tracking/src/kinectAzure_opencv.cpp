// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <k4a/k4a.h>
#include <k4abt.h>

#include <chrono>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "body_tracking/msg/hip_coordinates.hpp"
#include "body_tracking/msg/skeleton.hpp"
#include "std_msgs/msg/float64.hpp"

using namespace std::chrono_literals;

class MinimalPublisher : public rclcpp::Node
{
public:
	rclcpp::TimerBase::SharedPtr timer_;
	rclcpp::Publisher<body_tracking::msg::Skeleton>::SharedPtr publisher_;
      	
	//Metodos
	MinimalPublisher()
	: Node("body_tracker")//"body_tracking_node"
	{
		Init();
		publisher_ = this->create_publisher<body_tracking::msg::Skeleton>("body_tracking", 10);
		Run();
		close();
	}
	
	void Run(){
		while (rclcpp::ok()){
			RCLCPP_INFO(this->get_logger(), "Waiting for person to be detected...");
			body_tracking();
		}
	}
	
	void body_tracking()
	{
		// ---------------------- Aqui viene el desarrollo del nodo para usar el opencv --------------------------------
		
		k4a_image_t depthImage = k4a_capture_get_depth_image(capture); // get image metadata
		
		if (depthImage != NULL)
		{
		    // you can check the format with this function
		    k4a_image_format_t format = k4a_image_get_format(depthImage); // K4A_IMAGE_FORMAT_DEPTH16 

		    // get raw buffer
		    uint8_t* buffer = k4a_image_get_buffer(depthImage);

		    // convert the raw buffer to cv::Mat
		    int rows = k4a_image_get_height_pixels(depthImage);
		    int cols = k4a_image_get_width_pixels(depthImage);
		    cv::Mat depthMap(rows, cols, CV_16U, (void*)buffer, cv::Mat::AUTO_STEP);

		    // ...

		    k4a_image_release(depthImage);
		}
		
		
		
		publisher_->publish(skeleton_data);
  	}
	
	void Init(){
		//Inicializar la Kinect
	  	device_config = K4A_DEVICE_CONFIG_INIT_DISABLE_ALL;
	  	config.camera_fps = K4A_FRAMES_PER_SECOND_30;
		config.color_format = K4A_IMAGE_FORMAT_COLOR_BGRA32; // <==== For Color image
		config.color_resolution = K4A_COLOR_RESOLUTION_720P;
		config.depth_mode = K4A_DEPTH_MODE_NFOV_UNBINNED; // <==== For Depth image
		
	    	device_config.depth_mode = K4A_DEPTH_MODE_NFOV_UNBINNED;	    	
		if(k4a_device_open(0, &device) != K4A_RESULT_SUCCEEDED){
			printf("Open K4A Device failed!\n");
			exit(1);
		}
		if(k4a_device_start_cameras(device, &device_config) != K4A_RESULT_SUCCEEDED){
			printf("Start K4A cameras failed!\n");
			exit(1);
		}		
		if(k4a_device_get_calibration(device, device_config.depth_mode, K4A_COLOR_RESOLUTION_OFF, &sensor_calibration) != K4A_RESULT_SUCCEEDED){
			printf("Get depth camera calibration failed!\n");
			exit(1);
		}
	}
	
	void close(){
		k4abt_tracker_shutdown(tracker);
		k4abt_tracker_destroy(tracker);
		k4a_device_stop_cameras(device);
		k4a_device_close(device);
		printf("Finished body tracking processing!\n");
	}
	
	//Variables:
	k4a_device_configuration_t device_config;
	k4a_capture_t sensor_capture;
	k4a_device_t device;
	k4a_calibration_t sensor_calibration;
	k4abt_tracker_t tracker;
	k4abt_tracker_configuration_t tracker_config;	
	k4a_wait_result_t get_capture_result;
	k4abt_body_t body;
	uint32_t num_bodies;
};


int main(int argc, char * argv[])
{
  	//Inicializar el nodo
	rclcpp::init(argc, argv); 	
  
  	//Declaración y desarrollo del publisher
	rclcpp::spin(std::make_shared<MinimalPublisher>());

	//Cerrar nodo
	rclcpp::shutdown();

	return 0;
}
