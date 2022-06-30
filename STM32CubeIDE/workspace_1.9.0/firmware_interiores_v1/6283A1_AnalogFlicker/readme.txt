/**
  @page 6283A1_AnalogFlicker example based on X-NUCLEO-6283A1 expansion board and STM32 Nucleo boards
  
  @verbatim
  ******************************************************************************
  * @file    readme.txt
  * @author  IMG SW Application Team
  * @brief   This example shows how to extract flicker frquency 
  *          using the vd6283tx light sensor embedded on X-NUCLEO-62863A1 expansion board.
  *          The user can adjust gain and exposure time using the keypad.
  *          The communication is done using a UART connection with the PC.
  ******************************************************************************
  *
  * Copyright (c) 2021 STMicroelectronics. All rights reserved.
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  @endverbatim

@par Example Description 

This example shows how to use X-NUCLEO-6283A1 expansion board and a STM32 Nucleo board to extract flicker frequency 
from the sensor and send them to a connected PC via a UART. Data can be displayed on generic applications such as TeraTerm.
The user can adjust gain and exposure time.

A ADC and a timer are used in order to perform periodic conversions of the analog flicker output signal.
Then a FFT (Fast Fourier Transform) is applied on the signal in order to find the peak frequency.

The sample application uses the following default serial settings:
  - Baud Rate: 115200
  - Data Bits: 8
  - Parity: None
  - Stop Bits: 1

Please refer to AN5639 application note for more technical details regarding this example.

Warning: this application's results are not guaranteed for frequencies below 60 Hz.
Warning: the MDK-ARM project is compatible only with version 6 of ARM compiler.

------------------------------------
WARNING: When starting the project from Example Selector in STM32CubeMX and regenerating 
it from ioc file, you may face a build issue. To solve it, remove from the IDE project 
the file stm32f4xx_nucleo.c in Application/User virtual folder and delete from Src and 
Inc folders the files: stm32f4xx_nucleo.c, stm32f4xx_nucleo.h and stm32f4xx_nucleo_errno.h.
------------------------------------

@par Keywords

ALS, I2C, VCOM

@par Hardware and Software environment

  - This example runs on STM32 Nucleo devices with ALS sensor expansion board (X-NUCLEO-6283A1)
  - This example has been tested with STMicroelectronics:
    - NUCLEO-F401RE RevC board
    - NUCLEO-L476RG RevC board

ADDITIONAL_BOARD : X-NUCLEO-6283A1 https://www.st.com/en/evaluation-tools/x-nucleo-6283a1.html
ADDITIONAL_COMP : VD6283TX https://www.st.com/en/imaging-and-photonics-solutions/vd6283tx.html

@par How to use it ? 

This package contains projects for 3 IDEs: IAR, Keil uVision and STM32CubeIDE. In order to make the 
program work, you must do the following:
  - WARNING: before opening the project with any toolchain be sure your folder
    installation path is not too in-depth since the toolchain may report errors
    after building.
  - Open STM32CubeIDE or alternatively the Keil uVision toolchain or the IAR toolchain.
  - Rebuild all files and load your image into target memory.
  - Run the example.
  - Alternatively, you can download the pre-built binaries in "Binary" 
    folder included in the distributed package.


 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */