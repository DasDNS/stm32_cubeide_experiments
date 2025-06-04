# STM32 UART `printf("Hello World")` Example using Semihosting

This project demonstrates how to use the standard `printf()` function to send strings over a debug console using semihosting on an STM32 microcontroller. The message "Hello World" is printed every second.

---

## 📋 Project Description

- Initializes UART2 using STM32 HAL.
- Uses `initialise_monitor_handles()` to enable semihosting output via `printf`.
- Continuously prints `Hello World` every 1000ms.
- Ideal for debugging via STM32CubeIDE.

---

## 💡 Features

| Component   | Description                        |
|------------|------------------------------------|
| UART2       | Configured to 115200 baud          |
| GPIO        | LD2 and Button configured (not used)|
| Semihosting | `printf()` output via debugger     |

---

## 🛠️ Hardware Requirements

- STM32 development board (e.g., STM32L476RG, Nucleo series)
- ST-LINK or compatible debugger
- USB cable for power and programming
- STM32CubeIDE installed on your computer

---

## 🧠 How It Works

### Main Loop
```c
while (1)
{
    printf("Hello World\n");
    HAL_Delay(1000);
}

Semihosting Initialization

extern void initialise_monitor_handles(void);
initialise_monitor_handles();

This function is necessary for enabling semihosting so that printf() outputs to the debugger console.

⚙️ Setup Instructions
Open the project in STM32CubeIDE.

Enable semihosting in Debug Configuration:

Go to Run > Debug Configurations > Debugger.

Check Enable Semihosting.

Ensure your project includes:

extern void initialise_monitor_handles(void);
initialise_monitor_handles();

Connect your board via USB.

Press Debug to flash and run the project.

Observe "Hello World" in the Console window.

⚠️ Notes
Semihosting slows down execution and should only be used for debugging.

To redirect printf() to UART, implement _write() and use HAL_UART_Transmit() instead.

Ensure semihosting support is enabled in your debugger and IDE.


