# STM32 FFT-Based Audio Signal Analyzer

This project implements a real-time Fast Fourier Transform (FFT) on audio data using an STM32 microcontroller. The system receives 16-bit PCM `.wav` audio samples over UART, applies a Hanning window, performs FFT using CMSIS DSP library functions, and returns the magnitude spectrum over UART.

## 📌 Key Features

- 📦 **FFT Size**: 1024-point real-to-complex FFT
- 🪟 **Windowing**: Hanning window to reduce spectral leakage
- 🧮 **FFT Library**: CMSIS DSP (`arm_rfft_fast_f32`)
- 🔄 **UART Communication**: Full-duplex data exchange
- 📡 **Platform**: STM32 (Tested on STM32CubeIDE-generated HAL code)

---

## ⚙️ How It Works

### 1. **Data Acquisition**
The system continuously listens for `.wav`-encoded PCM data via UART (configured to 115200 baud). It expects 2048 bytes per transmission (1024 samples × 2 bytes/sample).

```c
HAL_UART_Receive(&huart2, uart_buffer, UART_BUFFER_SIZE, HAL_MAX_DELAY);

2. Preprocessing
The incoming 16-bit samples are converted to float32_t, and a Hanning window is applied to the input signal.
input_data[i] = (float32_t)((int16_t)(uart_buffer[2 * i] | (uart_buffer[2 * i + 1] << 8)));
input_data[i] *= window[i];
Hanning window generation:
for (int i = 0; i < FFT_SIZE; i++) {
    window[i] = 0.5f * (1.0f - arm_cos_f32((2.0f * PI * i) / (FFT_SIZE - 1)));
}

3. FFT Execution
FFT is performed using the CMSIS DSP function:
arm_rfft_fast_f32(&fft_instance, input_data, fft_output, 0);

4. Magnitude Spectrum
The complex FFT output is converted to a magnitude spectrum:
arm_cmplx_mag_f32(fft_output, fft_magnitude, FFT_SIZE / 2);
Only the first half of the FFT output is meaningful due to symmetry in the FFT of real signals.

5. Transmission
The calculated magnitude values are transmitted back over UART:
HAL_UART_Transmit(&huart2, (uint8_t *)fft_magnitude, sizeof(fft_magnitude), HAL_MAX_DELAY);
