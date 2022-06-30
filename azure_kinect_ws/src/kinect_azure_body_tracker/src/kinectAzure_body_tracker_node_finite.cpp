// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <k4a/k4a.h>
#include <k4arecord/record.h>
#include <k4abt.h>

#include <chrono>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "rclcpp/time.hpp"
#include "body_tracker_msgs/msg/hip_coordinates.hpp"
#include "body_tracker_msgs/msg/skeleton.hpp"
#include "body_tracker_msgs/msg/spine_bottom.hpp"

#define ruta 		"/home/robogait/pruebas_grabaciones/kinectRecordings/output_test_recording.mkv"
#define recordedFPS	100

using namespace std::chrono_literals;

class MinimalPublisher : public rclcpp::Node
{
public:
	rclcpp::TimerBase::SharedPtr timer_;
	rclcpp::Publisher<body_tracker_msgs::msg::SpineBottom>::SharedPtr publisher_;
      	
	//Metodos
	MinimalPublisher()
	: Node("kinect_azure_body_tracker_node_plus_recording_simplified")
	{
		Init();
		publisher_ = this->create_publisher<body_tracker_msgs::msg::SpineBottom>("body_tracker_plus_recording_simplified", 10);
		Run();
		close();
	}
	
	void Run(){	
		t_inicial = rclcpp::Clock().now().nanoseconds();
		while (rclcpp::ok() && counter < recordedFPS){
			
			body_tracking();
		}
	}
	
	void body_tracking()
	{	
		// ---------------------- Aqui viene el desarrollo del nodo para coger el body tracking --------------------------------
		get_capture_result = k4a_device_get_capture(device, &sensor_capture, K4A_WAIT_INFINITE);
		if (get_capture_result == K4A_WAIT_RESULT_SUCCEEDED)
		{
		    k4abt_tracker_enqueue_capture(tracker, sensor_capture, K4A_WAIT_INFINITE);
		    
	k4a_record_write_capture(recording_handle, sensor_capture);
		    k4a_capture_release(sensor_capture);
		    /*
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
		    */

		    k4abt_frame_t body_frame = NULL;
		    k4a_wait_result_t pop_frame_result = k4abt_tracker_pop_result(tracker, &body_frame, K4A_WAIT_INFINITE);
		    if (pop_frame_result == K4A_WAIT_RESULT_SUCCEEDED)
		    {
		        //printf("Time spent for this frame: %f s\n", time_spent);
		        
		        num_bodies = k4abt_frame_get_num_bodies(body_frame);
		        //printf("%u bodies are detected!\n", num_bodies);

			k4abt_frame_get_body_skeleton(body_frame, 0, &body.skeleton);
			body.id = k4abt_frame_get_body_id(body_frame, 0);
			/*
		        for (uint32_t i = 0; i < num_bodies; i++)
		        {
		            if(k4abt_frame_get_body_skeleton(body_frame, i, &body.skeleton) != K4A_RESULT_SUCCEEDED){
			    	printf("Get body from body frame failed!\n");
			    	exit(1);
			    }
		            body.id = k4abt_frame_get_body_id(body_frame, i);
		            //print_body_information(body);
		        }
		        */

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
		//Create message
		auto pelvis_data = body_tracker_msgs::msg::SpineBottom();		

		//Assign: body_id
		pelvis_data.body_id= num_bodies;

		//Assign: tiempo
		t_now = rclcpp::Clock().now().nanoseconds();
		elapsed_time = (t_now - t_inicial)* pow(10, -9);
		printf("Han transcurrido %.02f secs\n", elapsed_time);
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
		// -----------------------------------------------------------------------------
		
		//Check FPS
		counter++;
		total_frames++;
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
	/*
	int getch()
	{
		static struct termios oldt, newt;
		tcgetattr( STDIN_FILENO, &oldt);           // save old settings
		newt = oldt;
		newt.c_lflag &= ~(ICANON);                 // disable buffering      
		tcsetattr( STDIN_FILENO, TCSANOW, &newt);  // apply new settings

		int c = getchar();  // read character (non-blocking)

		tcsetattr( STDIN_FILENO, TCSANOW, &oldt);  // restore old settings
		return c;
	}
	*/
	void Init(){
		//Inicializar la Kinect
	  	device_config = K4A_DEVICE_CONFIG_INIT_DISABLE_ALL;
	  	device_config.camera_fps = K4A_FRAMES_PER_SECOND_30;
	    	device_config.depth_mode = K4A_DEPTH_MODE_NFOV_UNBINNED;
	    	device_config.color_resolution = K4A_COLOR_RESOLUTION_720P;
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
		
		if(k4a_record_create(ruta, device, device_config, &recording_handle) != K4A_RESULT_SUCCEEDED){
			printf("Recording initialization failed!\n");
			exit(1);
		}
		else{
			k4a_record_write_header(recording_handle);
			printf("\tEmpezamos a grabar en el archivo %s\n",ruta);
		}
		counter = 0;
		total_frames = 0;
	}
	
	void close(){
		//k4a_capture_release(sensor_capture);
		
		k4abt_tracker_shutdown(tracker);
		k4abt_tracker_destroy(tracker);
		k4a_device_stop_cameras(device);
		k4a_record_close(recording_handle);
		k4a_device_close(device);
		printf("Finished body tracking processing!\n");
		printf("Total frames recorded = %d\n", total_frames);
		printf("Recording time spent = %.02f\n", elapsed_time);
		FPS = total_frames / elapsed_time;
		printf("Total FPS = %0.2f\n", FPS);
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
	rclcpp::Clock clock;
	rclcpp::Time time;
	k4a_record_t recording_handle;
		
	double t_inicial, t_now;
	double elapsed_time;
	int counter, total_frames;
	double FPS;
	int inicio;
};


int main(int argc, char * argv[])
{
  	//Inicializar el nodo
	rclcpp::init(argc, argv); 	
  
  	//Declaración y desarrollo del publisher
	rclcpp::spin(std::make_shared<MinimalPublisher>());

	//Cerrar nodo
	rclcpp::shutdown();	//AJRS: A ver cómo cerramos esto bien...

	return 0;
}
