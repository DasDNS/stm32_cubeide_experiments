# STM32 I2S-to-UART Audio Sample Forwarding

This STM32 project uses I2S to receive 16-bit audio data from an external source (e.g., a MEMS microphone or audio codec) and transmits the data over UART using DMA.

## Features

- Uses **I2S2** peripheral in **Master RX** mode to receive audio samples.
- Transfers received 16-bit audio data via **USART2** using **DMA**.
- Includes **DMA**-based reception and transmission for efficiency and reduced CPU load.
- Implements a basic **HAL_I2S_RxCpltCallback** to handle continuous streaming.
- UART transmission begins with an acknowledgment message.

## Hardware Requirements

- STM32 microcontroller with I2S2 and USART2 (e.g., STM32L4 series).
- External audio source or I2S-compatible sensor (e.g., MEMS microphone).
- Serial UART monitor (e.g., USB-to-UART converter or ST-Link VCP).
- LED and user button (optional, connected to `LD2_Pin` and `B1_Pin`).

## Peripherals Used

| Peripheral | Mode / Function               |
|-----------|-------------------------------|
| I2S2      | Master Receive (16 kHz, 16-bit)|
| USART2    | UART TX @ 115200 baud         |
| DMA       | For both I2S receive and UART transmit |
| GPIO      | For LED (LD2) and Button (B1)  |

## How It Works

1. Upon boot, the microcontroller sends a startup message via UART.
2. It begins listening for audio samples via I2S.
3. Each time a new 16-bit audio sample is received:
   - The sample is immediately transmitted over UART using DMA.
   - The I2S receive operation is restarted to continue receiving audio.

## Code Highlights

- `HAL_I2S_RxCpltCallback`: Called when a single audio sample is received. It restarts I2S reception and triggers UART DMA transmission.
- `ackBuffer[]`: A short message sent via UART at startup.
- `toReceive` / `toWrite`: Variables to handle incoming and outgoing sample values.

## Build & Flash Instructions

1. Open the project in STM32CubeIDE.
2. Connect your STM32 board to your PC.
3. Build the project (`Project > Build Project`).
4. Flash to device (`Run > Debug` or `Run > Run`).

## Serial Output

To view output:
- Connect to `USART2` using a serial terminal (e.g., PuTTY, Tera Term).
- Configure to `115200 baud`, `8 data bits`, `1 stop bit`, `no parity`.

Expected output:
Data:
<binary 16-bit values representing audio samples>

---

**Note**: This project is a minimal example and does not include file storage or advanced signal processing. For recording, buffering, or transmitting multiple samples, you will need to extend the DMA buffer size and implement proper circular buffering.
