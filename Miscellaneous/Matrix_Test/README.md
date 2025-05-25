# STM32 Matrix Multiplication Benchmark

This project demonstrates matrix multiplication on an STM32 microcontroller using the HAL library, along with timing measurement and UART communication to output the elapsed time. It serves as a basic benchmark to evaluate the performance of the microcontroller in executing floating-point matrix operations.

## Features

- Initializes a 22x22 matrix (`MATRIX_SIZE = 22`)
- Populates two matrices with deterministic values
- Performs matrix multiplication
- Measures execution time using `HAL_GetTick()`
- Sends the elapsed time over UART (USART2)
- Peripheral initialization for:
  - UART (with DMA)
  - Timers (TIM2, TIM3, TIM4)
  - GPIO
  - System clock

## Hardware Requirements

- STM32F4 series microcontroller (tested on STM32F407VG)
- USB to UART converter (for viewing UART output if not using ST-Link VCP)
- STM32CubeIDE or compatible build environment

## Software Requirements

- STM32CubeMX (for peripheral configuration)
- STM32 HAL Library
- STM32CubeIDE or Makefile-based build system

## Matrix Initialization

Matrix `A` and `B` are initialized with the following values:
- `A[i][j] = (i + 1) * 0.1`
- `B[i][j] = (j + 1) * 0.2`

The result is stored in matrix `C`.

## UART Output

After the multiplication, the code computes elapsed time and transmits it over UART2 using:

```c
sprintf(buffer, "Elapsed Time: %lu ms\r\n", elapsed_time);
HAL_UART_Transmit(&huart2, (uint8_t*)buffer, strlen(buffer), HAL_MAX_DELAY);
