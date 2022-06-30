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

/*
 * This example uses the CMSIS DSP Software Library provided by ARM.
 * In particular, the FFT is applied on the flicker signal sampled by the ADC.
 * Please refer to the following page in order to obtain more information about
 * the types and functions employed in this example:
 * https://www.keil.com/pack/doc/CMSIS/DSP/html/group__RealFFT.html
 * */

/* Includes ------------------------------------------------------------------*/
#include "app_x-cube-als.h"
#include "main.h"

#define ARM_MATH_CM4
#include "arm_math.h"

#include <stdio.h>

#include "app_als_adc_utils.h"

#include "6283a1_light_sensor.h"
#include "stm32f4xx_nucleo.h"

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/
#define LIGHT_SENSOR_INSTANCE_0 (0U)
#define FLK_CHANNEL	(5U)

/*
 * Increasing the value of the FLK_DATA_SIZE symbol will increase
 * processing time, flicker accuracy and memory footprint
 */
#define FLK_DATA_SIZE (1024U)
#define FFT_SIZE (FLK_DATA_SIZE)

/* Private variables ---------------------------------------------------------*/
static int32_t status;
static uint8_t is_quit_requested;
static uint8_t is_autogain_requested;
static int16_t flk_data[FLK_DATA_SIZE];
volatile uint8_t ALS_EventDetected;

/*
 * The FFT of a real N-point sequence has even symmetry in the frequency domain.
 * The second half of the data equals the conjugate of the first half flipped in frequency.
 * Looking at the data, we see that we can uniquely represent the FFT using only N/2 complex numbers.
 * These are packed into the output array in alternating real and imaginary components:
 * X = { real[0], imag[0], real[1], imag[1], real[2], imag[2] ... real[(N/2)-1], imag[(N/2)-1 }
 */
static arm_rfft_fast_instance_f32 instance_fft;
static float32_t fft_in[FLK_DATA_SIZE];
static float32_t fft_out_tmp[FFT_SIZE];
static float32_t fft_out[FFT_SIZE/2];

/* Private function prototypes -----------------------------------------------*/
static void MX_VD6283A1_AnalogFlicker_Init(void);
static void MX_VD6283A1_AnalogFlicker_Process(void);

static float32_t complex_abs(float32_t real, float32_t complex);
static void init_fft(arm_rfft_fast_instance_f32 *instance, uint32_t size);
static void perform_fft(arm_rfft_fast_instance_f32 *instance, int16_t *data, float32_t *ffti, float32_t *ffto, uint32_t size);
static void find_flk_freq(uint32_t fs, float32_t *ffto, uint32_t *freq, uint8_t skip_dc, uint32_t size);

static int32_t flicker_autogain(uint8_t Instance, uint32_t *pAppliedGain, uint32_t timeoutMs);

static void decrease_exposure(uint8_t Instance);
static void increase_exposure(uint8_t Instance);
static void decrease_gain(uint8_t Instance);
static void increase_gain(uint8_t Instance);

static void display_gain(uint32_t gain);
static void display_commands_banner(void);
static void handle_cmd(uint8_t cmd);
static uint8_t get_key(void);
static int32_t com_has_data(void);

void MX_X_CUBE_ALS_Init(void)
{
    /* USER CODE BEGIN SV */

    /* USER CODE END SV */

    /* USER CODE BEGIN ALS_Init_PreTreatment */

    /* USER CODE END ALS_Init_PreTreatment */

    /* Initialize the peripherals and the ALS components */
    MX_VD6283A1_AnalogFlicker_Init();

    /* USER CODE BEGIN ALS_Init_PostTreatment */

    /* USER CODE END ALS_Init_PostTreatment */
}

/*
 * LM background task
 */
void MX_X_CUBE_ALS_Process(void)
{
    /* USER CODE BEGIN ALS_Process_PreTreatment */

    /* USER CODE END ALS_Process_PreTreatment */
    MX_VD6283A1_AnalogFlicker_Process();
    /* USER CODE BEGIN ALS_Process_PostTreatment */

    /* USER CODE END ALS_Process_PostTreatment */
}

