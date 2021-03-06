/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    stm32f4xx_it.c
  * @brief   Interrupt Service Routines.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f4xx_it.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "math.h"
#include "stdlib.h"
#include "string.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */


//Motor encoders----------------------------
extern float enc_res;
extern float sampling_time;
extern float tyre_deflection;
int indx=0;//this is only an aux variable

//extern int16_t enc_FR;
//extern int16_t enc_FL;
//extern int16_t enc_RL;
//extern int16_t enc_RR;

extern int16_t counter_M1;
extern int16_t counter_M2;
extern int16_t counter_M3;
extern int16_t counter_M4;
//------------------------------------


//setSpeed fun-------------------------
extern float lin;
extern float ang;
extern float L_wheel_lin_speed;
extern float R_wheel_lin_speed;
extern float L_wheel_angular_velocity;
extern float R_wheel_angular_velocity;
extern float L_enc_speed;
extern float R_enc_speed;

extern float rot_radio;
extern float new_L_enc_speed;
extern float new_R_enc_speed;
//------------------------------------

//updateOdometry fun----------------------------
extern float wheel_L_ang_vel;
extern float wheel_R_ang_vel;
extern float wheel_L_ang_pos;
extern float wheel_R_ang_pos;

extern float wheel_FL_ang_pos;
extern float wheel_FR_ang_pos;
extern float wheel_RL_ang_pos;
extern float wheel_RR_ang_pos;

extern float enc_L;
extern float enc_R;

extern float wheel_radius; //50 millimeters
extern float robot_width; //distance between robot left and right wheels, 21 centimeters
extern float diameter_mod; //DIAMETER_MODIFICATOR

extern float robot_angular_vel;
extern float robot_angular_pos;
extern float robot_x_vel;
extern float robot_y_vel;
extern float robot_x_pos;
extern float robot_y_pos;

//------------------------------------

//setPower----------------------------------
extern float max_speed;
extern float min_speed;
extern float min_pwm;
extern float max_pwm;
float out_map;
extern float M1_pwm;
extern float M2_pwm;
extern float M3_pwm;
extern float M4_pwm;
//------------------------------------------

//Transmision-----------------------
//extern uint8_t buffer_txt[64];
extern uint8_t buffer_txt[80];
//----------------------------------


/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/
extern PCD_HandleTypeDef hpcd_USB_OTG_FS;
extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim4;
extern TIM_HandleTypeDef htim5;
extern UART_HandleTypeDef huart6;
/* USER CODE BEGIN EV */

/* USER CODE END EV */

/******************************************************************************/
/*           Cortex-M4 Processor Interruption and Exception Handlers          */
/******************************************************************************/
/**
  * @brief This function handles Non maskable interrupt.
  */
void NMI_Handler(void)
{
  /* USER CODE BEGIN NonMaskableInt_IRQn 0 */

  /* USER CODE END NonMaskableInt_IRQn 0 */
  /* USER CODE BEGIN NonMaskableInt_IRQn 1 */
  while (1)
  {
  }
  /* USER CODE END NonMaskableInt_IRQn 1 */
}

/**
  * @brief This function handles Hard fault interrupt.
  */
void HardFault_Handler(void)
{
  /* USER CODE BEGIN HardFault_IRQn 0 */

  /* USER CODE END HardFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_HardFault_IRQn 0 */
    /* USER CODE END W1_HardFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Memory management fault.
  */
void MemManage_Handler(void)
{
  /* USER CODE BEGIN MemoryManagement_IRQn 0 */

  /* USER CODE END MemoryManagement_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_MemoryManagement_IRQn 0 */
    /* USER CODE END W1_MemoryManagement_IRQn 0 */
  }
}

/**
  * @brief This function handles Pre-fetch fault, memory access fault.
  */
