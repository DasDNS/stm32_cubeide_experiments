# STM32 UART DMA Example (Circular Mode)

This STM32 project demonstrates **UART data transmission using DMA in circular mode**. It uses STM32CubeIDE-generated code and shows how to offload repetitive data transfers from the CPU using Direct Memory Access (DMA).

---

## Overview

- **Microcontroller**: STM32 (tested with STM32F103 / STM32F4 series)
- **Peripherals Used**:
  - USART2 (TX)
  - DMA (for UART TX)
  - GPIO (for LED toggle)
- **DMA Mode**: Circular
- **UART Baudrate**: 115200
- **Buffer Size**: 10KB (`10240` bytes)

This project sends a 10KB data buffer continuously over UART using DMA in circular mode while blinking an LED every 1 second to indicate main loop activity.

---

## Features

- DMA **circular mode** is used to transmit the buffer repeatedly without re-triggering the transfer.
- **Interrupt-based** DMA completion callback is included (`HAL_UART_TxCpltCallback`) to track transfer completions.
- CPU is mostly free; DMA handles memory-to-peripheral data transfer in the background.
- LED connected to `GPIOA Pin 5` blinks to show the CPU is active.

---

## Circular Mode Behavior

- In **circular mode**, DMA:
  - Automatically restarts the transmission once the buffer is sent.
  - Keeps reusing the same memory buffer without further CPU intervention.
  - Triggers `HAL_UART_TxCpltCallback` at each cycle completion.
- Result: `countInterrupt` increases rapidly, while `countLoop` (updated every second) increases slowly.

---

## Buffer Initialization

```c
for (uint32_t i = 0; i < 10240; i++) {
    TxData[i] = i & 0xFF;
}

```c
for (uint32_t i = 0; i < 10240; i++) {
    TxData[i] = i & 0xFF;
}
