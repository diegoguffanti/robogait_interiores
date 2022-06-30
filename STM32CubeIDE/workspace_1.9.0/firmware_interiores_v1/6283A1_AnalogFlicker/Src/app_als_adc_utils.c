/**
 ******************************************************************************
 * @file    app_als_adc_utils.c
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

/* Includes ------------------------------------------------------------------*/
#include "app_als_adc_utils.h"
#include <string.h>

#define ADC_SAMPLING_FREQ 8000

extern ADC_HandleTypeDef hadc1;
extern TIM_HandleTypeDef htim2;

static uint16_t samples[4][ADC_FRAME_SIZE];
static uint32_t indexer[4];
static uint16_t ptr_rd;
static uint16_t ptr_wr;
static uint32_t sample_index;
static uint32_t irq_wr_index;

static int16_t single_sample;
static volatile uint8_t is_single_sample_ready;

int32_t als_adc_start(uint32_t *fe)
{
	HAL_StatusTypeDef res;

	ptr_rd = 0;
	ptr_wr = 0;
	sample_index = 0;
	irq_wr_index = 0;
	indexer[0] = 0;

	res = HAL_TIM_Base_Start(&htim2);

	if (res)
	{
		return -1;
	}

	res = HAL_ADC_Start_IT(&hadc1);

	if (res)
	{
		return -1;
	}

	*fe = ADC_SAMPLING_FREQ;

	return 0;
}

int32_t als_adc_get_frame(int16_t *data, uint32_t *index)
{
	if (ptr_rd == ptr_wr)
	{
		return -1;
	}

	memcpy(data, samples[ptr_rd], ADC_FRAME_SIZE * 2);
	*index = indexer[ptr_rd];
	ptr_rd = (ptr_rd + 1) % 4;

	return 0;
}

int32_t plaform_adc_get_sample(int16_t *data)
{
	if (!is_single_sample_ready)
	{
		return -1;
	}

	*data = single_sample;
	is_single_sample_ready = 0;

	return 0;
}

int32_t als_adc_stop(void)
{
	HAL_StatusTypeDef res1;
	HAL_StatusTypeDef res2;

	res1 = HAL_ADC_Stop_IT(&hadc1);
	res2 = HAL_TIM_Base_Stop(&htim2);

	return res1 || res2 ? -1 : 0;
}

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
{
	uint16_t sample;

	sample = HAL_ADC_GetValue(&hadc1);

	/* update single sample */
	if (!is_single_sample_ready)
	{
		single_sample = sample;
		is_single_sample_ready = 1;
	}

	/* first test if we have space to write datas */
	if (irq_wr_index == ADC_FRAME_SIZE)
	{
		if (((ptr_wr + 1) % 4) == ptr_rd)
		{
			sample_index++;
			return;
		}
		/* ok we can write more datas */
		ptr_wr = (ptr_wr + 1) % 4;
		indexer[ptr_wr] = sample_index;
		irq_wr_index = 0;
	}

	samples[ptr_wr][irq_wr_index++] = sample;
	sample_index++;
}