static void MX_VD6283A1_AnalogFlicker_Init(void)
{
    /* initialize Virtual COM Port */
    BSP_COM_Init(COM1);

    printf("VD6283TX Analog Flicker Example\n\n");
    display_commands_banner();

    /* initialize ARM FFT library */
    init_fft(&instance_fft, FFT_SIZE);

    status = VD6283A1_LIGHT_SENSOR_Init(LIGHT_SENSOR_INSTANCE_0);

    if (status)
    {
        printf("VD6283A1_LIGHT_SENSOR_Init failed\n");
        while(1);
    }
}

static void MX_VD6283A1_AnalogFlicker_Process(void)
{
    uint32_t fs; /* sampling frequency */
    uint32_t pos = 0; 
    uint32_t flk_freq = 0;
    uint32_t index;

    uint32_t current_gain;
    uint32_t current_exposure;

    /* initialize exposure time */
    VD6283A1_LIGHT_SENSOR_SetExposureTime(LIGHT_SENSOR_INSTANCE_0, 100000);
    VD6283A1_LIGHT_SENSOR_GetExposureTime(LIGHT_SENSOR_INSTANCE_0, &current_exposure);
    printf("Exposure set to %lu us\n", (unsigned long)current_exposure);

    /* initialize gain */
    flicker_autogain(LIGHT_SENSOR_INSTANCE_0, &current_gain, 1);
    printf("Channel %u gain set to", FLK_CHANNEL);
    display_gain(current_gain);

    status = als_adc_start(&fs);

    if (status)
    {
        printf("ADC Start failed\n");
        while (1);
    }

    VD6283A1_LIGHT_SENSOR_StartFlicker(LIGHT_SENSOR_INSTANCE_0, FLK_CHANNEL, LIGHT_SENSOR_FLICKER_ANALOG);

    while (!is_quit_requested)
    {
        status = als_adc_get_frame(&flk_data[pos], &index);

        /* fill the ADC frame buffer */
        if (status == 0)
        {
            pos += ADC_FRAME_SIZE;
        }

        /* if the ADC frame buffer is full, then process it */
        if (pos == FLK_DATA_SIZE)
        {
            perform_fft(&instance_fft, flk_data, fft_in, fft_out, FFT_SIZE);
            find_flk_freq(fs, fft_out, &flk_freq, 1, FFT_SIZE);
            pos = 0; /* reset position index */

            printf("Flicker freq: %4lu Hz\r", (unsigned long)flk_freq);
            fflush(stdout);

            if (is_autogain_requested == 1)
            {
              VD6283A1_LIGHT_SENSOR_StopFlicker(LIGHT_SENSOR_INSTANCE_0);

              flicker_autogain(LIGHT_SENSOR_INSTANCE_0, &current_gain, 1);
              printf("Channel %u gain set to", FLK_CHANNEL);
              display_gain(current_gain);

              VD6283A1_LIGHT_SENSOR_StartFlicker(LIGHT_SENSOR_INSTANCE_0, FLK_CHANNEL, LIGHT_SENSOR_FLICKER_ANALOG);
              is_autogain_requested = 0;
            }
        }

        handle_cmd(get_key());
    }

    als_adc_stop();

    VD6283A1_LIGHT_SENSOR_StopFlicker(LIGHT_SENSOR_INSTANCE_0);
    VD6283A1_LIGHT_SENSOR_DeInit(LIGHT_SENSOR_INSTANCE_0);

    printf("Quitting the demo...\n");
    while (1);
}

/* Private function implementation ------------------------------------------*/

/*
 * @brief compute absolute value of a complex number
 */
static float32_t complex_abs(float32_t real, float32_t complex)
{
  float32_t res;

  arm_sqrt_f32(real * real + complex * complex, &res);

  return res;
}

/*
 * @brief initilize arm rfft library
 */
static void init_fft(arm_rfft_fast_instance_f32 *instance, uint32_t size)
{
  arm_rfft_fast_init_f32(instance, size);
}

/*
 * @brief perform fft on the input buffer using arm rfft library
 */
