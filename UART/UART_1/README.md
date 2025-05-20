# STM32 UART "Hello World" Example

This project demonstrates a basic UART transmission on an STM32L4 microcontroller. It transmits `"Hello World\r\n"` every second using `USART2`. The project was generated with STM32CubeMX and built with STM32CubeIDE.

---

## 🚀 Features

- Sends a "Hello World" message via UART every second
- Uses STM32 HAL libraries
- Configures USART2 for UART communication
- Includes system clock and GPIO setup

---

## 🛠 Requirements

- STM32L4-based development board (e.g., NUCLEO-L476RG)
- STM32CubeIDE (or STM32CubeMX for configuration)
- USB-to-UART adapter (if not using onboard ST-LINK Virtual COM port)
- Baud rate: `115200`, Data bits: `8`, Parity: `None`, Stop bits: `1`

---

## 📁 Key Files

| File                      | Description                                      |
|---------------------------|--------------------------------------------------|
| `main.c`                  | Main program with UART logic                     |
| `usart.c`                 | UART2 peripheral initialization (auto-generated) |
| `stm32l4xx_hal_msp.c`     | HAL low-level hardware init (auto-generated)     |
| `stm32l4xx_it.c`          | Interrupt handlers (if used)                     |
| `system_stm32l4xx.c`      | System clock configuration (auto-generated)      |

---

## 🔧 Configuration Summary

- **USART2 TX**: PA2  
- **USART2 RX**: PA3  
- **Baud Rate**: 115200  
- **Mode**: TX only (RX enabled but unused in this example)  
- **Clock Source**: MSI (configured via `SystemClock_Config()`)

---

## 🧠 Notes

- The message `"Hello World\r\n"` is sent using `HAL_UART_Transmit()` in a blocking loop with a 1-second delay.
- UART reception is not used, but you can expand the code for RX or command parsing.
- For non-blocking or high-throughput applications, consider using **interrupt-based** or **DMA-based** UART.
- You can also implement a **circular buffer** for efficient continuous reception.

---

## 🧪 Output Example

Hello World
Hello World
Hello World

