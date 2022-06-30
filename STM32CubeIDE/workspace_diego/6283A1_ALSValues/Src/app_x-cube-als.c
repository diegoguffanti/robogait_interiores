/**
  ******************************************************************************
  * File Name          : app_x-cube-als.c
  * Description        : This file provides code for the configuration
  *                      of the STMicroelectronics.X-CUBE-ALS.1.0.0 instances.
  ******************************************************************************
  *
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "app_x-cube-als.h"
#include "main.h"
#include <stdio.h>

#include "6283a1_light_sensor.h"
#include "stm32f4xx_nucleo.h"

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/
#define LIGHT_SENSOR_INSTANCE_0 (0U)

/* Private variables ---------------------------------------------------------*/
static int32_t status;
static uint8_t is_quit_requested;
static uint8_t is_dark_enabled;
static uint32_t AlsResults[VD6283TX_MAX_CHANNELS] = {0};

static const char *AlsChannelStr[] =
{
  [LIGHT_SENSOR_RED_CHANNEL] = "RED",
  [LIGHT_SENSOR_VISIBLE_CHANNEL] = "VISIBLE",
  [LIGHT_SENSOR_BLUE_CHANNEL] = "BLUE",
  [LIGHT_SENSOR_GREEN_CHANNEL] = "GREEN",
  [LIGHT_SENSOR_IR_CHANNEL] = "IR",
  [LIGHT_SENSOR_CLEAR_CHANNEL] = "CLEAR"
};

volatile uint8_t ALS_EventDetected;

/* Private function prototypes -----------------------------------------------*/
static void MX_VD6283A1_ALSValues_Init(void);
static void MX_VD6283A1_ALSValues_Process(void);

static void decrease_exposure(uint8_t Instance);
static void increase_exposure(uint8_t Instance);
static void decrease_inter_measurement(uint8_t Instance);
static void increase_inter_measurement(uint8_t Instance);
static void decrease_gain(uint8_t Instance);
static void increase_gain(uint8_t Instance);
static void toggle_dark_output(uint8_t Instance);

static void display_gain(uint32_t Gain);
static void display_commands_banner(void);
static void handle_cmd(uint8_t cmd);
static uint8_t get_key(void);
static int32_t com_has_data(void);

void MX_X_CUBE_ALS_Init(void)
{
  /* USER CODE BEGIN SV */

  /* USER CODE END SV */

  /* USER CODE BEGIN X_CUBE_ALS_Init_PreTreatment */

  /* USER CODE END X_CUBE_ALS_Init_PreTreatment */

  /* Initialize the peripherals and the MEMS components */

  MX_VD6283A1_ALSValues_Init();

  /* USER CODE BEGIN X_CUBE_ALS_Init_PostTreatment */

  /* USER CODE END X_CUBE_ALS_Init_PostTreatment */
}

/*
 * LM background task
 */
void MX_X_CUBE_ALS_Process(void)
{
  /* USER CODE BEGIN X_CUBE_ALS_Process_PreTreatment */

  /* USER CODE END X_CUBE_ALS_Process_PreTreatment */

  MX_VD6283A1_ALSValues_Process();

  /* USER CODE BEGIN X_CUBE_ALS_Process_PostTreatment */

  /* USER CODE END X_CUBE_ALS_Process_PostTreatment */
}

static void MX_VD6283A1_ALSValues_Init(void)
{
  /* Initialize Virtual COM Port */
  BSP_COM_Init(COM1);

  printf("VD6283TX ALS Values Example\n\n");
  display_commands_banner();

  status = VD6283A1_LIGHT_SENSOR_Init(LIGHT_SENSOR_INSTANCE_0);

  if (status)
  {
    printf("VD6283A1_LIGHT_SENSOR_Init failed\n");
    while(1);
  }
}

