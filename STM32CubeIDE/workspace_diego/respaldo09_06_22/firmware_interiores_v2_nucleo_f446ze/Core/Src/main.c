/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
#include "usb_device.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "usbd_cdc_if.h"
#include "string.h"
#include "math.h"
#include "stdlib.h"
#include "stdbool.h"
//#include "MPU9250.h"
#include "IMU.h"
#include "math.h"
#include "WT901C.h"
//#include "MPU9250.h"



/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
 ADC_HandleTypeDef hadc1;

I2C_HandleTypeDef hi2c1;

TIM_HandleTypeDef htim2;

UART_HandleTypeDef huart2;
UART_HandleTypeDef huart3;
UART_HandleTypeDef huart6;

/* USER CODE BEGIN PV */

UART_HandleTypeDef* address_huart1=&huart3;
UART_HandleTypeDef* address_huart2=&huart6;

int cmd_pulse=4256;
int forw=1;
uint16_t raw;
int skip=200;
int cmd=0;
int cmd_command=0;
int forw_rot=0;
int back_rot=0;
int stop_rot=0;

char *data="x5.12345123451234512345,y1.12345123451234512345,v1.12345123451234512345,w1.12345123451234512345";
float x1=5.12345;
float x2=3.46789;
float f = 2.45;
//char a[sizeof(float)];

char *s;
float info[3]; // floats with info
uint8_t data1[12];
uint8_t *array;
char out_s[2];
char sz1[64] = {' '} ;
char szaux[64];
char fill_res[20];
int count_tim1=0;

char mp[20];


char volt_array[16];
float Vadc = 0;


float buffer_txt[9];
float buffer[2];

uint8_t bufferaux_v[64];
uint8_t bufferaux_w[64];


char test1;
int intposv=0;
int intposw=0;
//char *data="HolaDiego";




//Motor encoder----------------------------
float enc_res=979.0;
//float enc_res=1632.0;
float sampling_time=20.0; //20ms
float tyre_deflection=1.0;
float indx_odom=0;
float counter_test1=0;
//int16_t enc_FR=0;
//int16_t enc_FL=0;
//int16_t enc_RL=0;
//int16_t enc_RR=0;


int16_t counter_M1=0;
int16_t counter_M2=0;
int16_t counter_M3=0;
int16_t counter_M4=0;

int16_t M1=0;
int16_t M2=0;
int16_t M3=0;
int16_t M4=0;


//------------------------------------

//setSpeed fun-------------------------
float lin=0;
float ang=0;
float L_wheel_lin_speed=0;
float R_wheel_lin_speed=0;
float L_wheel_angular_velocity=0;
float R_wheel_angular_velocity=0;
float L_enc_speed=0;
float R_enc_speed=0;

float FL_enc_speed;
float FR_enc_speed;
float RL_enc_speed;
float RR_enc_speed;

float rot_radio=0;
float new_L_enc_speed=0;
float new_R_enc_speed=0;
//------------------------------------


//updateOdometry fun-------------------------
float wheel_L_ang_vel=0;
float wheel_R_ang_vel=0;
float wheel_L_ang_pos=0;
float wheel_R_ang_pos=0;

float wheel_L_linear_vel=0;
float wheel_R_linear_vel=0;
float ICCx=0;
float ICCy=0;
float sampling_time_odom=0;
float t_ant=0;
float t_curr=0;
float outgoing=0;
bool imu_ready=false;
wt901c imu;

float wheel_FL_ang_pos =0;
float wheel_FR_ang_pos =0;
float wheel_RL_ang_pos =0;
float wheel_RR_ang_pos =0;

float enc_L=0;
float enc_R=0;

float wheel_radius=0.05; //50 millimeters
float robot_width=0.21; //distance between robot left and right wheels, 21 centimeters
float diameter_mod=1.0; //DIAMETER_MODIFICATOR

float robot_angular_vel=0;
float robot_angular_pos=0;
float robot_angular_pos_aux=0;
float robot_angular_pos1=0;
float robot_angular_pos2=0;
float robot_x_vel=0;
float robot_y_vel=0;
float robot_x_pos=0;
float robot_y_pos=0;
float robot_linear_vel=0;

float R=0;
float wr=0;
//------------------------------------------

//setPower fun----------------------------------
float max_speed = 7996.8; //max pulses per second
float min_speed = -7996.8;//min pulses per second
float min_pwm = 2767;//2800;//3136.0;
float max_pwm = 5533;//5600;//5376.0;
float M1_pwm = 0;
float M2_pwm = 0;
float M3_pwm = 0;
float M4_pwm = 0;
//------------------------------------------

unsigned char *pFloat;
unsigned char* rx_ptr, * tx_ptr; //Punteros auxiliares UART
//unsigned char tx_buf[20], rx_buf[12]; //Buffers UART
float v_in, w_in, cam_in; //Valores deseados entrantes
float px_cur, py_cur, v_cur, w_cur, cam_cur; //Valores actuales salientes


//----ROBOCLAW------------------------

int32_t countsM1_roboclaw=0;
int32_t countsM2_roboclaw=0;
int32_t countsM3_roboclaw=0;
int32_t countsM4_roboclaw=0;

int32_t speedM1_roboclaw=0;
int32_t speedM2_roboclaw=0;
int32_t speedM3_roboclaw=0;
int32_t speedM4_roboclaw=0;
int32_t IspeedM1_roboclaw=0;
int32_t IspeedM2_roboclaw=0;

bool status_Counters_rw1;
bool status_Counters_rw2;
bool status_Speeds;
bool status_speedM1;
bool status_speedM2;
bool status_speedM3;
bool status_speedM4;

bool status_init_rw1;
bool status_init_rw2;

bool status_Set_Speed_rw1;
bool status_Set_Speed_rw2;

bool status_Set_Max_Current;
bool status_Read_Voltage;
bool status_state_rw1;
bool status_state_rw2;

