# STM32 DMA UART Transmission (Normal Mode)

This project demonstrates the use of **DMA in normal mode** for transmitting a large buffer (10KB) over **UART** on an STM32 microcontroller using STM32CubeIDE.

Unlike circular mode, **normal mode DMA** transfers the data once and then stops. This example is useful for understanding how DMA behaves in single-transfer scenarios.

---

## Key Concepts

- **DMA (Direct Memory Access):** Allows peripherals like UART to transfer data directly from memory without CPU intervention.
- **Normal Mode:** DMA transfers data **once** and stops. Requires re-triggering if continuous transmission is needed.
- **UART:** Asynchronous serial communication using USART2.
- **Callback Mechanism:** `HAL_UART_TxCpltCallback()` is triggered once after the full buffer is transmitted.

---

## Project Configuration

| Feature           | Description                                 |
|-------------------|---------------------------------------------|
| MCU               | STM32 series (e.g., STM32F103, STM32L476)   |
| UART Port         | USART2 (TX only used)                       |
| DMA Channel       | DMA1 Channel mapped to USART2_TX            |
| Buffer Size       | 10KB (`TxData[10240]`)                      |
| LED Blinking      | On PA5 every second                         |
| DMA Mode          | **Normal** (one-time transmission)          |

---

## How It Works

1. The `TxData` array (10KB) is filled with sample byte values (`i & 0xFF`).
2. DMA is configured to transfer the buffer over USART2.
3. `HAL_UART_Transmit_DMA()` is called **once** in `main()`.
4. When the transfer completes, the DMA triggers an interrupt.
5. Inside `HAL_UART_TxCpltCallback()`, a flag is set and a counter is incremented.
6. An LED continues to blink independently in the main loop.

---

## Code Highlights

### DMA Transfer

```c
HAL_UART_Transmit_DMA(&huart2, TxData, 10240);
