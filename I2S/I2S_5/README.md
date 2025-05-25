# STM32 I2S Audio Capture and UART Transmission

This project demonstrates how to capture audio data from an I2S microphone using the STM32 microcontroller and transmit the data over UART. It uses DMA to efficiently handle data transfer for both I2S and UART.

## Features

- Captures audio using I2S2 interface with DMA
- Transmits audio data via USART2 using DMA
- Designed for STM32 development boards (e.g., STM32L4 series)
- Sample rate: 8 kHz, 16-bit mono
- Non-blocking operation using DMA
- Suitable for real-time or low-power audio streaming applications

## Hardware Requirements

- STM32 microcontroller (tested on STM32L4 series)
- I2S-compatible MEMS microphone (e.g., ICS43434, SPH0645)
- USB-to-UART converter or onboard ST-Link for serial communication
- 3.3V power supply for sensors and MCU
- Optional: Oscilloscope or logic analyzer for debugging I2S/UART

## Software Requirements

- STM32CubeIDE (for compilation and flashing)
- STM32 HAL drivers (generated with STM32CubeMX or CubeIDE)
- Serial terminal (e.g., PuTTY, Tera Term) for receiving UART data

## Project Structure

```plaintext
├── Core
│   └── Src / Inc          # Source and header files
├── Drivers
│   └── STM32L4xx_HAL_Driver / CMSIS
├── .ioc                   # STM32CubeMX configuration file
├── README.md              # Project documentation
└── main.c                 # Main application code

How It Works
I2S Audio Capture:

Configures I2S2 as master receiver.

DMA is used to continuously receive 16-bit audio samples into audioBuffer.

UART Transmission:

The buffer is sent over USART2 using DMA for fast transmission.

Baud rate is set to 115200.

Main Loop:

In an infinite loop, audio data is received and transmitted.

A HAL_Delay(100) provides a basic timing control.

Configuration Summary
I2S2 Settings
Parameter	Value
Mode	Master RX
Standard	Philips I2S
Data Format	16-bit
Audio Frequency	8 kHz

USART2 Settings
Parameter	Value
Baud Rate	115200
Word Length	8 bits
Stop Bits	1
Parity	None
Mode	TX/RX

DMA Channels
SPI2_RX DMA

USART2_TX DMA

Build and Flash
Open the .ioc file using STM32CubeIDE.

Click Project > Build Project.

Connect your STM32 board via USB and flash the code using Run > Debug or the green play button.

Output
The audio data (16-bit PCM samples) is transmitted as binary over UART at 115200 baud. Use a serial terminal or custom PC software to interpret and store the received data.

Limitations
This implementation does not handle buffer overflows or interruptions between DMA transactions.

UART speed may be a bottleneck for higher sample rates.
