# STM32 Flash Memory Write Example

This STM32 project demonstrates how to write a 64-bit value to a specific address in the Flash memory using the STM32 HAL library. The project is intended for use with STM32 microcontrollers and was generated using STM32CubeMX and STM32CubeIDE.

## 📋 Overview

The application performs the following actions:
- Initializes the system clock and UART2 for communication.
- Writes a 64-bit data value (`0x5666766ABCD`) to a user-defined flash memory address (`0x0802F080`).
- The write operation is performed continuously in the main loop.

## 🛠️ Requirements

- STM32 microcontroller (Tested on STM32L4 series)
- STM32CubeIDE or compatible environment
- USB-to-serial interface (for UART communication, optional)
- ST-Link debugger or similar for flashing and debugging

## 📁 Project Structure

- `main.c` - Core application logic and peripheral initialization
- `stm32l4xx_hal_*.c/h` - HAL drivers (auto-generated or from STM32 HAL library)
- `Core/` - Standard STM32Cube project directory with source and headers
- `Drivers/` - HAL and BSP drivers

## 🔧 Configuration

### Flash Write Settings
- **Flash Address:** `0x0802F080`
- **Data to Write:** `0x5666766ABCD`

⚠️ Make sure the address `0x0802F080` is within the data flash or a user-allocated sector. Writing outside allowable flash areas can corrupt firmware or configuration data.

### UART2 Configuration
- **Baud Rate:** 115200
- **Data Bits:** 8
- **Stop Bits:** 1
- **Parity:** None

## 📌 Flash Write Logic

```c
HAL_FLASH_Unlock();
HAL_FLASH_Program(FLASH_TYPEPROGRAMDATA_WORD, Address, data);
HAL_FLASH_Lock();

The above code block is executed inside an infinite loop to repeatedly attempt writing data to flash. You may update this logic to write only once or under certain conditions (e.g., button press or UART command).

🚀 Getting Started
Clone or download the project to your STM32CubeIDE workspace.

Open with STM32CubeIDE.

Build the project.

Flash it to your STM32 board.

Monitor UART2 output if needed.

🧪 Testing
To verify that the flash write was successful:

Use the debugger to inspect memory at address 0x0802F080.

Alternatively, implement UART feedback or LED indicators to signal write success.

⚠️ Notes
Flash memory has limited write/erase cycles; avoid writing continuously in production code.

Ensure that flash programming is only done when absolutely necessary to avoid wearing out flash memory.


