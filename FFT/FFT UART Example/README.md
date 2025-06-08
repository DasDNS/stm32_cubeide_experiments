# STM32 FFT via UART Example

This project demonstrates how to perform a Fast Fourier Transform (FFT) on a test sine wave signal using the ARM CMSIS-DSP library on an STM32 microcontroller (STM32L0 series), and transmit the resulting frequency magnitudes over UART.

## 📦 Project Overview

- **Board**: STM32L0 Series (e.g., NUCLEO-L073RZ)
- **Peripheral Used**: UART2 (for transmitting FFT results)
- **Library**: CMSIS-DSP (for FFT)
- **FFT Length**: 256 samples
- **Sampling Rate**: 16 kHz
- **Test Signal**: 1 kHz sine wave

## 🧠 Features

- Initializes STM32 HAL and CMSIS DSP components.
- Generates a 1 kHz sine wave in software.
- Performs a real FFT using `arm_rfft_fast_f32`.
- Calculates the magnitude spectrum using `arm_cmplx_mag_f32`.
- Sends the frequency-domain magnitudes over UART.

## 🔧 Project Structure

- `main.c` — Core application logic:
  - Sine wave generation
  - FFT computation
  - UART output
- `MX_USART2_UART_Init` — Initializes USART2 for 115200 baud.
- `send_fft_results_via_uart()` — Formats and sends FFT results over UART.

## 📤 UART Output

The UART transmits data in the following format:
frequency 0.000000: 0.023487
frequency 62.500000: 0.034829
...
frequency 1000.000000: 128.392857


This output can be visualized using a serial plotter (e.g., Arduino Serial Plotter, RealTerm, or a custom Python script).

## 🔁 Main Loop Behavior

After one FFT is performed and transmitted, the program enters an infinite loop and does not repeat. This example is intended for demonstration and testing purposes.

## 🚀 Getting Started

### Prerequisites

- STM32CubeIDE
- ST-Link drivers
- Serial terminal (e.g., Tera Term, PuTTY)

### Build & Flash

1. Open the project in STM32CubeIDE.
2. Build the project.
3. Connect your STM32 board via USB.
4. Flash the firmware to the device.

### UART Setup

- **Baud Rate**: 115200
- **Data Bits**: 8
- **Stop Bits**: 1
- **Parity**: None

---


