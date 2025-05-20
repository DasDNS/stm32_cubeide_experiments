# STM32 Stop Mode Example with RTC Wakeup

This project demonstrates how to implement low-power STOP2 mode on an STM32 microcontroller with wake-up using the RTC wakeup timer. The example toggles an LED, then enters STOP2 low-power mode and wakes up periodically using the RTC.

---

## Features

- Initializes system clock, UART2, RTC, and GPIO.
- Toggles onboard LED (GPIOA PIN 5) every 100 ms before entering STOP2 mode.
- Uses RTC wake-up timer to wake the MCU from STOP2 mode after a configured delay.
- Demonstrates how to properly enter and exit STOP2 mode while maintaining system clock configuration.
- UART initialized for debug or communication (baud rate 115200).

---

## Hardware Requirements

- STM32 microcontroller (specific MCU depends on your board, e.g., STM32L4 series).
- Onboard LED connected to GPIOA Pin 5 (modify `HAL_GPIO_TogglePin` if different).
- RTC crystal (LSE) connected for RTC clock source.

---

## Software Requirements

- STM32Cube HAL library.
- STM32CubeIDE or any compatible IDE for STM32 development.
- C compiler and debugger for STM32.

---

## Code Overview

- **main.c**  
  Contains the main program loop:
  - Toggles LED.
  - Configures RTC wakeup timer.
  - Enters STOP2 low power mode.
  - Upon wakeup, reconfigures system clock and resumes execution.

- **SystemClock_Config()**  
  Configures the system clocks including MSI oscillator and LSE for RTC.

- **MX_RTC_Init()**  
  Initializes RTC peripheral with 24-hour format and enables wakeup timer interrupt.

- **MX_USART2_UART_Init()**  
  Initializes UART2 at 115200 baud for serial communication.

- **MX_GPIO_Init()**  
  Configures GPIO pins including LED and user button.

- **Error_Handler()**  
  Simple error handling function that traps the MCU in an infinite loop on error.

---

## How to Use

1. Open the project in STM32CubeIDE or your preferred STM32 IDE.
2. Build and flash the firmware to your STM32 board.
3. Observe the onboard LED toggling every 100 ms.
4. The MCU then enters STOP2 mode and wakes periodically based on RTC wakeup timer.
5. On wakeup, the system clock is reconfigured, and the LED toggling resumes.

---

## Notes

- RTC wakeup timer is configured with the parameters:
  ```c
  HAL_RTCEx_SetWakeUpTimer_IT(&hrtc, 0x500B, RTC_WAKEUPCLOCK_RTCCLK_DIV16);

Adjust wakeup period by modifying these parameters as needed.

Ensure the hardware has the LSE (low-speed external) crystal installed for RTC clock accuracy.

Modify HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5); if your LED pin differs.


