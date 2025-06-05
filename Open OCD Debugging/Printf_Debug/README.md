# STM32 "Hello World" Using `printf` via Semihosting

This STM32 project demonstrates how to use `printf()` for debug output by configuring semihosting through the `initialise_monitor_handles()` function. It prints "Hello World" every 1 second to the debug console.

---

## 🛠 Project Overview

- **Board**: STM32 (e.g., Nucleo or Discovery board)
- **Toolchain**: STM32CubeIDE (or compatible with STM32 HAL)
- **Output**: Standard I/O via semihosting (SWV/ITM debugger output)
- **Functionality**: Prints "Hello World" every second

---

## 🚀 How It Works

### Main Loop Behavior:

```c
while (1)
{
    printf("Hello World\n");
    HAL_Delay(1000); // Delay for 1 second
}

initialise_monitor_handles() sets up semihosting to allow printf() output.

printf() sends data to your debugger console.

HAL_Delay() introduces a delay between messages.

🧰 Dependencies
STM32 HAL drivers

Semihosting/debugger console support (e.g., SWV Viewer in STM32CubeIDE)

Proper linker and startup script enabling semihosting

🔧 Peripherals Used
USART2: Initialized but not used directly (only printf)

GPIOA Pin 5 (LD2): Configured, not toggled

Button (B1): Configured, unused in main loop

💡 Debug Console Setup (STM32CubeIDE)
Right-click project → Debug Configurations

Go to Debugger → SWV or Semihosting tab

Enable Semihosting or SWV ITM console

In debug mode, open SWV Console view → Click Start Trace

You should see Hello World printed every second

⚠️ Notes
If semihosting is not configured correctly, no output will be seen.

Make sure to use a debugger that supports ITM/SWO or semihosting.

initialise_monitor_handles() is specific to using printf() in this setup.

If you want printf() to work over UART, you need to override __io_putchar() or fputc().


