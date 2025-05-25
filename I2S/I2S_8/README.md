# STM32 I2S to UART Data Transfer Example

This project demonstrates a basic STM32 microcontroller application that receives audio data via the I2S peripheral and transmits it over UART. It uses STM32 HAL libraries and is intended for STM32 MCUs with SPI/I2S and UART peripherals.

---

## Overview

The firmware initializes the STM32 system clock, configures GPIO, DMA, UART, and I2S peripherals. It continuously receives 16-bit audio samples from an I2S interface (configured as master receiver) and immediately transmits the data through UART.

- **I2S Configuration**:  
  - Mode: Master Receiver  
  - Standard: Philips  
  - Data Format: 16-bit  
  - Audio Frequency: 8 kHz  

- **UART Configuration**:  
  - Baud Rate: 115200  
  - Word Length: 8 bits  
  - Stop Bits: 1  
  - No parity  

---

## Features

- Initializes I2S2 peripheral to receive audio data from an external source (e.g., microphone, codec).
- Uses UART2 to transmit received audio data for debugging, logging, or further processing.
- DMA initialized for efficient data handling (interrupt configuration provided).
- System clock configured using MSI oscillator.
- Basic error handling in case of peripheral initialization failure.

---

## Hardware Requirements

- STM32 microcontroller with SPI/I2S and UART peripherals (e.g., STM32F4 series).
- I2S audio source connected to SPI2 pins.
- UART2 connection for data output (e.g., to a PC via USB-UART converter).

---

## Usage

1. Build and flash the firmware to your STM32 device.
2. Connect the I2S audio source to SPI2 pins.
3. Connect UART2 to a serial terminal on your PC with the following settings: 115200 baud, 8-N-1.
4. Run the device; it will continuously receive 2 bytes of I2S audio data and transmit them over UART.

---

## Code Structure

- **main.c**:  
  Contains the main application loop and peripheral initialization functions.
  
- **SystemClock_Config()**:  
  Configures the system clock to use MSI at 4 MHz (MSIRANGE_5).
  
- **MX_I2S2_Init()**:  
  Configures the I2S2 peripheral as a master receiver at 8 kHz.
  
- **MX_USART2_UART_Init()**:  
  Configures UART2 for 115200 baud communication.
  
- **MX_DMA_Init()**:  
  Enables DMA1 clock and interrupt for DMA channels 4-7.
  
- **MX_GPIO_Init()**:  
  Sets up GPIO ports and configures onboard LED and button pins.

---

## Notes

- The program currently uses blocking HAL calls for I2S receive and UART transmit (`HAL_I2S_Receive` and `HAL_UART_Transmit`) with a timeout of 100 ms.
- You may extend the project by implementing DMA-based or interrupt-driven data handling for better performance.
- Adjust clock and peripheral settings based on your specific STM32 MCU and hardware setup.
