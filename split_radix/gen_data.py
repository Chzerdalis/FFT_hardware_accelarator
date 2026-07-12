import numpy as np
import sys

def sign(n):
    return '-' if n < 0 else ''

def bitrev(num, n):
    res = 0
    for i in range(n):
        bit = (num >> i*2) & 0x3
        res |= bit << 2*(n - 1 - i)
        #print(f'i={i}, bit={bit:04X}, res={res:04X}', num) 
    return res

try:
    Num_of_windows = int(sys.argv[1])
    Size_of_windows = int(sys.argv[2])
    Data_width = int(sys.argv[3])
    Random = int(sys.argv[4])
except IndexError:
    print("Correct_format: Number_of_windows, Size_of_windows, Data_width, Random(0/1)(No/Yes)")
    print("Using default parameters: Num_of_windows=100, Size_of_windows=256, Data_width=16, Random=yes")
    Num_of_windows = 100
    Size_of_windows = 256
    Data_width = 16
    Random = 1

np.random.seed(87)
N = Size_of_windows

if Random == 1:
    freqs = np.sort(np.random.randint(1, N/2, size=30))
    ampls = (np.abs(freqs / (N/4) - 1) - 1)**4 

    t = np.linspace(0, 1, N)
    x_all = []

    for _ in range(Num_of_windows):
        x_real = np.zeros(len(t))
        x_imag = np.zeros(len(t))

        freqs = np.sort(np.random.randint(1, N/2, size=30))
        ampls = (np.abs(freqs / (N/4) - 1) - 1)**4

        for freq, ampl in zip(freqs, ampls):
            x_real += ampl * np.sin(2 * np.pi * freq * t)
            x_imag += ampl * np.cos(2 * np.pi * freq * t)
        x_real = 2 * (x_real - x_real.min()) / (x_real.max() - x_real.min()) - 1
        x_imag = 2 * (x_imag - x_imag.min()) / (x_imag.max() - x_imag.min()) - 1
        x_all.append(x_real + 1j * x_imag)
else:
    x_all = []
    for i in range(Num_of_windows):
        t = np.linspace(0, 1, N)
        x_real = 0.5 * np.sin(2 * np.pi * (5 + (i+1)/2) * t) + 0.3 * np.sin(2 * np.pi * (20 + (i+1)/7) * t) + 0.2 * np.sin(2 * np.pi * (50 + (i+1)/3) * t) + 0.1 * np.sin(2 * np.pi * (100 + (i+1)/2) * t)
        x_imag = 0.5 * np.cos(2 * np.pi * (5 + (i+1)/2) * t) + 0.3 * np.cos(2 * np.pi * (20 + (i+1)/7) * t) + 0.2 * np.cos(2 * np.pi * (50 + (i+1)/3) * t) + 0.1 * np.cos(2 * np.pi * (100 + (i+1)/2) * t) 
        x_all.append(x_real + 1j * x_imag)

x_all = np.array(x_all)

if Data_width == 32:
    x_quantized = (x_all.real * 0x7FFF).astype(int) + 1j * (x_all.imag * 0x7FFF).astype(int)
elif Data_width == 24:
    x_quantized = (x_all.real * 0x7FF).astype(int) + 1j * (x_all.imag * 0x7FF).astype(int)
elif Data_width == 18:
    x_quantized = (x_all.real * 0xFF).astype(int) + 1j * (x_all.imag * 0xFF).astype(int)
elif Data_width == 16:
    x_quantized = (x_all.real * 0x7F).astype(int) + 1j * (x_all.imag * 0x7F).astype(int)
else:
    raise ValueError("Unsupported Data Width")

x_fft_all = []
for x in x_quantized:
    x_fft = np.fft.fft(x, len(x))
    x_fft.real = x_fft.real.astype(int)
    x_fft.imag = x_fft.imag.astype(int)
    x_fft_all.append(x_fft)

x_fft_all = np.array(x_fft_all)

with open(f'input_data.txt', 'w') as f:
    for j, window in enumerate(x_quantized):
        for i, value in enumerate(window):
            xir = int(value.real)
            xii = int(value.imag)
            f.write(f'{sign(xir)}{abs(xir)} {sign(xii)}{abs(xii)}\n')


with open(f'correct_output.txt', 'w') as f:
    for window in x_fft_all:
        for i, value in enumerate(window):
            xir = int(value.real)
            xii = int(value.imag)
            f.write(f'{sign(xir)}{abs(xir)} {sign(xii)}{abs(xii)}\n')