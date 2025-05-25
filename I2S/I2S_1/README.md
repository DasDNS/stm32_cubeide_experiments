# STM32 I2S Audio Receiver with UART DMA Transmission

This STM32 project demonstrates how to receive 16-bit audio data over I2S using DMA and transmit the data over UART using DMA. It is designed for applications where audio or other high-frequency data streams are to be forwarded in real-time to another system (e.g., a PC or external MCU).

## Features

- **I2S2 Master Receiver**  
  Receives 16-bit audio samples at 16 kHz from an external I2S audio source.

- **UART2 Transmission (DMA)**  
  Transmits received I2S samples via UART2 using DMA for efficient non-blocking data transfer.

- **DMA Integration**  
  Both I2S and UART use DMA to minimize CPU usage.

## Hardware Requirements

- STM32 microcontroller (tested on STM32L4 series)
- I2S-compatible microphone or audio source (e.g., ICS43434)
- USB-to-UART adapter (for UART2 monitoring)
- STM32CubeIDE for compiling and flashing

## Peripherals Used

| Peripheral | Function                  | Notes                    |
|-----------|---------------------------|--------------------------|
| I2S2      | Audio data input (Rx)     | Master Receiver mode     |
| UART2     | Serial output             | Baudrate: 115200         |
| DMA       | Non-blocking data transfer| For both I2S and UART    |
| GPIO      | LED and button            | Optional for feedback    |

## System Behavior

- Upon startup, the system initializes the clock and peripherals.
- It begins receiving 16-bit samples using I2S2 + DMA.
- Each time a sample is received (I2S Rx Complete Callback), the sample is immediately transmitted via UART2 using DMA.
- The system runs in a low-overhead infinite loop while the transfers are handled by interrupts and DMA.

## Code Overview

### Main Components

- `main()`  
  Initializes peripherals and starts the first I2S DMA reception.

- `HAL_I2S_RxCpltCallback()`  
  Triggered when a 16-bit sample is received via I2S.  
  - Transfers the sample to `toWrite`
  - Sends it out via UART2 using DMA
  - Re-arms the I2S DMA receiver

### Initialization Functions

- `MX_I2S2_Init()`  
  Configures I2S2 in master receive mode (Philips standard, 16-bit data, 16 kHz).

- `MX_USART2_UART_Init()`  
  Configures UART2 at 115200 baud, 8-N-1 format.

- `MX_DMA_Init()`  
  Enables the DMA controller and interrupts.

## Build & Flash Instructions

1. Open the project in STM32CubeIDE.
2. Connect your STM32 board via ST-Link.
3. Build and flash the firmware (`Project > Build All`, then `Run > Debug` or `Run > Run`).
4. Connect a UART2 receiver to monitor transmitted data (e.g., Serial Plotter, Python script, etc.).

## Notes

- Ensure your I2S microphone or source is connected to the correct SPI2 pins.
- This project uses single-sample transfer via DMA to minimize latency and simplify data forwarding.
- Can be extended to transmit larger blocks of data or log to SD card.
