#include "main.h"
#include "arm_math.h"
#include "string.h"

#define UART_BUFFER_SIZE 2048
#define FFT_SIZE 1024

UART_HandleTypeDef huart2;
uint8_t uart_buffer[UART_BUFFER_SIZE];
float32_t input_data[FFT_SIZE];
float32_t fft_output[FFT_SIZE];
float32_t fft_magnitude[FFT_SIZE / 2];
float32_t window[FFT_SIZE]; // Hanning window
arm_rfft_fast_instance_f32 fft_instance;

// Function prototypes
void SystemClock_Config(void);
void Error_Handler(void);
static void MX_USART2_UART_Init(void);
void apply_window(float32_t *data, float32_t *window, uint32_t size);
void process_wav_fft(void);

int main(void) {
    HAL_Init();
    SystemClock_Config();
    MX_USART2_UART_Init();

    // Initialize the FFT instance
    arm_rfft_fast_init_f32(&fft_instance, FFT_SIZE);

    // Generate Hanning window manually
     for (int i = 0; i < FFT_SIZE; i++) {
    	 window[i] = 0.5f * (1.0f - arm_cos_f32((2.0f * PI * i) / (FFT_SIZE - 1)));
     }

    // Generate Hanning window
    //arm_hann_window_f32(window, FFT_SIZE);

    while (1) {
        // Receive the .wav file data via UART
        if (HAL_UART_Receive(&huart2, uart_buffer, UART_BUFFER_SIZE, HAL_MAX_DELAY) == HAL_OK) {
            // Convert received data to float32_t format (assumes 16-bit PCM data in .wav file)
            for (int i = 0; i < FFT_SIZE; i++) {
                input_data[i] = (float32_t)((int16_t)(uart_buffer[2 * i] | (uart_buffer[2 * i + 1] << 8)));
            }

            // Apply the Hanning window to the input data
            for (int i = 0; i < FFT_SIZE; i++) {
            	input_data[i] *= window[i];
            }

            // Apply Hanning window to the input data
            //apply_window(input_data, window, FFT_SIZE);

            // Perform FFT
            arm_rfft_fast_f32(&fft_instance, input_data, fft_output, 0);

            // Compute the magnitude of the FFT output
            arm_cmplx_mag_f32(fft_output, fft_magnitude, FFT_SIZE / 2);

            // Send FFT output via UART
            HAL_UART_Transmit(&huart2, (uint8_t *)fft_magnitude, sizeof(fft_magnitude), HAL_MAX_DELAY);
        }
    }
}

void apply_window(float32_t *data, float32_t *window, uint32_t size) {
    for (uint32_t i = 0; i < size; i++) {
        data[i] *= window[i];
    }
}

static void MX_USART2_UART_Init(void) {
    huart2.Instance = USART2;
    huart2.Init.BaudRate = 115200;
    huart2.Init.WordLength = UART_WORDLENGTH_8B;
    huart2.Init.StopBits = UART_STOPBITS_1;
    huart2.Init.Parity = UART_PARITY_NONE;
    huart2.Init.Mode = UART_MODE_TX_RX;
    huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    huart2.Init.OverSampling = UART_OVERSAMPLING_16;
    huart2.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
    if (HAL_UART_Init(&huart2) != HAL_OK) {
        Error_Handler();
    }
}

void SystemClock_Config(void) {
    // System Clock Configuration
}

void Error_Handler(void) {
    while (1) {
        // Stay in error handler
    }
}
