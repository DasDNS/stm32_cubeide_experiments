# STM32 I2S Audio Acquisition with DMA and UART Transmission

This STM32 firmware initializes and configures peripherals to receive audio data via the I2S interface using DMA and optionally transmit it over UART. The setup is optimized for low-latency and efficient sound sample acquisition using an I2S-compatible microphone or audio codec.

## Features

- 📥 **I2S Audio Input**: Configured in **Master Receiver** mode with 16-bit extended format and 8kHz sample rate.
- 🚀 **DMA Support**: Audio samples are received efficiently via DMA without CPU intervention.
- 📤 **UART Transmission (Optional)**: Transmits the received sample over UART using DMA (currently commented out).
- 📟 **USART2 at 115200 Baud**: Enables serial communication with host PC or other devices.
- 💡 **LED GPIO Support**: Includes basic GPIO initialization for status indication.

## Hardware Requirements

- STM32 development board (e.g., STM32L4 series)
- I2S Microphone or Audio Codec (e.g., ICS43434, SPH0645LM4H)
- USB-UART Bridge (for serial output)
- Optional: Serial Terminal software (e.g., PuTTY, Tera Term)

## Peripherals Used

| Peripheral | Description                         |
|-----------|-------------------------------------|
| I2S2      | Audio input from microphone         |
| USART2    | UART for transmitting audio samples |
| DMA1      | DMA channels for I2S and UART       |
| GPIO      | For user button and LED             |

## Setup Instructions

1. **Connect the I2S microphone** to the STM32 board's SPI2 interface (used as I2S2).
2. **Open the project in STM32CubeIDE**.
3. Compile and upload the firmware to your STM32 board.
4. Open a serial terminal on your PC at `115200 8N1` to receive UART output (if enabled).

## How It Works

- The program configures I2S2 in `MASTER_RX` mode.
- DMA is initialized to continuously fill `data_i2s[]` with 16-bit samples.
- Upon DMA completion, the `HAL_I2S_RxCpltCallback` is triggered.
- The first sample is extracted (`data_i2s[0]`) and stored in `sample_i2s`.
- UART transmission of the sample is provided but currently commented out.

### Example Callback Logic (Optional UART DMA Transmission)

Uncomment the lines below inside `HAL_I2S_RxCpltCallback` to enable UART DMA transmission:

```c
buffer[0] = (uint8_t)(sample_i2s & 0xFF);
buffer[1] = (uint8_t)((sample_i2s >> 8) & 0xFF);
HAL_UART_Transmit_DMA(&huart2, buffer, sizeof(buffer));

Notes
This code is a starting point and does not implement buffering, filtering, or advanced audio processing.