void BusFault_Handler(void)
{
  /* USER CODE BEGIN BusFault_IRQn 0 */

  /* USER CODE END BusFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_BusFault_IRQn 0 */
    /* USER CODE END W1_BusFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Undefined instruction or illegal state.
  */
void UsageFault_Handler(void)
{
  /* USER CODE BEGIN UsageFault_IRQn 0 */

  /* USER CODE END UsageFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_UsageFault_IRQn 0 */
    /* USER CODE END W1_UsageFault_IRQn 0 */
  }
}

/**
  * @brief This function handles System service call via SWI instruction.
  */
void SVC_Handler(void)
{
  /* USER CODE BEGIN SVCall_IRQn 0 */

  /* USER CODE END SVCall_IRQn 0 */
  /* USER CODE BEGIN SVCall_IRQn 1 */

  /* USER CODE END SVCall_IRQn 1 */
}

/**
  * @brief This function handles Debug monitor.
  */
void DebugMon_Handler(void)
{
  /* USER CODE BEGIN DebugMonitor_IRQn 0 */

  /* USER CODE END DebugMonitor_IRQn 0 */
  /* USER CODE BEGIN DebugMonitor_IRQn 1 */

  /* USER CODE END DebugMonitor_IRQn 1 */
}

/**
  * @brief This function handles Pendable request for system service.
  */
void PendSV_Handler(void)
{
  /* USER CODE BEGIN PendSV_IRQn 0 */

  /* USER CODE END PendSV_IRQn 0 */
  /* USER CODE BEGIN PendSV_IRQn 1 */

  /* USER CODE END PendSV_IRQn 1 */
}

/**
  * @brief This function handles System tick timer.
  */
void SysTick_Handler(void)
{
  /* USER CODE BEGIN SysTick_IRQn 0 */
	indx++;
	if(indx==sampling_time){
		/*//M1_FORWARD_RIGHT
		wheel_ang_pos_M1=(180/3.14)*2*3.14*counter_M1/enc_res;
		vel_ang_M1=((wheel_ang_pos_M1-old_wheel_ang_pos_M1)/(sampling_time/1000));
		old_wheel_ang_pos_M1=wheel_ang_pos_M1;
		//M2_FORWARD_LEFT
		wheel_ang_pos_M2=(180/3.14)*2*3.14*counter_M2/enc_res;
		vel_ang_M2=((wheel_ang_pos_M2-old_wheel_ang_pos_M2)/(sampling_time/1000));
		old_wheel_ang_pos_M2=wheel_ang_pos_M2;
		//M3_REAR_LEFT
		wheel_ang_pos_M3=(180/3.14)*2*3.14*counter_M3/enc_res;
		vel_ang_M3=((wheel_ang_pos_M3-old_wheel_ang_pos_M3)/(sampling_time/1000));
		old_wheel_ang_pos_M3=wheel_ang_pos_M3;
		//M3_REAR_RIGHT
		wheel_ang_pos_M4=(180/3.14)*2*3.14*counter_M4/enc_res;
		vel_ang_M4=((wheel_ang_pos_M4-old_wheel_ang_pos_M4)/(sampling_time/1000));
		old_wheel_ang_pos_M4=wheel_ang_pos_M4;*/



		odometryUpdater(counter_M1,counter_M2,counter_M3,counter_M4);
	    __HAL_TIM_SET_COUNTER(&htim2,0);
	    __HAL_TIM_SET_COUNTER(&htim3,0);
	    __HAL_TIM_SET_COUNTER(&htim4,0);
	    __HAL_TIM_SET_COUNTER(&htim5,0);
	    counter_M1=0; counter_M2=0; counter_M3=0; counter_M4=0;

		//setSpeed(-1.55,0.0); //w(+)L wheels back R wheels forw.(turn right)//w(-)L wheels forw. R wheels back.(turn left)
		//out_map=map(5, 0, 10, 0, 100);
		indx=0;
	}


  /* USER CODE END SysTick_IRQn 0 */
  HAL_IncTick();
  /* USER CODE BEGIN SysTick_IRQn 1 */

  /* USER CODE END SysTick_IRQn 1 */
}

