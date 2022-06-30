---
pagetitle: Release Notes for 6283A1_ALSValues sample application for NUCLEO-F401RE
lang: en
header-includes: <link rel="icon" type="image/x-icon" href="_htmresc/favicon.png" />
---

::: {.row}
::: {.col-sm-12 .col-lg-4}

<center>
# Release Notes for <mark>6283A1_ALSValues</mark> sample applications for <mark>NUCLEO-F401RE</mark>
Copyright &copy; 2021 STMicroelectronics\
    
[![ST logo](_htmresc/st_logo_2020.png)](https://www.st.com){.logo}
</center>

# License

This software component is licensed by ST under SLA0044, the "License"; You may not use this component except in compliance with the License. You may obtain a copy of the License at:

[SLA0044: SOFTWARE LICENSE AGREEMENT](https://www.st.com/content/ccc/resource/legal/legal_agreement/license_agreement/group0/87/0c/3d/ad/0a/ba/44/26/DM00216740/files/DM00216740.pdf/jcr:content/translations/en.DM00216740.pdf)

# Purpose

This example shows how to retrieve light counts from vd6283tx light sensor embedded on X-NUCLEO-62863A1 expansion board. The user can adjust gain, exposure time and inter-measurement using the keypad. The communication is done using a UART connection with the PC.

:::

::: {.col-sm-12 .col-lg-8}
# Update history

::: {.collapse}
<input type="checkbox" id="collapse-section2" checked aria-hidden="true">
<label for="collapse-section2" aria-hidden="true">__V1.0.1 / July 12th 2021__</label>
<div>			

## Main changes

### Maintenance release

This maintenance release fix issues encoutered in MDK-ARM IDE projects:

- Remove snprintf calls from sample applications
- Add define in Nucleo BSP common to enable printf through stdio library in ARMCC v6

## Contents

Available examples projects:

- 6283A1_ALSValues

## Known limitations

N/A

## Development toolchains and compilers

- IAR System Workbench V8.50.9
- ARM Keil V5.32
- STM32CubeIDE v1.6.1

## Supported devices and boards

- NUCLEO-F401RE MB1136 rev.C
- X-NUCLEO-6283A1

## Backward compatibility

N/A

## Dependencies

- VD6283TX BSP Component Driver
- X-NUCLEO-6283A1 BSP Driver
- STM32F4xx_Nucleo BSP Drivers
- STM32F4xx CMSIS Drivers
- STM32F4xx HAL Drivers

</div>
:::

::: {.collapse}
<input type="checkbox" id="collapse-section1" checked aria-hidden="true">
<label for="collapse-section1" aria-hidden="true">__V1.0.0 / June 11th 2021__</label>
<div>			

## Main changes

### First release

Initial release.

## Contents

Available examples projects:

- 6283A1_ALSValues

## Known limitations

N/A

## Development toolchains and compilers

- IAR System Workbench V8.50.9
- ARM Keil V5.31
- STM32CubeIDE v1.6.0

## Supported devices and boards

- NUCLEO-F401RE MB1136 rev.C
- X-NUCLEO-6283A1

## Backward compatibility

N/A

## Dependencies

- VD6283TX BSP Component Driver
- X-NUCLEO-6283A1 BSP Driver
- STM32F4xx_Nucleo BSP Drivers
- STM32F4xx CMSIS Drivers
- STM32F4xx HAL Drivers

</div>
:::

:::
:::

<footer class="sticky">
::: {.columns}
::: {.column width="95%"}
For complete documentation on **STM32Cube Expansion Packages** ,
visit: [STM32Cube Expansion Packages](https://www.st.com/en/embedded-software/stm32cube-expansion-packages.html)
:::
::: {.column width="5%"}
<abbr title="Based on template cx566953 version 2.0">Info</abbr>
:::
:::
</footer>