float testvar1;
int flag_pos=0;
float angular_test=0;
float ant_enc_L;
float ant_enc_R;
float test_robot_angular_vel;
float test_wheel_L_ang_vel;
float test_wheel_R_ang_vel;
float ant_wheel_R_ang_pos,ant_wheel_L_ang_pos;
//STATUS ROBOCLAW--------------------------------------------------
float time_overcurrent_first_rw1,time_overcurrent_first_rw2;
float time_overcurrent_rw1,time_overcurrent_rw2;
float max_overcurrent=4.0;
float max_time_overcurrent=3.0;

int flag_status_register_rw2[7];
int flag_status_register_rw1[7];


bool status_Roboclaw;
bool status_button;

//------------------------------------------------------------------

int32_t max_current;
int32_t min_current;

int flagtest=0;


uint8_t rx_data[10];
#define address_roboclaw1      0x80
#define address_roboclaw2      0x80

#define PI 3.142857

uint8_t* readBufuart_dir;
uint8_t readBufuart_copy[4];
uint8_t readBufuart_copy_speed[4];
uint8_t readBufuart_copy_bat[2];
uint8_t readBufuart[7];


uint8_t readBufuart_bat[4];
uint8_t readBufuart_speed[7];
float voltage=0;
float timer_indoor_system=0;
//-------------------------------------

float offset_theta=0;
float theta_curr=0;
float delta_theta=0;
float theta_ant=0;

//MPU9250_Handle_t imu;
float accel_x;
float accel_y;
float accel_z;
float gyro_x;
float gyro_y;
float gyro_z;
float mag_x;
float mag_y;
float mag_z;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART3_UART_Init(void);
static void MX_TIM2_Init(void);
static void MX_USART6_UART_Init(void);
static void MX_ADC1_Init(void);
static void MX_I2C1_Init(void);
static void MX_USART2_UART_Init(void);
/* USER CODE BEGIN PFP */

//callback it
void HAL_UART_RxCpltCallback(UART_HandleTypeDef* huart)
{
//	for (int i = 0; i < 11; i++)
//		parse_data(rx_buf[i]);
//
//	    calculate();
//
//	HAL_UART_Receive_IT(&huart2, rx_buf, 11);
	wt901c_callback();
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
	status_button=true;
}




/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
/*char readBuf[1];
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *UartHandle) {
  Se recibe el caracter y se pide el siguiente
 HAL_UART_Receive_IT(&huart6, (uint8_t*)readBuf, 1);
}*/




/*void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim){
	if(htim->Instance==TIM2){
			//count_tim1+=1;
			counter_M1=(int16_t)__HAL_TIM_GET_COUNTER(htim);//Encoder M1

		}
	if(htim->Instance==TIM3){
			counter_M2=(int16_t)__HAL_TIM_GET_COUNTER(htim);//Encoder M2
		}
	if(htim->Instance==TIM4){
			counter_M3=(int16_t)__HAL_TIM_GET_COUNTER(htim);//Encoder M3
		}
	if(htim->Instance==TIM5){
			counter_M4=(int16_t)__HAL_TIM_GET_COUNTER(htim);//Encoder M4
		}


}*/




/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART3_UART_Init();
  MX_TIM2_Init();
  MX_USART6_UART_Init();
  MX_ADC1_Init();
  MX_USB_DEVICE_Init();
  MX_I2C1_Init();
  MX_USART2_UART_Init();
  /* USER CODE BEGIN 2 */


  HAL_TIM_Base_Start_IT(&htim2);


  //main