/******************************************************************************/
/* STM32F4xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f4xx.s).                    */
/******************************************************************************/

/**
  * @brief This function handles TIM2 global interrupt.
  */
void TIM2_IRQHandler(void)
{
  /* USER CODE BEGIN TIM2_IRQn 0 */

  /* USER CODE END TIM2_IRQn 0 */
  HAL_TIM_IRQHandler(&htim2);
  /* USER CODE BEGIN TIM2_IRQn 1 */

  /* USER CODE END TIM2_IRQn 1 */
}

/**
  * @brief This function handles TIM3 global interrupt.
  */
void TIM3_IRQHandler(void)
{
  /* USER CODE BEGIN TIM3_IRQn 0 */

  /* USER CODE END TIM3_IRQn 0 */
  HAL_TIM_IRQHandler(&htim3);
  /* USER CODE BEGIN TIM3_IRQn 1 */

  /* USER CODE END TIM3_IRQn 1 */
}

/**
  * @brief This function handles TIM4 global interrupt.
  */
void TIM4_IRQHandler(void)
{
  /* USER CODE BEGIN TIM4_IRQn 0 */

  /* USER CODE END TIM4_IRQn 0 */
  HAL_TIM_IRQHandler(&htim4);
  /* USER CODE BEGIN TIM4_IRQn 1 */

  /* USER CODE END TIM4_IRQn 1 */
}

/**
  * @brief This function handles TIM5 global interrupt.
  */
void TIM5_IRQHandler(void)
{
  /* USER CODE BEGIN TIM5_IRQn 0 */

  /* USER CODE END TIM5_IRQn 0 */
  HAL_TIM_IRQHandler(&htim5);
  /* USER CODE BEGIN TIM5_IRQn 1 */

  /* USER CODE END TIM5_IRQn 1 */
}

/**
  * @brief This function handles USB On The Go FS global interrupt.
  */
void OTG_FS_IRQHandler(void)
{
  /* USER CODE BEGIN OTG_FS_IRQn 0 */

  /* USER CODE END OTG_FS_IRQn 0 */
  HAL_PCD_IRQHandler(&hpcd_USB_OTG_FS);
  /* USER CODE BEGIN OTG_FS_IRQn 1 */

  /* USER CODE END OTG_FS_IRQn 1 */
}

/**
  * @brief This function handles USART6 global interrupt.
  */
void USART6_IRQHandler(void)
{
  /* USER CODE BEGIN USART6_IRQn 0 */

  /* USER CODE END USART6_IRQn 0 */
  HAL_UART_IRQHandler(&huart6);
  /* USER CODE BEGIN USART6_IRQn 1 */

  /* USER CODE END USART6_IRQn 1 */
}

/* USER CODE BEGIN 1 */

