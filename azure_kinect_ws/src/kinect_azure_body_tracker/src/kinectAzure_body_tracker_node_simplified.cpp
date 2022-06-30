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
#include "body_tracker_msgs/msg/hip_coordinates.hpp"
#include "body_tracker_msgs/msg/skeleton.hpp"
#include "body_tracker_msgs/msg/spine_bottom.hpp"

using namespace std::chrono_literals;

class MinimalPublisher : public rclcpp::Node
{
public:
	rclcpp::TimerBase::SharedPtr timer_;
	rclcpp::Publisher<body_tracker_msgs::msg::SpineBottom>::SharedPtr publisher_;
      	
	//Metodos
	MinimalPublisher() : Node("kinect_azure_body_tracker_node_simplified")
	{
		Init();
		publisher_ = this->create_publisher<body_tracker_msgs::msg::SpineBottom>("body_tracker_simplified", 10);
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
		// ---------------------- Getting pelvis coordinates and message variables --------------------------------
		//Capturing image
		get_capture_result = k4a_device_get_capture(device, &sensor_capture, K4A_WAIT_INFINITE);
		if (get_capture_result == K4A_WAIT_RESULT_SUCCEEDED)
		{
			//Processing to obtain frame from capture
			k4a_wait_result_t queue_capture_result = k4abt_tracker_enqueue_capture(tracker, sensor_capture, K4A_WAIT_INFINITE);

			k4a_capture_release(sensor_capture);
			if (queue_capture_result == K4A_WAIT_RESULT_TIMEOUT)
			{
				// It should never hit timeout when K4A_WAIT_INFINITE is set.
				printf("Error! Add capture to tracker process queue timeout!\n");
				return;
			}
			else if (queue_capture_result == K4A_WAIT_RESULT_FAILED)
			{
				printf("Error! Add capture to tracker process queue failed!\n");
				return;
			}

			k4abt_frame_t body_frame = NULL;
			k4a_wait_result_t pop_frame_result = k4abt_tracker_pop_result(tracker, &body_frame, K4A_WAIT_INFINITE);
			if (pop_frame_result == K4A_WAIT_RESULT_SUCCEEDED)
			{
				//Obtaining body tracking parameters from frame
				num_bodies = k4abt_frame_get_num_bodies(body_frame);
				if(num_bodies == 1)
					printf("1 body detected!\n");
				else if(num_bodies == 0)
					printf("No bodies have been detected!\n");
				else
					printf("%u bodies are detected!\n", num_bodies);				

				for (uint32_t i = 0; i < num_bodies; i++)
				{
					if(k4abt_frame_get_body_skeleton(body_frame, i, &body.skeleton) != K4A_RESULT_SUCCEEDED){
						printf("Get body from body frame failed!\n");
						exit(1);
					}
					body.id = k4abt_frame_get_body_id(body_frame, i);
				}

				k4a_image_t body_index_map = k4abt_frame_get_body_index_map(body_frame);
				if (body_index_map != NULL)
				{
					k4a_image_release(body_index_map);
				}
				else
				{
					printf("Error: Fail to generate bodyindex map!\n");
				}
				
				//Releasing and closing capture/frame/body
				k4abt_frame_release(body_frame);
			}
			else if (pop_frame_result == K4A_WAIT_RESULT_TIMEOUT)
			{
				//  It should never hit timeout when K4A_WAIT_INFINITE is set.
				printf("Error! Pop body frame result timeout!\n");
				return;
			}
			else
			{
				printf("Pop body frame result failed!\n");
				return;
			}
		}
		else if (get_capture_result == K4A_WAIT_RESULT_TIMEOUT)
		{
			// It should never hit time out when K4A_WAIT_INFINITE is set.this->get_logger()
			printf("Error! Get depth frame time out!\n");
			return;
		}
		else
		{
			printf("Get depth capture returned error: %d\n", get_capture_result);
			return;
		}

		// ---------------------- Building the message --------------------------------
		//Create message
		auto pelvis_data = body_tracker_msgs::msg::SpineBottom();		

		//Assign: body_id
		pelvis_data.body_id= num_bodies;

		//Assign: tiempo
		t_final = rclcpp::Clock().now().nanoseconds();
		elapsed_time = t_final - t_inicial;
		printf("Han transcurrido %.02f secs\n", elapsed_time * pow(10, -9));
		pelvis_data.tiempo = elapsed_time;

		//Assign: pelvis coordinates
		k4a_float3_t position;
		position = body.skeleton.joints[0].position;		
		pelvis_data.joint_position_spine_bottom.x = position.v[0];
		pelvis_data.joint_position_spine_bottom.y = position.v[1];
		pelvis_data.joint_position_spine_bottom.z = position.v[2];
		
		//Publishing
		RCLCPP_INFO(this->get_logger(), "Publishing pelvis coordinates: x->'%f' ; y->'%f' ; z->'%f'", pelvis_data.joint_position_spine_bottom.x, pelvis_data.joint_position_spine_bottom.y, pelvis_data.joint_position_spine_bottom.z);
		publisher_->publish(pelvis_data);
	}
	
	void Init(){
		//Initialice counting time
		t_inicial = rclcpp::Clock().now().nanoseconds();
		
		//Initialice Kinect
	  	device_config = K4A_DEVICE_CONFIG_INIT_DISABLE_ALL;
	  	device_config.camera_fps = K4A_FRAMES_PER_SECOND_30;
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
		tracker = NULL;
		tracker_config = K4ABT_TRACKER_CONFIG_DEFAULT;
		tracker_config.processing_mode = K4ABT_TRACKER_PROCESSING_MODE_CPU;
		if(k4abt_tracker_create(&sensor_calibration, tracker_config, &tracker) != K4A_RESULT_SUCCEEDED){
			printf("Body tracker initialization failed!\n");
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
	
	//double t_inicial, t_final;
	double t_inicial, t_final;
	double elapsed_time;
};


int main(int argc, char * argv[])
{
  	//Initialice node
	rclcpp::init(argc, argv); 	
  
  	//Declare and launch publisher node
	rclcpp::spin(std::make_shared<MinimalPublisher>());

	//Close node
	rclcpp::shutdown();

	return 0;
}
