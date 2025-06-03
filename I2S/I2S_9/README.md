# STM32 I2S to UART DMA Example

This project demonstrates how to set up an STM32 microcontroller to:
- Receive audio data via **I2S** (using DMA)
- Transmit data via **UART** (using DMA)
- Toggle an LED to indicate data reception (optional)
- Use basic peripheral initialization with STM32Cube HAL

---

## 📦 Features

- 📥 **I2S2 Master Receiver** mode using DMA
- 📤 **USART2 UART Transmit** using DMA
- ⚙️ **DMA** setup for both I2S and UART
- 🟢 Optional LED toggling on data reception
- 🧠 Written using STM32CubeMX auto-generated boilerplate with user-implemented logic

---

## 🧰 Peripherals Used

| Peripheral | Function             |
|-----------|----------------------|
| `I2S2`    | Audio data reception |
| `USART2`  | Serial transmission  |
| `DMA1`    | Efficient data transfer for I2S and UART |
| `GPIO`    | LED (LD2) and Button (B1) |

---

## 🧾 Configuration Summary

### I2S2

- Mode: `I2S_MODE_MASTER_RX`
- Standard: `I2S_STANDARD_PHILIPS`
- Data format: `16-bit`
- Audio Frequency: `8 kHz`

### USART2

- Baud Rate: `115200`
- Word Length: `8 Bits`
- Parity: `None`
- Mode: `TX/RX`
- DMA Enabled for TX

---

## 🚀 Getting Started

1. Flash the firmware to your STM32 device (configured for `I2S2` and `USART2`)
2. Connect an audio source to I2S input
3. Observe transmitted bytes on UART serial terminal (e.g., via USB-to-Serial adapter)

> ⚠️ Note: `HAL_UART_Transmit(huart, pData, Size, Timeout)` in `main.c` is a placeholder and **needs proper arguments** or **should be removed** if handled in DMA callback.

---

## 🧠 Callback Behavior (optional)

If using the `HAL_I2S_RxCpltCallback()` (currently commented):

- Toggles the LD2 LED on each data chunk received
- Sends one byte via UART (demo only)
- Add buffering or parsing for real-world audio applications

---

## 🛠 Known Issues / To Do

- [`HAL_UART_Transmit()`] in `main.c` is not correctly initialized — should use `&huart2` and real data
- DMA buffer and audio parsing logic not yet implemented
- `I2S_BUFFER_SIZE` and data array need to be defined for full DMA usage

---



