// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <math.h>

#include <k4a/k4a.h>
#include <k4arecord/playback.h>
#include <k4abt.h>

using namespace std;

bool predict_joints(const char* myfile_name, int cabecera, k4abt_tracker_t tracker, k4a_capture_t capture_handle)
{
    k4a_wait_result_t queue_capture_result = k4abt_tracker_enqueue_capture(tracker, capture_handle, K4A_WAIT_INFINITE);
    if (queue_capture_result != K4A_WAIT_RESULT_SUCCEEDED)
    {
        cerr << "Error! Adding capture to tracker process queue failed!" << endl;
        return false;
    }

    k4abt_frame_t body_frame = nullptr;
    k4a_wait_result_t pop_frame_result = k4abt_tracker_pop_result(tracker, &body_frame, K4A_WAIT_INFINITE);
    if (pop_frame_result != K4A_WAIT_RESULT_SUCCEEDED)
    {
        cerr << "Error! Popping body tracking result failed!" << endl;
        return false;
    }

    float timestamp = k4abt_frame_get_device_timestamp_usec(body_frame);    

    std::ofstream myfile;
    myfile.open (myfile_name, std::ofstream::out | std::ofstream::app);
    if (cabecera == 0) {
	    myfile << "field.tiempo,field.joint_position_head.x,field.joint_position_head.y,field.joint_position_head.z,field.joint_position_neck.x,field.joint_position_neck.y,field.joint_position_neck.z,\
field.joint_position_shoulder.x,field.joint_position_shoulder.y,field.joint_position_shoulder.z,field.joint_position_spine_top.x,field.joint_position_spine_top.y,field.joint_position_spine_top.z,\
field.joint_position_spine_mid.x,field.joint_position_spine_mid.y,field.joint_position_spine_mid.z,field.joint_position_spine_bottom.x,field.joint_position_spine_bottom.y,field.joint_position_spine_bottom.z,\
field.joint_position_left_shoulder.x,field.joint_position_left_shoulder.y,field.joint_position_left_shoulder.z,field.joint_position_left_elbow.x,field.joint_position_left_elbow.y,field.joint_position_left_elbow.z,\
field.joint_position_left_hand.x,field.joint_position_left_hand.y,field.joint_position_left_hand.z,field.joint_position_right_shoulder.x,field.joint_position_right_shoulder.y,field.joint_position_right_shoulder.z,\
field.joint_position_right_elbow.x,field.joint_position_right_elbow.y,field.joint_position_right_elbow.z,field.joint_position_right_hand.x,field.joint_position_right_hand.y,field.joint_position_right_hand.z,\
field.joint_position_right_hip.x,field.joint_position_right_hip.y,field.joint_position_right_hip.z,field.joint_position_right_knee.x,field.joint_position_right_knee.y,field.joint_position_right_knee.z,\
field.joint_position_right_ankle.x,field.joint_position_right_ankle.y,field.joint_position_right_ankle.z,field.joint_position_left_hip.x,field.joint_position_left_hip.y,field.joint_position_left_hip.z,\
field.joint_position_left_knee.x,field.joint_position_left_knee.y,field.joint_position_left_knee.z,field.joint_position_left_ankle.x,field.joint_position_left_ankle.y,field.joint_position_left_ankle.z";
	    myfile << "\n";
	    cabecera++;
    }

    	k4abt_skeleton_t skeleton;
	k4abt_frame_get_body_skeleton(body_frame, 0, &skeleton);
	timestamp = timestamp * pow(10, -6);
	myfile << timestamp;

	//Para guardarlas en el orden que queremos hay que hacerlo de esta manera
	myfile << "," << skeleton.joints[27].position.xyz.x * (-1) << "," << skeleton.joints[27].position.xyz.y * (-1) << "," << skeleton.joints[27].position.xyz.z;
	myfile << "," << skeleton.joints[26].position.xyz.x * (-1) << "," << skeleton.joints[26].position.xyz.y * (-1) << "," << skeleton.joints[26].position.xyz.z;
	myfile << "," << skeleton.joints[4].position.xyz.x * (-1) << "," << skeleton.joints[4].position.xyz.y * (-1) << "," << skeleton.joints[4].position.xyz.z;
	myfile << "," << skeleton.joints[3].position.xyz.x * (-1) << "," << skeleton.joints[3].position.xyz.y * (-1) << "," << skeleton.joints[3].position.xyz.z;
	myfile << "," << skeleton.joints[1].position.xyz.x * (-1) << "," << skeleton.joints[1].position.xyz.y * (-1) << "," << skeleton.joints[1].position.xyz.z;
	myfile << "," << skeleton.joints[0].position.xyz.x * (-1) << "," << skeleton.joints[0].position.xyz.y * (-1) << "," << skeleton.joints[0].position.xyz.z;
	myfile << "," << skeleton.joints[5].position.xyz.x * (-1) << "," << skeleton.joints[5].position.xyz.y * (-1) << "," << skeleton.joints[5].position.xyz.z;
	myfile << "," << skeleton.joints[6].position.xyz.x * (-1) << "," << skeleton.joints[6].position.xyz.y * (-1) << "," << skeleton.joints[6].position.xyz.z;
	myfile << "," << skeleton.joints[8].position.xyz.x * (-1) << "," << skeleton.joints[8].position.xyz.y * (-1) << "," << skeleton.joints[8].position.xyz.z;
	myfile << "," << skeleton.joints[12].position.xyz.x * (-1) << "," << skeleton.joints[12].position.xyz.y * (-1) << "," << skeleton.joints[12].position.xyz.z;
	myfile << "," << skeleton.joints[13].position.xyz.x * (-1) << "," << skeleton.joints[13].position.xyz.y * (-1) << "," << skeleton.joints[13].position.xyz.z;
	myfile << "," << skeleton.joints[15].position.xyz.x * (-1) << "," << skeleton.joints[15].position.xyz.y * (-1) << "," << skeleton.joints[15].position.xyz.z;
	myfile << "," << skeleton.joints[22].position.xyz.x * (-1) << "," << skeleton.joints[22].position.xyz.y * (-1) << "," << skeleton.joints[22].position.xyz.z;
	myfile << "," << skeleton.joints[23].position.xyz.x * (-1) << "," << skeleton.joints[23].position.xyz.y * (-1) << "," << skeleton.joints[23].position.xyz.z;
	myfile << "," << skeleton.joints[24].position.xyz.x * (-1) << "," << skeleton.joints[24].position.xyz.y * (-1) << "," << skeleton.joints[24].position.xyz.z;
	myfile << "," << skeleton.joints[18].position.xyz.x * (-1) << "," << skeleton.joints[18].position.xyz.y * (-1) << "," << skeleton.joints[18].position.xyz.z;
	myfile << "," << skeleton.joints[19].position.xyz.x * (-1) << "," << skeleton.joints[19].position.xyz.y * (-1) << "," << skeleton.joints[19].position.xyz.z;
	myfile << "," << skeleton.joints[20].position.xyz.x * (-1) << "," << skeleton.joints[20].position.xyz.y * (-1) << "," << skeleton.joints[20].position.xyz.z;

	myfile << "\n";
k4abt_frame_release(body_frame);
        
    myfile.close();

    return true;
}

bool check_depth_image_exists(k4a_capture_t capture)
{
    k4a_image_t depth = k4a_capture_get_depth_image(capture);
    if (depth != nullptr)
    {
        k4a_image_release(depth);
        return true;
    }
    else
    {
        return false;
    }
}

bool process_mkv_offline(const char* input_path, const char* output_path, bool deleteExistingFile, k4abt_tracker_configuration_t tracker_config = K4ABT_TRACKER_CONFIG_DEFAULT)
{
    k4a_playback_t playback_handle = nullptr;
    k4a_result_t result = k4a_playback_open(input_path, &playback_handle);
    if (result != K4A_RESULT_SUCCEEDED)
    {
        cerr << "Cannot open recording at " << input_path << endl;
        return false;
    }

    k4a_calibration_t calibration;
    result = k4a_playback_get_calibration(playback_handle, &calibration);
    if (result != K4A_RESULT_SUCCEEDED)
    {
        cerr << "Failed to get calibration" << endl;
        return false;
    }

    k4abt_tracker_t tracker = NULL;
    if (K4A_RESULT_SUCCEEDED != k4abt_tracker_create(&calibration, tracker_config, &tracker))
    {
        cerr << "Body tracker initialization failed!" << endl;
        return false;
    }

    cout << "Processing " << input_path << endl;

    int frame_count = 0, cabecera = 0;
    
	char csvFullPath[100];
	sprintf(csvFullPath, "%s.csv", output_path);
	if(FILE *file = fopen(csvFullPath, "r")){
		if(deleteExistingFile){
			printf("\tOld csv file detected --> Deleting\n");
	    		fclose(file);
	    		remove(output_path);
	    	}
	    	else{
	    		auto now = std::chrono::system_clock::now();
	    		auto in_time_t = std::chrono::system_clock::to_time_t(now);
	    		printf("\tOld csv file detected --> Will not be deleted, instead the file is kept and new file is named after it with current time\n");
	    		stringstream ss;
	    		ss << std::put_time(std::localtime(&in_time_t), "_%Y_%m_%d_%X");
	    		sprintf(csvFullPath, "%s%s.csv", output_path, ss.str().c_str());
	    	}
    	}
    	else
    		printf("\tNo old csv file detected --> Creating\n");
    	
    
    bool success = true;
    while (true)
    {
        k4a_capture_t capture_handle = nullptr;
        k4a_stream_result_t stream_result = k4a_playback_get_next_capture(playback_handle, &capture_handle);
        if (stream_result == K4A_STREAM_RESULT_EOF)
        {
            break;
        }

        if (stream_result == K4A_STREAM_RESULT_SUCCEEDED)
        {
            // Only try to predict joints when capture contains depth image
            if (check_depth_image_exists(capture_handle))
            {
                success = predict_joints(csvFullPath, cabecera, tracker, capture_handle);
                cabecera = 1;
                k4a_capture_release(capture_handle);
                if (!success)
                {
                    cerr << "Predict joints failed for clip at frame " << frame_count << endl;
                    break;
                }
            }
        }
        else
        {
            success = false;
            cerr << "Stream error for clip at frame " << frame_count << endl;
            break;
        }

        frame_count++;
    }

    if (success)
    {

        cout << frame_count << " frames read" << endl;
        
        cout << "Processed results saved in " << csvFullPath << endl;
    }

    k4abt_tracker_shutdown(tracker);
    k4abt_tracker_destroy(tracker);
    k4a_playback_close(playback_handle);

    return success;
}

int processVideo(const char* input_path, const char* output_path, bool deleteExistingFile)
{
    k4abt_tracker_configuration_t tracker_config = K4ABT_TRACKER_CONFIG_DEFAULT;
    tracker_config.processing_mode = K4ABT_TRACKER_PROCESSING_MODE_CPU;
    return process_mkv_offline(input_path, output_path, deleteExistingFile, tracker_config) ? 0 : -1;
}