static void MX_VD6283A1_ALSValues_Process(void)
{
  uint8_t channel;
  uint32_t current_gain;
  uint32_t current_exposure;
  uint32_t current_imt; /* inter-measurement time */

  /* initialize exposure time */
  VD6283A1_LIGHT_SENSOR_SetExposureTime(LIGHT_SENSOR_INSTANCE_0, 100000); /* microseconds */
  VD6283A1_LIGHT_SENSOR_GetExposureTime(LIGHT_SENSOR_INSTANCE_0, &current_exposure);
  printf("Exposure set to %lu us\n", (unsigned long)current_exposure);

  /* initialize gains */
  for (channel = 0; channel < LIGHT_SENSOR_MAX_CHANNELS; channel++)
  {
    VD6283A1_LIGHT_SENSOR_SetGain(LIGHT_SENSOR_INSTANCE_0, channel, 256);
    VD6283A1_LIGHT_SENSOR_GetGain(LIGHT_SENSOR_INSTANCE_0, channel, &current_gain);
    printf("Channel %d gain set to", channel + 1);
    display_gain(current_gain);
  }

  /* initialize inter measurement time */
  VD6283A1_LIGHT_SENSOR_SetInterMeasurementTime(LIGHT_SENSOR_INSTANCE_0, 500000); /* 100 ms */
  VD6283A1_LIGHT_SENSOR_GetInterMeasurementTime(LIGHT_SENSOR_INSTANCE_0, &current_imt);

  /* start ALS capture on all channels in continuous mode */
  VD6283A1_LIGHT_SENSOR_Start(LIGHT_SENSOR_INSTANCE_0, LIGHT_SENSOR_MODE_CONTINUOUS);

  while (!is_quit_requested)
  {
    /* wait for interrupt event */
    if (ALS_EventDetected != 0U)
    {
      ALS_EventDetected = 0U;

      status = VD6283A1_LIGHT_SENSOR_GetValues(LIGHT_SENSOR_INSTANCE_0, AlsResults);

      if (status == BSP_ERROR_NONE)
      {
        /* display ALS values */
        for (channel = 0; channel < LIGHT_SENSOR_MAX_CHANNELS; channel++)
        {
          if (is_dark_enabled && (channel == LIGHT_SENSOR_VISIBLE_CHANNEL))
            printf("Channel %u - %8s", channel + 1, "DARK");
          else
            printf("Channel %u - %8s", channel + 1, AlsChannelStr[channel]);

          printf("\tValue: %lu\n", (unsigned long)AlsResults[channel]);
        }
        printf("\n\n");
      }
    }

    handle_cmd(get_key());
  }

  VD6283A1_LIGHT_SENSOR_Stop(LIGHT_SENSOR_INSTANCE_0);
  VD6283A1_LIGHT_SENSOR_DeInit(LIGHT_SENSOR_INSTANCE_0);

  printf("Quitting the demo...\n");
  while (1);
}

/* Private function implementation ------------------------------------------*/

/*
 * @brief divide exposure time by 2
 */
static void decrease_exposure(uint8_t Instance)
{
  uint32_t current_exposure;

  VD6283A1_LIGHT_SENSOR_Stop(LIGHT_SENSOR_INSTANCE_0);
  VD6283A1_LIGHT_SENSOR_GetExposureTime(Instance, &current_exposure);
  VD6283A1_LIGHT_SENSOR_SetExposureTime(Instance, current_exposure >> 1);
  VD6283A1_LIGHT_SENSOR_GetExposureTime(Instance, &current_exposure);
  VD6283A1_LIGHT_SENSOR_Start(LIGHT_SENSOR_INSTANCE_0, LIGHT_SENSOR_MODE_CONTINUOUS);
  printf("\nExposure set to %lu us\n", (unsigned long)current_exposure);
}

/*
 * @brief multiply exposure time by 2
 */
static void increase_exposure(uint8_t Instance)
{
  uint32_t current_exposure;

  VD6283A1_LIGHT_SENSOR_Stop(LIGHT_SENSOR_INSTANCE_0);
  VD6283A1_LIGHT_SENSOR_GetExposureTime(Instance, &current_exposure);
  VD6283A1_LIGHT_SENSOR_SetExposureTime(Instance, current_exposure << 1);
  VD6283A1_LIGHT_SENSOR_GetExposureTime(Instance, &current_exposure);
  VD6283A1_LIGHT_SENSOR_Start(LIGHT_SENSOR_INSTANCE_0, LIGHT_SENSOR_MODE_CONTINUOUS);
  printf("\nExposure set to %lu us\n", (unsigned long)current_exposure);
}

/*
 * @brief divide inter-measurement time by 2
 */
static void decrease_inter_measurement(uint8_t Instance)
{
  uint32_t current_imt;
  uint32_t next_imt;

  VD6283A1_LIGHT_SENSOR_Stop(LIGHT_SENSOR_INSTANCE_0);
  VD6283A1_LIGHT_SENSOR_GetInterMeasurementTime(Instance, &current_imt);
  next_imt = (current_imt == 20500) ? 0 : (current_imt >> 1);
  VD6283A1_LIGHT_SENSOR_SetInterMeasurementTime(Instance, next_imt);
  VD6283A1_LIGHT_SENSOR_GetInterMeasurementTime(Instance, &current_imt);
  VD6283A1_LIGHT_SENSOR_Start(LIGHT_SENSOR_INSTANCE_0, LIGHT_SENSOR_MODE_CONTINUOUS);
  printf("\nInter measurement set to %lu us\n", (unsigned long)current_imt);
}

/*
 * @brief multiply inter-measurement time by 2
 */
static void increase_inter_measurement(uint8_t Instance)
{
  uint32_t current_imt;
  uint32_t next_imt;

  VD6283A1_LIGHT_SENSOR_Stop(LIGHT_SENSOR_INSTANCE_0);
  VD6283A1_LIGHT_SENSOR_GetInterMeasurementTime(Instance, &current_imt);
  next_imt = (current_imt) ? (current_imt << 1) : 20500;
  VD6283A1_LIGHT_SENSOR_SetInterMeasurementTime(Instance, next_imt);
  VD6283A1_LIGHT_SENSOR_GetInterMeasurementTime(Instance, &current_imt);
  VD6283A1_LIGHT_SENSOR_Start(LIGHT_SENSOR_INSTANCE_0, LIGHT_SENSOR_MODE_CONTINUOUS);
  printf("\nInter measurement set to %lu us\n", (unsigned long)current_imt);
}

