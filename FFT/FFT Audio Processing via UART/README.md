# STM32 Real-Time FFT on UART Audio Stream

This project implements real-time Fast Fourier Transform (FFT) on audio samples received over UART. It uses the ARM CMSIS-DSP library on an STM32 microcontroller (e.g., STM32L0 series) to process `.wav`-style 16-bit PCM data in chunks and return the FFT magnitude spectrum over UART.

---

## 🔧 System Overview

- **Platform**: STM32 (tested on STM32L0 series)
- **FFT Size**: 1024 points
- **Input Format**: 16-bit PCM audio (.wav style)
- **Windowing**: Hanning Window
- **Libraries**:
  - STM32 HAL
  - CMSIS-DSP (`arm_math.h`)

---

## 📦 Features

- Receives 2048 bytes of 16-bit PCM audio over UART.
- Applies a Hanning window to reduce spectral leakage.
- Performs a 1024-point real FFT.
- Calculates magnitude spectrum from the complex FFT output.
- Transmits `fft_magnitude[]` (512 float32 values) back via UART.

---

## 📤 UART Communication

### Input:
- 2048 bytes of 16-bit signed PCM audio.
- Format: Little-endian, interleaved LSB-MSB for each sample.
- Example (Python):
  ```python
  # Send 1024-sample, 16-bit mono audio over serial
  import serial
  import numpy as np

  ser = serial.Serial('COMx', 115200)
  data = (np.sin(2 * np.pi * 1000 * np.arange(1024) / 16000) * 32767).astype(np.int16)
  ser.write(data.tobytes())

Output:
512 float32 values (fft_magnitude[])

Each represents magnitude of corresponding frequency bin.

Example UART output format (raw bytes):
<float32 bin0><float32 bin1><float32 bin2>...<float32 bin511>


This project performs real-time FFT (Fast Fourier Transform) on audio data received via UART. It uses the ARM CMSIS-DSP library on an STM32 microcontroller to process 16-bit PCM audio samples and return the magnitude spectrum.

---

## 📁 Project Structure

| File/Function             | Description                                                              |
|--------------------------|--------------------------------------------------------------------------|
| `main.c`                 | Main firmware logic for receiving, processing, and transmitting FFT data |
| `arm_math.h`             | CMSIS DSP library for FFT, windowing, magnitude                          |
| `MX_USART2_UART_Init()`  | UART2 initialization                                                     |
| `apply_window()`         | Optional reusable function to apply Hanning or other windows             |

---

## 📊 Frequency Resolution

- **Sampling Rate**: 16,000 Hz (assumed from external source)  
- **FFT Size**: 1024  
- **Frequency Bin Size**:  
  \[
  \text{Bin Size} = \frac{Fs}{FFT\_SIZE} = \frac{16000}{1024} \approx 15.625 \text{ Hz/bin}
  \]  
- **Bin `i` corresponds to frequency**:  
  \[
  f_i = i \times 15.625 \text{ Hz}
  \]

---

## 🚀 How to Use

### 1. Setup
- Flash firmware to STM32 using **STM32CubeIDE** or **STM32CubeProgrammer**.
- Connect to **UART2** via serial terminal or PC application.

### 2. Stream Audio Data
- Send **2048 bytes** of 16-bit PCM samples over UART.
- The STM32 will:
  - Convert data to `float32_t`
  - Apply a **Hanning window**
  - Compute **FFT**
  - Send back **512 float32** values (2048 bytes)

### 3. Visualize
- Capture output via PC and plot using:
  - Python + `matplotlib`
  - Arduino Serial Plotter
  - MATLAB

---

## 🛠️ Customization

- **Change FFT size**: Modify `FFT_SIZE` and `UART_BUFFER_SIZE` as needed.
- **Alternate windows**: Use `arm_hann_window_f32()` instead of manual generation (if available in your CMSIS version).
- **Repeat processing**: Add timeout-based polling or interrupt-driven callbacks for continuous data streaming.

---


