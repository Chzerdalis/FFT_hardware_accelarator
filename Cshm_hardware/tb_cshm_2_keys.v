`timescale 1ns / 1ps

// =========================================================================
// Self-checking testbench for cshm_2_keys.
//
// Reads cshm_vectors.txt, produced by the Python CSHMEncoder. Each line is
//
//     <key_hex> <twiddle_decimal>
//
// i.e. the ROM word and the constant it is supposed to represent. For every
// key the DUT is driven with a set of multiplicands `a`, and the result is
// checked against  twiddle * a  computed independently by the testbench.
//
// Both slots are exercised at once: key0 gets vector i and key1 gets a
// different vector, so a bug that swaps, shares or crosses slot state shows
// up rather than cancelling out.
//
// The DUT has 5 register stages:
//   1 a_q1/key_q1   2 alphabet_*/key_q2   3 slot_q3/key_q3
//   4 shift_out_q4/sign_q4                5 out0/out1
// so expected values run down a matching 5-deep delay line here instead of
// the testbench assuming a settling time.
// =========================================================================

module tb_cshm_2_keys;

    // ---- must match the DUT --------------------------------------------
    localparam WIDTH    = 16;
    localparam Tw_WIDTH = 9;   // twiddles are 9-bit -> PROD = 25
    localparam PROD     = WIDTH + Tw_WIDTH;
    localparam LAT      = 5;

    localparam MAX_VEC  = 512;
    localparam CLK_P    = 10;

    reg clock = 1'b0;
    always #(CLK_P/2) clock = ~clock;

    reg signed [WIDTH-1:0] a;
    reg [13:0] key0, key1;
    wire signed [PROD-1:0] out0, out1;

    cshm_2_keys #(.WIDTH(WIDTH), .Tw_WIDTH(Tw_WIDTH)) dut (
        .clock (clock),
        .a     (a),
        .key0  (key0),
        .key1  (key1),
        .out0  (out0),
        .out1  (out1)
    );

    // ---- vector storage --------------------------------------------------
    reg [13:0] vec_key [0:MAX_VEC-1];
    integer    vec_tw  [0:MAX_VEC-1];
    integer    n_vec;

    // ---- expectation delay line -----------------------------------------
    // 32-bit signed integers, so the TB can see a product that overflows
    // the DUT's PROD-bit output and report it as such instead of as a bug.
    integer exp0 [0:LAT];
    integer exp1 [0:LAT];
    reg     vld  [0:LAT];

    integer i;
    always @(posedge clock) begin
        for (i = LAT; i > 0; i = i - 1) begin
            exp0[i] <= exp0[i-1];
            exp1[i] <= exp1[i-1];
            vld[i]  <= vld[i-1];
        end
    end

    // ---- scoreboard -------------------------------------------------------
    integer checks   = 0;
    integer errors   = 0;
    integer overflow = 0;

    function fits_prod;
        input integer v;
        begin
            fits_prod = (v <= ((1 << (PROD-1)) - 1)) && (v >= -(1 << (PROD-1)));
        end
    endfunction

    task check_one;
        input integer           e;
        input signed [PROD-1:0] got;
        input integer           slot;
        reg   signed [PROD-1:0] e_trunc;
        begin
            e_trunc = e;                       // assignment truncates to PROD
            if (!fits_prod(e)) begin
                overflow = overflow + 1;
                if (overflow <= 5)
                    $display("  NOTE  out%0d: expected %0d is outside signed PROD=%0d range (a=%0d) - not counted as an error",
                             slot, e, PROD, a);
            end else begin
                checks = checks + 1;
                if (got !== e_trunc) begin
                    errors = errors + 1;
                    if (errors <= 20)
                        $display("  FAIL  out%0d: expected %0d, got %0d   (t=%0t)",
                                 slot, e, got, $time);
                end
            end
        end
    endtask

    always @(negedge clock) begin
        if (vld[LAT] === 1'b1) begin
            check_one(exp0[LAT], out0, 0);
            check_one(exp1[LAT], out1, 1);
        end
    end

    // ---- stimulus ----------------------------------------------------------
    localparam N_DIRECTED = 12;
    integer a_dir [0:N_DIRECTED-1];

    integer vi, ai, k1, a_val;
    integer seed;

    task drive;
        input [13:0]  k0_in;
        input [13:0]  k1_in;
        input integer a_in;
        input integer tw0;
        input integer tw1;
        begin
            @(negedge clock);
            a       = a_in;                    // truncates to WIDTH
            key0    = k0_in;
            key1    = k1_in;
            exp0[0] = tw0 * a_in;
            exp1[0] = tw1 * a_in;
            vld[0]  = 1'b1;
        end
    endtask

    initial begin
        a_dir[0]  = 0;
        a_dir[1]  = 1;
        a_dir[2]  = -1;
        a_dir[3]  = 2;
        a_dir[4]  = -2;
        a_dir[5]  = 255;
        a_dir[6]  = -256;
        a_dir[7]  = 32767;      // most positive
        a_dir[8]  = -32768;     // most negative
        a_dir[9]  = 21845;
        a_dir[10] = -21845;
        a_dir[11] = 12345;

        for (i = 0; i <= LAT; i = i + 1) begin
            exp0[i] = 0; exp1[i] = 0; vld[i] = 1'b0;
        end
        a = 0; key0 = 14'h0000; key1 = 14'h0000;
        seed = 12345;

        load_vectors;

        $display("=========================================================");
        $display("tb_cshm_2_keys   WIDTH=%0d  Tw_WIDTH=%0d  PROD=%0d  LAT=%0d",
                 WIDTH, Tw_WIDTH, PROD, LAT);
        $display("loaded %0d vectors", n_vec);
        $display("=========================================================");

        // Pass 1: every key x every directed multiplicand
        for (vi = 0; vi < n_vec; vi = vi + 1) begin
            k1 = (vi + n_vec/2) % n_vec;
            for (ai = 0; ai < N_DIRECTED; ai = ai + 1)
                drive(vec_key[vi], vec_key[k1], a_dir[ai], vec_tw[vi], vec_tw[k1]);
        end

        // Pass 2: random multiplicands over the full signed range
        for (vi = 0; vi < n_vec; vi = vi + 1) begin
            k1 = (n_vec - 1) - vi;
            for (ai = 0; ai < 8; ai = ai + 1) begin
                a_val = ($random(seed) & 16'hFFFF) - 32768;
                drive(vec_key[vi], vec_key[k1], a_val, vec_tw[vi], vec_tw[k1]);
            end
        end

        // drain the pipeline
        @(negedge clock);
        vld[0] = 1'b0;
        repeat (LAT + 3) @(negedge clock);

        $display("=========================================================");
        $display("checks performed : %0d", checks);
        $display("errors           : %0d", errors);
        if (overflow > 0)
            $display("uncounted        : %0d (true product exceeds signed PROD=%0d - widen Tw_WIDTH)",
                     overflow, PROD);
        if (errors == 0) $display("RESULT: PASS");
        else             $display("RESULT: FAIL");
        $display("=========================================================");
        $finish;
    end

    // ---- vector file loader ------------------------------------------------
    integer fd, code, tw_tmp;
    reg [13:0] key_tmp;

    task load_vectors;
        begin
            n_vec = 0;
            fd = $fopen("cshm_vectors.txt", "r");
            if (fd == 0) begin
                $display("ERROR: cannot open cshm_vectors.txt");
                $finish;
            end
            while (!$feof(fd) && n_vec < MAX_VEC) begin
                code = $fscanf(fd, "%h %d", key_tmp, tw_tmp);
                if (code == 2) begin
                    vec_key[n_vec] = key_tmp;
                    vec_tw [n_vec] = tw_tmp;
                    n_vec = n_vec + 1;
                end
            end
            $fclose(fd);
            if (n_vec == 0) begin
                $display("ERROR: no vectors parsed from cshm_vectors.txt");
                $finish;
            end
        end
    endtask

    // ---- safety net ---------------------------------------------------------
    initial begin
        #(CLK_P * 500000);
        $display("ERROR: testbench timeout");
        $finish;
    end

endmodule