//  imu_ready=false;
//  HAL_UART_Receive_IT(&huart2, rx_buf, 11);
//  HAL_Delay(200);
//  offset_theta=theta_imu[2]+180;
//  HAL_UART_Receive_IT(&huart2, rx_buf, 11);
//  HAL_Delay(200);
//  theta_ant=theta_imu[2]+180;
//  HAL_UART_Receive_IT(&huart2, rx_buf, 11);
//  HAL_Delay(200);
//  theta_curr=theta_imu[2]+180;
//  imu_ready=true;
  wt901c_init(&huart2);



  status_init_rw1=roboclaw1_init(address_huart1,(uint8_t) address_roboclaw1);
  status_init_rw2=roboclaw2_init(address_huart2,(uint8_t) address_roboclaw2);


  //HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
  //HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
  //HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3);
  //HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_4);
  //HAL_TIM_Encoder_Start_IT(&htim2, TIM_CHANNEL_ALL);
  //HAL_TIM_Encoder_Start_IT(&htim3, TIM_CHANNEL_ALL);
  //HAL_TIM_Encoder_Start_IT(&htim4, TIM_CHANNEL_ALL);
  //HAL_TIM_Encoder_Start_IT(&htim5, TIM_CHANNEL_ALL);







  //HAL_ADCEx_InjectedStart(&hadc1);




  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  //HAL_UART_Receive_IT(&huart6, (uint8_t*)readBuf, 1);

  while (1)
  {



    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */









	  //if(Check_Status_Roboclaws(address_huart1,address_huart2,(uint8_t)address_roboclaw1,(uint8_t)address_roboclaw2)!=0)
	  //{
		  /*if(timer_indoor_system<=10){
			  setSpeed(0.5, 0);
		  }
		  if(timer_indoor_system>10 & timer_indoor_system<15){
			  setSpeed(0, 0);
		  }
		  if(timer_indoor_system>=15 & timer_indoor_system<=25){
			  setSpeed(-0.5, 0);
		  }
		  if(timer_indoor_system>25){
			  setSpeed(0, 0);
		  }

		  if(timer_indoor_system<=10){
			  setSpeed(v_in, w_in);
		  }else{
			  setSpeed(0, 0);
		  }*/




		  setSpeed(v_in, w_in);
		  status_speedM1=Read_Encoder_Speed(address_huart1,(uint8_t)address_roboclaw1,(uint8_t)1,&speedM1_roboclaw);
		  status_speedM2=Read_Encoder_Speed(address_huart1,(uint8_t)address_roboclaw1,(uint8_t)2,&speedM2_roboclaw);
		  status_speedM3=Read_Encoder_Speed(address_huart2,(uint8_t)address_roboclaw2,(uint8_t)1,&speedM3_roboclaw);
		  status_speedM4=Read_Encoder_Speed(address_huart2,(uint8_t)address_roboclaw2,(uint8_t)2,&speedM4_roboclaw);
		  status_Counters_rw1=Read_Both_Encoder_Counts(address_huart1,(uint8_t)address_roboclaw1,&countsM1_roboclaw,&countsM2_roboclaw);
		  status_Counters_rw2=Read_Both_Encoder_Counts(address_huart2,(uint8_t)address_roboclaw2,&countsM3_roboclaw,&countsM4_roboclaw);
		  //status_button=HAL_GPIO_ReadPin(B1_reset_odom_GPIO_Port, B1_reset_odom_Pin);
		  if(status_button==true){
			  reset_Odometry();
		  }


	  //}




  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_BYPASS;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 168;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  RCC_OscInitStruct.PLL.PLLR = 2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief ADC1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_ADC1_Init(void)
{

  /* USER CODE BEGIN ADC1_Init 0 */

  /* USER CODE END ADC1_Init 0 */

  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC1_Init 1 */

  /* USER CODE END ADC1_Init 1 */

  /** Configure the global features of the ADC (Clock, Resolution, Data Alignment and number of conversion)
  */
  hadc1.Instance = ADC1;
  hadc1.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV4;
  hadc1.Init.Resolution = ADC_RESOLUTION_12B;
  hadc1.Init.ScanConvMode = DISABLE;
  hadc1.Init.ContinuousConvMode = DISABLE;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.NbrOfConversion = 1;
  hadc1.Init.DMAContinuousRequests = DISABLE;
  hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
  */
  sConfig.Channel = ADC_CHANNEL_4;
  sConfig.Rank = 1;
  sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC1_Init 2 */

  /* USER CODE END ADC1_Init 2 */

}

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */

  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.ClockSpeed = 100000;
  hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 59;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 1400;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 57600;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * @brief USART3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART3_UART_Init(void)
{

  /* USER CODE BEGIN USART3_Init 0 */

  /* USER CODE END USART3_Init 0 */

  /* USER CODE BEGIN USART3_Init 1 */

  /* USER CODE END USART3_Init 1 */
  huart3.Instance = USART3;
  huart3.Init.BaudRate = 38400;
  huart3.Init.WordLength = UART_WORDLENGTH_8B;
  huart3.Init.StopBits = UART_STOPBITS_1;
  huart3.Init.Parity = UART_PARITY_NONE;
  huart3.Init.Mode = UART_MODE_TX_RX;
  huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart3.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart3) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART3_Init 2 */

  /* USER CODE END USART3_Init 2 */

}

/**
  * @brief USART6 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART6_UART_Init(void)
{

  /* USER CODE BEGIN USART6_Init 0 */

  /* USER CODE END USART6_Init 0 */

  /* USER CODE BEGIN USART6_Init 1 */

  /* USER CODE END USART6_Init 1 */
  huart6.Instance = USART6;
  huart6.Init.BaudRate = 38400;
  huart6.Init.WordLength = UART_WORDLENGTH_8B;
  huart6.Init.StopBits = UART_STOPBITS_1;
  huart6.Init.Parity = UART_PARITY_NONE;
  huart6.Init.Mode = UART_MODE_TX_RX;
  huart6.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart6.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart6) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART6_Init 2 */

  /* USER CODE END USART6_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOG_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOG, GPIO_PIN_6, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, GPIO_PIN_RESET);

  /*Configure GPIO pin : PC13 */
  GPIO_InitStruct.Pin = GPIO_PIN_13;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PA0 PA1 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF2_TIM5;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : PB0 */
  GPIO_InitStruct.Pin = GPIO_PIN_0;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF2_TIM3;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : PG6 */
  GPIO_InitStruct.Pin = GPIO_PIN_6;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

  /*Configure GPIO pin : USB_OverCurrent_Pin */
  GPIO_InitStruct.Pin = USB_OverCurrent_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(USB_OverCurrent_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : PC9 */
  GPIO_InitStruct.Pin = GPIO_PIN_9;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI15_10_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

}

/* USER CODE BEGIN 4 */



//----ODOMETRY---------------------------------------------------


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* htim)
{
	  if(htim->Instance==TIM2){
		  timer_indoor_system+=0.001;
		  indx_odom++;
		  if(indx_odom==sampling_time){
			  //if(imu_ready==true)
			  //{
				  odometryUpdater(countsM1_roboclaw,countsM2_roboclaw,countsM3_roboclaw,countsM4_roboclaw,speedM1_roboclaw,speedM2_roboclaw,speedM3_roboclaw,speedM4_roboclaw);
			  //}
			  indx_odom=0;
		  }
	  }
}

void reset_Odometry()
{
	bool set_1=Drive_M1_M2_With_Signed_Speed(address_huart1,(uint8_t)address_roboclaw1, 0, 0);
	bool set_2=Drive_M1_M2_With_Signed_Speed(address_huart2,(uint8_t)address_roboclaw2, 0, 0);
	bool set_3=Reset_Encoder_Counters(address_huart1,(uint8_t)address_roboclaw1);
	bool set_4=Reset_Encoder_Counters(address_huart2,(uint8_t)address_roboclaw2);

	wt901c_init(&huart2);

//	  imu_ready=false;
//	  HAL_UART_Receive_IT(&huart2, rx_buf, 11);
//	  HAL_Delay(200);
//	  offset_theta=theta_imu[2]+180;
//	  HAL_UART_Receive_IT(&huart2, rx_buf, 11);
//	  HAL_Delay(200);
//	  theta_ant=theta_imu[2]+180;
//	  HAL_UART_Receive_IT(&huart2, rx_buf, 11);
//	  HAL_Delay(200);
//	  theta_curr=theta_imu[2]+180;
//	  imu_ready=true;


	robot_x_pos=0;
	robot_y_pos=0;
	robot_angular_pos=0;
	robot_angular_pos_aux=0;
	theta_ant=0;
	theta_curr=0;
	delta_theta=0;
	robot_linear_vel=0;
	robot_x_vel=0;
	robot_y_vel=0;
	robot_angular_vel=0;
	status_button=false;


}

