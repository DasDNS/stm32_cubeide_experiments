# STM32 UART `printf("Hello World")` Example with Semihosting

This STM32 project demonstrates how to use the standard `printf()` function via semihosting in an STM32-based application. The program continuously prints `"Hello World"` to the debug console using UART2.

---

## 🚀 Overview

- Initializes UART2 at 115200 baud.
- Uses `initialise_monitor_handles()` for semihosting.
- Continuously prints `"Hello World"` to the console.
- Based on HAL and STM32CubeMX configuration.

---

## 🔧 Hardware Requirements

- STM32 Nucleo board (e.g., STM32L476RG or compatible).
- ST-LINK debugger (built-in or external).
- USB connection for programming and semihosting output.
- STM32CubeIDE installed.

---

## 📦 Features

| Feature       | Description                            |
|---------------|----------------------------------------|
| UART2         | Transmit `"Hello World"` using `printf` |
| GPIO          | No active GPIO usage in this demo      |
| Clock         | MSI oscillator with default PLL config |
| Debugging     | Semihosting via ST-LINK                |

---

## 📜 Code Behavior

```c
initialise_monitor_handles(); // Required for printf to work via semihosting

while (1) {
    printf("Hello World ");
}

The code prints "Hello World" continuously to the debugger console.

UART is configured but not explicitly used since semihosting reroutes printf().

🛠 How to Use
Open the project in STM32CubeIDE.

Ensure semihosting is enabled:

Go to Run > Debug Configurations > Debugger > Enable semihosting.

Make sure _write() and initialise_monitor_handles() are implemented.

Connect your STM32 board via USB.

Build and flash the project (Run > Debug).

Open the console window and observe repeated Hello World messages.

💡 Notes
Semihosting significantly slows down execution. Use it only for debugging.

If semihosting is not supported or enabled, no output will appear.

To use printf with UART directly, redirect _write() to HAL_UART_Transmit().