void odometryUpdater(int16_t enc_FL, int16_t enc_FR, int16_t enc_RR, int16_t enc_RL)
{

    wheel_FL_ang_pos = 2 * 3.14 * enc_FL / enc_res;
    wheel_FR_ang_pos = 2 * 3.14 * enc_FR / enc_res;
    wheel_RL_ang_pos = 2 * 3.14 * enc_RL / enc_res;
    wheel_RR_ang_pos = 2 * 3.14 * enc_RR / enc_res;




    enc_L = (enc_FL + enc_RL) / (2 * tyre_deflection);
    enc_R = (enc_FR + enc_RR) / (2 * tyre_deflection);

    wheel_L_ang_vel = ((2 * 3.14 * enc_L / enc_res)) / (sampling_time/1000);
    wheel_R_ang_vel = ((2 * 3.14 * enc_R / enc_res)) / (sampling_time/1000);

    wheel_L_ang_pos = wheel_L_ang_pos+(2 * 3.14 * enc_L / enc_res);
    wheel_R_ang_pos = wheel_R_ang_pos+(2 * 3.14 * enc_R / enc_res);

    robot_angular_vel = (((wheel_R_ang_pos - wheel_L_ang_pos) * wheel_radius / (robot_width * diameter_mod)) - robot_angular_pos) / (sampling_time/1000);
    //robot_angular_pos=(robot_angular_pos+(robot_angular_vel*(sampling_time/1000)))*(180/3.14);
    robot_angular_pos = (wheel_R_ang_pos - wheel_L_ang_pos) * wheel_radius / (robot_width * diameter_mod);
    robot_x_vel = (wheel_L_ang_vel * wheel_radius + robot_angular_vel * robot_width / 2) * cos(robot_angular_pos);
    robot_y_vel = (wheel_L_ang_vel * wheel_radius + robot_angular_vel * robot_width / 2) * sin(robot_angular_pos);
    robot_x_pos = robot_x_pos + robot_x_vel * (sampling_time/1000);
    robot_y_pos = robot_y_pos + robot_y_vel * (sampling_time/1000);








    //for (int i = 0; i < 64; i++ ) {
    //	buffer_txt[i]=*(sztxt + i);
    //}

    //char sz1[64];
    //strcpy(sztxt,);

    //sz1=build_buffer(robot_x_pos,robot_y_pos,robot_angular_pos,robot_x_vel,robot_y_vel,robot_angular_vel,txt_resolution);

    memset(buffer_txt,'\0',80);
    char *sztxt;
    sztxt=build_buffer(robot_x_pos,robot_y_pos,robot_angular_pos,robot_x_vel,robot_y_vel,robot_angular_vel);
    strcpy(buffer_txt,sztxt);
    CDC_Transmit_FS((uint8_t *) buffer_txt, strlen (buffer_txt));





}

void setSpeed(float linear, float angular)
{
    lin = linear;
    ang = angular;
    if(fabs(lin)>1.5386) 	lin=(linear/fabs(linear))*1.5386;
    if(fabs(ang)>14.65) 	ang=(angular/fabs(angular))*14.65;

    L_wheel_lin_speed = lin - (ang * robot_width / 2);
    R_wheel_lin_speed = lin + (ang * robot_width / 2);
    L_wheel_angular_velocity = L_wheel_lin_speed / wheel_radius;
    R_wheel_angular_velocity = R_wheel_lin_speed / wheel_radius;
    L_enc_speed = enc_res * L_wheel_angular_velocity / (2 * M_PI);
    R_enc_speed = enc_res * R_wheel_angular_velocity / (2 * M_PI);


    if(abs(L_enc_speed)>max_speed || abs(R_enc_speed)>max_speed)
    {
    	if(abs(R_enc_speed)>abs(L_enc_speed))
    	{
    		rot_radio= fabs(R_enc_speed/max_speed);
    		new_R_enc_speed=(R_enc_speed/fabs(R_enc_speed))*max_speed;  //(R_enc_speed/fabs(R_enc_speed)) is to get the sign of the original command
    		new_L_enc_speed=L_enc_speed/rot_radio;
    	}else{
    		rot_radio= fabs(L_enc_speed/max_speed);
    		new_L_enc_speed=(R_enc_speed/fabs(R_enc_speed))*max_speed;
    		new_R_enc_speed=R_enc_speed/rot_radio;
    	}
    	setPower(new_L_enc_speed, new_R_enc_speed, new_R_enc_speed, new_L_enc_speed);  //M1-M2-M3-M4
    }else
    {
    	setPower(L_enc_speed, R_enc_speed, R_enc_speed, L_enc_speed);  //M1-M2-M3-M4
    }



}



float map(float value, float in_low, float in_high, float out_low, float out_high)
{
    float outgoing = out_low + (out_high - out_low) * ((value - in_low) / (in_high - in_low));
    return outgoing;
  }
/* USER CODE END 1 */