void odometryUpdater(int32_t enc_FL, int32_t enc_FR, int32_t enc_RL, int32_t enc_RR, int32_t w_FL, int32_t w_FR, int32_t w_RL, int32_t w_RR)
{
	float enc_res=979.2;
	t_curr=timer_indoor_system;


	counter_test1++;
	wheel_FL_ang_pos = 2 * 3.14 * enc_FL / enc_res;
    wheel_FR_ang_pos = 2 * 3.14 * enc_FR / enc_res;
    wheel_RL_ang_pos = 2 * 3.14 * enc_RL / enc_res;
    wheel_RR_ang_pos = 2 * 3.14 * enc_RR / enc_res;


    testvar1=w_FL;






    enc_L = (enc_FL+enc_RL) / (2 * tyre_deflection);
    enc_R = (enc_FR+enc_RR) / (2 * tyre_deflection);

    wheel_L_ang_vel=(((w_FL+w_RL)/2)/979.2)*(2*M_PI);
    wheel_R_ang_vel=(((w_FR+w_RR)/2)/979.2)*(2*M_PI);

    wheel_L_linear_vel=wheel_L_ang_vel*wheel_radius;
	wheel_R_linear_vel=wheel_R_ang_vel*wheel_radius;

    //R=(robot_width/2)*((wheel_L_linear_vel+wheel_R_linear_vel)/(wheel_R_linear_vel-wheel_L_linear_vel));


//    if(((wheel_L_linear_vel>=0) & (wheel_R_linear_vel>=0))||((wheel_L_linear_vel<=0) & (wheel_R_linear_vel<=0))){
//    	wr=(wheel_R_linear_vel-wheel_L_linear_vel)/robot_width;
//
//    }else{
//    	wr=((wheel_R_linear_vel-wheel_L_linear_vel)/2)/robot_width;
//
//    }




    float cur_wheel_L_ang_pos = 2 * M_PI * enc_L / 979.2;
    float cur_wheel_R_ang_pos = 2 * M_PI * enc_R / 979.2;

    if(((wheel_L_ang_vel>=0) & (wheel_R_ang_vel>=0))||((wheel_L_ang_vel<=0) & (wheel_R_ang_vel<=0))){
    	robot_angular_vel=((wheel_R_ang_vel-wheel_L_ang_vel)*wheel_radius)/robot_width;

    }else{
    	robot_angular_vel=(((wheel_R_ang_vel-wheel_L_ang_vel)/2)*wheel_radius)/robot_width;

    }

    float delta_wheel_L_ang_pos=cur_wheel_L_ang_pos-ant_wheel_L_ang_pos;
    ant_wheel_L_ang_pos=cur_wheel_L_ang_pos;

    float delta_wheel_R_ang_pos=cur_wheel_R_ang_pos-ant_wheel_R_ang_pos;
    ant_wheel_R_ang_pos=cur_wheel_R_ang_pos;


//    if(((delta_wheel_L_ang_pos>=0) & (delta_wheel_R_ang_pos>=0)) || ((delta_wheel_L_ang_pos<=0) & (delta_wheel_R_ang_pos<=0))){
//    	robot_angular_pos=robot_angular_pos+((delta_wheel_R_ang_pos-delta_wheel_L_ang_pos)*wheel_radius/robot_width);
//    }else{
//    	if(delta_wheel_R_ang_pos>0){
//    		robot_angular_pos=robot_angular_pos+fabs(((delta_wheel_R_ang_pos+fabs(delta_wheel_L_ang_pos))/2)*wheel_radius/robot_width);
//    	}else{
//    		robot_angular_pos=robot_angular_pos-fabs(((fabs(delta_wheel_R_ang_pos)+delta_wheel_L_ang_pos)/2)*wheel_radius/robot_width);
//    	}
//    }





    theta_curr=theta_imu[2]+180;
    delta_theta=theta_curr-theta_ant;


    if(abs(delta_theta)>=50)
    {
    	delta_theta=0;
    }
    robot_angular_pos_aux=robot_angular_pos_aux+delta_theta;
    if(abs(robot_angular_pos_aux)>=360){
    	robot_angular_pos_aux=0;
    }
    if(abs(robot_angular_pos_aux)<=-360){
        	robot_angular_pos_aux=0;
    }
    if(robot_angular_pos_aux>=0 & robot_angular_pos_aux<=180){
    	robot_angular_pos=robot_angular_pos_aux;
    }else{
    	robot_angular_pos=(robot_angular_pos_aux-360);
    	if(robot_angular_pos<=-360)
    	{
    		robot_angular_pos+=360;
    	}

    }
    if(robot_angular_pos<=-180)
        	{
        		robot_angular_pos=180-abs(robot_angular_pos+180);
        	}

    robot_angular_pos=robot_angular_pos*M_PI/180;
    theta_ant=theta_curr;


    sampling_time_odom=t_curr-t_ant;
    //robot_angular_pos=robot_angular_pos+robot_angular_vel*0.02;
    //robot_angular_pos1=(theta_imu[2]);
    //robot_angular_pos=(theta_imu[2]-offset_theta);

    //robot_linear_vel=(wheel_L_ang_vel * wheel_radius+(robot_angular_vel*robot_width));
    robot_linear_vel=(wheel_L_linear_vel+wheel_R_linear_vel)/2;
    robot_x_vel = robot_linear_vel * cos(robot_angular_pos);
    robot_y_vel = robot_linear_vel * sin(robot_angular_pos);
    robot_x_pos = robot_x_pos + robot_x_vel * (sampling_time_odom);
    robot_y_pos = robot_y_pos + robot_y_vel * (sampling_time_odom);



    t_ant=t_curr;



//    float out_low=-180;
//    float out_high=180;
//    float in_low=-180-offset_theta;
//    float in_high=180-offset_theta;
//    float value=robot_angular_pos;
//    outgoing = out_low + (out_high - out_low) * ((value - in_low) / (in_high - in_low));
//
//    if(offset_theta>0){
//		if((robot_angular_pos1>180-offset_theta))
//		{
//			float aux=180-fabs(robot_angular_pos);
//			robot_angular_pos=180-aux;
//		}
//		if((robot_angular_pos1<(-180+offset_theta)) &((robot_angular_pos1>-180)))
//		{
//			float aux=fabs(180-fabs(robot_angular_pos1));
//			robot_angular_pos=(180-offset_theta)+aux;
//		}
//    }else{
//    	if((robot_angular_pos1>180-abs(offset_theta)))
//    	{
//    		float aux=robot_angular_pos1-fabs(180-abs(offset_theta));
//    		robot_angular_pos=fabs(180-abs(offset_theta))+aux;
//    	}
//
//
//    }






    //ICCx=robot_x_pos-(R*sin(wr*(sampling_time/1000)));
    //ICCy=robot_y_pos+(R*cos(wr*(sampling_time/1000)));




	//MPU9250_ReadAccel(&imu);
	//MPU9250_ReadGyro(&imu);
	//MPU9250_ReadMag(&imu);



	//mag_x=imu.mag[0];
	//mag_y=imu.mag[1]; //y-angular orientation
	//mag_z=imu.mag[2];



	//gyro_x=imu.gyr[0];
	//gyro_y=imu.gyr[1];
	//gyro_z=imu.gyr[2];  //z-angular velocity

	//accel_x=imu.acc[0];//x-linear acceleration
	//accel_y=imu.acc[1];
	//accel_z=imu.acc[2];

    mag_y=0;
    gyro_z=0;
    accel_x=0;


    buffer_txt[0]=robot_x_pos;
    buffer_txt[1]=robot_y_pos;
    buffer_txt[2]=imu.ang[2]*M_PI/180;//theta_imu[2]-offset_theta;
    buffer_txt[3]=robot_linear_vel;
    buffer_txt[4]=0;
    buffer_txt[5]=imu.w[2]*M_PI/180;//robot_angular_vel
    buffer_txt[6]=mag_y;
    buffer_txt[7]=gyro_z;
    buffer_txt[8]=accel_x;
    CDC_Transmit_FS(&buffer_txt, 9 * sizeof(float));



}



