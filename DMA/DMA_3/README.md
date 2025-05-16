# STM32 DMA UART Transmission Example

This project demonstrates how to use **DMA (Direct Memory Access)** for efficient UART transmission on an STM32 microcontroller using STM32CubeIDE and HAL drivers.

## Overview

Traditional UART transmission using blocking or interrupt modes can consume valuable CPU cycles, especially when sending large buffers. This example sends a **10KB buffer** using DMA, significantly reducing CPU load and allowing concurrent operations (like blinking an LED).

## Project Structure

- `main.c`: Core logic implementing UART transmission using DMA.
- `.ioc`: STM32CubeMX configuration file (if available).
- `Inc/` and `Src/`: HAL initialization and peripheral setup.

## Features

- Uses **USART2** for UART communication.
- **DMA** handles large buffer transfer (`10KB`) from memory to UART.
- **LED blinking** continues during UART transfer, proving CPU isn't blocked.
- **Interrupt** (`HAL_UART_TxCpltCallback`) notifies when DMA transfer completes.

## Peripherals Configuration

| Peripheral | Config                                                  |
|------------|----------------------------------------------------------|
| USART2     | Baudrate: 115200, Mode: TX/RX, Word length: 8-bit        |
| DMA        | DMA1 Channel for USART2_TX, interrupt enabled            |
| GPIO       | PA5 as output (LED), User button as input                |

## How It Works

1. A 10KB array (`TxData`) is filled with sample data.
2. The DMA is configured to transfer this buffer over USART2.
3. `HAL_UART_Transmit_DMA()` is called if the previous transmission is complete.
4. The **LED toggles every 1 second** to visually indicate non-blocking behavior.
5. On DMA completion, `HAL_UART_TxCpltCallback()` sets a flag to allow the next transfer.

## Main Loop Logic

```c
if (isSent == 1)
{
    HAL_UART_Transmit_DMA(&huart2, TxData, 10240);
    isSent = 0;
}
HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
HAL_Delay(1000);
