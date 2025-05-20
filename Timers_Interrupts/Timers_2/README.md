# STM32 TIM3 Interrupt & UART Example

This project demonstrates the basic setup and usage of the STM32 microcontroller peripherals using HAL libraries:

- **Timer 3 (TIM3)** configured to generate periodic interrupts (~1 second interval)
- **UART2** configured for serial communication at 115200 baud rate
- **GPIO** configured for onboard LED (LD2) and user button (B1)
- System clock configured to MSI oscillator (approx. 2.1 MHz)

## Features

- Timer 3 interrupt triggers every 1 second
- LED toggles state on every timer interrupt event
- UART2 ready for serial communication (TX/RX)
- User button configured with falling edge interrupt (not handled in this example)

## Hardware

- STM32 microcontroller (specific MCU depends on your board)
- Onboard LED connected to `LD2_Pin`
- User button connected to `B1_Pin`

## Clock Configuration

- MSI oscillator enabled at range 5 (~2.1 MHz)
- No PLL used
- APB1 and APB2 clocks derived directly from MSI

## Timer Configuration (TIM3)

- Prescaler: 208
- Period: 10000
- Timer frequency calculation:
  - Timer clock = MSI frequency / (Prescaler + 1) ≈ 2,097,000 / 209 ≈ 10,040 Hz
  - Timer period interrupt = (Period + 1) / Timer clock ≈ 1 second

## Code Overview

- **`main.c`** initializes peripherals and starts the TIM3 timer interrupt
- Interrupt callback toggles the LED on each timer interrupt
- Main loop is empty, as functionality is interrupt driven

## How to Build and Run

1. Open this project in STM32CubeIDE or your preferred IDE.
2. Build the project.
3. Flash the binary to your STM32 device.
4. Observe the onboard LED toggling approximately once per second.
5. Use UART2 for serial communication if needed (configuration ready).

## Example Timer Interrupt Callback (in `main.c`)

```c
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  if (htim->Instance == TIM3)
  {
    HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
  }
}