void setSpeed(float linear, float angular)
{
    float enc_res=979.2;

	bool set_0,set_1;
	lin = linear;
    ang = angular;
    if(fabs(lin)>1.5386) 	lin=(linear/fabs(linear))*1.5386;
    if(fabs(ang)>14.65) 	ang=(angular/fabs(angular))*14.65;



    L_wheel_lin_speed = lin - (ang * robot_width);
    R_wheel_lin_speed = lin + (ang * robot_width);
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



    	set_0=Drive_M1_M2_With_Signed_Speed(address_huart1,(uint8_t)address_roboclaw1, L_enc_speed, R_enc_speed);
    	set_1=Drive_M1_M2_With_Signed_Speed(address_huart2,(uint8_t)address_roboclaw2, L_enc_speed, R_enc_speed);
    }

}

//----------------------------------------------------



float map(float value, float in_low, float in_high, float out_low, float out_high)
{
    float outgoing = out_low + (out_high - out_low) * ((value - in_low) / (in_high - in_low));
    return outgoing;
  }

void setPower(float power_M1, float power_M2, float power_M3, float power_M4)
{
	M1_pwm = map(power_M1,min_speed,max_speed,min_pwm,max_pwm);
	M2_pwm = map(power_M2,min_speed,max_speed,min_pwm,max_pwm);
	M3_pwm = map(power_M3,min_speed,max_speed,min_pwm,max_pwm);
	M4_pwm = map(power_M4,min_speed,max_speed,min_pwm,max_pwm);

	//__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, M1_pwm);
	//__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, M2_pwm);
	//__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_3, M3_pwm);
	//__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_4, M4_pwm);


}


int32_t Read_Encoder_Count(UART_HandleTypeDef* address_huart,uint8_t address_roboclaw, int motor)
{
      uint8_t cmd_motor;
	  if (motor==1) cmd_motor=16;
	  if (motor==2) cmd_motor=17;
	  uint8_t txBuff[2]; // two bytes for address and cmd, two for value
	  txBuff[0] = address_roboclaw; //first to write is address
	  txBuff[1] = cmd_motor; // second is cmd
	  HAL_UART_Transmit(address_huart, txBuff, sizeof(txBuff), 100);

	  uint8_t rxBuff[7];
	  HAL_UART_Receive(address_huart, rxBuff, 7,100);
	  return (int32_t) ((uint32_t)((rxBuff[0] << 24) | (rxBuff[1] << 16) | (rxBuff[2] << 8) | rxBuff[3]));
}

