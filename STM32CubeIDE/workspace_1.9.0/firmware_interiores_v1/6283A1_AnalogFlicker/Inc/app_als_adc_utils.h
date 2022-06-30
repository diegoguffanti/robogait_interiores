/**
 ******************************************************************************
 * @file    app_als_adc_utils.h
 * @author  IMG SW Application Team
 * @brief   This file provides a set of functions to manage the ADC
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __APP_ALS_ADC_UTILS_H__
#define __APP_ALS_ADC_UTILS_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Exported symbols ----------------------------------------------------------*/
#define ADC_FRAME_SIZE          512

/* Exported Functions --------------------------------------------------------*/
int32_t als_adc_start(uint32_t *fe);
int32_t als_adc_get_frame(int16_t *data, uint32_t *index);
int32_t als_adc_get_sample(int16_t *data);
int32_t als_adc_stop(void);

#ifdef __cplusplus
}
#endif

#endif /* __APP_ALS_ADC_UTILS_H__ */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
