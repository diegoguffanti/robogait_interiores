/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stdbool.h"
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */
void setSpeed(float linear, float angular);
void odometryUpdater(int32_t enc_FL, int32_t enc_FR, int32_t enc_RL, int32_t enc_RR, int32_t w_FL, int32_t w_FR, int32_t w_RL, int32_t w_RR);

float map(float value, float in_low, float in_high, float out_low, float out_high);
void setPower(float power_M1, float power_M2, float power_M3, float power_M4);
//void build_buffer(int32_t px,int32_t py,int32_t th ,int32_t vx,int32_t vy, int32_t wz);
char* build_buffer(float px,float py,float th ,float vx,float vy, float wz);
int32_t Read_Encoder_Count(UART_HandleTypeDef* address_huart,uint8_t address_roboclaw, int motor);
bool Read_Encoder_Speed(UART_HandleTypeDef* address_huart, uint8_t address_roboclaw, int motor, int32_t *speedMX_roboclaw);
bool Read_Both_Encoder_Counts(UART_HandleTypeDef* address_huart,uint8_t address_roboclaw, int32_t *countsM1_roboclaw, int32_t *countsM2_roboclaw);
bool Read_Encoder_ISpeed(UART_HandleTypeDef* address_huart, uint8_t address_roboclaw, int32_t *IspeedM1_roboclaw, int32_t *IspeedM2_roboclaw);
uint16_t crc16(unsigned char *packet, int nBytes);
int Check_Status_Roboclaws();
bool roboclaw1_init(UART_HandleTypeDef* address_huart_roboclaw,uint8_t address_roboclaw);
bool roboclaw2_init(UART_HandleTypeDef* address_huart_roboclaw,uint8_t address_roboclaw);
bool Drive_M1_M2_With_Signed_Speed(UART_HandleTypeDef* address_huart,uint8_t address_roboclaw, int32_t SpeedM1, int32_t SpeedM2);
bool Set_Max_Motor_Current(UART_HandleTypeDef* address_huart,uint8_t address_roboclaw, int motor, int32_t max_current_value);
bool Read_Motor_Currents(UART_HandleTypeDef* address_huart,uint8_t address_roboclaw, float *Current_M1_roboclaw, float *Current_M2_roboclaw);
bool Reset_Encoder_Counters(UART_HandleTypeDef* address_huart,uint8_t address_roboclaw);
void Roboclaw1_State(UART_HandleTypeDef* address_huart,uint8_t address_roboclaw);
void Roboclaw2_State(UART_HandleTypeDef* address_huart,uint8_t address_roboclaw);
void update_Odometry();
void reset_Odometry();
bool Read_Main_battery_Voltage(UART_HandleTypeDef* address_huart,uint8_t address_roboclaw, float* main_battery_voltage);
bool Read_Status(UART_HandleTypeDef* address_huart,uint8_t address_roboclaw,uint32_t* Byte_Status);


/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define B1_reset_odom_Pin GPIO_PIN_13
#define B1_reset_odom_GPIO_Port GPIOC
#define USB_OverCurrent_Pin GPIO_PIN_7
#define USB_OverCurrent_GPIO_Port GPIOG
#define USB_SOF_Pin GPIO_PIN_8
#define USB_SOF_GPIO_Port GPIOA
#define USB_VBUS_Pin GPIO_PIN_9
#define USB_VBUS_GPIO_Port GPIOA
#define USB_ID_Pin GPIO_PIN_10
#define USB_ID_GPIO_Port GPIOA
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
