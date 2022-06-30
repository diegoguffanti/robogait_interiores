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

using namespace std::chrono_literals;

class MinimalPublisher : public rclcpp::Node
{
public:
	rclcpp::TimerBase::SharedPtr timer_;
	rclcpp::Publisher<body_tracker_msgs::msg::Skeleton>::SharedPtr publisher_;
      	
	//Metodos
	MinimalPublisher()
	: Node("kinect_azure_body_tracker_node")
	{
		Init();
		publisher_ = this->create_publisher<body_tracker_msgs::msg::Skeleton>("kinect_azure_body_tracker_node", 10);
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
		// ---------------------- Aqui viene el desarrollo del nodo para coger el body tracking --------------------------------
		get_capture_result = k4a_device_get_capture(device, &sensor_capture, K4A_WAIT_INFINITE);
		if (get_capture_result == K4A_WAIT_RESULT_SUCCEEDED)
		{
		    //clock_t begin_clock = clock();

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
		        //clock_t end_clock = clock();
		        //double time_spent = (double)(end_clock - begin_clock) / CLOCKS_PER_SEC;

		        //printf("Time spent for this frame: %f s\n", time_spent);

		        num_bodies = k4abt_frame_get_num_bodies(body_frame);
		        //printf("%u bodies are detected!\n", num_bodies);
		        
		        //Voy por aquí
		        //t_muestra = t_muestra.now();

		        for (uint32_t i = 0; i < num_bodies; i++)
		        {
		            if(k4abt_frame_get_body_skeleton(body_frame, i, &body.skeleton) != K4A_RESULT_SUCCEEDED){
			    	printf("Get body from body frame failed!\n");
			    	exit(1);
			    }
		            body.id = k4abt_frame_get_body_id(body_frame, i);
		            //print_body_information(body);
		        }

		        k4a_image_t body_index_map = k4abt_frame_get_body_index_map(body_frame);
		        if (body_index_map != NULL)
		        {
		            //print_body_index_map_middle_line(body_index_map);
		            k4a_image_release(body_index_map);
		        }
		        else
		        {
		            printf("Error: Fail to generate bodyindex map!\n");
		        }

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
		//auto message = body_tracking::msg::HipCoordinates();
		//k4a_float3_t position = body.skeleton.joints[coordenadaCadera].position;
	      	//message.x = position.v[0];
		//message.y = position.v[1];
		//message.z = position.v[2];
		
		auto skeleton_data = body_tracker_msgs::msg::Skeleton();		
		
		//body_id
		skeleton_data.body_id= num_bodies;
		
		//tiempo
		//Voy por aquí
		//skeleton_data.tiempo = t_muestra - t_inicial;

		k4a_float3_t position[18];
		for(int i=0;i<18;i++){
			if(i == 0){	//Head
				position[i] = body.skeleton.joints[27].position;
				skeleton_data.joint_position_head.x = position[i].v[0];
				skeleton_data.joint_position_head.y = position[i].v[1];
				skeleton_data.joint_position_head.z = position[i].v[2];
			}
			else if (i == 1){
				position[i] = body.skeleton.joints[26].position;
				skeleton_data.joint_position_neck.x = position[i].v[0];
				skeleton_data.joint_position_neck.y = position[i].v[1];
				skeleton_data.joint_position_neck.z = position[i].v[2];
			}
			else if (i == 2){
				position[i].v[0] = (body.skeleton.joints[4].position.xyz.x + body.skeleton.joints[11].position.xyz.x) / 2;
				position[i].v[1] = (body.skeleton.joints[4].position.xyz.y + body.skeleton.joints[11].position.xyz.y) / 2;
				position[i].v[2] = (body.skeleton.joints[4].position.xyz.z + body.skeleton.joints[11].position.xyz.z) / 2;			
				skeleton_data.joint_position_shoulder.x = position[i].v[0];
				skeleton_data.joint_position_shoulder.y = position[i].v[1];
				skeleton_data.joint_position_shoulder.z = position[i].v[2];
			}
			else if (i == 3){
				position[i] = body.skeleton.joints[3].position;
				skeleton_data.joint_position_spine_top.x = position[i].v[0];
				skeleton_data.joint_position_spine_top.y = position[i].v[1];
				skeleton_data.joint_position_spine_top.z = position[i].v[2];
			}
			else if (i == 4){
				position[i] = body.skeleton.joints[1].position;
				skeleton_data.joint_position_spine_mid.x = position[i].v[0];
				skeleton_data.joint_position_spine_mid.y = position[i].v[1];
				skeleton_data.joint_position_spine_mid.z = position[i].v[2];
			}
			else if (i == 5){
				position[i] = body.skeleton.joints[0].position;
				skeleton_data.joint_position_spine_bottom.x = position[i].v[0];
				skeleton_data.joint_position_spine_bottom.y = position[i].v[1];
				skeleton_data.joint_position_spine_bottom.z = position[i].v[2];
			}
			else if (i == 6){
				position[i] = body.skeleton.joints[5].position;
				skeleton_data.joint_position_left_shoulder.x = position[i].v[0];
				skeleton_data.joint_position_left_shoulder.y = position[i].v[1];
				skeleton_data.joint_position_left_shoulder.z = position[i].v[2];
			}
			else if (i == 7){
				position[i] = body.skeleton.joints[6].position;
				skeleton_data.joint_position_left_elbow.x = position[i].v[0];
				skeleton_data.joint_position_left_elbow.y = position[i].v[1];
				skeleton_data.joint_position_left_elbow.z = position[i].v[2];
			}
			else if (i == 8){
				position[i] = body.skeleton.joints[8].position;
				skeleton_data.joint_position_left_hand.x = position[i].v[0];
				skeleton_data.joint_position_left_hand.y = position[i].v[1];
				skeleton_data.joint_position_left_hand.z = position[i].v[2];
			}
			else if (i == 9){
				position[i] = body.skeleton.joints[12].position;
				skeleton_data.joint_position_right_shoulder.x = position[i].v[0];
				skeleton_data.joint_position_right_shoulder.y = position[i].v[1];
				skeleton_data.joint_position_right_shoulder.z = position[i].v[2];
			}
			else if (i == 10){
				position[i] = body.skeleton.joints[13].position;
				skeleton_data.joint_position_right_elbow.x = position[i].v[0];
				skeleton_data.joint_position_right_elbow.y = position[i].v[1];
				skeleton_data.joint_position_right_elbow.z = position[i].v[2];
			}
			else if (i == 11){
				position[i] = body.skeleton.joints[15].position;
				skeleton_data.joint_position_right_hand.x = position[i].v[0];
				skeleton_data.joint_position_right_hand.y = position[i].v[1];
				skeleton_data.joint_position_right_hand.z = position[i].v[2];
			}
			else if (i == 12){
				position[i] = body.skeleton.joints[22].position;
				skeleton_data.joint_position_right_hip.x = position[i].v[0];
				skeleton_data.joint_position_right_hip.y = position[i].v[1];
				skeleton_data.joint_position_right_hip.z = position[i].v[2];
			}
			else if (i == 13){
				position[i] = body.skeleton.joints[23].position;
				skeleton_data.joint_position_right_knee.x = position[i].v[0];
				skeleton_data.joint_position_right_knee.y = position[i].v[1];
				skeleton_data.joint_position_right_knee.z = position[i].v[2];
			}
			else if (i == 14){
				position[i] = body.skeleton.joints[24].position;
				skeleton_data.joint_position_right_ankle.x = position[i].v[0];
				skeleton_data.joint_position_right_ankle.y = position[i].v[1];
				skeleton_data.joint_position_right_ankle.z = position[i].v[2];
			}
			else if (i == 15){
				position[i] = body.skeleton.joints[18].position;
				skeleton_data.joint_position_left_hip.x = position[i].v[0];
				skeleton_data.joint_position_left_hip.y = position[i].v[1];
				skeleton_data.joint_position_left_hip.z = position[i].v[2];
			}
			else if (i == 16){
				position[i] = body.skeleton.joints[19].position;
				skeleton_data.joint_position_left_knee.x = position[i].v[0];
				skeleton_data.joint_position_left_knee.y = position[i].v[1];
				skeleton_data.joint_position_left_knee.z = position[i].v[2];
			}
			else if (i == 17){
				position[i] = body.skeleton.joints[20].position;
				skeleton_data.joint_position_left_ankle.x = position[i].v[0];
				skeleton_data.joint_position_left_ankle.y = position[i].v[1];
				skeleton_data.joint_position_left_ankle.z = position[i].v[2];
			}
		}
		
		RCLCPP_INFO(this->get_logger(), "Publishing skeleton coordinates. Pelvis coodinates are: x->'%f' ; y->'%f' ; z->'%f'", skeleton_data.joint_position_spine_bottom.x, skeleton_data.joint_position_spine_bottom.y, skeleton_data.joint_position_spine_bottom.z);
		publisher_->publish(skeleton_data);
  	}
  	
  	void print_body_information(k4abt_body_t body)
	{
	    printf("Body ID: %u\n", body.id);
	    for (int i = 0; i < (int)K4ABT_JOINT_COUNT; i++)
	    {
		k4a_float3_t position = body.skeleton.joints[i].position;
		k4a_quaternion_t orientation = body.skeleton.joints[i].orientation;
		k4abt_joint_confidence_level_t confidence_level = body.skeleton.joints[i].confidence_level;
		printf("Joint[%d]: Position[mm] ( %f, %f, %f ); Orientation ( %f, %f, %f, %f); Confidence Level (%d) \n",
		    i, position.v[0], position.v[1], position.v[2], orientation.v[0], orientation.v[1], orientation.v[2], orientation.v[3], confidence_level);
	    }
	}

	void print_body_index_map_middle_line(k4a_image_t body_index_map)
	{
	    uint8_t* body_index_map_buffer = k4a_image_get_buffer(body_index_map);

	    // Given body_index_map pixel type should be uint8, the stride_byte should be the same as width
	    // TODO: Since there is no API to query the byte-per-pixel information, we have to compare the width and stride to
	    // know the information. We should replace this assert with proper byte-per-pixel query once the API is provided by
	    // K4A SDK.
	    assert(k4a_image_get_stride_bytes(body_index_map) == k4a_image_get_width_pixels(body_index_map));

	    int middle_line_num = k4a_image_get_height_pixels(body_index_map) / 2;
	    body_index_map_buffer = body_index_map_buffer + middle_line_num * k4a_image_get_width_pixels(body_index_map);

	    printf("BodyIndexMap at Line %d:\n", middle_line_num);
	    for (int i = 0; i < k4a_image_get_width_pixels(body_index_map); i++)
	    {
		printf("%u, ", *body_index_map_buffer);
		body_index_map_buffer++;
	    }
	    printf("\n");
	}
	
	void Init(){
		//Voy por aquí
		//t_inicial = rclcpp::Clock::now();
		//Inicializar la Kinect
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
	//Voy por aquí
	//float t_inicial;
	//rclcpp::Clock t_muestra;
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
