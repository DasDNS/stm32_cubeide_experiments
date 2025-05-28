# X-CUBE-AI Embedded Inference Project

This project demonstrates a basic setup for running an AI model inference on an STM32 microcontroller using STMicroelectronics' X-CUBE-AI expansion package. The application is generated with STM32CubeMX and executed on a supported STM32 board.

## Features

* X-CUBE-AI integration
* DFSDM-based audio input
* Peripheral initialization for I2C, QSPI, SPI, UART, and USB OTG
* Continuous model inference loop

## Hardware Requirements

* STM32 board with support for DFSDM (e.g., STM32L4 series)
* USB connectivity (for UART or debug)
* Audio input via DFSDM
* Optional QSPI flash and I2C peripherals depending on model and data handling

## Software Requirements

* STM32CubeMX
* STM32CubeIDE or compatible development environment
* X-CUBE-AI Expansion Package
* STM32 HAL library

## Project Structure

The application is built on the STM32 HAL framework. Key components include:

* **main.c**: Main entry point for the application
* **app\_x-cube-ai.c/h**: Handles initialization and inference of the neural network
* **MX\_X\_CUBE\_AI\_Init()**: Initializes the AI model
* **MX\_X\_CUBE\_AI\_Process()**: Runs inference loop

## Initialization

### System Clock

The system clock is configured with LSE and MSI, and PLL is used for core clocking.

### Peripherals

* **DFSDM1**: For audio input
* **I2C2**: General communication
* **QSPI**: External flash memory access
* **SPI3**: For external device communication
* **UART1, UART3**: Serial communication/debugging
* **USB OTG FS**: USB device support

## Execution Flow

```c
int main(void)
{
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  MX_DFSDM1_Init();
  MX_I2C2_Init();
  MX_QUADSPI_Init();
  MX_SPI3_Init();
  MX_USART1_UART_Init();
  MX_USART3_UART_Init();
  MX_USB_OTG_FS_PCD_Init();
  MX_X_CUBE_AI_Init();

  while (1)
  {
    MX_X_CUBE_AI_Process();
  }
}
```

## Notes

* Modify the `MX_X_CUBE_AI_Process()` function to include application-specific processing of inference results.
* Ensure model quantization and input formatting match your AI network configuration.

## References

* [X-CUBE-AI Documentation](https://www.st.com/en/embedded-software/x-cube-ai.html)
* [STM32CubeMX](https://www.st.com/en/development-tools/stm32cubemx.html)
* [STM32CubeIDE](https://www.st.com/en/development-tools/stm32cubeide.html)

