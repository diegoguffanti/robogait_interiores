/**
 ******************************************************************************
 * @file    app_als_int_pin.c
 * @author  IMG SW Application Team
 * @brief   This file contains the ALS interrupt callback
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

extern volatile uint8_t ALS_EventDetected;

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  if (GPIO_Pin == GPIO_PIN_0)
  {
    ALS_EventDetected = 1;
  }
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
