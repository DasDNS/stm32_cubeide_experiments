# Hello World with `printf` in Embedded C

This project demonstrates how to use `printf()` in an embedded C application by initializing monitor handles for semihosting or debugger output.

---

## 📋 Overview

This is a minimal embedded program designed to:

- Set up the standard output using `initialise_monitor_handles()`
- Print `Hello, World!` using `printf`
- Loop infinitely after the message is printed

---

## 🧠 Key Features

| Feature       | Description |
|---------------|-------------|
| `printf()`    | Outputs message over a debugger console (e.g., via semihosting or SWV) |
| Infinite loop | Keeps the program alive after execution |

---

## 💻 Code Structure

```c
#include "stdio.h"

extern void initialise_monitor_handles(void);

int main(void) {
    initialise_monitor_handles();  // Enables printf output
    printf("Hello, World!\n");     // Prints to debugger console
    for (;;);                      // Infinite loop
}

🛠 Requirements
STM32 or ARM Cortex-M development board

IDE: STM32CubeIDE, Keil uVision, or any ARM-GCC based environment

Debugging tool: ST-Link, J-Link, or OpenOCD

Semihosting or SWV console output enabled in your debugger configuration

🧪 How to Use
Build and flash the firmware to your target board.

Start a debug session.

Open the debugger console (e.g., SWV Console or Semihosting Console).

Observe the output:
Hello, World!

⚠️ Notes
This program relies on a debugging interface — it won’t show output on UART or LCD unless redirected.

Make sure semihosting or SWV is enabled in your debug configuration.
