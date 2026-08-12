import sys
import numpy as np
# import matplotlib.pyplot as plt
# from sklearn.metrics import r2_score

def psnr(original, compressed, max_val):
    mse = np.mean((original - compressed) ** 2)
    if mse == 0:
        return 100
    psnr_val = 20 * np.log10(max_val) - 10 * np.log10(mse)
    return psnr_val

# Load data
def load_file(filename):
    with open(filename, 'r') as f:
        lines = f.readlines()
    data = [list(map(int, line.strip().split())) for line in lines if line.strip()]
    return np.array(data)

try:
    N = int(sys.argv[1])
    BIT = int(sys.argv[2])
    Win = int(sys.argv[3])
except IndexError:
    print("Correct_format: Number_of_samples, Data_width, Number_of_windows")
    print("Using default parameters: N=256, BIT=16, Win=2")
    N = 256
    BIT = 16
    Win = 1

out = load_file("../Outputs.txt")
if(Win == 1):
    correct = load_file(f"../gen_data/f_correct_{N}_{BIT}bit.vh")
else:
    correct = load_file(f"../gen_data/large_dataset_fft_{Win}x{N}_{BIT}bit_Random1.vh")

out_real = out[:, 0]
out_imag = out[:, 1]
correct_real = correct[:, 0]
correct_imag = correct[:, 1]

# r2_real = r2_score(correct_real, out_real)
# r2_imag = r2_score(correct_imag, out_imag)

max_value = 2**(BIT - 1) - 1
psnr_real = psnr(correct_real, out_real, max_value)
psnr_imag = psnr(correct_imag, out_imag, max_value)

# print(f"R² Score (Real): {r2_real:.6f}")
# print(f"R² Score (Imag): {r2_imag:.6f}")
print(f"PSNR (Real): {psnr_real:.2f} dB")
print(f"PSNR (Imag): {psnr_imag:.2f} dB")

# plt.figure(figsize=(12, 6))

# #plt.subplot(1, 2, 1)
# plt.plot(correct_real, label="Correct Real", color='green', linewidth=2)
# plt.plot(out_real, label="Output Real", color='red', linestyle='--')
# plt.title(f"Real Part (R² = {r2_real:.4f}, PSNR = {psnr_real:.2f} dB)")
# plt.xlabel("Index")
# plt.ylabel("Amplitude")
# plt.grid(True)

# # Add vertical lines every N samples
# for i in range(N, len(correct_real), N):
#     plt.axvline(x=i, color='red', linestyle=':', linewidth=1, label='End of window' if i == N else "")

# plt.legend()

# plt.figure(figsize=(12, 6))

# #plt.subplot(1, 2, 2)
# plt.plot(correct_imag, label="Correct Imag", color='blue', linewidth=2)
# plt.plot(out_imag, label="Output Imag", color='orange', linestyle='--')
# plt.title(f"Imaginary Part (R² = {r2_imag:.4f}, PSNR = {psnr_imag:.2f} dB)")
# plt.xlabel("Index")
# plt.ylabel("Amplitude")
# plt.grid(True)

# # Add vertical lines every N samples
# for i in range(N, len(correct_imag), N):
#     plt.axvline(x=i, color='red', linestyle=':', linewidth=1, label='End of window' if i == N else "")

# plt.legend()

# plt.tight_layout()
# plt.show()
