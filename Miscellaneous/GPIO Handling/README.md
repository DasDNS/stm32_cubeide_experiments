# STM32 UART Blink Template

This is a basic STM32 project template generated using STM32CubeMX and developed in C. It initializes GPIO and UART (USART2) peripherals and is ready for further expansion with user logic.

## Project Overview

- **Microcontroller**: STM32 (exact model depends on CubeMX configuration)
- **Peripherals Used**:
  - **USART2**: Initialized at 115200 baud rate for serial communication.
  - **GPIO**: 
    - Output pin (LD2) for driving an LED.
    - Input pin (B1) configured for falling-edge interrupt detection (e.g., user button).

This project currently includes system initialization and runs an infinite loop. You can add your application logic inside the `while(1)` loop.

## Features

- System clock configured using MSI oscillator
- UART setup with 8N1 format and no hardware flow control
- LD2 configured as output pin
- B1 configured as external interrupt source
- Error handler function included
- Full assertion support enabled

## Getting Started

### Prerequisites

- STM32CubeIDE or another IDE that supports STM32 HAL
- STM32 board (e.g., Nucleo-L476RG or similar)
- USB connection for programming and UART communication
- USB to Serial viewer (e.g., PuTTY, Tera Term, or Arduino Serial Monitor)

### Building and Flashing

1. Open the project in STM32CubeIDE.
2. Build the project (`Project > Build Project`).
3. Connect your STM32 board via USB.
4. Flash the firmware to the board (`Run > Debug As > STM32 Cortex-M C/C++ Application`).

### UART Communication

Once flashed, you can use a serial terminal to monitor communication via USART2 (PA2 = TX, PA3 = RX):

- Baud Rate: `115200`
- Data Bits: `8`
- Parity: `None`
- Stop Bits: `1`
- Flow Control: `None`

You can implement UART Tx/Rx logic in the `while(1)` loop using HAL functions like `HAL_UART_Transmit()` or `HAL_UART_Receive()`.

## File Structure

- `main.c`: Contains the main application code.
- `stm32fxxx_hal_conf.h`: HAL configuration.
- `startup_stm32xxx.s`: Startup code.
- `Drivers/`: HAL and CMSIS drivers.

## How to Extend

You can modify the following sections:
- **Add UART communication**: Send/receive data to/from a PC.
- **Blink LD2**: Use `HAL_GPIO_TogglePin()` in the main loop.
- **Interrupt Handling**: Implement button-press logic in the EXTI callback function.


