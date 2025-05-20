# STM32 Timer Interrupt Example

This project demonstrates how to use a **hardware timer (TIM2)** on an STM32 microcontroller with **interrupt-driven** operation to periodically send data over UART.

---

## Focus: Timers

### Timer Used: TIM2

- **TIM2** is configured as a basic timer with:
  - Prescaler = 1000
  - Period = 83999
- This configuration determines the timer's counting frequency and the interrupt rate.
- The timer runs in **up-counting mode** and generates an update event (overflow) when the counter reaches the period value.
- The timer interrupt is enabled, so when the update event occurs, the **`HAL_TIM_PeriodElapsedCallback()`** callback function is executed.

### Timer Frequency Calculation

- Assuming the APB1 timer clock is 84 MHz (typical for STM32 running at 84 MHz system clock):
  
Timer tick frequency = 84 MHz / (Prescaler + 1) = 84,000,000 / 1001 ≈ 83,916 Hz
Timer period = 83999 counts
Timer update event frequency = Timer tick frequency / (Period + 1)
≈ 83,916 / 84,000 ≈ 1 Hz

- So, the timer triggers an interrupt approximately every **1 second**.

### Interrupt Handling

- The interrupt callback function `HAL_TIM_PeriodElapsedCallback()` sends the string `"Interrupt Triggered\r\n"` over UART2.
- This demonstrates periodic, interrupt-driven behavior with the timer.

---

## UART Interaction

- UART2 is initialized at 115200 baud.
- On startup, the message `"HAL_TIM_Base_Start_IT"` is transmitted once.
- Every 1 second, the timer interrupt triggers sending of `"Interrupt Triggered\r\n"` via UART.

---

## How the Code Works

1. **Initialization**
 - HAL library is initialized.
 - System clock is configured.
 - GPIO, DMA, UART2, and TIM2 peripherals are initialized.
 - TIM2 timer base is started in interrupt mode (`HAL_TIM_Base_Start_IT`).

2. **Main Loop**
 - The `while(1)` loop continuously runs, here it just prints `"While loop"` (though note this does not send data over UART).
 - Timer interrupts operate independently, triggered every 1 second.

3. **Timer Interrupt**
 - Each time TIM2 period elapses (~1 second), the `HAL_TIM_PeriodElapsedCallback()` function executes.
 - The callback sends `"Interrupt Triggered\r\n"` over UART.

---

## Key Points

- **Timer interrupts** allow execution of code periodically without blocking the main loop.
- The timer frequency and period control how often the interrupt occurs.
- The combination of timer + UART interrupt-driven communication is common in embedded applications requiring periodic status updates or sensor readings.
- This example can be extended by adding other tasks inside the interrupt or main loop.

---

## Building and Running

- Use STM32CubeMX or STM32CubeIDE to generate project and set up peripherals.
- Flash the firmware to the STM32 device.
- Connect UART2 pins (e.g., PA2 as TX) to a serial monitor at 115200 baud.
- Observe `"HAL_TIM_Base_Start_IT"` on startup, then `"Interrupt Triggered"` printed every second.

---

## References

- STM32 HAL Timer documentation: https://www.st.com/en/embedded-software/stm32cubeh7.html
- STM32 Timer tutorial: https://controllerstech.com/stm32-timers-basics/
- UART communication with STM32: https://www.st.com/en/embedded-software/stm32cubeexpansion.html

---

Feel free to extend this example by changing the timer period or adding more complex processing in the timer callback!

