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
#include "MPU9250.h"



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

TIM_HandleTypeDef htim1;
TIM_HandleTypeDef htim2;
TIM_HandleTypeDef htim3;
TIM_HandleTypeDef htim4;
TIM_HandleTypeDef htim5;
TIM_HandleTypeDef htim8;

UART_HandleTypeDef huart3;
UART_HandleTypeDef huart6;

/* USER CODE BEGIN PV */
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
char a[sizeof(float)];

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


uint8_t buffer_txt[80];
uint8_t buffer[64];

uint8_t bufferaux_v[64];
uint8_t bufferaux_w[64];
float v_in=0;
float w_in=0;
char test1;
int intposv=0;
int intposw=0;
//char *data="HolaDiego";




//Motor encoder----------------------------
//float enc_res=979.0;
float enc_res=1632.0;
float sampling_time=20.0; //20ms
float tyre_deflection=1.0;

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

float rot_radio=0;
float new_L_enc_speed=0;
float new_R_enc_speed=0;
//------------------------------------


//updateOdometry fun-------------------------
float wheel_L_ang_vel=0;
float wheel_R_ang_vel=0;
float wheel_L_ang_pos=0;
float wheel_R_ang_pos=0;

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
float robot_x_vel=0;
float robot_y_vel=0;
float robot_x_pos=0;
float robot_y_pos=0;
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
unsigned char tx_buf[20], rx_buf[12]; //Buffers UART
float v_in, w_in, cam_in; //Valores deseados entrantes
float px_cur, py_cur, v_cur, w_cur, cam_cur; //Valores actuales salientes



#define ACC_FULL_SCALE_2_G       0x00
#define ACC_FULL_SCALE_4_G       0x08
#define ACC_FULL_SCALE_8_G       0x10
#define ACC_FULL_SCALE_16_G      0x18
float acc_x,acc_y,acc_z;

#define GYRO_FULL_SCALE_250_DPS  0x00
#define GYRO_FULL_SCALE_500_DPS  0x08
#define GYRO_FULL_SCALE_1000_DPS 0x10
#define GYRO_FULL_SCALE_2000_DPS 0x18
float gyro_x,gyro_y,gyro_z;

#define MAG_MODE_POWERDOWN        0x0
#define MAG_MODE_SINGLE           0x1
#define MAG_MODE_CONTINUOUS_8HZ   0x2
#define MAG_MODE_EXTERNAL         0x4
#define MAG_MODE_CONTINUOUS_100HZ 0x6
#define MAG_MODE_SELFTEST         0x8
#define MAG_MODE_FUSEROM          0xF
#define AK8963_ADDRESS  0x0C
#define AK8963_RA_HXL   0x03
#define AK8963_RA_CNTL1 0x0A
#define AK8963_RA_ASAX  0x10
float mag_x,mag_y,mag_z,magHoriz;


/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART3_UART_Init(void);
static void MX_TIM2_Init(void);
static void MX_TIM3_Init(void);
static void MX_TIM4_Init(void);
static void MX_TIM5_Init(void);
static void MX_USART6_UART_Init(void);
static void MX_ADC1_Init(void);
static void MX_TIM1_Init(void);
static void MX_I2C1_Init(void);
static void MX_TIM8_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
/*char readBuf[1];
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *UartHandle) {
  Se recibe el caracter y se pide el siguiente
 HAL_UART_Receive_IT(&huart6, (uint8_t*)readBuf, 1);
}*/




