# STM32 UART Communication Example

This project demonstrates basic **UART (USART2)** communication using an STM32 microcontroller and the HAL library.

## 📦 Overview

The firmware initializes USART2 and sets up **interrupt-based UART receive (RX)**. When 6 bytes of data are received, the same data is echoed back to the sender via UART transmit (TX). This example is built using STM32CubeMX and STM32CubeIDE.

## 🔧 Hardware Requirements

- STM32 microcontroller (e.g., STM32L4 series)
- USB to UART interface (e.g., ST-Link V2 or USB-TTL module)
- Terminal program (e.g., PuTTY, Tera Term, minicom)
- Micro USB cable

## 🚀 Getting Started

### 1. Wiring

Connect your STM32 board's USART2 TX/RX pins to your USB-UART converter or ST-Link as follows:

| STM32 Pin | Function | USB-UART |
|-----------|----------|----------|
| PA2       | TX       | RX       |
| PA3       | RX       | TX       |
| GND       | GND      | GND      |

> Note: Pin mapping may vary depending on your STM32 board.

### 2. Flash the Code

Build and flash the firmware using STM32CubeIDE or another supported environment.

### 3. Serial Terminal Settings

Open a terminal program and configure it with the following settings:

- **Baud rate:** 115200
- **Data bits:** 8
- **Stop bits:** 1
- **Parity:** None
- **Flow Control:** None

## 📡 UART Functionality

### Initialization

USART2 is initialized with the following settings:

- Baud Rate: `115200`
- Word Length: `8 bits`
- Stop Bits: `1`
- Parity: `None`
- Mode: `TX and RX`
- Hardware Flow Control: `None`

### RX Interrupt

```c
HAL_UART_Receive_IT(&huart2, rx_data, 6);
The received 6 bytes are immediately echoed back via UART.

📁 Key Files
main.c: Main program with UART logic

stm32l4xx_hal_msp.c: HAL low-level hardware init (auto-generated)

stm32l4xx_it.c: Interrupt handlers (if used)

usart.c: UART peripheral initialization (auto-generated)

🧠 Notes
The project uses interrupt-based UART reception rather than polling or DMA.

You can expand the code to parse received commands or communicate with other devices.

For higher efficiency and continuous reception, consider implementing a circular buffer with DMA.