static void perform_fft(arm_rfft_fast_instance_f32 *instance, int16_t *flk, float32_t *ffti, float32_t *ffto, uint32_t size)
{
    uint32_t i;
    uint32_t index = 0;

    /* copy the ADC sampled signal into the fft input buffer
     * this allows to convert the data from int16_t to float32_t */
    for (i = 0; i < size; i++)
    {
        ffti[i] = flk[i];
    }

    /* Perform the FFT on the input buffer:
     * results are packed in a way so that even indexes contain real values
     * and odd indexes contain the complex value of each bin.
     * Therefore the fft_output array contains FFT_SIZE / 2 bins */
    arm_rfft_fast_f32(instance, ffti, fft_out_tmp, 0);

    /* Calculate the magnitude for each bin from the temp fft output buffer */
    for (i = 0; i < size; i += 2)
    {
        ffto[index] = complex_abs(fft_out_tmp[i], fft_out_tmp[i+1]);
        if (ffto[index] < 0) ffto[index] = 0;
        index++;
    }
}

/*
 * @brief find peak frequency value
 */
static void find_flk_freq(uint32_t fs, float32_t *ffto, uint32_t *freq, uint8_t skip_dc, uint32_t size)
{
    uint32_t i;
    uint32_t res;
    uint32_t index_max = 0;
    uint32_t limit = size / 2;

    float32_t max_value = -1;

    /* do not take account of the DC value if the flag skip_dc is set */
    skip_dc ? (i = 1) : (i = 0);

    /* run through the output array to detect the peak */
    for (; i < limit; i++)
    {
        if (ffto[i] > max_value)
        {
            index_max = i;
            max_value = ffto[i];
        }
    }

    /* convert index of the bin into frequency */
    res = (index_max * fs) / size;

    /* return the result if the pointer is valid */
    if (freq)
    {
        *freq = res;
    }
}

/*
 * @brief find and apply appropriate gain value depending on saturation value
 * @warning this function mustn't be called when a capture is ongoing
 */
static int32_t flicker_autogain(uint8_t Instance, uint32_t *pAppliedGain, uint32_t timeoutMs)
{
  int32_t res;
  uint8_t i, j;
  uint8_t idx = 7; /* start with mid-table value */
  const uint8_t sat_limit = 2;
  uint32_t saturation;

  /* duplicate 0x42AB to avoid 100x and keep multiples of 2 for array size */
  const uint16_t Gains[] = {
    0x42AB, 0x42AB, 0x3200, 0x2154, 0x1900, 0x10AB, 0x0A00, 0x0723,
    0x0500, 0x0354, 0x0280, 0x01AB, 0x0140, 0x0100, 0x00D4, 0x00B5
  };

  /* clip timeout value */
  timeoutMs = timeoutMs == 0 ? 1 : timeoutMs;
  timeoutMs = timeoutMs >= 100 ? 100 : timeoutMs;

  for (i = 0; i <= 3; i++)
  {
    VD6283A1_LIGHT_SENSOR_SetGain(Instance, FLK_CHANNEL, Gains[idx]);
    VD6283A1_LIGHT_SENSOR_GetGain(Instance, FLK_CHANNEL, pAppliedGain);

    res = VD6283A1_LIGHT_SENSOR_StartFlicker(Instance, FLK_CHANNEL, LIGHT_SENSOR_FLICKER_ANALOG);
    
    if (res)
      return res;

    /* read saturation value each ms so we can exit early if saturation detected */
    for (j = 0; j < timeoutMs; j++)
    {
      HAL_Delay(1);

      res = VD6283A1_LIGHT_SENSOR_GetSaturation(Instance, &saturation);

      if (res)
        return res;
      if (saturation > sat_limit)
        break;
    }

    res = VD6283A1_LIGHT_SENSOR_StopFlicker(Instance);
    
    if (res)
      return res;

    /* update index to next value */
    if (i)
      idx += saturation > sat_limit ? 1 << (i - 1) : -(1 << (i - 1));
    else if (saturation > sat_limit)
      idx++;
  }

  /* clip index if it reaches max value */
  if (idx > 15) 
    idx = 15;

  VD6283A1_LIGHT_SENSOR_SetGain(Instance, FLK_CHANNEL, Gains[idx]);
  res = VD6283A1_LIGHT_SENSOR_GetGain(Instance, FLK_CHANNEL, pAppliedGain);

  return res;
}

/*
 * @brief divide exposure time by 2
 */
