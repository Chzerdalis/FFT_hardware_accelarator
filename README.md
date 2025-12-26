# 🚀 Radix-4 FFT Hardware Implementation

This project focuses on a high-performance hardware implementation of the **Radix-4 Fast Fourier Transform (FFT)** algorithm. The design is optimized for FPGA/ASIC deployment, balancing throughput, latency, and resource utilization.

---

## 🎯 Project Objectives

* **Throughput Optimization**: Maximize data processing rates to handle high-bandwidth signal streams.
* **Hardware Efficiency**: Optimize resource utilization (LUTs, FFs, and DSPs) to ensure a compact footprint.
* **Pipelining & Timing**: Strategic use of pipelining to reduce critical paths and achieve higher maximum clock frequencies ($F_{max}$).
* **Numerical Accuracy**: Extensive testing across various **data widths** (Fixed-point) to analyze the trade-off between precision and resource cost.
* **Arithmetic Exploration**: Comparative analysis of different **multiplier architectures** to evaluate impact on power and area.
* **Low Latency**: Minimizing processing delay to meet the strict requirements of real-time Digital Signal Processing (DSP) applications.

---

## 📂 Project Structure

* [**fft_radix_2**](./fft_radix_2) - Verilog source files for the Radix-2 unrolled core and butterfly units.
* * [**fft_radix_4**](./fft_radix_4) - Verilog source files for the Radix-4 unrolled core and butterfly units.
* [**radix_2_SDF**](./radix_2_SDF) - Verilog source files for the Radix-2 SDF implementation.
* [**radix_4_SDF**](./radix_4_SDF) - Verilog source files for initial unoptimized Radix-4 SDF implementation.
* [**radix_4_SDF_Fast**](./radix_4_SDF_Fast) - Verilog source files for optimized Radix-4 SDF implementation.

## 🛠 Tech Stack
* **HDL:**  Verilog
* **Tools:** Xilinx Vivado
* **Verification:** Python (NumPy/SciPy for Golden Model comparison)