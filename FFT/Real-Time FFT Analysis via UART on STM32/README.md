# Real-Time FFT Analysis via UART on STM32

This project performs real-time Fast Fourier Transform (FFT) analysis on audio data received via UART on an STM32 microcontroller. It reads 16-bit PCM `.wav` data, applies a Hanning window, performs an FFT using CMSIS DSP library, and transmits the FFT magnitude data back over UART.

## Features

- UART communication for receiving `.wav` data and transmitting FFT results
- 1024-point FFT using `CMSIS-DSP`'s `arm_rfft_fast_f32`
- Hanning windowing for spectral smoothing
- Real-time data processing loop
- Works with 16-bit PCM `.wav` samples

## Dependencies

- STM32 HAL drivers
- CMSIS-DSP library

## Hardware Requirements

- STM32 microcontroller (tested with STM32F series)
- UART communication interface (e.g., USB-to-Serial adapter)
- Host computer or external device to send `.wav` audio samples and receive FFT results

## File Overview

- `main.c`: Main application source code
- `main.h`: Header file for prototypes and includes
- `arm_math.h`: CMSIS DSP functions
- UART Buffer: `2048` bytes for receiving `.wav` audio samples
- FFT Buffer: 1024 samples (512-point frequency resolution)

## How It Works

1. The STM32 initializes the UART and CMSIS FFT structures.
2. A Hanning window is computed and stored in a buffer.
3. The microcontroller waits to receive audio data over UART.
4. Upon receiving 1024 samples:
   - It converts 16-bit PCM data to 32-bit float.
   - Applies the Hanning window.
   - Computes the FFT.
   - Calculates the magnitude of the complex FFT output.
   - Sends the magnitude spectrum back over UART.

## UART Protocol

- **Baud Rate**: 115200
- **Data Format**: 16-bit PCM little-endian
- **Input Chunk Size**: 2048 bytes (1024 samples)
- **Output Format**: 512 `float32_t` values (FFT magnitude)

## Notes

- Ensure the audio sample rate and UART speed allow for timely real-time processing.
- For testing, you can use Python scripts to send `.wav` segments over UART.
- The Hanning window helps reduce spectral leakage.

## To Do

- Add support for dynamic FFT sizes
- Implement `.wav` file parsing on-device
- Improve error handling and timeout management

## License

This project is open-source and available under the MIT License.

