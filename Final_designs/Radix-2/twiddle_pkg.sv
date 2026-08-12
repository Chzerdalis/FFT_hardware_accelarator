package twiddle_pkg;
    parameter int STAGE_NUM = 8;

    parameter string REAL_FILES [0:7] = '{
        "../Data/f_twiddle_real_1.mem",
        "../Data/f_twiddle_real_2.mem",
        "../Data/f_twiddle_real_3.mem",
        "../Data/f_twiddle_real_4.mem",
        "../Data/f_twiddle_real_5.mem",
        "../Data/f_twiddle_real_6.mem",
        "../Data/f_twiddle_real_7.mem",
        "../Data/f_twiddle_real_8.mem"
    };

    parameter string IMAG_FILES [0:7] = '{
        "../Data/f_twiddle_imag_1.mem",
        "../Data/f_twiddle_imag_2.mem",
        "../Data/f_twiddle_imag_3.mem",
        "../Data/f_twiddle_imag_4.mem",
        "../Data/f_twiddle_imag_5.mem",
        "../Data/f_twiddle_imag_6.mem",
        "../Data/f_twiddle_imag_7.mem",
        "../Data/f_twiddle_imag_8.mem"
    };
endpackage
