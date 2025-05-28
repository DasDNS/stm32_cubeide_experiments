# Text Classification Neural Network (STM32F4 Deployment)

This project documents the conversion of a Keras-based text classification model into an optimized C representation using ST's **Edge AI Core v2.0.0-20049** for deployment on STM32F4 series microcontrollers.

---

## 📅 Creation Details

- **Date Created**: 2025-03-07 12:49:06
- **Tool Version**: ST Edge AI Core v2.0.0-20049
- **Input Model**: `text_classification_dense_input.h5`
- **Output Target**: STM32F4
- **Output Directory**: `C:\Users\Dasuni Saparamadu\.stm32cubemx\network_output`

---

## 🧠 Model Summary

| Attribute         | Value                            |
|------------------|----------------------------------|
| Model Format      | Keras (.h5)                      |
| Converted Format  | Float (uncompressed)             |
| Model Name        | `text_classification_dense_input`|
| Network C Name    | `network`                        |
| Parameters        | 1,185 (4.63 KiB)                 |
| MACC              | 1,259                            |
| Activations RAM   | 320 B                            |
| Flash Size        | 14,376 bytes                     |
| RAM Usage         | 2,132 bytes                      |

---

## 🧩 Model Architecture

| Layer Name        | Type             | Output Shape | MACC | Parameters |
|------------------|------------------|--------------|------|------------|
| input_1          | Input             | (1, 1)       | 0    | 0          |
| dense            | Dense             | (1, 16)      | 32   | 128        |
| flatten          | Reshape (Flatten) | (1, 16)      | 0    | 0          |
| dense_1_dense    | Dense             | (1, 64)      | 1088 | 4352       |
| dense_1          | Activation (ReLU) | (1, 64)      | 64   | 0          |
| dense_2_dense    | Dense             | (1, 1)       | 65   | 260        |
| dense_2          | Activation (Sigmoid) | (1, 1)    | 10   | 0          |

---

## ⚙️ Resource Utilization

### Memory Footprint

| Section        | Flash (RO) | RAM (RW) |
|----------------|------------|----------|
| Runtime Total  | 9,632 B    | 1,812 B  |
| Weights        | 4,744 B    | 0        |
| Activations    | 0          | 320 B    |
| **Total**      | 14,376 B   | 2,132 B  |

---

## 🔢 Operation Statistics

| Operation Type | Count | Percentage |
|----------------|-------|------------|
| Multiply Float (smul_f32_f32) | 1,185 | 94.1% |
| Element-wise Ops (op_f32_f32) | 74    | 5.9%  |

---

## 🧾 Generated Files

The following files were generated in the output directory:

- `network_data_params.h`
- `network_data_params.c`
- `network_data.h`
- `network_data.c`
- `network.h`
- `network.c`
- Additional runtime libraries for STM32

---

## 📌 Notes

- Inputs: `'input_1_output'` (float32, shape: 1x1)
- Outputs: `'dense_2_output'` (float32, shape: 1x1)
- Model suitable for text classification tasks where input is a single scalar or dense embedding.
- No compression or quantization applied.

---

## 📂 Workspace & Tooling Paths

- Workspace: `C:\Users\DASUNI~1\AppData\Local\Temp\mxAI_workspace...`
- CLI Tool: `generate --target stm32f4 --name network ...`

---

## ✅ Usage

Include the generated C files into your STM32CubeIDE project or other STM32-based firmware to run inference on-device.

---

