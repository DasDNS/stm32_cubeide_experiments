# STM32 Flash Memory Write and Read Example

This STM32 project demonstrates how to write and read 64-bit data to and from the internal flash memory using HAL functions. The code was generated using STM32CubeIDE and runs on STM32 microcontrollers, with UART2 initialized for potential future debugging output.

## Features

- Writes a 64-bit data value to a specified flash memory address
- Reads back the stored value from flash
- Flash protection is properly managed using `HAL_FLASH_Unlock()` and `HAL_FLASH_Lock()`
- Uses low-power MSI oscillator as system clock source
- Includes basic GPIO and UART2 peripheral initialization

## Memory Details

- **Flash Address Used**: `0x0802F080`
- **Data Written**: `0x5666766ABCD` (64-bit)
- **Read Method**: Direct pointer casting after unlocking flash

## Hardware Requirements

- STM32 board (e.g., Nucleo, Discovery, or compatible STM32L series MCU)
- STM32CubeIDE
- USB connection for programming and power
- Optional: Serial terminal to observe UART2 output (not implemented yet)

## Code Overview

### Flash Write and Read Logic

```c
uint32_t Address = 0x0802F080;
uint64_t data = 0x5666766ABCD;
uint64_t readData;

HAL_FLASH_Unlock();
HAL_FLASH_Program(FLASH_TYPEPROGRAMDATA_WORD, Address, data);
HAL_FLASH_Lock();

HAL_FLASH_Unlock();
readData = *(uint64_t*) Address;
HAL_FLASH_Lock();

### System Initialization
```c
HAL_Init() – Initializes HAL library

SystemClock_Config() – Configures system clock (MSI 2.097 MHz)

MX_GPIO_Init() – Initializes onboard LED and push-button

MX_USART2_UART_Init() – Sets up UART2 at 115200 bps

### Main Loop
The infinite loop continuously writes and reads from flash every cycle (without delay). Intended for testing purposes.

### Limitations and Notes
Flash write operations have limited endurance (~10,000 cycles). Avoid frequent writes in production.

The project does not implement verification or serial output yet, but UART2 is initialized and ready.

Be cautious with flash memory addresses—ensure the address does not overlap application code or reserved regions.

### How to Build and Flash
Open the project in STM32CubeIDE

Connect your STM32 board via USB

Click Build to compile the code

Click Run to flash and execute on the board

### Future Improvements
Add UART printf output to display readData

Add button press logic to trigger write/read operations

Add verification of write operation
