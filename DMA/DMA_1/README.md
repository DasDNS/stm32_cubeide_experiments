# STM32 DMA UART (Blocking Mode) Example

This project demonstrates **UART transmission** of a large data buffer (10KB) using **blocking mode** on an STM32 microcontroller. DMA is initialized, but **not actively used in transmission**, showing the inefficiencies of blocking communication.

## 🧠 Key Concepts

- **UART2** is used to transmit 10KB of data.
- **DMA** is initialized but not used for actual transmission.
- Uses **blocking HAL_UART_Transmit** instead of interrupt or DMA mode.
- **LED** toggles every 500ms (can lag due to blocking transfer).

---

## 🔍 Why This Matters

Sending large data in **blocking mode** forces the CPU to wait until transmission finishes, delaying other operations like blinking LEDs or handling inputs. This highlights the importance of **DMA or interrupt-based communication** in real-time systems.

---

## 📋 Behavior

- A 10KB buffer (`TxData`) is filled with sequential values.
- In each loop:
  - UART sends the buffer using `HAL_UART_Transmit`.
  - GPIO LED toggles every 500ms.
- **If transmission takes too long**, the LED may blink slower than expected.

---

## 🔧 Hardware Requirements

- STM32L0 series MCU (e.g., Nucleo-L073RZ).
- USART2 connected via USB or serial adapter.
- Onboard LED (e.g., LD2 on PA5).

---

## 💡 Code Snippet

```c
HAL_UART_Transmit(&huart2, TxData, 10240, HAL_MAX_DELAY);
HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
HAL_Delay(500);
