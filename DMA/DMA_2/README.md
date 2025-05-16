# STM32 DMA UART Example

This project demonstrates using **DMA** for efficient data transfer to **UART** on an STM32 microcontroller. The program sends 10KB of data using DMA, minimizing CPU usage.

## Key Features
- **DMA** transfers 10KB data to **USART2**.
- **Interrupt-driven** UART transmission.
- **LED blink** as visual feedback during data transfer.

## Components
- **DMA**: Transfers data without CPU involvement.
- **UART2**: Transmits the data over serial communication.
- **LED**: Blinks every 500ms to indicate activity.

## Code Overview
1. **DMA Initialization**: Configures the DMA controller for efficient data transfer.
2. **UART Transmit**: Sends data in 10KB chunks via interrupt mode.
3. **LED Feedback**: Blinks every 500ms to show program activity.

```c
uint8_t TxData[10240]; // 10KB data array
if (isSent == 1) {
    HAL_UART_Transmit_IT(&huart2, TxData, 10240); // Transmit data via DMA
    isSent = 0;
}
