# STM32 I2S to UART Bridge (Using DMA)

This STM32 project implements an I2S (audio) to UART data bridge using DMA for both peripherals. The microcontroller receives 16-bit audio data via the I2S interface and transmits it over USART2. This setup is commonly used in embedded audio streaming or sensor communication applications.

---

## 📦 Features

- 🎧 **I2S2 Interface** (16-bit audio data @ 16kHz)
- 📤 **USART2 UART** (115200 baud) for serial transmission
- ⚙️ **DMA** enabled for efficient data transfer
- 🧠 **Interrupt-driven** I2S reception and UART transmission
- 🚫 No polling or blocking delays in the main loop

---

## 🔧 System Configuration

### ➕ I2S2 Configuration
| Parameter       | Value                  |
|----------------|------------------------|
| Mode           | Master Transmit        |
| Standard       | Philips                |
| Data Format    | 16-bit                 |
| Audio Freq     | 16 kHz                 |
| MCLK Output    | Disabled               |
| CPOL           | Low                    |

> Note: Although configured as **Master Transmit**, the code uses `HAL_I2S_Receive_DMA()` indicating it functions as a receiver. Update mode if needed.

### 🔌 USART2 Configuration
| Parameter     | Value          |
|--------------|----------------|
| Baud Rate    | 115200         |
| Word Length  | 8 bits         |
| Parity       | None           |
| Stop Bits    | 1              |
| Mode         | TX/RX          |

### 🛠 DMA Configuration
- DMA is enabled for both I2S and UART
- Interrupts are configured for DMA transfer completion

---

## 📜 Code Workflow

1. **Initialization**:
   - Clock, GPIO, DMA, I2S, and USART2 are initialized in `main()`.

2. **Reception (DMA)**:
   - `HAL_I2S_Receive_DMA()` is started in `main()` to begin capturing 1 word (16-bit) from the I2S line.

3. **Callback Handling**:
   - In `HAL_I2S_RxCpltCallback()`, the received value is copied and sent over UART using `HAL_UART_Transmit_IT()`.

4. **Re-start DMA**:
   - The I2S DMA receive is re-initialized for the next transfer.

---

## 🔁 Infinite Loop

The `while (1)` loop does nothing explicitly. All core logic is handled through interrupt callbacks, making the system non-blocking and efficient.

---

## 🧠 Notes

- Ensure the I2S peripheral is wired correctly and a valid master clock (BCLK, WS, SD) is provided by the external audio source.
- Although `I2S2` is initialized in **Master Transmit Mode**, the actual usage is **Receive**. This may need correcting in `MX_I2S2_Init()`.
- The DMA buffer size is set to 1 word for simplicity. You can increase it to stream larger blocks.

---

## ⚠️ Known Issues

- `HAL_I2S_Receive_DMA()` expects I2S to be in **Receive Mode**, but current config is `I2S_MODE_MASTER_TX`.
- Ensure correct configuration for your hardware: match I2S mode (Master/Slave) to external device requirements.

---

## 📚 Dependencies

- STM32 HAL Drivers
- CubeMX generated startup and peripheral initialization code

---

