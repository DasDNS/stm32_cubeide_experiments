# STM32 UART Interrupt Example

This STM32 project demonstrates basic UART communication using interrupt mode (HAL_UART_Receive_IT and HAL_UART_Transmit_IT). The microcontroller listens for a "Hi" message via UART and replies with "okay" using the STM32 HAL library.

## Features

- **UART Interrupt Mode**: Receives data asynchronously via interrupts.
- **Command Recognition**: Responds to a specific input ("Hi").
- **Non-blocking Transmission**: Uses `HAL_UART_Transmit_IT` to send responses.
- **Minimal CPU Usage**: UART operations are interrupt-driven, keeping the main loop free.

## Requirements

- STM32 development board (e.g., STM32F4, STM32L4, etc.)
- USART2 peripheral enabled
- USB to UART converter or ST-Link Virtual COM Port for communication
- STM32CubeMX + STM32CubeIDE for building and uploading the firmware

## UART Configuration

- **Baud Rate**: 115200
- **Data Bits**: 8
- **Stop Bits**: 1
- **Parity**: None
- **Mode**: TX/RX
- **Flow Control**: None

## How It Works

1. Initializes USART2 using HAL.
2. Starts receiving 2 bytes in interrupt mode.
3. Waits for user to type `Hi` (case-sensitive).
4. On receiving `"Hi"`, the system replies with `"okay\r\n"` using interrupt-based transmit.

## Code Highlights

### UART Initialization

```c
huart2.Instance = USART2;
huart2.Init.BaudRate = 115200;
huart2.Init.WordLength = UART_WORDLENGTH_8B;
huart2.Init.StopBits = UART_STOPBITS_1;
huart2.Init.Parity = UART_PARITY_NONE;
huart2.Init.Mode = UART_MODE_TX_RX;
huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
HAL_UART_Init(&huart2);

Start Receiving in Main

HAL_UART_Receive_IT(&huart2, rxBuffer, 2);
UART Receive Complete Callback

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
    if (huart->Instance == USART2) {
        if (strcmp((char*)rxBuffer, "Hi") == 0) {
            HAL_UART_Transmit_IT(&huart2, ackBuffer, sizeof(ackBuffer) - 1);
        }
        HAL_UART_Receive_IT(&huart2, rxBuffer, 2); // Restart reception
    }
}
Transmission Complete Callback (Optional)

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart) {
    // Optional: Add post-transmission logic here
}
Building and Flashing
Open the project in STM32CubeIDE.

Build the project (Ctrl + B).

Connect your STM32 board and flash the firmware (Run or Debug).

Use a terminal program (e.g., Tera Term, PuTTY, or minicom) to send "Hi" and receive a reply.

Output Example
markdown
> Hi
< okay

