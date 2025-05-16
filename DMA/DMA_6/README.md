# UART DMA Transfer with Circular Mode

This project demonstrates how to use **Direct Memory Access (DMA)** for UART communication on an STM32 microcontroller. The code sets up UART in DMA mode to transmit a large data buffer (10KB) continuously by using **circular mode** to ensure that data is updated and sent without CPU intervention.

## Features:
- **UART DMA Transfer**: Using DMA to offload data transfer from the CPU.
- **Circular DMA Mode**: Continuously transmitting data by updating the DMA buffer as data is transferred.
- **Callbacks**: Utilizing `HAL_UART_RxHalfCpltCallback` and `HAL_UART_TxCpltCallback` to handle data update when half of the data is transmitted.
- **LED Toggle**: Toggle an LED (LD2) every second to indicate the program is running.

## Requirements:
- STM32 Microcontroller (e.g., STM32F4 series or similar).
- STM32 HAL library and CubeMX for initialization and peripheral configuration.
- Keil or STM32CubeIDE to compile and upload the firmware.

## File Overview:
- `main.c`: Main program that initializes UART, DMA, and handles transmission of data in a loop.
- `stm32f4xx_it.c`: Interrupt service routines for handling DMA and UART interrupts.
- `system_stm32f4xx.c`: System configuration and initialization functions (including clock setup).

## Code Explanation:

### 1. **Data Initialization and DMA Transmission:**

The code begins by initializing a 10KB data buffer (`TxData`) with sequential values. It then starts a UART DMA transmission using `HAL_UART_Transmit_DMA`.

```c
for (uint32_t i = 0; i < 10240; i++) {
    TxData[i] = i & (0xff);
}
HAL_UART_Transmit_DMA(&huart2, TxData, 10240);