void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim){
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


}




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
  MX_TIM3_Init();
  MX_TIM4_Init();
  MX_TIM5_Init();
  MX_USART6_UART_Init();
  MX_ADC1_Init();
  MX_USB_DEVICE_Init();
  MX_TIM1_Init();
  MX_I2C1_Init();
  MX_TIM8_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3);
  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_4);
  HAL_TIM_Encoder_Start_IT(&htim2, TIM_CHANNEL_ALL);
  HAL_TIM_Encoder_Start_IT(&htim3, TIM_CHANNEL_ALL);
  HAL_TIM_Encoder_Start_IT(&htim4, TIM_CHANNEL_ALL);
  HAL_TIM_Encoder_Start_IT(&htim5, TIM_CHANNEL_ALL);



  MPU9250_beginAccel(ACC_FULL_SCALE_16_G);

  MPU9250_beginGyro(GYRO_FULL_SCALE_2000_DPS);

  MPU9250_beginMag(MAG_MODE_CONTINUOUS_100HZ);





  //HAL_ADCEx_InjectedStart(&hadc1);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  //HAL_UART_Receive_IT(&huart6, (uint8_t*)readBuf, 1);

  while (1)
  {



    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

	  //counter=__HAL_TIM_GET_COUNTER(&htim2);
	  //counter_M1=__HAL_TIM_GET_COUNTER(&htim2);
	  //counter_M2=__HAL_TIM_GET_COUNTER(&htim2);
	  //counter_M3=__HAL_TIM_GET_COUNTER(&htim2);
	  //counter_M4=__HAL_TIM_GET_COUNTER(&htim2);

	  //counter_M1=(int16_t)__HAL_TIM_GET_COUNTER(&htim2);
	  //counter_M2=(int16_t)__HAL_TIM_GET_COUNTER(&htim3);
	  //counter_M3=(int16_t)__HAL_TIM_GET_COUNTER(&htim4);
	  //counter_M4=(int16_t)__HAL_TIM_GET_COUNTER(&htim5);


	  /*for(int i=0;i<sizeof(buffer);i++)
	  	  	  {
	  		  	  buffer[0]=(int)'v';
	  		  	  buffer[1]=(int)'1';
	  		  	  buffer[2]=(int)'.';
	  		  	  buffer[3]=(int)'2';
	  		  	  buffer[4]=(int)'w';
	  		  	  buffer[5]=(int)'4';


	  		  	  test1=buffer[i];
	  		  	  if(strcmp(&test1,"v")==0) intposv=i;
	  	  		  if(strcmp(&test1, "w")==0) intposw=i;
	  	  	  }

	  memcpy(&bufferaux,&buffer[intposv+1],intposw-intposv-1); v_in=(float)atof(bufferaux);
	  memcpy(&bufferaux,&buffer[intposw+1],sizeof(buffer)); w_in=(float)atof(bufferaux);*/


	  //*buffertest=(uint8_t)x1;

	  info[0]=1.14;
	  info[1]=2.14;
	  info[2]=3.14;


	  //memcpy(a, &f, sizeof(float));
	  //s = (char *) &f;

	  //memcpy(data1,&info,sizeof(info));

	  //out_s=(char)x1;

	  //sprintf(buffertest, &x1);

	  //float px=1.1413121212121212;
	  //float py=2.6414121212121212;
	  //float th=3.1415121212121212;
	  //float vx=4.5416121212121212;
	  //float vy=5.8417121212121212;
	  //float wz=6.2418121212121212;
	  //int txt_resolution=5;
	  //strcpy(buffer_txt,build_buffer(px, py, th, vx, vy, wz,txt_resolution));


	  //strcat(buffer_txt,"y");
	  //strcat(buffer_txt,sz);


	  /*px_cur=3.1415;
	  py_cur=2.18;
	  v_cur=7.10;
	  w_cur=1.54;
	  cam_cur=3.17;


	  tx_ptr = (unsigned char*)&px_cur; //Posicion x (actual)
	  for (int i = 0; i < 4; i++) tx_buf[i] = *(tx_ptr + i);
	  tx_ptr = (unsigned char*)&py_cur; //Posicion y (actual)
	  for (int i = 4; i < 8; i++) tx_buf[i] = *(tx_ptr + i);
	  tx_ptr = (unsigned char*)&v_cur; //Velocidad x (actual)
	  for (int i = 8; i < 12; i++) tx_buf[i] = *(tx_ptr + i);
	  tx_ptr = (unsigned char*)&w_cur; //Rotacion z (actual)
	  for (int i = 12; i < 16; i++) tx_buf[i] = *(tx_ptr + i);
	  tx_ptr = (unsigned char*)&cam_cur; //Angulo camara (actual)
	  for (int i = 16; i < 20; i++) tx_buf[i] = *(tx_ptr + i);
	  CDC_Transmit_FS((uint8_t *)tx_buf, sizeof(tx_buf));*/


	  //ftoa(n, res, 4);
	  //sprintf(n)



	  //strcpy(szaux,float_to_char(0.000015, 5));

	  //__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, 4200);
	  //__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, 4200);
	  //__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_3, 4200);
	  //__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_4, 4200);

	  //count_tim1=__HAL_TIM_GET_COUNTER(&htim1);


	  //setPower(4800, 4800, 4800, 4800);
	  //HAL_Delay(10);


	  //M1=(int16_t)__HAL_TIM_GET_COUNTER(&htim2);//Encoder M1
	  //M2=(int16_t)__HAL_TIM_GET_COUNTER(&htim3);//Encoder M2
	  //M3=(int16_t)__HAL_TIM_GET_COUNTER(&htim4);//Encoder M3
	  //M4=(int16_t)__HAL_TIM_GET_COUNTER(&htim5);//Encoder M4


	  MPU9250_accelUpdate();
	  MPU9250_gyroUpdate();
	  MPU9250_magUpdate();



	  acc_x=MPU9250_accelX();
	  acc_y=MPU9250_accelY();
	  acc_z=MPU9250_accelZ();

	  gyro_x=MPU9250_gyroX();
	  gyro_y=MPU9250_gyroY();
	  gyro_z=MPU9250_gyroZ();

	  mag_x=MPU9250_magX();
	  mag_y=MPU9250_magY();
	  mag_z=MPU9250_magZ();
	  magHoriz=MPU9250_magHorizDirection();























	  //CDC_Transmit_FS((uint8_t *) data, strlen (data));
	  //HAL_Delay(10);




  	  //__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, cmd_pulse);
  	  //__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, cmd_pulse);
  	  //__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_3, cmd_pulse);
  	  //__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_4, cmd_pulse);
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
  sConfig.Channel = ADC_CHANNEL_2;
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
  * @brief TIM1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM1_Init(void)
{

  /* USER CODE BEGIN TIM1_Init 0 */

  /* USER CODE END TIM1_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};
  TIM_BreakDeadTimeConfigTypeDef sBreakDeadTimeConfig = {0};

  /* USER CODE BEGIN TIM1_Init 1 */

  /* USER CODE END TIM1_Init 1 */
  htim1.Instance = TIM1;
  htim1.Init.Prescaler = 59;
  htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim1.Init.Period = 56000;
  htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim1.Init.RepetitionCounter = 0;
  htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim1) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim1, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_Init(&htim1) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCNPolarity = TIM_OCNPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  sConfigOC.OCIdleState = TIM_OCIDLESTATE_RESET;
  sConfigOC.OCNIdleState = TIM_OCNIDLESTATE_RESET;
  if (HAL_TIM_PWM_ConfigChannel(&htim1, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_ConfigChannel(&htim1, &sConfigOC, TIM_CHANNEL_2) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_ConfigChannel(&htim1, &sConfigOC, TIM_CHANNEL_3) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_ConfigChannel(&htim1, &sConfigOC, TIM_CHANNEL_4) != HAL_OK)
  {
    Error_Handler();
  }
  sBreakDeadTimeConfig.OffStateRunMode = TIM_OSSR_DISABLE;
  sBreakDeadTimeConfig.OffStateIDLEMode = TIM_OSSI_DISABLE;
  sBreakDeadTimeConfig.LockLevel = TIM_LOCKLEVEL_OFF;
  sBreakDeadTimeConfig.DeadTime = 0;
  sBreakDeadTimeConfig.BreakState = TIM_BREAK_DISABLE;
  sBreakDeadTimeConfig.BreakPolarity = TIM_BREAKPOLARITY_HIGH;
  sBreakDeadTimeConfig.AutomaticOutput = TIM_AUTOMATICOUTPUT_DISABLE;
  if (HAL_TIMEx_ConfigBreakDeadTime(&htim1, &sBreakDeadTimeConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM1_Init 2 */

  /* USER CODE END TIM1_Init 2 */
  HAL_TIM_MspPostInit(&htim1);

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

  TIM_Encoder_InitTypeDef sConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 0;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 4294967295;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  sConfig.EncoderMode = TIM_ENCODERMODE_TI12;
  sConfig.IC1Polarity = TIM_ICPOLARITY_RISING;
  sConfig.IC1Selection = TIM_ICSELECTION_DIRECTTI;
  sConfig.IC1Prescaler = TIM_ICPSC_DIV1;
  sConfig.IC1Filter = 0;
  sConfig.IC2Polarity = TIM_ICPOLARITY_RISING;
  sConfig.IC2Selection = TIM_ICSELECTION_DIRECTTI;
  sConfig.IC2Prescaler = TIM_ICPSC_DIV1;
  sConfig.IC2Filter = 0;
  if (HAL_TIM_Encoder_Init(&htim2, &sConfig) != HAL_OK)
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
  * @brief TIM3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM3_Init(void)
{

  /* USER CODE BEGIN TIM3_Init 0 */

  /* USER CODE END TIM3_Init 0 */

  TIM_Encoder_InitTypeDef sConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM3_Init 1 */

  /* USER CODE END TIM3_Init 1 */
  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 0;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = 65535;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  sConfig.EncoderMode = TIM_ENCODERMODE_TI12;
  sConfig.IC1Polarity = TIM_ICPOLARITY_RISING;
  sConfig.IC1Selection = TIM_ICSELECTION_DIRECTTI;
  sConfig.IC1Prescaler = TIM_ICPSC_DIV1;
  sConfig.IC1Filter = 0;
  sConfig.IC2Polarity = TIM_ICPOLARITY_RISING;
  sConfig.IC2Selection = TIM_ICSELECTION_DIRECTTI;
  sConfig.IC2Prescaler = TIM_ICPSC_DIV1;
  sConfig.IC2Filter = 0;
  if (HAL_TIM_Encoder_Init(&htim3, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM3_Init 2 */

  /* USER CODE END TIM3_Init 2 */

}

/**
  * @brief TIM4 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM4_Init(void)
{

  /* USER CODE BEGIN TIM4_Init 0 */

  /* USER CODE END TIM4_Init 0 */

  TIM_Encoder_InitTypeDef sConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM4_Init 1 */

  /* USER CODE END TIM4_Init 1 */
  htim4.Instance = TIM4;
  htim4.Init.Prescaler = 0;
  htim4.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim4.Init.Period = 65535;
  htim4.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim4.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  sConfig.EncoderMode = TIM_ENCODERMODE_TI12;
  sConfig.IC1Polarity = TIM_ICPOLARITY_RISING;
  sConfig.IC1Selection = TIM_ICSELECTION_DIRECTTI;
  sConfig.IC1Prescaler = TIM_ICPSC_DIV1;
  sConfig.IC1Filter = 0;
  sConfig.IC2Polarity = TIM_ICPOLARITY_RISING;
  sConfig.IC2Selection = TIM_ICSELECTION_DIRECTTI;
  sConfig.IC2Prescaler = TIM_ICPSC_DIV1;
  sConfig.IC2Filter = 0;
  if (HAL_TIM_Encoder_Init(&htim4, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim4, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM4_Init 2 */

  /* USER CODE END TIM4_Init 2 */

}

/**
  * @brief TIM5 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM5_Init(void)
{

  /* USER CODE BEGIN TIM5_Init 0 */

  /* USER CODE END TIM5_Init 0 */

  TIM_Encoder_InitTypeDef sConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM5_Init 1 */

  /* USER CODE END TIM5_Init 1 */
  htim5.Instance = TIM5;
  htim5.Init.Prescaler = 0;
  htim5.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim5.Init.Period = 4294967295;
  htim5.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim5.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  sConfig.EncoderMode = TIM_ENCODERMODE_TI12;
  sConfig.IC1Polarity = TIM_ICPOLARITY_RISING;
  sConfig.IC1Selection = TIM_ICSELECTION_DIRECTTI;
  sConfig.IC1Prescaler = TIM_ICPSC_DIV1;
  sConfig.IC1Filter = 0;
  sConfig.IC2Polarity = TIM_ICPOLARITY_RISING;
  sConfig.IC2Selection = TIM_ICSELECTION_DIRECTTI;
  sConfig.IC2Prescaler = TIM_ICPSC_DIV1;
  sConfig.IC2Filter = 0;
  if (HAL_TIM_Encoder_Init(&htim5, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim5, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM5_Init 2 */

  /* USER CODE END TIM5_Init 2 */

}

/**
  * @brief TIM8 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM8_Init(void)
{

  /* USER CODE BEGIN TIM8_Init 0 */

  /* USER CODE END TIM8_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};
  TIM_BreakDeadTimeConfigTypeDef sBreakDeadTimeConfig = {0};

  /* USER CODE BEGIN TIM8_Init 1 */

  /* USER CODE END TIM8_Init 1 */
  htim8.Instance = TIM8;
  htim8.Init.Prescaler = 0;
  htim8.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim8.Init.Period = 65535;
  htim8.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim8.Init.RepetitionCounter = 0;
  htim8.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim8) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim8, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_Init(&htim8) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim8, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCNPolarity = TIM_OCNPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  sConfigOC.OCIdleState = TIM_OCIDLESTATE_RESET;
  sConfigOC.OCNIdleState = TIM_OCNIDLESTATE_RESET;
  if (HAL_TIM_PWM_ConfigChannel(&htim8, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  sBreakDeadTimeConfig.OffStateRunMode = TIM_OSSR_DISABLE;
  sBreakDeadTimeConfig.OffStateIDLEMode = TIM_OSSI_DISABLE;
  sBreakDeadTimeConfig.LockLevel = TIM_LOCKLEVEL_OFF;
  sBreakDeadTimeConfig.DeadTime = 0;
  sBreakDeadTimeConfig.BreakState = TIM_BREAK_DISABLE;
  sBreakDeadTimeConfig.BreakPolarity = TIM_BREAKPOLARITY_HIGH;
  sBreakDeadTimeConfig.AutomaticOutput = TIM_AUTOMATICOUTPUT_DISABLE;
  if (HAL_TIMEx_ConfigBreakDeadTime(&htim8, &sBreakDeadTimeConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM8_Init 2 */

  /* USER CODE END TIM8_Init 2 */
  HAL_TIM_MspPostInit(&htim8);

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
  huart3.Init.BaudRate = 115200;
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
  huart6.Init.BaudRate = 115200;
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
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOG_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOG, GPIO_PIN_6, GPIO_PIN_RESET);

  /*Configure GPIO pin : USER_Btn_Pin */
  GPIO_InitStruct.Pin = USER_Btn_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(USER_Btn_GPIO_Port, &GPIO_InitStruct);

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

}

/* USER CODE BEGIN 4 */

char* build_buffer(float px,float py,float th ,float vx,float vy, float wz){

	static char sz_buff[80];
	memset(sz_buff,'\0',80);
	char res[20];

	sprintf(res,"px%.6f%s",px,",");
	strcat(sz_buff,res);
	sprintf(res,"py%.6f%s",py,",");
	strcat(sz_buff,res);
	sprintf(res,"th%.6f%s",th,",");
	strcat(sz_buff,res);
	sprintf(res,"vx%.6f%s",vx,",");
	strcat(sz_buff,res);
	sprintf(res,"vy%.6f%s",vy,",");
	strcat(sz_buff,res);
	sprintf(res,"wz%.6f%s",wz,"n");
	strcat(sz_buff,res);








	return sz_buff;
}


void setPower(float power_M1, float power_M2, float power_M3, float power_M4)
{
	M1_pwm = map(power_M1,min_speed,max_speed,min_pwm,max_pwm);
	M2_pwm = map(power_M2,min_speed,max_speed,min_pwm,max_pwm);
	M3_pwm = map(power_M3,min_speed,max_speed,min_pwm,max_pwm);
	M4_pwm = map(power_M4,min_speed,max_speed,min_pwm,max_pwm);

	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, M1_pwm);
	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, M2_pwm);
	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_3, M3_pwm);
	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_4, M4_pwm);


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