static void decrease_exposure(uint8_t Instance)
{
    uint32_t current_exposure;

    VD6283A1_LIGHT_SENSOR_GetExposureTime(Instance, &current_exposure);
    VD6283A1_LIGHT_SENSOR_SetExposureTime(Instance, current_exposure >> 1);
    VD6283A1_LIGHT_SENSOR_GetExposureTime(Instance, &current_exposure);
    printf("\nExposure set to %lu us\n", (unsigned long)current_exposure);
}

/*
 * @brief multiply exposure time by 2
 */
static void increase_exposure(uint8_t Instance)
{
    uint32_t current_exposure;

    VD6283A1_LIGHT_SENSOR_GetExposureTime(Instance, &current_exposure);
    VD6283A1_LIGHT_SENSOR_SetExposureTime(Instance, current_exposure << 1);
    VD6283A1_LIGHT_SENSOR_GetExposureTime(Instance, &current_exposure);
    printf("\nExposure set to %lu us\n", (unsigned long)current_exposure);
}

/*
 * @brief divide gain by 2 on all channels
 */
static void decrease_gain(uint8_t Instance)
{
    uint8_t c = FLK_CHANNEL;
    uint32_t current_gain;

    VD6283A1_LIGHT_SENSOR_GetGain(Instance, c, &current_gain);
    VD6283A1_LIGHT_SENSOR_SetGain(Instance, c, current_gain >> 1);
    VD6283A1_LIGHT_SENSOR_GetGain(Instance, c, &current_gain);
    printf("\nChannel %d gain set to", c);
    display_gain(current_gain);
}

/*
 * @brief multiply gain by 2 on all channels
 */
static void increase_gain(uint8_t Instance)
{
    uint8_t c = FLK_CHANNEL;
    uint32_t current_gain;

    VD6283A1_LIGHT_SENSOR_GetGain(Instance, c, &current_gain);
    VD6283A1_LIGHT_SENSOR_SetGain(Instance, c, current_gain << 1);
    VD6283A1_LIGHT_SENSOR_GetGain(Instance, c, &current_gain);
    printf("\nChannel %d gain set to", c);
    display_gain(current_gain);
}

/*
 * @brief normalize, convert and dislay gain 
 */
static void display_gain(uint32_t gain)
{
    uint32_t g = (gain * 100) / 256;

    printf(" %3lu.%02lu\n", (unsigned long)g / 100, (unsigned long)(g % 100));
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
    printf(" 'a' : autogain\n");
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
            VD6283A1_LIGHT_SENSOR_StopFlicker(LIGHT_SENSOR_INSTANCE_0);
            increase_gain(LIGHT_SENSOR_INSTANCE_0);
            VD6283A1_LIGHT_SENSOR_StartFlicker(LIGHT_SENSOR_INSTANCE_0, FLK_CHANNEL, LIGHT_SENSOR_FLICKER_ANALOG);
            break;
        case '2':
            VD6283A1_LIGHT_SENSOR_StopFlicker(LIGHT_SENSOR_INSTANCE_0);
            decrease_gain(LIGHT_SENSOR_INSTANCE_0);
            VD6283A1_LIGHT_SENSOR_StartFlicker(LIGHT_SENSOR_INSTANCE_0, FLK_CHANNEL, LIGHT_SENSOR_FLICKER_ANALOG);
            break;
        case '4':
            VD6283A1_LIGHT_SENSOR_StopFlicker(LIGHT_SENSOR_INSTANCE_0);
            decrease_exposure(LIGHT_SENSOR_INSTANCE_0);
            VD6283A1_LIGHT_SENSOR_StartFlicker(LIGHT_SENSOR_INSTANCE_0, FLK_CHANNEL, LIGHT_SENSOR_FLICKER_ANALOG);
            break;
        case '6':
            VD6283A1_LIGHT_SENSOR_StopFlicker(LIGHT_SENSOR_INSTANCE_0);
            increase_exposure(LIGHT_SENSOR_INSTANCE_0);
            VD6283A1_LIGHT_SENSOR_StartFlicker(LIGHT_SENSOR_INSTANCE_0, FLK_CHANNEL, LIGHT_SENSOR_FLICKER_ANALOG);
            break;
        case 'a':
            is_autogain_requested = 1;
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
    return __HAL_UART_GET_FLAG(&hcom_uart[COM1], UART_FLAG_RXNE);
}

#ifdef __cplusplus
}
#endif

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
