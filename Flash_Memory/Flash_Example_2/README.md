# STM32 Flash Memory Write and Read Example

This project demonstrates how to write and read bytes to/from internal flash memory on an STM32 microcontroller using the HAL (Hardware Abstraction Layer) API.

## Overview

The program performs the following operations:
- Writes four bytes (0x1, 0x2, 0x3, 0x4) to a fixed flash memory address (`0x0802FF80`)
- Reads the bytes back from the same address
- UART is initialized but not used in this basic example
- Optional flash erase code is provided (commented out)

## Memory Operation Details

### Flash Write Operation

```c
HAL_FLASH_Unlock();
for (i = 0; i <= 3; i++) {
    HAL_FLASH_Program(FLASH_TYPEPROGRAMDATA_BYTE, Address, DATA[i]);
    Address++;
}
HAL_FLASH_Lock();

- Flash Read Operation
Address = 0x0802FF80;
HAL_FLASH_Unlock();
for (i = 0; i <= 3; i++) {
    READDATA[i] = *(__IO uint8_t*) Address;
    Address++;
}
HAL_FLASH_Lock();

- (Optional) Flash Erase Operation
This block is included in the source but commented out:

// HAL_FLASH_Unlock();
// FLASH_Erase_Sector(47, FLASH_VOLTAGE_RANGE_3);
// HAL_FLASH_Lock();

⚠️ Flash erase is required only if you're writing to a section that hasn't been previously erased. Flash memory must be erased in sectors before new data can be written.

 - Important Notes
Writing to flash too frequently can reduce its lifespan. Avoid excessive loops in production systems.

Always ensure you are writing to a safe memory location.

Double-check the memory mapping of your specific STM32 MCU before using this example. Writing to an incorrect address can corrupt code or cause undefined behavior.

The address 0x0802FF80 should fall within a writable flash sector. This address may need to be adjusted for your STM32 variant.