/*
 * @brief divide gain by 2 on all channels
 */
static void decrease_gain(uint8_t Instance)
{
  uint8_t c;
  uint32_t current_gain;

  VD6283A1_LIGHT_SENSOR_Stop(LIGHT_SENSOR_INSTANCE_0);

  printf("\n");
  for (c = 0; c < LIGHT_SENSOR_MAX_CHANNELS; c++)
  {
    VD6283A1_LIGHT_SENSOR_GetGain(Instance, c, &current_gain);
    VD6283A1_LIGHT_SENSOR_SetGain(Instance, c, current_gain >> 1);
    VD6283A1_LIGHT_SENSOR_GetGain(Instance, c, &current_gain);
    printf("Channel %u gain set to", c);
    display_gain(current_gain);
  }

  VD6283A1_LIGHT_SENSOR_Start(LIGHT_SENSOR_INSTANCE_0, LIGHT_SENSOR_MODE_CONTINUOUS);
}

/*
 * @brief multiply gain by 2 on all channels
 */
static void increase_gain(uint8_t Instance)
{
  uint8_t c;
  uint32_t current_gain;

  printf("\n");
  VD6283A1_LIGHT_SENSOR_Stop(LIGHT_SENSOR_INSTANCE_0);

  for (c = 0; c < LIGHT_SENSOR_MAX_CHANNELS; c++)
  {
    VD6283A1_LIGHT_SENSOR_GetGain(Instance, c, &current_gain);
    VD6283A1_LIGHT_SENSOR_SetGain(Instance, c, current_gain << 1);
    VD6283A1_LIGHT_SENSOR_GetGain(Instance, c, &current_gain);
    printf("Channel %u gain set to", c);
    display_gain(current_gain);
  }

  VD6283A1_LIGHT_SENSOR_Start(LIGHT_SENSOR_INSTANCE_0, LIGHT_SENSOR_MODE_CONTINUOUS);
}

/*
 * @brief enable/disable dark channel
 */
static void toggle_dark_output(uint8_t Instance)
{
  is_dark_enabled = !is_dark_enabled;
  VD6283A1_LIGHT_SENSOR_Stop(LIGHT_SENSOR_INSTANCE_0);
  VD6283A1_LIGHT_SENSOR_SetControlMode(Instance, LIGHT_SENSOR_CTRL_DARK, is_dark_enabled);
  VD6283A1_LIGHT_SENSOR_Start(LIGHT_SENSOR_INSTANCE_0, LIGHT_SENSOR_MODE_CONTINUOUS);
  printf("\nOutput dark enable is now %u\n", is_dark_enabled);
}

/*
 * @brief normalize, convert and dislay gain
 */
static void display_gain(uint32_t gain)
{
  uint32_t g = (gain * 100) / 256;

  printf(" %3lu.%02lu\n", g / 100, (g % 100));
}

/*
 * @brief display application commands
 */
static void display_commands_banner(void)
{
  printf("Use the following keys to control application\n");
  printf(" '8' : increase gain by 2\n");
  printf(" '2' : decrease gain by 2\n");
  printf(" '6' : increase exposure by 2\n");
  printf(" '4' : decrease exposure by 2\n");
  printf(" '3' : increase inter-measurement by 2\n");
  printf(" '1' : decrease inter-measurement by 2\n");
  printf(" 'd' : toggle dark for channel 2\n");
  printf(" 'q' : quit application\n");
  printf("\n");
}

/*
 * @brief process user command
 */
static void handle_cmd(uint8_t cmd)
{
  /* the device has to be stopped in order to perform one of these actions */
  switch (cmd)
  {
    case '8':
      increase_gain(LIGHT_SENSOR_INSTANCE_0);
      break;
    case '2':
      decrease_gain(LIGHT_SENSOR_INSTANCE_0);
      break;
    case '4':
      decrease_exposure(LIGHT_SENSOR_INSTANCE_0);
      break;
    case '6':
      increase_exposure(LIGHT_SENSOR_INSTANCE_0);
      break;
    case '1':
      decrease_inter_measurement(LIGHT_SENSOR_INSTANCE_0);
      break;
    case '3':
      increase_inter_measurement(LIGHT_SENSOR_INSTANCE_0);
      break;
    case 'd':
      toggle_dark_output(LIGHT_SENSOR_INSTANCE_0);
      break;
    case 'q':
      is_quit_requested = 1;
      break;
  }
}

/*
 * @brief read new character from uart if availble
 */
static uint8_t get_key(void)
{
  uint8_t cmd = 0;

  if (com_has_data())
  {
    HAL_UART_Receive(&hcom_uart[COM1], &cmd, 1, HAL_MAX_DELAY);
  }

  return cmd;
}

/*
 * @brief check if new data is available on uart
 */
static int32_t com_has_data(void)
{
  return __HAL_UART_GET_FLAG(&hcom_uart[COM1], UART_FLAG_RXNE);;
}

#ifdef __cplusplus
}
#endif

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
