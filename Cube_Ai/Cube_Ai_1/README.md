# STM32F4xx Embedded System Project

This project is developed for STM32F4-based microcontrollers (e.g., STM32F469 Discovery) using STM32CubeIDE and FreeRTOS. It integrates various hardware peripherals and is designed to demonstrate key features like Ethernet, LCD display, camera interface, audio I/O, and more.

---

## ⚙️ Peripherals Configuration Summary

| Peripheral | Description |
|------------|-------------|
| **ETH**     | Ethernet communication using RMII interface |
| **LTDC**    | LCD display control with RGB565 format |
| **DCMI**    | Camera sensor interface |
| **DMA2D**   | Accelerated 2D graphics processing |
| **ADC3**    | Analog input sensing (Channel 4) |
| **CRC**     | CRC data integrity checks |
| **QUADSPI** | External flash memory access |
| **RTC**     | Real-Time Clock with alarm functionality |
| **SAI2**    | Audio signal input/output |
| **SDMMC1**  | SD card storage |
| **TIMx**    | PWM, encoder, and timing functions |
| **USART1/6**| Serial communication |
| **I2C1/I2C3**| Sensor/device communication |
| **SPI2**    | SPI-based device communication |
| **FMC/SDRAM**| External SDRAM memory interface |

---

## 🛠️ Build Instructions

### Prerequisites

- STM32CubeIDE installed
- STM32CubeMX (optional, for configuration adjustments)
- Target board: STM32F4xx (e.g., STM32F469 Discovery)

### Steps to Build

1. Open the project in **STM32CubeIDE**.
2. Verify the correct target MCU is selected.
3. Use the `.ioc` file to review or adjust pinouts and peripheral settings.
4. Build the project using `Project → Build All`.
5. Connect your STM32 board via **ST-LINK** or a compatible debugger.
6. Flash the firmware:
   - Use the built-in debugger, or
   - Drag the generated `.elf` file to the board's bootloader (if supported).

---

## 📋 FreeRTOS Tasks

### Default Task

```c
void StartDefaultTask(void const * argument)
{
  MX_USB_HOST_Init();
  for(;;)
  {
    osDelay(1);
  }
}
This task initializes the USB Host stack and loops with a minimal delay.

🔧 GPIO Pinout Summary
Key GPIOs initialized:

LCD Control: LCD_DISP, LCD_BL_CTRL

Power Switch: OTG_FS_PowerSwitchOn

Camera Enable: DCMI_PWR_EN

User Detect: uSD_Detect, OTG_FS_OverCurrent

Refer to MX_GPIO_Init() in main.c for the full list of initialized GPIOs.

📦 Memory Layout
SDRAM is initialized via the FMC interface for external memory use.

Ethernet DMA descriptors are placed at designated memory locations via compiler directives.

📝 Notes
The code uses HAL (Hardware Abstraction Layer) from the STM32CubeF4 package.

FreeRTOS is included and configured for multitasking.

Some peripherals are pre-configured but may require user code within the /* USER CODE BEGIN */ sections.

The system clock is configured to run at 180 MHz using HSE and PLL.

📁 Project Structure
css
Copy
Edit
├── Core/
│   ├── Inc/
│   └── Src/
├── Drivers/
│   ├── BSP/
│   └── STM32F4xx_HAL_Driver/
├── Middlewares/
│   └── Third_Party/
├── .ioc
├── README.md
└── ...
