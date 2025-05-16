# STM32 UART with DMA and Circular Buffer

This project demonstrates how to use **UART** with **DMA** for data transfer on an STM32 microcontroller. The application continuously receives data via UART using DMA and echoes it back to the sender.

## Features:
- **UART Reception with DMA**: Receives data via UART and stores it in a buffer.
- **UART Transmission with DMA**: Automatically transmits the received data back to the sender using DMA.
- **LED Feedback**: A simple LED (LD2) toggles when the system is running.
- **DMA Interrupt Handling**: Uses DMA interrupts to handle UART data reception and transmission asynchronously.

## Requirements:
- **STM32 Microcontroller**: Any STM32 microcontroller with UART and DMA capabilities.
- **STM32CubeMX & STM32CubeIDE**: Used for configuration and project management.
- **Keil** or **STM32CubeIDE**: Used for compiling and uploading the firmware.

## File Overview:

### 1. `main.c`

This file contains the main logic for the UART communication using DMA and the basic system initialization. It includes the DMA initialization, UART reception, and transmission setup.

#### Key Functions:

- `main()` - Initializes the system and starts UART reception with DMA.
- `HAL_UART_RxCpltCallback()` - Callback for handling UART data reception complete. It immediately sends the received data back through UART.

```c
int main(void)
{
  /* Initialize HAL library */
  HAL_Init();

  /* Configure the system clock */
  SystemClock_Config();

  /* Initialize peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_USART2_UART_Init();

  /* Start UART reception via DMA */
  HAL_UART_Receive_DMA(&huart2, rx_data, 5);

  /* Infinite loop */
  while (1)
  {
    /* Main loop (currently empty) */
  }
}