bool Read_Encoder_Speed(UART_HandleTypeDef* address_huart, uint8_t address_roboclaw, int motor, int32_t *speedMX_roboclaw)
{
	uint8_t cmd_motor;
	if (motor==1) cmd_motor=18;
	if (motor==2) cmd_motor=19;
	uint8_t txBuff[2]; // two bytes for address and cmd, two for value
	txBuff[0] = address_roboclaw; //first to write is address
	txBuff[1] = cmd_motor; // second is cmd
	HAL_UART_Transmit(address_huart, txBuff, sizeof(txBuff), 100);

	uint8_t rxBuff[7];
	HAL_UART_Receive(address_huart, rxBuff, 7,100);


	//CHECK THE CHK REGISTER-----------------
	uint8_t chk[7];
	memcpy(&chk[0],&txBuff[0],2);
	memcpy(&chk[2],&rxBuff[0],5);
	uint16_t crc_tx= crc16((unsigned char *)chk,7);
	uint16_t crc_rx= (rxBuff[5]<<8 | rxBuff[6]);
	//---------------------------------------

	if(crc_tx==crc_rx){
		*speedMX_roboclaw=(int32_t) ((uint32_t)((rxBuff[0] << 24) | (rxBuff[1] << 16) | (rxBuff[2] << 8) | rxBuff[3]));
		return true;
	}
	else{
		return false;
	}
}

bool Read_Encoder_ISpeed(UART_HandleTypeDef* address_huart, uint8_t address_roboclaw, int32_t *IspeedM1_roboclaw, int32_t *IspeedM2_roboclaw){
	uint8_t txBuff[2]; // two bytes for address and cmd, two for value
	txBuff[0] = address_roboclaw; //first to write is address
	txBuff[1] = (uint8_t)79; // second is cmd
	HAL_UART_Transmit(address_huart, txBuff, sizeof(txBuff), 100);

	uint8_t rxBuff[10];
	HAL_UART_Receive(address_huart, rxBuff, 10,100);

	//CHECK THE CHK REGISTER-----------------
	uint8_t chk[10];
	memcpy(&chk[0],&txBuff[0],2);
	memcpy(&chk[2],&rxBuff[0],8);
	uint16_t crc_tx= crc16((unsigned char *)chk,10);
	uint16_t crc_rx= (rxBuff[8]<<8 | rxBuff[9]);
	//---------------------------------------

	if(crc_tx==crc_rx){
		*IspeedM1_roboclaw=(int32_t) ((uint32_t)((rxBuff[0] << 24) | (rxBuff[1] << 16) | (rxBuff[2] << 8) | rxBuff[3]));
		*IspeedM2_roboclaw=(int32_t) ((uint32_t)((rxBuff[4] << 24) | (rxBuff[5] << 16) | (rxBuff[6] << 8) | rxBuff[7]));
		return true;
	}
	else{
		return false;
	}

}


bool Read_Both_Encoder_Counts(UART_HandleTypeDef* address_huart,uint8_t address_roboclaw, int32_t *countsM1_roboclaw, int32_t *countsM2_roboclaw){
	uint8_t txBuff[2]; // two bytes for address and cmd, two for value
	txBuff[0] = address_roboclaw; //first to write is address
	txBuff[1] = (uint8_t)78; // second is cmd
	HAL_UART_Transmit(address_huart, txBuff, sizeof(txBuff), 100);

	uint8_t rxBuff[10];
	HAL_UART_Receive(address_huart, rxBuff, 10,100);

	//CHECK THE CHK REGISTER-----------------
	uint8_t chk[10];
	memcpy(chk,txBuff,2);
	memcpy(chk+2,rxBuff,8);
	uint16_t crc_tx= crc16((unsigned char *)chk,10);
	uint16_t crc_rx= (rxBuff[8]<<8 | rxBuff[9]);
	//---------------------------------------

	if(crc_tx==crc_rx){
		*countsM1_roboclaw=(int32_t) ((uint32_t)((rxBuff[0] << 24) | (rxBuff[1] << 16) | (rxBuff[2] << 8) | rxBuff[3]));
		*countsM2_roboclaw=(int32_t) ((uint32_t)((rxBuff[4] << 24) | (rxBuff[5] << 16) | (rxBuff[6] << 8) | rxBuff[7]));
		return true;
	}
	else{
		return false;
	}

}

/*other way to copy in CHK-------------------------------
		chk[0]=txBuff[0];
		chk[1]=txBuff[1];
		uint8_t* rxBuff_dir=&rxBuff[0];
		for(int i=0;i<=7;i++){
			chk[i+2]=*(rxBuff_dir+i);
		}
*/

bool Drive_M1_M2_With_Signed_Speed(UART_HandleTypeDef* address_huart,uint8_t address_roboclaw, int32_t SpeedM1, int32_t SpeedM2){

	  uint8_t txBuff[12];
	  txBuff[0] = address_roboclaw;
	  txBuff[1] = (uint8_t)37;
	  txBuff[2] = SpeedM1>>24;
	  txBuff[3] = SpeedM1>>16;
	  txBuff[4] = SpeedM1>>8;
	  txBuff[5] = SpeedM1;

	  txBuff[6] = SpeedM2>>24;
	  txBuff[7] = SpeedM2>>16;
	  txBuff[8] = SpeedM2>>8;
	  txBuff[9] = SpeedM2;

	  uint16_t crc_chk = crc16(txBuff, 10);
  	  txBuff[10] = crc_chk >> 8; // high value byte
  	  txBuff[11] = crc_chk; // low value byte
   	  HAL_UART_Transmit(address_huart, txBuff, sizeof(txBuff),200);

   	  uint8_t rxBuff[1];
   	  HAL_UART_Receive(address_huart, rxBuff, 1,200);

   	  if(rxBuff[0]==(uint8_t)255){
   		  return true;
   	  }
   	  else{
   		  return false;
   	  }

}

bool Set_Max_Motor_Current(UART_HandleTypeDef* address_huart,uint8_t address_roboclaw, int motor, int32_t max_current_value){

	  uint8_t cmd_motor;
	  if (motor==1) cmd_motor=133;
	  if (motor==2) cmd_motor=134;
	  uint8_t txBuff[12];
	  txBuff[0] = address_roboclaw;
	  txBuff[1] = (uint8_t)cmd_motor;
	  txBuff[2] = max_current_value>>24;
	  txBuff[3] = max_current_value>>16;
	  txBuff[4] = max_current_value>>8;
	  txBuff[5] = max_current_value;

	  txBuff[6] = 0;
	  txBuff[7] = 0;
	  txBuff[8] = 0;
	  txBuff[9] = 0;

	  uint16_t crc_chk = crc16(txBuff, 10);
  	  txBuff[10] = crc_chk >> 8; // high value byte
  	  txBuff[11] = crc_chk; // low value byte
   	  HAL_UART_Transmit(address_huart, txBuff, sizeof(txBuff), 10);

   	  uint8_t rxBuff=0;
   	  HAL_UART_Receive(address_huart, &rxBuff, 1,10);

   	  if(rxBuff==(uint8_t)255){
   		  return true;
   	  }
   	  else{
   		  return false;
   	  }

}

