import numpy as np
import matplotlib.pyplot as plt
import sys

np.random.seed(43)

try:
    N = int(sys.argv[1])
except IndexError:
    N = 16

freqs = np.sort(np.random.randint(1, N/2, size=30))
ampls = (np.abs(freqs / (N/4) - 1) - 1)**4

t = np.linspace(0, 1, N)
x = np.zeros(len(t))

for freq, ampl in zip(freqs, ampls):
    x += ampl * np.sin(2 * np.pi * freq * t)

x = 2 * (x - x.min()) / (x.max() - x.min()) - 1

x_32bit = (x * 0x7FFF).astype(int)
x_24bit = (x * 0x7FF).astype(int)
x_16bit = (x * 0x7F).astype(int)

x_fft_32bit = np.fft.fft(x_32bit, len(x_32bit))
x_fft_32bit.real = x_fft_32bit.real.astype(int)
x_fft_32bit.imag = x_fft_32bit.imag.astype(int)

x_fft_24bit = np.fft.fft(x_24bit, len(x_24bit))
x_fft_24bit.real = x_fft_24bit.real.astype(int)
x_fft_24bit.imag = x_fft_24bit.imag.astype(int)

x_fft_16bit = np.fft.fft(x_16bit, len(x_16bit))
x_fft_16bit.real = x_fft_16bit.real.astype(int)
x_fft_16bit.imag = x_fft_16bit.imag.astype(int)

# plt.plot(t, x)
# plt.plot(t, x_fft.real)
# plt.plot(t, x_fft.imag)
# plt.show()

k = np.arange(N)
twiddles = np.exp(-2j * np.pi * k / N)

twiddle_real_q_16 = np.clip(twiddles.real * (1 << 15), -0x8000, 0x7FFF).astype(int) & 0xFFFF
twiddle_imag_q_16 = np.clip(twiddles.imag * (1 << 15), -0x8000, 0x7FFF).astype(int) & 0xFFFF

twiddle_real_q_12 = np.clip(twiddles.real * (1 << 11), -0x800, 0x7FF).astype(int) & 0xFFF
twiddle_imag_q_12 = np.clip(twiddles.imag * (1 << 11), -0x800, 0x7FF).astype(int) & 0xFFF

twiddle_real_q_8 = np.clip(twiddles.real * (1 << 7), -0x80, 0x7F).astype(int) & 0xFF
twiddle_imag_q_8 = np.clip(twiddles.imag * (1 << 7), -0x80, 0x7F).astype(int) & 0xFF

######### SW #########

# with open('f_input.txt', 'w') as f:
#     for xi in x:
#         f.write(f'{xi}\n')

# with open('f_correct.txt', 'w') as f:
#     for xi in x_fft:
#         f.write(f'{int(xi.real)} {int(xi.imag)}\n')

# with open(f'f_twiddle.txt', 'w') as f:
#     for twr, twi in zip(twiddle_real_q, twiddle_imag_q):
#         f.write(f'{twr} {twi}\n')

######### HW #########

def sign(n):
    return '-' if n < 0 else ''

def bitrev(num, n):
    res = 0
    for i in range(n):
        bit = (num >> i*2) & 0x3
        res |= bit << 2*(n - 1 - i)
        #print(f'i={i}, bit={bit:04X}, res={res:04X}', num) 
    return res
###############################
# with open(f'f_input_{N}_32bit.vh', 'w') as f:
#     for i, xi in enumerate(x_32bit):
#         xir = int(xi)
#         f.write(f'gen_input_real[{i}] = {sign(xir):}32\'sd{abs(xir)};\n')

# with open(f'f_input_{N}_24bit.vh', 'w') as f:
#     for i, xi in enumerate(x_24bit):
#         xir = int(xi)
#         f.write(f'gen_input_real[{i}] = {sign(xir):}24\'sd{abs(xir)};\n')

# with open(f'f_input_{N}_16bit.vh', 'w') as f:
#     for i, xi in enumerate(x_16bit):
#         xir = int(xi)
#         f.write(f'gen_input_real[{i}] = {sign(xir):}16\'sd{abs(xir)};\n')
################################
with open(f'f_input_rev_{N}_32bit.vh', 'w') as f:
    for i, xi in enumerate(x_32bit):
        xir = int(xi)
        f.write(f'gen_input_real[{bitrev(i, int(np.log2(N)/2))}] = {sign(xir):}32\'sd{abs(xir)};\n')

with open(f'f_input_rev_{N}_24bit.vh', 'w') as f:
    for i, xi in enumerate(x_24bit):
        xir = int(xi)
        f.write(f'gen_input_real[{bitrev(i, int(np.log2(N)/2))}] = {sign(xir):}24\'sd{abs(xir)};\n')

with open(f'f_input_rev_{N}_16bit.vh', 'w') as f:
    for i, xi in enumerate(x_16bit):
        xir = int(xi)
        f.write(f'gen_input_real[{bitrev(i, int(np.log2(N)/2))}] = {sign(xir):}16\'sd{abs(xir)};\n')
################################
with open(f'f_correct_{N}_32bit.vh', 'w') as f:
    for i, xi in enumerate(x_fft_32bit):
        xir, xii = int(xi.real), int(xi.imag)
        f.write(f'{sign(xir)}{abs(xir)} {sign(xii)}{abs(xii)}\n')

with open(f'f_correct_{N}_24bit.vh', 'w') as f:
    for i, xi in enumerate(x_fft_24bit):
        xir, xii = int(xi.real), int(xi.imag)
        f.write(f'{sign(xir)}{abs(xir)} {sign(xii)}{abs(xii)}\n')

with open(f'f_correct_{N}_16bit.vh', 'w') as f:
    for i, xi in enumerate(x_fft_16bit):
        xir, xii = int(xi.real), int(xi.imag)
        f.write(f'{sign(xir)}{abs(xir)} {sign(xii)}{abs(xii)}\n')

###############################
with open(f'f_twiddle_{N}_16bit.vh', 'w') as f:
    for i, (twr, twi) in enumerate(zip(twiddle_real_q_16, twiddle_imag_q_16)):
        f.write(f'w_real[{i}] = 16\'h{twr:04X}; w_imag[{i}] = 16\'h{twi:04X};\n')

with open(f'f_twiddle_{N}_12bit.vh', 'w') as f:
    for i, (twr, twi) in enumerate(zip(twiddle_real_q_12, twiddle_imag_q_12)):
        f.write(f'w_real[{i}] = 12\'h{twr:03X}; w_imag[{i}] = 12\'h{twi:03X};\n')

with open(f'f_twiddle_{N}_8bit.vh', 'w') as f:
    for i, (twr, twi) in enumerate(zip(twiddle_real_q_8, twiddle_imag_q_8)):
        f.write(f'w_real[{i}] = 8\'h{twr:02X}; w_imag[{i}] = 8\'h{twi:02X};\n')
###############################