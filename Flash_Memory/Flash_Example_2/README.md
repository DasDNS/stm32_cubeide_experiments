# STM32 Flash Memory Write and Read Example

This STM32 project demonstrates how to write bytes to the internal flash memory of the microcontroller and read them back. The project is implemented using STM32 HAL drivers and runs on an STM32-based board (e.g., Nucleo or Discovery series).

## Features

- Writes four bytes (`0x01`, `0x02`, `0x03`, `0x04`) to a specific flash memory address.
- Reads back the data from the same address.
- Uses STM32 HAL Flash API for memory operations.
- UART initialized for potential debugging (not used in this example).
- Designed using STM32CubeMX and STM32CubeIDE.

## Flash Memory Address

- Target flash memory address: `0x0802FF80`
  - Ensure this address is within the writable area of your STM32 MCU flash memory and not part of your code or data segment.
  - Sector erase operations are commented out, but can be enabled if needed.

## File Structure

- `main.c`: Main source file with logic to:
  1. Unlock flash
  2. Write data
  3. Lock flash
  4. Unlock flash again
  5. Read back the data
  6. Lock flash

## Requirements

- STM32 microcontroller with HAL support
- STM32CubeIDE (or your preferred development environment)
- UART2 enabled (115200 8N1) for optional debugging

## How It Works

1. **Write Operation:**
   ```c
   HAL_FLASH_Unlock();
   for (i=0; i<=3; i++) {
       HAL_FLASH_Program(FLASH_TYPEPROGRAMDATA_BYTE, Address, DATA[i]);
       Address++;
   }
   HAL_FLASH_Lock();

Read Operation:

c
Copy
Edit
Address = 0x0802FF80;
HAL_FLASH_Unlock();
for (i=0; i<=3; i++) {
    READDATA[i] = *(__IO uint8_t*) Address;
    Address++;
}
HAL_FLASH_Lock();
(Optional) Flash erase code is included but commented out:

c
Copy
Edit
// HAL_FLASH_Unlock();
// FLASH_Erase_Sector(47, FLASH_VOLTAGE_RANGE_3);
// HAL_FLASH_Lock();
Important Notes
Writing to flash too frequently can reduce its lifespan. Avoid excessive loops in production systems.

Always ensure you are writing to a safe memory location.

Double-check memory mapping of your specific STM32 MCU before using this example.
