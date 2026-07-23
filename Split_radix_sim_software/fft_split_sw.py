
import numpy as np
#import pdb; pdb.set_trace()

def first_stage(x, A, number_of_inputs):
    for i in range(number_of_inputs//4):
        A[i] = (x[i] - x[i + number_of_inputs//2]) - 1j * (x[i + number_of_inputs//4] - x[i + 3*number_of_inputs//4])
        A[i + number_of_inputs//4] = x[i] + x[i + number_of_inputs//2]
        A[i + number_of_inputs//2] = x[i + number_of_inputs//4] + x[i + 3*number_of_inputs//4]
        A[i + 3*number_of_inputs//4] = (x[i] - x[i + number_of_inputs//2]) + 1j * (x[i + number_of_inputs//4] - x[i + 3*number_of_inputs//4])

def even_stage(x, A, number_of_inputs, stage_num, twiddles):
    butterfly_size = number_of_inputs//(2**(stage_num-1))
    mun_of_changes = (2**(stage_num+1) + (-1)**stage_num)//3

    index_counter = 0
    twidle_change_counter = 0

    for y in range(mun_of_changes):
        if(y % 2 == 0):
            for i in range(butterfly_size//2):
                if(twidle_change_counter % 2 == 0):
                    twiddle_index = i * (2**(stage_num-2))
                    #breakpoint()
                else:
                    twiddle_index = 3 * i * (2**(stage_num-2))
                A[i + index_counter] = x[i + index_counter]*twiddles[twiddle_index]
                #print(f"i={i}, twiddle_index={twiddles[twiddle_index]}, stage_num={stage_num}")
            index_counter = index_counter + butterfly_size//2
            twidle_change_counter = twidle_change_counter + 1
        else:
            for i in range(butterfly_size//4):
                A[i + index_counter] = (x[i + index_counter] - x[i + index_counter + butterfly_size//2]) - 1j * (x[i + index_counter + butterfly_size//4] - x[i + index_counter + 3*butterfly_size//4])
                A[i + index_counter + butterfly_size//4] = x[i + index_counter] + x[i + index_counter + butterfly_size//2]
                A[i + index_counter + butterfly_size//2] = x[i + index_counter + butterfly_size//4] + x[i + index_counter + 3*butterfly_size//4]
                A[i + index_counter + 3*butterfly_size//4] = (x[i + index_counter] - x[i + index_counter + butterfly_size//2]) + 1j * (x[i + index_counter + butterfly_size//4] - x[i + index_counter + 3*butterfly_size//4])
            index_counter = index_counter + butterfly_size

def odd_stage(x, A, number_of_inputs, stage_num, twiddles):
    butterfly_size = number_of_inputs//(2**(stage_num-1))
    mun_of_changes = (2**(stage_num+1) + (-1)**stage_num)//3

    index_counter = 0
    twidle_change_counter = 0

    #print(f"Stage {stage_num}: butterfly_size = {butterfly_size}, mun_of_changes = {mun_of_changes}")

    for y in range(mun_of_changes):
        if(y % 2 == 0):
            for i in range(butterfly_size//4):
                A[i + index_counter] = (x[i + index_counter] - x[i + index_counter + butterfly_size//2]) - 1j * (x[i + index_counter + butterfly_size//4] - x[i + index_counter + 3*butterfly_size//4])
                A[i + index_counter + butterfly_size//4] = x[i + index_counter] + x[i + index_counter + butterfly_size//2]
                A[i + index_counter + butterfly_size//2] = x[i + index_counter + butterfly_size//4] + x[i + index_counter + 3*butterfly_size//4]
                A[i + index_counter + 3*butterfly_size//4] = (x[i + index_counter] - x[i + index_counter + butterfly_size//2]) + 1j * (x[i + index_counter + butterfly_size//4] - x[i + index_counter + 3*butterfly_size//4])
            index_counter = index_counter + butterfly_size
        else:
            for i in range(butterfly_size//2):
                if(twidle_change_counter % 2 == 0):
                    twiddle_index = i * (2**(stage_num-2))
                    #print(f"i={i}, twiddle_index={twiddle_index}, stage_num={stage_num}")
                else:
                    twiddle_index = 3 *i * (2**(stage_num-2))
                    #print(f"i={i}, twiddle_index={twiddle_index}, stage_num={stage_num}")

                A[i + index_counter] = x[i + index_counter]*twiddles[twiddle_index]
            index_counter = index_counter + butterfly_size//2
            twidle_change_counter = twidle_change_counter + 1


def last_stage(x, A, number_of_inputs, stage_num):
    i = 0
    change_counter = 0

    if(stage_num % 2 == 0):
        while(i < number_of_inputs):
            if(change_counter % 2 == 0):
                A[i] = x[i]
                i = i + 1
            else:
                A[i] = x[i] + x[i + 1]
                A[i + 1] = x[i] - x[i + 1]
                i = i + 2
            change_counter = change_counter + 1
    else:
        while(i < number_of_inputs):
            if(change_counter % 2 == 0):
                A[i] = x[i] + x[i + 1]
                A[i + 1] = x[i] - x[i + 1]
                i = i + 2
            else:
                A[i] = x[i]
                i = i + 1
            change_counter = change_counter + 1

def get_index_from_position(p, n):
    """
    Inverse Mapping: Provide vertical line position (p), 
    get the frequency index (k).
    """
    if n <= 2:
        return p
    
    if p < n // 4:
        return 4 * get_index_from_position(p, n // 4) + 1
    elif p >= 3 * n // 4:
        return 4 * get_index_from_position(p - 3 * n // 4, n // 4) + 3
    else:
        return 2 * get_index_from_position(p - n // 4, n // 2)
    
def test_butterfly():
    # Test the butterfly function with a simple input
    x = np.array([1+5j, 2+3j, 3+7j, 4+1j], dtype=complex)

    x_16bit_real = np.clip(np.round(x.real * 0x7F), -32768, 32767).astype(np.int16)
    x_16bit_imag = np.clip(np.round(x.imag * 0x7F), -32768, 32767).astype(np.int16)

    print("Input (16-bit fixed-point):")
    for r, i in zip(x_16bit_real, x_16bit_imag):
        print(f"Real: {r}, Imag: {i}")  

    A = np.zeros(4, dtype=complex)
    first_stage(x, A, 4)
    print("Butterfly Output:", A)

    out_16bit_real = np.clip(np.round(A.real * 0x7F), -32768, 32767).astype(np.int16)
    out_16bit_imag = np.clip(np.round(A.imag * 0x7F), -32768, 32767).astype(np.int16)

    print("Output (16-bit fixed-point):")
    for r, i in zip(out_16bit_real, out_16bit_imag):
        print(f"Real: {r}, Imag: {i}")

def main():
    N = 64
    x = np.random.rand(N) + 1j * np.random.rand(N)
    k = np.arange(N)
    twiddles = np.exp(-2j * np.pi * k / N)

    #Butterfly test
    #test_butterfly()
    # print("Input x:")

    # for i in range(N):
    #     print(f"x[{i}] = {x[i]:.4f}")

    # Initialize Stage Arrays
    A, A2, B, C, D, E , F, G = [np.zeros(N, dtype=complex) for _ in range(8)]

    # for i in range((N//4)//2):
    #     print(f"i={i}")
    #     start = N//4
    #     stride = (N//2)//4
    #     A[i + start] = (i*(16)+0) + 1j*(i*16+0)
    #     A[i+start+stride] = (i*16+1) + 1j*(i*16+1)
    #     A[i+start+2*stride] = (i*16+2) + 1j*(i*16+2)
    #     A[i+start+3*stride] = (i*16+3) + 1j*(i*16+3)
    
    # y=0
    # for i  in range((N//4)//2, (N//4)//2 + (N//4)//4):
    #     print(f"i={i}")
    #     A[4*y] = (i*(16)+0) + 1j*(i*16+0)
    #     A[4*y + 1] = (i*16+1) + 1j*(i*16+1)
    #     A[4*y + 2] = (i*16+2) + 1j*(i*16+2)
    #     A[4*y + 3] = (i*16+3) + 1j*(i*16+3)
    #     y+=1
    
    # y=0
    # for i in range((N//4)//2 + (N//4)//4, (N//4)):
    #     print(f"i={i}")
    #     start = N//4 + (N//2)
    #     A[4*y + start] = (i*(16)+0) + 1j*(i*16+0)
    #     A[4*y + 1 + start] = (i*16+1) + 1j*(i*16+1)
    #     A[4*y + 2 + start] = (i*16+2) + 1j*(i*16+2)
    #     A[4*y + 3 + start] = (i*16+3) + 1j*(i*16+3)
    #     y+=1

    ###################################################
    # for i in range(N//4):
    #     A[i] = (i*(16)+0) + 1j*(i*16+0)
    #     A[i+N//4] = (i*16+1) + 1j*(i*16+1)
    #     A[i+2*N//4] = (i*16+2) + 1j*(i*16+2)
    #     A[i+3*N//4] = (i*16+3) + 1j*(i*16+3)

    ###################################################
    for i in range(N//4):
        A[i*4] = (i*(16)+0) + 1j*(i*16+0)
        A[i*4 + 1] = (i*16+1) + 1j*(i*16+1)
        A[i*4 + 2] = (i*16+2) + 1j*(i*16+2)
        A[i*4 + 3] = (i*16+3) + 1j*(i*16+3)
    print("Input A:")

    for i in range(N):
        print(f"A[{i}] = {A[i]:.4f}")

    for i in range(N//4):
        A2[i*4] = (i*(32)+0) + 1j*(i*32+0)
        A2[i*4 + 1] = (i*32+1) + 1j*(i*32+1)
        A2[i*4 + 2] = (i*32+2) + 1j*(i*32+2)
        A2[i*4 + 3] = (i*32+3) + 1j*(i*32+3)
    print("Input A2:")

    for i in range(N):
        print(f"A2[{i}] = {A2[i]:.4f}")

    for i in range(2):
        if(i == 0):
            print("Processing A:")
        else:
            print("Processing A2:")
            A = A2.copy()

        first_stage(A, B, N)

        # print("After Stage 1 (B):")
        # for i in range(N):
        #     print(f"B[{i}] = {B[i]:.4f}")

        even_stage(B, C, N, 2, twiddles)

        # print("After Stage 2 (C):")
        # for i in range(N):
        #     print(f"C[{i}] = {C[i]:.4f}")

        odd_stage(C, D, N, 3, twiddles)

        # print("After Stage 3 (D):")
        # for i in range(N):
        #     print(f"D[{i}] = {D[i]:.4f}")

        even_stage(D, E, N, 4, twiddles)

        # print("After Stage 4 (E):")
        # for i in range(N):
        #     print(f"E[{i}] = {E[i]:.4f}")

        odd_stage(E, F, N, 5, twiddles)

        # print("After Stage 5 (F):")
        # for i in range(N):
        #     print(f"F[{i}] = {F[i]:.4f}")
        
        last_stage(F, G, N, 6)

        # print("After Stage 6 (G):")
        # for i in range(N):
        #     print(f"G[{i}] = {G[i]:.4f}")

        X_final = np.zeros(N, dtype=complex)
        for p in range(N):
            # Calculate which frequency k belongs at position p
            k = get_index_from_position(p, N)
            X_final[k] = G[p]

        print("Final Output X_final:")
        for i in range(N):
            print(f"X_final[{i}] = {X_final[i]:.4f}")

        # Verification
        normal_fft = np.fft.fft(A)

        for i in range(N):
            if(np.allclose(X_final[i], normal_fft[i]) == False):
                print(f"Mismatch at position {i}: X_final[{i}] = {X_final[i]:.4f}, Normal FFT X({i}) = {normal_fft[i]:.4f}")

if __name__ == "__main__":
    main()