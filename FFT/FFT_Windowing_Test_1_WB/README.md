# STM32 UART-Based FFT Processing

This project implements a basic real-time Fast Fourier Transform (FFT) system on an STM32 microcontroller using the CMSIS-DSP library. It receives audio sample data (e.g., from a `.wav` file in 16-bit PCM format) via UART, performs an FFT after applying a Hanning window, and transmits the magnitude spectrum back over UART.

## Features

- UART reception and transmission (USART1)
- 1024-point FFT using CMSIS-DSP `arm_rfft_fast_f32`
- Hanning window function applied to minimize spectral leakage
- Real-time frequency analysis of audio signals
- Optimized for Cortex-M4 (hardware FPU supported)

## Hardware Requirements

- STM32 MCU (e.g., STM32L4 series with UART and FPU)
- UART interface (can be connected to PC or another MCU)
- CMSIS-DSP library included in the project

## Software Requirements

- STM32CubeIDE or compatible STM32 toolchain
- CMSIS-DSP library
- HAL drivers for UART

## How It Works

1. **UART Receive**: The system waits for `2048 bytes` of audio data (corresponding to `1024` 16-bit PCM samples).
2. **Conversion**: The raw data is converted into `float32_t` values.
3. **Windowing**: A Hanning window is applied to the time-domain signal.
4. **FFT Execution**: A real FFT is computed using `arm_rfft_fast_f32`.
5. **Magnitude Calculation**: The complex FFT result is converted into magnitude values using `arm_cmplx_mag_f32`.
6. **UART Transmit**: The resulting frequency spectrum (512 float values) is transmitted back via UART.

## Configuration

- **UART Settings**:
  - Baud Rate: 115200
  - Data Bits: 8
  - Stop Bits: 1
  - Parity: None

- **FFT Size**: 1024
- **Window Function**: Hanning (manually computed)
- **Input Format**: 16-bit PCM, little-endian
- **Output Format**: 512 `float32_t` magnitude values

## File Structure

- `main.c` – Main program logic
- `arm_math.h` – CMSIS-DSP functions
- `MX_USART1_UART_Init` – Initializes UART peripheral
- `apply_window()` – Multiplies input signal with Hanning window
- `arm_rfft_fast_f32()` – Computes FFT
- `arm_cmplx_mag_f32()` – Computes magnitude

## Usage

1. Connect the STM32 UART (USART1) to your host system.
2. Send 2048 bytes of PCM audio data (16-bit, mono).
3. Receive 512 float values representing the magnitude of the FFT result.

## Example Tools for Testing

- Python script for serial communication (PySerial)
- Audacity to extract PCM WAV data
- RealTerm / CoolTerm for UART testing

## Known Limitations

- Assumes 16-bit PCM input; not validated for other formats.
- No error-checking on received data.
- Blocking UART calls (`HAL_UART_Receive` and `HAL_UART_Transmit`) — may affect real-time performance for larger buffers.

## License

This project includes code generated by STM32CubeMX and uses STMicroelectronics' HAL drivers. The project is provided **AS-IS** without warranty under the license specified by ST.

---

