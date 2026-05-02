# Plotting Script for FFT Validation

This folder contains a python script `plot_x_fft.py` to visualize FFT data from the simulation outputs or generated test data.

## Prerequisites

You need Python 3 installed with `numpy` and `matplotlib`.

```bash
pip install numpy matplotlib
```

## Usage

Run the script providing the input file containing complex numbers (Real Imag).

```bash
python3 plot_x_fft.py <input_file> [output_image_filename]
```

## Examples

To plot the simulation output `Outputs.txt` located in the parent directory:

```bash
python3 plot_x_fft.py ../Outputs.txt plot_outputs.png
```

To plot a generated correct FFT dataset (e.g., `f_correct_1024_16bit.vh` - note: format might differ, script expects pure numbers):
If the `.vh` files contain Verilog syntax, you might need to use the `Outputs.txt` format (pure numbers) or `large_dataset_fft_...`.

Example with `large_dataset_fft_...`:
```bash
python3 plot_x_fft.py large_dataset_fft_20x256_16bit_Random0.vh plot_ref.png
```