int Check_Status_Roboclaws(){
	bool set_0,set_1;
	Roboclaw1_State(address_huart1,(uint8_t)address_roboclaw1);
	Roboclaw2_State(address_huart2,(uint8_t)address_roboclaw2);
	if(flag_status_register_rw1[3]==1 || flag_status_register_rw2[3]==1){
		set_0=Drive_M1_M2_With_Signed_Speed(address_huart1,(uint8_t)address_roboclaw1, 0, 0);
		set_1=Drive_M1_M2_With_Signed_Speed(address_huart2,(uint8_t)address_roboclaw2, 0, 0);
		return 0;
	}else{
		return 1;
	}

}



void Roboclaw1_State(UART_HandleTypeDef* address_huart,uint8_t address_roboclaw){

	bool set_0,set_1,set_2;
	float Current_M1,Current_M2;
	uint32_t Byte_Status_roboclaw;


	set_0=Read_Status(address_huart,(uint8_t)address_roboclaw, &Byte_Status_roboclaw);


	if(set_0==true){
		if((Byte_Status_roboclaw & 0x000000)==0x000000) flag_status_register_rw1[0]=1;//Normal Status
		if((Byte_Status_roboclaw & 0x080000)==0x080000) flag_status_register_rw1[1]=1;//Main Voltage Low Warning
		if((Byte_Status_roboclaw & 0x010000)==0x010000) flag_status_register_rw1[2]=1;//Temperature Warning
	}



	set_2=Read_Motor_Currents(address_huart,(uint8_t) address_roboclaw, &Current_M1,&Current_M2);
	if(set_2==true && flag_status_register_rw1[3]==0 ){

		if((Current_M1>=max_overcurrent || Current_M2>=max_overcurrent) && (time_overcurrent_first_rw1==0.0)){
			time_overcurrent_first_rw1=timer_indoor_system;
		}

		if((Current_M1>=max_overcurrent || Current_M2>=max_overcurrent) && (time_overcurrent_first_rw1>0.0)){
			time_overcurrent_rw1=timer_indoor_system;
		}else{
			time_overcurrent_first_rw1=0;
			time_overcurrent_rw1=0;
		}

		if((time_overcurrent_rw1-time_overcurrent_first_rw1)>=max_time_overcurrent){
			flag_status_register_rw1[3]=1;
		}

	}


}

void Roboclaw2_State(UART_HandleTypeDef* address_huart,uint8_t address_roboclaw){

	bool set_0,set_1,set_2;
	float Current_M1,Current_M2;
	uint32_t Byte_Status_roboclaw;


	set_0=Read_Status(address_huart,(uint8_t)address_roboclaw, &Byte_Status_roboclaw);


	if(set_0==true){
		if((Byte_Status_roboclaw & 0x000000)==0x000000) flag_status_register_rw2[0]=1;//Normal Status
		if((Byte_Status_roboclaw & 0x080000)==0x080000) flag_status_register_rw2[1]=1;//Main Voltage Low Warning
		if((Byte_Status_roboclaw & 0x010000)==0x010000) flag_status_register_rw2[2]=1;//Temperature Warning
	}


	set_2=Read_Motor_Currents(address_huart,(uint8_t) address_roboclaw, &Current_M1,&Current_M2);
	if(set_2==true && flag_status_register_rw2[3]==0 ){

		if((Current_M1>=max_overcurrent || Current_M2>=max_overcurrent) && (time_overcurrent_first_rw2==0.0)){
			time_overcurrent_first_rw2=timer_indoor_system;
		}

		if((Current_M1>=max_overcurrent || Current_M2>=max_overcurrent) && (time_overcurrent_first_rw2>0.0)){
			time_overcurrent_rw2=timer_indoor_system;
		}else{
			time_overcurrent_first_rw2=0;
			time_overcurrent_rw2=0;
		}

		if((time_overcurrent_rw2-time_overcurrent_first_rw2)>=max_time_overcurrent){
			flag_status_register_rw2[3]=1;
		}

	}


}

