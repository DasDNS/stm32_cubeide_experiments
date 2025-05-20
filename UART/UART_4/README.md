# STM32 UART Echo Example

This project demonstrates a basic UART (USART2) communication using the STM32 HAL library. It initializes UART2, receives a 20-byte string over UART using interrupts, and immediately echoes it back.

## Features

- Initializes USART2 at 115200 baud.
- Configures GPIO and system clock.
- Uses `HAL_UART_Receive_IT` for non-blocking UART reception.
- Echoes received data back to the sender via `HAL_UART_Transmit`.
- Contains minimal delay or blocking logic for responsiveness.

## Hardware Requirements

- STM32 microcontroller (e.g., STM32L4, STM32F4 series)
- USB to UART converter (if PC communication is needed)
- Terminal software (e.g., PuTTY, Tera Term, or Arduino Serial Monitor)

## Baud Rate Settings

- **Baud Rate**: 115200
- **Data Bits**: 8
- **Stop Bits**: 1
- **Parity**: None
- **Flow Control**: None

## File Overview

- `main.c`: Core logic for UART initialization and data echoing.
- `SystemClock_Config()`: Sets up system clock using MSI.
- `MX_USART2_UART_Init()`: Configures USART2.
- `MX_GPIO_Init()`: Initializes basic GPIOs like LD2 LED and button B1.
- `Error_Handler()`: Simple infinite loop on error.

## Code Behavior

Upon startup:
1. System and peripherals are initialized.
2. USART2 is configured.
3. A loop constantly:
   - Waits for 20 bytes to be received via UART interrupt.
   - Transmits the received data back to the sender.

The line `HAL_UART_Transmit(&huart2, receive, 20, 100);` sends the data immediately after receiving.

> **Note**: `HAL_UART_Receive_IT()` should ideally be called again after a complete reception to keep the reception continuous. This code calls it once per loop, which works for simple applications.

## Example Output

If you send `Hello STM32` (padded to 20 bytes), the same string will be echoed back.

