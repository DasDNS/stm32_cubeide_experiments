# STM32 Real-Time FFT Analyzer Using CMSIS-DSP and UART

This project implements a real-time FFT (Fast Fourier Transform) analyzer on an STM32 microcontroller. It receives 16-bit PCM audio data over UART, applies a Hanning window using CMSIS-DSP, computes the FFT, and sends the magnitude spectrum back via UART.

## Overview

- **Platform**: STM32 (tested with STM32F series)
- **Input**: 16-bit PCM audio data via UART
- **Output**: FFT magnitude spectrum via UART
- **FFT Size**: 1024-point
- **Windowing**: Hanning (using `arm_hann_window_f32`)
- **DSP Library**: CMSIS-DSP

## Key Features

- UART-based input and output for easy data streaming
- Real-time FFT processing of audio samples
- Uses CMSIS DSP for high-performance FFT and windowing
- Minimal memory footprint (suitable for embedded systems)

## How It Works

1. Initializes the UART and CMSIS FFT instance.
2. Receives a block of 2048 bytes (1024 samples of 16-bit PCM audio).
3. Converts samples to `float32_t`.
4. Applies a Hanning window using CMSIS.
5. Computes the FFT using `arm_rfft_fast_f32`.
6. Calculates magnitude using `arm_cmplx_mag_f32`.
7. Transmits the 512-point magnitude spectrum over UART.

## UART Configuration

- **Port**: USART2
- **Baud Rate**: 115200
- **Data Bits**: 8
- **Stop Bits**: 1
- **Parity**: None
- **Flow Control**: None

### Input Format

- **Size**: 2048 bytes per block (1024 samples)
- **Encoding**: Little-endian 16-bit signed PCM audio

### Output Format

- **Size**: 512 `float32_t` values (2048 bytes)
- **Content**: Magnitude spectrum of the FFT

## Dependencies

- STM32 HAL Drivers
- CMSIS-DSP Library

Make sure you have these configured in your project settings and included in your build system.

## Example UART Communication (Host Side)

You can use a Python script like the following to send and receive data:

```python
import serial
import numpy as np

# Open serial port
ser = serial.Serial('COM3', 115200, timeout=1)

# Prepare 1024 16-bit PCM samples
samples = np.sin(2 * np.pi * 440 * np.arange(1024) / 44100)  # 440 Hz sine wave
samples_int16 = (samples * 32767).astype(np.int16)
ser.write(samples_int16.tobytes())

# Read FFT magnitude response
response = ser.read(2048)  # 512 float32 values
fft_magnitude = np.frombuffer(response, dtype=np.float32)

print(fft_magnitude)

Project Files
main.c – Core logic for UART receive, FFT processing, and transmission

main.h – Header file for main application

arm_math.h – CMSIS DSP header

SystemClock_Config – Stub function for clock configuration

Error_Handler – Simple error trap loop

Build & Flash
Use STM32CubeIDE or your preferred STM32 toolchain to build and flash the firmware. Ensure CMSIS-DSP is included in your project.

License
This project is released under the MIT License.
