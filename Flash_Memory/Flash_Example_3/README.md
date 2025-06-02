# STM32 Flash Memory Example

This STM32 project demonstrates how to:

- Erase a specific flash memory sector
- Write data bytes (`0x01`, `0x02`, `0x03`, `0x04`) to a specified flash address
- Read the data back from flash memory

## 📁 Overview

The program runs in an infinite loop and performs the following steps:

1. Erases one flash memory page at address `0x0802F080`
2. Writes 4 bytes to the erased memory
3. Reads the bytes back and stores them in a buffer

This project uses STM32 HAL libraries and is configured for STM32 with USART2 UART debugging (baud rate 115200).

## 📦 Flash Operation Summary

- **Erase Address**: `0x0802F080`
- **Written Data**: `{0x01, 0x02, 0x03, 0x04}`
- **Flash Write Type**: `FLASH_TYPEPROGRAMDATA_BYTE`
- **Write Offset**: Every 8 bytes (due to alignment/padding)

## 🔧 Setup

### Prerequisites

- STM32CubeIDE or equivalent development environment
- STM32 MCU (tested with STM32L4 series)
- USB-to-serial UART connection (for debugging)


### Flash Write Logic

```c
HAL_FLASH_Unlock();
for (i = 0; i <= 3; i++)
{
    HAL_FLASH_Program(FLASH_TYPEPROGRAMDATA_BYTE, Address, DATA[i]);
    Address += 8; // 8-byte aligned writes
}
HAL_FLASH_Lock();

### Flash Read Logic

```c
for (i = 0; i <= 3; i++)
{
    READDATA[i] = *(__IO uint8_t*) Address;
    Address += 8;
}

### Flash Erase Function

```c
void Erase_Flash(uint32_t Address)
{
    FLASH_EraseInitTypeDef EraseInitStruct;
    uint32_t PageError;

    HAL_FLASH_Unlock();
    EraseInitStruct.TypeErase = FLASH_TYPEERASE_PAGES;
    EraseInitStruct.PageAddress = Address;
    EraseInitStruct.NbPages = 1;

    HAL_FLASHEx_Erase(&EraseInitStruct, &PageError);
    HAL_FLASH_Lock();
}

🚀 How It Works
Erase_Flash() erases the flash page at 0x0802F080.

The program writes four bytes to the flash memory using HAL_FLASH_Program.

The same memory address is used to read the data back and store it in the READDATA[] buffer.

💡 Note: Flash memory on STM32 must be erased before writing. It is only possible to change bits from 1 to 0 unless the sector is erased.

🛠️ Debugging Tips
You can use HAL_UART_Transmit() to print READDATA values to a serial console (currently commented out).

Be cautious with address alignment and page boundaries.

Flash writing takes time and power—avoid writing in tight loops without control.


