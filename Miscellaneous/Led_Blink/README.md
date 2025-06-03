# STM32 GPIO LED Blinking Example

This project demonstrates a simple STM32 application where an onboard LED is toggled (blinks) every 100 milliseconds. The example is based on STM32Cube HAL libraries and utilizes GPIO and UART peripherals.

---

## 🔧 Features

- Toggles the onboard LED (connected to `GPIOA_PIN_5`) with a 100ms delay.
- UART2 initialized at 115200 baud for potential serial communication (though not used in the main loop).
- System Clock configured using MSI (Multi-Speed Internal) oscillator.
- Follows STM32 HAL library conventions and generated structure.

---

## 📁 Project Structure

- `main.c`: Main application logic.
- `SystemClock_Config()`: Configures system clocks.
- `MX_GPIO_Init()`: Initializes LED and Button GPIO pins.
- `MX_USART2_UART_Init()`: Initializes UART2 peripheral.
- `Error_Handler()`: Fallback in case of runtime errors.

---

## ⚙️ Hardware Requirements

- STM32 Nucleo board or compatible STM32 development board.
- Onboard or externally connected LED to `GPIOA_PIN_5`.
- ST-Link debugger/programmer.
- USB-to-Serial connection (optional, for UART).

---

## ▶️ How It Works

1. Initializes the HAL library and system clocks.
2. Configures GPIO for LED and button.
3. UART2 is configured but unused in the current loop.
4. Inside the `while(1)` loop:
   ```c
   HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
   HAL_Delay(100);

