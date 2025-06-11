# STM32 UART-Based Real-Time FFT Analyzer

This project performs real-time Fast Fourier Transform (FFT) analysis on audio data received via UART using the CMSIS-DSP library. It targets STM32 microcontrollers and is suitable for applications such as audio spectrum analysis, signal monitoring, or embedded DSP projects.

---

## 🚀 Overview

- **Platform**: STM32 (tested with STM32F series)
- **Input**: 16-bit PCM audio data via UART
- **Processing**: 1024-point FFT using CMSIS-DSP
- **Output**: FFT magnitude (512 `float32_t` values) sent over UART
- **No windowing** is applied in this version for simplicity and raw spectral view

---

## 📦 Features

- **UART Input/Output** for communication with a PC or external device
- **1024-point FFT** using the optimized `arm_rfft_fast_f32()` function
- **Magnitude Calculation** using `arm_cmplx_mag_f32()`
- Optimized for real-time use on STM32 microcontrollers
- Designed for simple integration into DSP pipelines or PC-based spectrum viewers

---

## 🛠️ System Requirements

- STM32 MCU with UART support and floating-point unit (FPU recommended)
- STM32 HAL and CMSIS-DSP libraries configured
- UART interface (e.g., USB to Serial adapter)
- PC or device capable of sending PCM data and receiving float32 FFT results

---

## 📡 UART Configuration

| Setting        | Value     |
|----------------|-----------|
| Port           | USART2    |
| Baud Rate      | 115200    |
| Word Length    | 8 bits    |
| Stop Bits      | 1         |
| Parity         | None      |
| Flow Control   | None      |

### 🔁 Data Format

- **Input**: 2048 bytes = 1024 samples of 16-bit PCM (little-endian)
- **Output**: 2048 bytes = 512 `float32_t` magnitude values

---

## 📂 Project Structure

| File           | Description |
|----------------|-------------|
| `main.c`       | Main application logic including FFT processing |
| `main.h`       | Declarations and includes |
| `arm_math.h`   | CMSIS-DSP functions |
| `SystemClock_Config()` | Placeholder for clock setup |
| `MX_USART2_UART_Init()` | Initializes UART2 |
| `perform_fft()` | Optional function to encapsulate FFT steps |

---

## 🧠 How It Works

1. The STM32 initializes UART and the CMSIS FFT instance.
2. It waits for 2048 bytes (1024 samples) of 16-bit PCM data over UART.
3. The data is converted to `float32_t` for FFT processing.
4. A 1024-point FFT is computed using CMSIS-DSP.
5. The complex FFT result is converted to magnitude.
6. The resulting 512-point magnitude array is transmitted back over UART.

---

## 🧪 Testing with Python (Example)

```python
import serial
import numpy as np

# Open UART port
ser = serial.Serial('COM3', 115200, timeout=1)

# Generate a test 440 Hz sine wave
fs = 44100
samples = np.sin(2 * np.pi * 440 * np.arange(1024) / fs)
pcm_data = (samples * 32767).astype(np.int16)

# Send data
ser.write(pcm_data.tobytes())

# Receive FFT output
fft_bytes = ser.read(2048)  # 512 float32 values
fft_magnitude = np.frombuffer(fft_bytes, dtype=np.float32)

print(fft_magnitude)

📝 Notes
This version does not apply any windowing function to the input data. For more accurate spectral analysis, consider applying a Hanning or Hamming window.

You can easily enable windowing using CMSIS's arm_hann_window_f32() or manually.

📜 License
This project is open-source and released under the MIT License.
