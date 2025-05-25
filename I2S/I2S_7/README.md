# STM32 I2S2 Basic Initialization Project

This project demonstrates basic initialization and configuration of the I2S2 peripheral in master transmit mode using the STM32 HAL library. It was generated using STM32CubeIDE and is intended as a starting point for applications involving audio data transmission over I2S.

## Features

- I2S2 configured in **Master Transmit Mode**
- Audio frequency: **8 kHz**
- 16-bit data format
- Standard Philips I2S protocol
- No MCLK output
- Minimal GPIO initialization
- MSI clock as system clock source

## Target Hardware

- STM32 microcontroller (compatible with SPI2 peripheral)
- Audio codec or DAC that supports I2S protocol (optional for extension)

## Peripherals Used

- **I2S2 (via SPI2):** Configured as Master Transmitter
- **GPIOB:** Enabled (pins configured through CubeMX or manually if needed)

## Clock Configuration

- Oscillator: **MSI**
- MSI Range: **RCC_MSIRANGE_5**
- PLL: **Disabled**
- SYSCLK Source: **MSI**
- AHB, APB1, APB2: **Prescaler set to 1**

## File Structure

- `main.c` - Contains main loop, peripheral initialization, and clock setup
- `main.h` - Header file for main module
- `stm32fxxx_hal_conf.h` - HAL configuration
- `system_stm32fxxx.c` - System clock setup
- `Startup/` - Assembly startup code and linker script

> Replace `xxx` with your actual STM32 family (e.g., `stm32l4xx`, `stm32f4xx`).

## How to Build and Flash

1. Open the project in STM32CubeIDE.
2. Connect your STM32 board via ST-Link.
3. Click the **Build** button to compile.
4. Click the **Debug** or **Run** button to flash the firmware.

## Next Steps

This project currently initializes I2S and enters an infinite loop. You can extend it by:
- Sending audio data over I2S
- Integrating an external microphone or DAC
- Implementing DMA for efficient audio streaming


