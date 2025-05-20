STM32 UART Communication Example
This project demonstrates UART (Universal Asynchronous Receiver/Transmitter) communication using STM32 HAL libraries. It is designed for STM32 boards with USART2 configured and uses interrupt-based reception.

📦 Features
Initializes USART2 with the following settings:

Baud Rate: 115200

Data Bits: 8

Stop Bits: 1

Parity: None

Mode: TX/RX

Receives 6 bytes via UART using interrupt (HAL_UART_Receive_IT)

Echoes back received bytes via UART (HAL_UART_Transmit)

Includes a transmit buffer ("Welcome!\n\r") for optional periodic messaging (currently commented out)

🧰 Hardware Requirements
STM32 development board (e.g., Nucleo-L476RG or similar)

USB-to-UART converter or onboard ST-LINK Virtual COM port

Serial terminal (e.g., PuTTY, Tera Term, minicom)

📋 UART Pin Configuration (USART2)
Signal	STM32 Pin	Function
TX	PA2	USART2_TX
RX	PA3	USART2_RX

🚀 How It Works
On startup, USART2 is initialized with the configuration described above.

The MCU enters an infinite loop, staying ready to receive UART data.

Upon receiving 6 bytes (configured buffer size), the HAL_UART_RxCpltCallback() is triggered.

The received 6-byte message is transmitted back to the sender (loopback/echo).

🧪 Testing the UART
Flash the firmware to your STM32 board using STM32CubeIDE or STM32CubeProgrammer.

Open a serial terminal on your PC and connect to the board's UART port.

Configure the terminal:

Baud Rate: 115200

Data Bits: 8

Stop Bits: 1

No Parity

No Flow Control

Send a 6-character message.

You will see the same 6 characters echoed back.

📁 Key Code Highlights

HAL_UART_Receive_IT(&huart2, rx_data, 6);  // Start receiving 6 bytes in interrupt mode
...
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    HAL_UART_Transmit(&huart2, rx_data, 6, 10);  // Echo received data
}
🛠 Notes
Modify rx_data size in HAL_UART_Receive_IT if you expect different data lengths.

If continuous reception is needed, re-enable HAL_UART_Receive_IT() in the callback after transmission.
