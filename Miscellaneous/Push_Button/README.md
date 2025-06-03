# STM32 GPIO Button-Controlled LED

This project is a simple STM32 application that turns an LED on or off based on the state of a user push-button. It utilizes GPIO for both input and output operations, and UART2 is initialized for possible future use.

---

## 🔧 Features

- Reads the state of a push-button connected to pin `PC13`.
- Controls an LED connected to pin `PA5` (commonly onboard LED on STM32 Nucleo boards).
- Turns ON the LED when the button is pressed (logic LOW).
- UART2 initialized (not actively used in this demo).
- Configured system clock using HSI and PLL.

---

## 🧰 Requirements

- STM32 development board (e.g., STM32 Nucleo-L476RG or similar).
- STM32CubeIDE or STM32CubeMX + compatible toolchain.
- Button connected to `GPIOC_PIN_13`.
- LED connected to `GPIOA_PIN_5`.

---

## 🚦 Behavior

In the main loop:

```c
if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) == GPIO_PIN_RESET)
{
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);   // Turn ON LED
}
else
{
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET); // Turn OFF LED
}

The LED turns ON when the button is pressed.

The LED turns OFF when the button is released.

📄 Peripheral Configuration
GPIO
Input: PC13 - Button input with no internal pull-up/down (assumes external pull-up).

Output: PA5 - LED output, push-pull, low speed.

UART2
Baud Rate: 115200

Word Length: 8 bits

Stop Bits: 1

Parity: None

Mode: TX/RX

Flow Control: None

(Currently unused in main loop but available for debugging or future extensions.)

📦 How to Build & Flash
Open the project in STM32CubeIDE.

Connect your STM32 board via USB.

Build the project (Project > Build Project).

Flash the binary to the board (Run > Debug or Run > Run).

⚠️ Notes
GPIO_PIN_13 reads LOW when the button is pressed (normally pulled-up).

Make sure external pull-up or pull-down resistors are appropriately configured if using custom hardware.

You can modify the logic to invert LED behavior if needed.