bool Read_Status(UART_HandleTypeDef* address_huart,uint8_t address_roboclaw,uint32_t* Byte_Status){

	uint8_t txBuff[2]; // two bytes for address and cmd, two for value
	txBuff[0] = address_roboclaw; //first to write is address
	txBuff[1] = (uint8_t)90; // second is cmd
	HAL_UART_Transmit(address_huart, txBuff, sizeof(txBuff), 10);

	uint8_t rxBuff[6];
	HAL_UART_Receive(address_huart, rxBuff, 6,10);

	//CHECK THE CHK REGISTER-----------------
	uint8_t chk[6];
	memcpy(&chk[0],&txBuff[0],2);
	memcpy(&chk[2],&rxBuff[0],4);
	uint16_t crc_tx= crc16((unsigned char *)chk,6);
	uint16_t crc_rx= (rxBuff[4]<<8 | rxBuff[5]);
	//---------------------------------------



	if(crc_tx==crc_rx){

		*Byte_Status=(uint32_t)((rxBuff[0] << 24) | (rxBuff[1] << 16) | (rxBuff[2] << 8) | rxBuff[3]);

		return true;
	}
	else{
		return false;
	}

}
bool Read_Main_battery_Voltage(UART_HandleTypeDef* address_huart,uint8_t address_roboclaw, float* main_battery_voltage){

	uint8_t txBuff[2]; // two bytes for address and cmd, two for value
	txBuff[0] = address_roboclaw; //first to write is address
	txBuff[1] = (uint8_t)24; // second is cmd
	HAL_UART_Transmit(address_huart, txBuff, sizeof(txBuff), 10);

	uint8_t rxBuff[4];
	HAL_UART_Receive(address_huart, rxBuff, 4,10);

	//CHECK THE CHK REGISTER-----------------
	uint8_t chk[4];
	memcpy(&chk[0],&txBuff[0],2);
	memcpy(&chk[2],&rxBuff[0],2);
	uint16_t crc_tx= crc16((unsigned char *)chk,4);
	uint16_t crc_rx= (rxBuff[2]<<8 | rxBuff[3]);
	//---------------------------------------

	if(crc_tx==crc_rx){
		*main_battery_voltage=(float) ((uint16_t)((rxBuff[0] << 8) | (rxBuff[1])))/10.0;
		return true;
	}
	else{
		return false;
	}

}
bool Read_Motor_Currents(UART_HandleTypeDef* address_huart,uint8_t address_roboclaw, float *Current_M1_roboclaw, float *Current_M2_roboclaw){
	uint8_t txBuff[2]; // two bytes for address and cmd, two for value
	txBuff[0] = address_roboclaw; //first to write is address
	txBuff[1] = (uint8_t)49; // second is cmd
	HAL_UART_Transmit(address_huart, txBuff, sizeof(txBuff), 100);

	uint8_t rxBuff[6];
	HAL_UART_Receive(address_huart, rxBuff, 6,100);

	//CHECK THE CHK REGISTER-----------------
	uint8_t chk[6];
	memcpy(&chk[0],&txBuff[0],2);
	memcpy(&chk[2],&rxBuff[0],4);
	uint16_t crc_tx= crc16((unsigned char *)chk,6);
	uint16_t crc_rx= (rxBuff[4]<<8 | rxBuff[5]);
	//---------------------------------------

	if(crc_tx==crc_rx){
		*Current_M1_roboclaw=(float) ((uint16_t)((rxBuff[0] << 8) | (rxBuff[1])))/100.0;
		*Current_M2_roboclaw=(float) ((uint16_t)((rxBuff[2] << 8) | (rxBuff[3])))/100.0;
		return true;
	}
	else{
		return false;
	}

}

bool Reset_Encoder_Counters(UART_HandleTypeDef* address_huart,uint8_t address_roboclaw){
	  uint8_t txBuff[4];
	  txBuff[0] = address_roboclaw;
	  txBuff[1] = (uint8_t)20;


	  uint16_t crc_chk = crc16(txBuff, 2);
	  txBuff[2] = crc_chk >> 8; // high value byte
	  txBuff[3] = crc_chk; // low value byte
 	  HAL_UART_Transmit(address_huart, txBuff, sizeof(txBuff), 10);

 	  uint8_t rxBuff[1];
 	  HAL_UART_Receive(address_huart, rxBuff, 1,10);

 	  if(rxBuff[0]==(uint8_t)255){
 		  return true;
 	  }
 	  else{
 		  return false;
 	  }

}

bool roboclaw1_init(UART_HandleTypeDef* address_huart_roboclaw,uint8_t address_roboclaw){
		flag_status_register_rw1[0]=0;
		flag_status_register_rw1[1]=0;
		flag_status_register_rw1[2]=0;
		flag_status_register_rw1[3]=0;
		flag_status_register_rw1[4]=0;
		flag_status_register_rw1[5]=0;
		flag_status_register_rw1[6]=0;

	  	bool set_1=Set_Max_Motor_Current(address_huart_roboclaw,(uint8_t)address_roboclaw,1,3000);
	  	bool set_2=Set_Max_Motor_Current(address_huart_roboclaw,(uint8_t)address_roboclaw,2,3000);
	  	bool set_3=Drive_M1_M2_With_Signed_Speed(address_huart_roboclaw,(uint8_t)address_roboclaw, 0, 0);
	  	bool set_4=Reset_Encoder_Counters(address_huart_roboclaw,(uint8_t)address_roboclaw);

	  	if((set_1*set_2*set_3*set_4)==true){
	  	   		  return true;
	  	}
	  	else{
	  		return false;
	  	}

}
bool roboclaw2_init(UART_HandleTypeDef* address_huart_roboclaw,uint8_t address_roboclaw){
		flag_status_register_rw2[0]=0;
		flag_status_register_rw2[1]=0;
		flag_status_register_rw2[2]=0;
		flag_status_register_rw2[3]=0;
		flag_status_register_rw2[4]=0;
		flag_status_register_rw2[5]=0;
		flag_status_register_rw2[6]=0;

	  	bool set_1=Set_Max_Motor_Current(address_huart_roboclaw,(uint8_t)address_roboclaw,1,3000);
	  	bool set_2=Set_Max_Motor_Current(address_huart_roboclaw,(uint8_t)address_roboclaw,2,3000);
	  	bool set_3=Drive_M1_M2_With_Signed_Speed(address_huart_roboclaw,(uint8_t)address_roboclaw, 0, 0);
	  	bool set_4=Reset_Encoder_Counters(address_huart_roboclaw,(uint8_t)address_roboclaw);

	  	if((set_1*set_2*set_3*set_4)==true){
	  	   		  return true;
	  	}
	  	else{
	  		return false;
	  	}

}

uint16_t crc16(unsigned char *packet, int nBytes) {
  uint16_t crc=0;
  for (int byte = 0; byte < nBytes; byte++) {
    crc = crc ^ ((unsigned int)packet[byte] << 8);
    for (unsigned char bit = 0; bit < 8; bit++) {
      if (crc & 0x8000) {
        crc = (crc << 1) ^ 0x1021;
      } else {
        crc = crc << 1;
      }
    }
  }
  return crc;
}




/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
