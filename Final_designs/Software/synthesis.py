# import numpy as np
# import math
# import subprocess
# import sys
# import os
# import shutil
# import re
# from datetime import datetime
 
# def clean_data_folder(folder_path="../Data"):
#     """
#     Deletes all files and subdirectories inside the specified folder.
#     """
#     # Convert to an absolute path to prevent accidental deletions in the wrong directory
#     abs_path = os.path.abspath(folder_path)
    
#     # Check if the folder actually exists before trying to clean it
#     if not os.path.exists(abs_path):
#         print(f"Folder not found: {abs_path}. Nothing to clean.")
#         # Optionally create it if you want it to always exist:
#         # os.makedirs(abs_path)
#         return
 
#     print(f"Cleaning folder: {abs_path}...")
    
#     # Loop through everything inside the folder
#     for item_name in os.listdir(abs_path):
#         item_path = os.path.join(abs_path, item_name)
        
#         try:
#             if os.path.isfile(item_path) or os.path.islink(item_path):
#                 os.unlink(item_path)  # Delete the file or link
#             elif os.path.isdir(item_path):
#                 shutil.rmtree(item_path)  # Delete the subdirectory and its contents
#         except Exception as e:
#             print(f"Failed to delete {item_path}. Reason: {e}")
            
#     print("Folder cleaned successfully!")
 
    
# def generate_twiddles(N, twiddle_width, type_fft=0, bit_growth=0):
#     stages = int(math.log2(N))
#     max_stage_num = twiddle_width + 1
#     Current_bits_stages = min(stages, max_stage_num)
#     bit_growth_stages = max(0, stages - max_stage_num)
 
#     k = np.arange(N)
#     twiddles = np.exp(-2j * np.pi * k / N)
 
#     real_file = lambda stage: f"../Data/f_twiddle_real_{stage}.mem"
#     imag_file = lambda stage: f"../Data/f_twiddle_imag_{stage}.mem"
 
#     # =========================================================================
#     # Fallback for No Bit Growth
#     # =========================================================================
#     # Calculate scaling once for the static width
#     fractional_bits = twiddle_width - 1
#     scale_factor = 1 << fractional_bits
#     min_val = -scale_factor
#     max_val = scale_factor - 1
#     mask = (1 << twiddle_width) - 1
 
#     twiddle_real = np.clip(twiddles.real * scale_factor, min_val, max_val).astype(int) & mask
#     twiddle_imag = np.clip(twiddles.imag * scale_factor, min_val, max_val).astype(int) & mask
 
#     for stage in range(1, stages + 1):
#         if (type_fft == 0): 
#             real_q = twiddle_real[0 : N // 2]
#             imag_q = twiddle_imag[0 : N // 2]
 
#             stride = (N // 2) // 2**(stage-1)
#             iter_count = 2**(stage-1)
 
#             temp_real = []
#             temp_imag = []
 
#             for j in range(0, iter_count):
#                 temp_real.append(real_q[stride*j])
#                 temp_imag.append(imag_q[stride*j])
 
#             hex_chars = (twiddle_width + 3) // 4
#             with open(real_file(stage), "w") as f_real:
#                 for value in temp_real:
#                     f_real.write(f"{value:0{hex_chars}X}\n")
 
#             with open(imag_file(stage), "w") as f_imag:
#                 for value in temp_imag:
#                     f_imag.write(f"{value:0{hex_chars}X}\n")
 
#     if __debug__:
#         print(f"Generated twiddles for {stages} stages.")
#         if bit_growth == 1:
#             print(f"Base width: {twiddle_width} bits. Max width: {twiddle_width + bit_growth_stages} bits.")
 
#     # Return the base twiddles for reference
#     return twiddles.real, twiddles.imag
 
# import math
 
 
# def generate_twiddle_pkg(N, src_dir, type_fft=0):
#     """
#     Generate twiddle_pkg.vh with ternary-macro file lookup trees.

#     type_fft = 0 : radix-2  -> log2(N) stages, ONE twiddle pair per stage
#                    macros:  GET_REAL_FILE(idx), GET_IMAG_FILE(idx)

#     type_fft = 1 : radix-4  -> log2(N)/2 stages, THREE twiddle pairs per
#                    stage (W^1, W^2, W^3)
#                    macros:  GET_REAL_FILE_1/2/3(idx)
#                             GET_IMAG_FILE_1/2/3(idx)
#     """
#     if type_fft == 0:
#         stages = int(math.log2(N))
#     elif type_fft == 1:
#         stages = int(math.log2(N)) // 2  # Radix-4 has half the number of stages
#     else:
#         raise ValueError(f"unknown type_fft: {type_fft}")

#     def build_macro(macro_name, path_fn):
#         """Build one ternary lookup tree mapping stage index -> filename."""
#         s = f"`define {macro_name}(idx) \\\n"
#         for stage in range(1, stages + 1):
#             s += f'    ((idx) == {stage-1}) ? "{path_fn(stage)}" : \\\n'
#         s += f'    "{path_fn(1)}"\n\n'  # Default fallback
#         return s

#     pkg_content = ""

#     if type_fft == 0:
#         # ---------------- Radix-2: one twiddle pair per stage -------------
#         real_file = lambda stage: f"../Data/f_twiddle_real_{stage}.mem"
#         imag_file = lambda stage: f"../Data/f_twiddle_imag_{stage}.mem"

#         pkg_content += build_macro("GET_REAL_FILE", real_file)
#         pkg_content += build_macro("GET_IMAG_FILE", imag_file)

#     else:
#         # ---------------- Radix-4: three twiddle pairs per stage ----------
#         # NOTE: these filename patterns must match exactly what
#         # generate_twiddles() writes for the radix-4 case.
#         # Order is stage first, then the twiddle index k (1,2,3).
#         real_file_r4 = lambda k: (
#             lambda stage: f"../Data/f_twiddle_real_{stage}_{k}.mem"
#         )
#         imag_file_r4 = lambda k: (
#             lambda stage: f"../Data/f_twiddle_imag_{stage}_{k}.mem"
#         )

#         for k in (1, 2, 3):
#             pkg_content += build_macro(f"GET_REAL_FILE_{k}", real_file_r4(k))
#             pkg_content += build_macro(f"GET_IMAG_FILE_{k}", imag_file_r4(k))

#     # Write to a header file
#     filepath = f"{src_dir}twiddle_pkg.vh"
#     with open(filepath, "w") as f:
#         f.write(pkg_content)

#     radix = "radix-2" if type_fft == 0 else "radix-4"
#     per_stage = 1 if type_fft == 0 else 3
#     print(
#         f"Generated {filepath} with ternary macros for {stages} {radix} "
#         f"stages ({per_stage} twiddle pair(s) per stage)."
#     )
 
 
# def _write_constraints(xdc_path, clock_port, clock_period_ns):
#     """Writes a minimal XDC with just a clock constraint."""
#     with open(xdc_path, "w") as f:
#         f.write(
#             f"create_clock -period {clock_period_ns} -name sys_clk "
#             f"[get_ports {{{clock_port}}}]\n"
#         )
 
 
# def _write_synth_impl_tcl(tcl_path, design_files, top, part, generics,
#                           xdc_path, out_dir, max_threads=8, max_dsp=-1, retiming=True, no_dsp=False):
#     """
#     Generates a Tcl script that runs synthesis and implementation and
#     produces timing and utilization reports.
#     """
#     generic_flags = " ".join(
#         f"-generic {{{name}={val}}}" for name, val in generics.items()
#     )
 
#     # Read commands replicate the GUI "No_fast" synth run exactly:
#     #   - twiddle_pkg.vh  -> plain read_verilog (NOT -sv)
#     #   - *.sv            -> read_verilog -sv
#     #   - *.v             -> plain read_verilog
#     #   - all in library xil_defaultlib
#     read_lines = []
#     for design_file in design_files:
#         if design_file.endswith(".sv"):
#             read_lines.append(
#                 f"read_verilog -library xil_defaultlib -sv {{{design_file}}}"
#             )
#         else:  # .v and .vh are read as plain Verilog
#             read_lines.append(
#                 f"read_verilog -library xil_defaultlib {{{design_file}}}"
#             )
 
#     read_block = "\n".join(read_lines)
 
#     # Only emit -max_dsp when the caller overrides the default (-1 = unlimited).
#     # Keeping it omitted at the default leaves the synth command byte-identical
#     # to the GUI's.
#     max_dsp_flag = "" if max_dsp == -1 else f" -max_dsp {max_dsp}"
#     retiming_flag = " -retiming" if retiming else ""
#     define_flag = " -verilog_define NO_DSP" if no_dsp else ""
 
#     tcl = f"""
# # ---- Auto-generated synth+impl script ----
# {read_block}
# read_xdc {{{xdc_path}}}
 
# # Number of threads for synth/place/route (2018.3 caps at 8).
# set_param general.maxThreads {max_threads}
 
# # ------------------------------------------------------------------
# # Synthesis -- matches the GUI "Vivado Synthesis Defaults" run exactly.
# # The GUI's generated command is simply:
# #     synth_design -top <top> -part <part> -retiming
# # The many strategy flags (flatten_hierarchy, fanout_limit, etc.) are
# # applied as internal DEFAULTS by that command; spelling them out
# # explicitly changes the result, so we do NOT add them here.
# # -max_dsp caps DSP usage: 0 = force everything to fabric (no DSPs),
# # N = at most N DSPs, -1 = unlimited (default, flag omitted so the
# # command stays byte-identical to the GUI's).
# # ------------------------------------------------------------------
# synth_design -top {top} -part {part} {generic_flags}{retiming_flag}{max_dsp_flag}{define_flag}
# write_checkpoint -force {out_dir}/post_synth.dcp
# report_utilization -file {out_dir}/post_synth_util.rpt
 
# # ------------------------------------------------------------------
# # Implementation -- replicates the GUI "Performance_ExtraTimingOpt"
# # strategy (impl_1) exactly:
# #   opt_design              directive Default   (enabled)
# #   power_opt_design                            (disabled)
# #   place_design            directive ExtraTimingOpt
# #   post_place_power_opt                        (disabled)
# #   phys_opt_design         directive Explore   (enabled, pre-route)
# #   route_design            directive NoTimingRelaxation
# #   post_route_phys_opt                         (disabled)
# # ------------------------------------------------------------------
# opt_design -directive Default
# place_design -directive ExtraTimingOpt
# phys_opt_design -directive Explore
# route_design -directive NoTimingRelaxation
# write_checkpoint -force {out_dir}/post_route.dcp
 
# # Human-readable reports (kept for manual inspection)
# report_timing_summary -file {out_dir}/post_route_timing.rpt
# report_utilization    -file {out_dir}/post_route_util.rpt
 
# # ------------------------------------------------------------------
# # Metrics for Vivado 2018.3.
# # Timing: read the four summary values straight off the timer via
# # report_timing_summary's return string is not stable in 2018.3, so we
# # use timer properties that DO exist in 2018.3.
# # Utilization: count cells by REF_NAME prefix (stable in 2018.3).
# # ------------------------------------------------------------------
 
# # --- Timing (2018.3-safe) ------------------------------------------
# # IMPORTANT: the GUI's WNS/TNS come from the Design Timing Summary in
# # report_timing_summary. get_timing_paths can report a different worst
# # path, so read the summary itself to match the GUI exactly.
# report_timing_summary -delay_type min_max -file {out_dir}/post_route_timing.rpt
 
# # Also emit the summary to stdout wrapped in markers so Python can grab
# # the exact same numbers the GUI shows.
# puts "TIMING_SUMMARY_BEGIN"
# report_timing_summary -delay_type min_max -no_detailed_paths
# puts "TIMING_SUMMARY_END"
 
# # --- Utilization (2018.3-safe, count by REF_NAME) ------------------
# set n_lut  [llength [get_cells -hier -filter {{REF_NAME =~ LUT*}}]]
# set n_reg  [llength [get_cells -hier -filter {{REF_NAME =~ FD* || REF_NAME =~ LD*}}]]
# set n_dsp  [llength [get_cells -hier -filter {{REF_NAME =~ DSP*}}]]
# set n_bram [llength [get_cells -hier -filter {{REF_NAME =~ RAMB*}}]]
# puts "METRIC luts=$n_lut"
# puts "METRIC registers=$n_reg"
# puts "METRIC dsps=$n_dsp"
# puts "METRIC bram_prims=$n_bram"
# report_power -file {out_dir}/post_route_power.rpt
# puts "SYNTH_IMPL_DONE"
# """
 
#     with open(tcl_path, "w") as f:
#         f.write(tcl)
 
# def _parse_power(power_rpt_path):
#     """Extract total on-chip power (W) from a Vivado report_power file."""
#     if not os.path.exists(power_rpt_path):
#         return None
#     with open(power_rpt_path, "r") as f:
#         text = f.read()
#     m = re.search(r"Total On-Chip Power\s*\(W\)\s*\|\s*([\d.]+)", text)
#     return float(m.group(1)) if m else None

# def _parse_metrics_from_stdout(stdout):
#     """
#     Pull the 'METRIC key=value' lines the Tcl script printed. These are the
#     authoritative values from Vivado's own timing/utilization engine, so they
#     match the GUI and don't depend on report text layout or part family.
#     """
#     metrics = {}
#     for m in re.finditer(r"METRIC\s+(\w+)=(\S+)", stdout):
#         key, val = m.group(1), m.group(2)
#         try:
#             f = float(val)
#             metrics[key] = int(f) if f.is_integer() else f
#         except ValueError:
#             metrics[key] = None  # Tcl printed empty / non-numeric
#     return metrics
 
 
# def _parse_timing_summary(stdout):
#     """
#     Parse WNS/TNS/WHS/THS from the Design Timing Summary that
#     report_timing_summary prints between the TIMING_SUMMARY markers.
#     This is the SAME table the Vivado GUI's timing panel shows, so the
#     WNS here matches the GUI's WNS exactly.
 
#     The 2018.3 summary looks like:
 
#         Design Timing Summary
#         ---------------------
#         WNS(ns)  TNS(ns)  TNS Failing Endpoints  TNS Total Endpoints  \
#         WHS(ns)  THS(ns)  ...
#         -------  -------  ---------------------  -------------------  ...
#         -0.060  -12.345                     42                 5000  \
#          0.031    0.000  ...
 
#     Returns (wns, tns, whs, ths), any of which may be None.
#     """
#     wns = tns = whs = ths = None
 
#     m = re.search(
#         r"TIMING_SUMMARY_BEGIN(.*?)TIMING_SUMMARY_END",
#         stdout,
#         re.DOTALL,
#     )
#     block = m.group(1) if m else stdout
 
#     # Locate the WNS(ns) ... THS(ns) header row, then take the first numeric
#     # values row after it. This is the Design Timing Summary the GUI shows.
#     header = re.search(r"WNS\(ns\).*?THS\(ns\)", block, re.DOTALL)
#     if header:
#         after = block[header.end():]
#         num = re.search(
#             r"(-?\d+\.\d+)\s+(-?\d+\.\d+)\s+\d+\s+\d+\s+"
#             r"(-?\d+\.\d+)\s+(-?\d+\.\d+)",
#             after,
#         )
#         if num:
#             wns = float(num.group(1))
#             tns = float(num.group(2))
#             whs = float(num.group(3))
#             ths = float(num.group(4))
 
#     return wns, tns, whs, ths
 
 
# def _parse_wns_tns_report(timing_rpt_path):
#     """Fallback: parse WNS/TNS/WHS/THS from the post_route_timing.rpt file."""
#     if not os.path.exists(timing_rpt_path):
#         return None, None, None, None
#     with open(timing_rpt_path, "r") as f:
#         text = f.read()
#     return _parse_timing_summary(text)
 
 
# def _parse_utilization(util_rpt_path):
#     """
#     Backup text parser, only used if the stdout METRIC lines are missing.
#     Handles BOTH 7-series ("Slice LUTs"/"Slice Registers") and UltraScale
#     ("CLB LUTs"/"CLB Registers") naming.
#     """
#     luts = registers = dsps = bram_tiles = None
#     if not os.path.exists(util_rpt_path):
#         return luts, registers, dsps, bram_tiles
 
#     with open(util_rpt_path, "r") as f:
#         text = f.read()
 
#     def find(*labels):
#         for label in labels:
#             m = re.search(
#                 r"\|\s*" + re.escape(label) + r"\s*\|\s*([\d,]+)\s*\|",
#                 text,
#             )
#             if m:
#                 return int(m.group(1).replace(",", ""))
#         return None
 
#     luts = find("Slice LUTs", "CLB LUTs")
#     registers = find("Slice Registers", "CLB Registers")
#     dsps = find("DSPs", "DSP48E1", "DSP48E2", "DSP48 Blocks")
#     bram_tiles = find("Block RAM Tile", "Block RAM Tiles")
#     return luts, registers, dsps, bram_tiles
 
 
# def synthesize_and_implement(
#     Data_width=16,
#     Tw_width=8,
#     N=256,
#     SimpleMult=0,
#     Fast_DSP=0,
#     carry_save=0,
#     Bram=1,
#     bit_growth=0,
#     part="xc7a200tfbg676-2",
#     clock_period_ns=2.5,
#     clock_port="clock",
#     top="fft_top",
#     out_dir="../Data/vivado_run",
#     max_threads=8,
#     max_dsp=-1,
#     retiming=True,
#     no_dsp=False
# ):
#     """
#     Runs Vivado synthesis and implementation in batch mode.
 
#     Returns a dictionary containing:
#         met_timing
#         wns_ns
#         tns_ns
#         whs_ns
#         ths_ns
#         luts
#         registers
#         dsps
#         bram_tiles
 
#     Resource values are taken from the post-route Vivado utilization report.
#     """
#     src_dir = "../Radix-2/"
#     os.makedirs(out_dir, exist_ok=True)
 
#     generate_twiddles(N, Tw_width, 0, bit_growth)
#     generate_twiddle_pkg(N, src_dir)
 
#     # File read order matches the GUI "No_fast" synth run:
#     #   stage_unit.sv, fft_radix_2_top.sv, Carry_mult.v, butterfly.v,
#     #   delay_buffer.v, delay_reg.v
#     # twiddle_pkg.vh is kept first because this flow generates it and the
#     # RTL includes it; the GUI project uses a committed copy instead.
#     design_files = [
#         f"{src_dir}twiddle_pkg.vh",
#         f"{src_dir}stage_unit.sv",
#         f"{src_dir}fft_radix_2_top.sv",
#         f"{src_dir}Carry_mult.v",
#         f"{src_dir}butterfly.v",
#         f"{src_dir}delay_buffer.v",
#         f"{src_dir}delay_reg.v",
#     ]
 
#     generics = {
#         "WIDTH": Data_width,
#         "Num_of_samples": N,
#         "Tw_WIDTH": Tw_width,
#         "SimpleMult": SimpleMult,
#         "Fast_DSP": Fast_DSP,
#         "carry_save": carry_save,
#         "Bram": Bram,
#         "bit_growth": bit_growth,
#     }
 
#     xdc_path = os.path.join(out_dir, "constraints.xdc")
#     tcl_path = os.path.join(out_dir, "synth_impl.tcl")
#     log_path = os.path.join(out_dir, "vivado.log")
#     journal_path = os.path.join(out_dir, "vivado.jou")
 
#     _write_constraints(xdc_path, clock_port, clock_period_ns)
#     _write_synth_impl_tcl(
#         tcl_path,
#         design_files,
#         top,
#         part,
#         generics,
#         xdc_path,
#         out_dir,
#         max_threads=max_threads,
#         max_dsp=max_dsp,
#         retiming=retiming,
#         no_dsp=no_dsp
#     )
 
#     if __debug__:
#         print(
#             f"Running Vivado synth+impl (part={part}, "
#             f"clock={clock_period_ns} ns)..."
#         )
    
    
#     vivado_cmd = [
#         "vivado",
#         "-mode",
#         "batch",
#         "-source",
#         tcl_path,
#         "-log",
#         log_path,
#         "-journal",
#         journal_path,
#     ]
 
#     result = subprocess.run(vivado_cmd, capture_output=True, text=True)
 
#     if result.returncode != 0 or "SYNTH_IMPL_DONE" not in result.stdout:
#         print("--- VIVADO SYNTH/IMPL FAILED ---")
#         print("Standard Output:")
#         print(result.stdout)
#         print("Standard Error:")
#         print(result.stderr)
#         print(f"See {log_path} for the full Vivado log.")
#         sys.exit(1)
 
#     # ------------------------------------------------------------------
#     # Read the metrics Tcl emitted on stdout.
#     # ------------------------------------------------------------------
#     metrics = _parse_metrics_from_stdout(result.stdout)
 
#     # Timing comes from the Design Timing Summary (same as the GUI panel),
#     # not from get_timing_paths, so the WNS matches the GUI exactly.
#     wns, tns, whs, ths = _parse_timing_summary(result.stdout)
 
#     # If the summary parse failed for any field, fall back to the text
#     # report on disk, then to any METRIC lines.
#     if wns is None or tns is None:
#         f_wns, f_tns, f_whs, f_ths = _parse_wns_tns_report(
#             os.path.join(out_dir, "post_route_timing.rpt")
#         )
#         wns = wns if wns is not None else f_wns
#         tns = tns if tns is not None else f_tns
#         whs = whs if whs is not None else f_whs
#         ths = ths if ths is not None else f_ths
 
#     # For utilization on Vivado 2018.3 the report_utilization text table is
#     # the authoritative source (matches the GUI's utilization panel exactly),
#     # so prefer it and fall back to the cell-count metrics only if parsing
#     # the report fails.
#     util_rpt = os.path.join(out_dir, "post_route_util.rpt")
#     r_luts, r_regs, r_dsps, r_bram = _parse_utilization(util_rpt)
 
#     luts = r_luts if r_luts is not None else metrics.get("luts")
#     registers = r_regs if r_regs is not None else metrics.get("registers")
#     dsps = r_dsps if r_dsps is not None else metrics.get("dsps")
#     bram_tiles = r_bram if r_bram is not None else metrics.get("bram_prims")
#     power_w = _parse_power(os.path.join(out_dir, "post_route_power.rpt"))
 
#     met_timing = (
#         wns is not None
#         and wns >= 0
#         and (ths is None or ths >= 0)
#     )
 
#     if __debug__:
#         status = "MET" if met_timing else "VIOLATED"
#         print(
#             f"Timing {status}: "
#             f"WNS={wns} ns, TNS={tns} ns, "
#             f"WHS={whs} ns, THS={ths} ns"
#         )
#         print(
#             f"Resources: LUTs={luts}, Registers={registers}, "
#             f"DSPs={dsps}, BRAM Tiles={bram_tiles}, Power={power_w} W"
#         )
#         print(f"Reports written to {out_dir}")
 
#     return {
#         "met_timing": met_timing,
#         "wns_ns": wns,
#         "tns_ns": tns,
#         "whs_ns": whs,
#         "ths_ns": ths,
#         "luts": luts,
#         "registers": registers,
#         "dsps": dsps,
#         "bram_tiles": bram_tiles,
#         "power_w": power_w,
#     }

# if __name__ == "__main__":

#     clean_data_folder("../Data")
#     print(datetime.now().strftime("%Y-%m-%d %H:%M:%S"))


#     result = synthesize_and_implement(
#         Data_width=16,
#         Tw_width=9,
#         N=256,
#         SimpleMult=0,
#         Fast_DSP=1,
#         carry_save=0,
#         Bram=0,
#         bit_growth=0,
#         part="xc7a200tfbg676-2",
#         clock_period_ns=2.5,
#         clock_port="clock",
#         top="fft_top",
#         out_dir="../Data/vivado_run"
#     )

#     print("\n===== VIVADO RESULTS =====")
#     print("Setting: SimpleMult=1, Fast_DSP=1, carry_save=0, Bram=0")
#     print(f"LUTs       : {result['luts']}")
#     print(f"Registers  : {result['registers']}")
#     print(f"DSPs       : {result['dsps']}")
#     print(f"BRAMs      : {result['bram_tiles']}")
#     print(f"WNS        : {result['wns_ns']} ns")
#     print(f"TNS        : {result['tns_ns']} ns")
#     print(f"Power      : {result['power_w']} W")
#     print(datetime.now().strftime("%Y-%m-%d %H:%M:%S"))

#     result = synthesize_and_implement(
#         Data_width=16,
#         Tw_width=9,
#         N=256,
#         SimpleMult=1,
#         Fast_DSP=0,
#         carry_save=1,
#         Bram=0,
#         bit_growth=0,
#         part="xc7a200tfbg676-2",
#         clock_period_ns=2.5,
#         clock_port="clock",
#         top="fft_top",
#         out_dir="../Data/vivado_run",
#         retiming=True,
#         no_dsp=True
#     )

#     print("\n===== VIVADO RESULTS =====")
#     print("Setting: SimpleMult=0, Fast_DSP=1, carry_save=0, Bram=0")
#     print(f"LUTs       : {result['luts']}")
#     print(f"Registers  : {result['registers']}")
#     print(f"DSPs       : {result['dsps']}")
#     print(f"BRAMs      : {result['bram_tiles']}")
#     print(f"WNS        : {result['wns_ns']} ns")
#     print(f"TNS        : {result['tns_ns']} ns")
#     print(f"Power      : {result['power_w']} W")
#     print(datetime.now().strftime("%Y-%m-%d %H:%M:%S"))


#     result = synthesize_and_implement(
#         Data_width=11,
#         Tw_width=9,
#         N=256,
#         SimpleMult=1,
#         Fast_DSP=0,
#         carry_save=1,
#         Bram=0,
#         bit_growth=1,
#         part="xc7a200tfbg676-2",
#         clock_period_ns=2.5,
#         clock_port="clock",
#         top="fft_top",
#         out_dir="../Data/vivado_run",
#         max_dsp=0,
#         retiming=True
#     )   

#     print("\n===== VIVADO RESULTS =====")
#     print("Setting: SimpleMult=1, Fast_DSP=0, carry_save=1, Bram=0")
#     print(f"LUTs       : {result['luts']}")
#     print(f"Registers  : {result['registers']}")
#     print(f"DSPs       : {result['dsps']}")
#     print(f"BRAMs      : {result['bram_tiles']}")
#     print(f"WNS        : {result['wns_ns']} ns")
#     print(f"TNS        : {result['tns_ns']} ns")
#     print(f"Power      : {result['power_w']} W")
#     print(datetime.now().strftime("%Y-%m-%d %H:%M:%S"))

#     result = synthesize_and_implement(
#         Data_width=11,
#         Tw_width=9,
#         N=256,
#         SimpleMult=0,
#         Fast_DSP=0,
#         carry_save=1,
#         Bram=0,
#         bit_growth=1,
#         part="xc7a200tfbg676-2",
#         clock_period_ns=2.5,
#         clock_port="clock",
#         top="fft_top",
#         out_dir="../Data/vivado_run",
#         max_dsp=0,
#         retiming=True
#     )

#     print("\n===== VIVADO RESULTS =====")
#     print("Setting: SimpleMult=0, Fast_DSP=0, carry_save=1, Bram=0")
#     print(f"LUTs       : {result['luts']}")
#     print(f"Registers  : {result['registers']}")
#     print(f"DSPs       : {result['dsps']}") 
#     print(f"BRAMs      : {result['bram_tiles']}")
#     print(f"WNS        : {result['wns_ns']} ns")
#     print(f"TNS        : {result['tns_ns']} ns")
#     print(f"Power      : {result['power_w']} W")
#     print(datetime.now().strftime("%Y-%m-%d %H:%M:%S"))

#     result = synthesize_and_implement(
#         Data_width=11,
#         Tw_width=9,
#         N=256,
#         SimpleMult=1,
#         Fast_DSP=0,
#         carry_save=0,
#         Bram=0,
#         bit_growth=1,
#         part="xc7a200tfbg676-2",
#         clock_period_ns=2.5,
#         clock_port="clock",
#         top="fft_top",
#         out_dir="../Data/vivado_run"
#     )

#     print("\n===== VIVADO RESULTS =====")
#     print("Setting: SimpleMult=1, Fast_DSP=0, carry_save=0, Bram=0")
#     print(f"LUTs       : {result['luts']}")
#     print(f"Registers  : {result['registers']}")
#     print(f"DSPs       : {result['dsps']}") 
#     print(f"BRAMs      : {result['bram_tiles']}")
#     print(f"WNS        : {result['wns_ns']} ns")
#     print(f"TNS        : {result['tns_ns']} ns")
#     print(f"Power      : {result['power_w']} W")
#     print(datetime.now().strftime("%Y-%m-%d %H:%M:%S"))

#     result = synthesize_and_implement(
#         Data_width=11,
#         Tw_width=9,
#         N=256,
#         SimpleMult=0,
#         Fast_DSP=0,
#         carry_save=0,
#         Bram=0,
#         bit_growth=1,
#         part="xc7a200tfbg676-2",
#         clock_period_ns=2.5,
#         clock_port="clock",
#         top="fft_top",
#         out_dir="../Data/vivado_run"
#     )

#     print("\n===== VIVADO RESULTS =====")
#     print("Setting: SimpleMult=0, Fast_DSP=0, carry_save=0, Bram=0")
#     print(f"LUTs       : {result['luts']}")
#     print(f"Registers  : {result['registers']}")
#     print(f"DSPs       : {result['dsps']}") 
#     print(f"BRAMs      : {result['bram_tiles']}")
#     print(f"WNS        : {result['wns_ns']} ns")
#     print(f"TNS        : {result['tns_ns']} ns")
#     print(f"Power      : {result['power_w']} W")
#     print(datetime.now().strftime("%Y-%m-%d %H:%M:%S"))

#     result = synthesize_and_implement(
#         Data_width=11,
#         Tw_width=9,
#         N=256,
#         SimpleMult=1,
#         Fast_DSP=0,
#         carry_save=0,
#         Bram=1,
#         bit_growth=1,
#         part="xc7a200tfbg676-2",
#         clock_period_ns=2.5,
#         clock_port="clock",
#         top="fft_top",
#         out_dir="../Data/vivado_run"
#     )

#     print("\n===== VIVADO RESULTS =====")
#     print("Setting: SimpleMult=1, Fast_DSP=0, carry_save=0, Bram=1")
#     print(f"LUTs       : {result['luts']}")
#     print(f"Registers  : {result['registers']}")
#     print(f"DSPs       : {result['dsps']}") 
#     print(f"BRAMs      : {result['bram_tiles']}")
#     print(f"WNS        : {result['wns_ns']} ns")
#     print(f"TNS        : {result['tns_ns']} ns")
#     print(f"Power      : {result['power_w']} W")
#     print(datetime.now().strftime("%Y-%m-%d %H:%M:%S"))

# import numpy as np
# import math
# import subprocess
# import sys
# import os
# import shutil
# import re
# from datetime import datetime
 
# def clean_data_folder(folder_path="../Data"):
#     """
#     Deletes all files and subdirectories inside the specified folder.
#     """
#     # Convert to an absolute path to prevent accidental deletions in the wrong directory
#     abs_path = os.path.abspath(folder_path)
    
#     # Check if the folder actually exists before trying to clean it
#     if not os.path.exists(abs_path):
#         print(f"Folder not found: {abs_path}. Nothing to clean.")
#         # Optionally create it if you want it to always exist:
#         # os.makedirs(abs_path)
#         return
 
#     print(f"Cleaning folder: {abs_path}...")
    
#     # Loop through everything inside the folder
#     for item_name in os.listdir(abs_path):
#         item_path = os.path.join(abs_path, item_name)
        
#         try:
#             if os.path.isfile(item_path) or os.path.islink(item_path):
#                 os.unlink(item_path)  # Delete the file or link
#             elif os.path.isdir(item_path):
#                 shutil.rmtree(item_path)  # Delete the subdirectory and its contents
#         except Exception as e:
#             print(f"Failed to delete {item_path}. Reason: {e}")
            
#     print("Folder cleaned successfully!")
 
    
# def generate_twiddles(N, twiddle_width, type_fft=0, bit_growth=0):
#     stages = int(math.log2(N))
#     max_stage_num = twiddle_width + 1
#     Current_bits_stages = min(stages, max_stage_num)
#     bit_growth_stages = max(0, stages - max_stage_num)
 
#     k = np.arange(N)
#     twiddles = np.exp(-2j * np.pi * k / N)
 
#     real_file = lambda stage: f"../Data/f_twiddle_real_{stage}.mem"
#     imag_file = lambda stage: f"../Data/f_twiddle_imag_{stage}.mem"
 
#     # =========================================================================
#     # Fallback for No Bit Growth
#     # =========================================================================
#     # Calculate scaling once for the static width
#     fractional_bits = twiddle_width - 1
#     scale_factor = 1 << fractional_bits
#     min_val = -scale_factor
#     max_val = scale_factor - 1
#     mask = (1 << twiddle_width) - 1
 
#     twiddle_real = np.clip(twiddles.real * scale_factor, min_val, max_val).astype(int) & mask
#     twiddle_imag = np.clip(twiddles.imag * scale_factor, min_val, max_val).astype(int) & mask
 
#     for stage in range(1, stages + 1):
#         if (type_fft == 0): 
#             real_q = twiddle_real[0 : N // 2]
#             imag_q = twiddle_imag[0 : N // 2]
 
#             stride = (N // 2) // 2**(stage-1)
#             iter_count = 2**(stage-1)
 
#             temp_real = []
#             temp_imag = []
 
#             for j in range(0, iter_count):
#                 temp_real.append(real_q[stride*j])
#                 temp_imag.append(imag_q[stride*j])
 
#             hex_chars = (twiddle_width + 3) // 4
#             with open(real_file(stage), "w") as f_real:
#                 for value in temp_real:
#                     f_real.write(f"{value:0{hex_chars}X}\n")
 
#             with open(imag_file(stage), "w") as f_imag:
#                 for value in temp_imag:
#                     f_imag.write(f"{value:0{hex_chars}X}\n")
 
#     if __debug__:
#         print(f"Generated twiddles for {stages} stages.")
#         if bit_growth == 1:
#             print(f"Base width: {twiddle_width} bits. Max width: {twiddle_width + bit_growth_stages} bits.")
 
#     # Return the base twiddles for reference
#     return twiddles.real, twiddles.imag
 
# import math
 
 
# def generate_twiddle_pkg(N, src_dir, type_fft=0):
#     """
#     Generate twiddle_pkg.vh with ternary-macro file lookup trees.

#     type_fft = 0 : radix-2  -> log2(N) stages, ONE twiddle pair per stage
#                    macros:  GET_REAL_FILE(idx), GET_IMAG_FILE(idx)

#     type_fft = 1 : radix-4  -> log2(N)/2 stages, THREE twiddle pairs per
#                    stage (W^1, W^2, W^3)
#                    macros:  GET_REAL_FILE_1/2/3(idx)
#                             GET_IMAG_FILE_1/2/3(idx)
#     """
#     if type_fft == 0:
#         stages = int(math.log2(N))
#     elif type_fft == 1:
#         stages = int(math.log2(N)) // 2  # Radix-4 has half the number of stages
#     else:
#         raise ValueError(f"unknown type_fft: {type_fft}")

#     def build_macro(macro_name, path_fn):
#         """Build one ternary lookup tree mapping stage index -> filename."""
#         s = f"`define {macro_name}(idx) \\\n"
#         for stage in range(1, stages + 1):
#             s += f'    ((idx) == {stage-1}) ? "{path_fn(stage)}" : \\\n'
#         s += f'    "{path_fn(1)}"\n\n'  # Default fallback
#         return s

#     pkg_content = ""

#     if type_fft == 0:
#         # ---------------- Radix-2: one twiddle pair per stage -------------
#         real_file = lambda stage: f"../Data/f_twiddle_real_{stage}.mem"
#         imag_file = lambda stage: f"../Data/f_twiddle_imag_{stage}.mem"

#         pkg_content += build_macro("GET_REAL_FILE", real_file)
#         pkg_content += build_macro("GET_IMAG_FILE", imag_file)

#     else:
#         # ---------------- Radix-4: three twiddle pairs per stage ----------
#         # NOTE: these filename patterns must match exactly what
#         # generate_twiddles() writes for the radix-4 case.
#         # Order is stage first, then the twiddle index k (1,2,3).
#         real_file_r4 = lambda k: (
#             lambda stage: f"../Data/f_twiddle_real_{stage}_{k}.mem"
#         )
#         imag_file_r4 = lambda k: (
#             lambda stage: f"../Data/f_twiddle_imag_{stage}_{k}.mem"
#         )

#         for k in (1, 2, 3):
#             pkg_content += build_macro(f"GET_REAL_FILE_{k}", real_file_r4(k))
#             pkg_content += build_macro(f"GET_IMAG_FILE_{k}", imag_file_r4(k))

#     # Write to a header file
#     filepath = f"{src_dir}twiddle_pkg.vh"
#     with open(filepath, "w") as f:
#         f.write(pkg_content)

#     radix = "radix-2" if type_fft == 0 else "radix-4"
#     per_stage = 1 if type_fft == 0 else 3
#     print(
#         f"Generated {filepath} with ternary macros for {stages} {radix} "
#         f"stages ({per_stage} twiddle pair(s) per stage)."
#     )
 
 
# def _write_constraints(xdc_path, clock_port, clock_period_ns):
#     """Writes a minimal XDC with just a clock constraint."""
#     with open(xdc_path, "w") as f:
#         f.write(
#             f"create_clock -period {clock_period_ns} -name sys_clk "
#             f"[get_ports {{{clock_port}}}]\n"
#         )
 
 
# def _write_synth_impl_tcl(tcl_path, design_files, top, part, generics,
#                           xdc_path, out_dir, max_threads=8, max_dsp=-1, retiming=True, no_dsp=False, no_bram=False):
#     """
#     Generates a Tcl script that runs synthesis and implementation and
#     produces timing and utilization reports.
#     """
#     generic_flags = " ".join(
#         f"-generic {{{name}={val}}}" for name, val in generics.items()
#     )
 
#     # Read commands replicate the GUI "No_fast" synth run exactly:
#     #   - twiddle_pkg.vh  -> plain read_verilog (NOT -sv)
#     #   - *.sv            -> read_verilog -sv
#     #   - *.v             -> plain read_verilog
#     #   - all in library xil_defaultlib
#     read_lines = []
#     for design_file in design_files:
#         if design_file.endswith(".sv"):
#             read_lines.append(
#                 f"read_verilog -library xil_defaultlib -sv {{{design_file}}}"
#             )
#         else:  # .v and .vh are read as plain Verilog
#             read_lines.append(
#                 f"read_verilog -library xil_defaultlib {{{design_file}}}"
#             )
 
#     read_block = "\n".join(read_lines)
 
#     # Only emit -max_dsp when the caller overrides the default (-1 = unlimited).
#     # Keeping it omitted at the default leaves the synth command byte-identical
#     # to the GUI's.
#     max_dsp_flag = "" if max_dsp == -1 else f" -max_dsp {max_dsp}"
#     retiming_flag = " -retiming" if retiming else ""
#     define_flag = " -verilog_define NO_DSP" if no_dsp else ""
#     define_flag_2 = " -verilog_define NO_BRAM" if no_bram else ""
 
#     tcl = f"""
# # ---- Auto-generated synth+impl script ----
# {read_block}
# read_xdc {{{xdc_path}}}
 
# # Number of threads for synth/place/route (2018.3 caps at 8).
# set_param general.maxThreads {max_threads}
 
# # ------------------------------------------------------------------
# # Synthesis -- matches the GUI "Vivado Synthesis Defaults" run exactly.
# # The GUI's generated command is simply:
# #     synth_design -top <top> -part <part> -retiming
# # The many strategy flags (flatten_hierarchy, fanout_limit, etc.) are
# # applied as internal DEFAULTS by that command; spelling them out
# # explicitly changes the result, so we do NOT add them here.
# # -max_dsp caps DSP usage: 0 = force everything to fabric (no DSPs),
# # N = at most N DSPs, -1 = unlimited (default, flag omitted so the
# # command stays byte-identical to the GUI's).
# # ------------------------------------------------------------------
# synth_design -top {top} -part {part} {generic_flags}{retiming_flag}{max_dsp_flag}{define_flag}{define_flag_2}
# write_checkpoint -force {out_dir}/post_synth.dcp
# report_utilization -file {out_dir}/post_synth_util.rpt
 
# # ------------------------------------------------------------------
# # Implementation -- replicates the GUI "Performance_ExtraTimingOpt"
# # strategy (impl_1) exactly:
# #   opt_design              directive Default   (enabled)
# #   power_opt_design                            (disabled)
# #   place_design            directive ExtraTimingOpt
# #   post_place_power_opt                        (disabled)
# #   phys_opt_design         directive Explore   (enabled, pre-route)
# #   route_design            directive NoTimingRelaxation
# #   post_route_phys_opt                         (disabled)
# # ------------------------------------------------------------------
# opt_design -directive Default
# place_design -directive ExtraTimingOpt
# phys_opt_design -directive Explore
# route_design -directive NoTimingRelaxation
# write_checkpoint -force {out_dir}/post_route.dcp
 
# # Human-readable reports (kept for manual inspection)
# report_timing_summary -file {out_dir}/post_route_timing.rpt
# report_utilization    -file {out_dir}/post_route_util.rpt
 
# # ------------------------------------------------------------------
# # Metrics for Vivado 2018.3.
# # Timing: read the four summary values straight off the timer via
# # report_timing_summary's return string is not stable in 2018.3, so we
# # use timer properties that DO exist in 2018.3.
# # Utilization: count cells by REF_NAME prefix (stable in 2018.3).
# # ------------------------------------------------------------------
 
# # --- Timing (2018.3-safe) ------------------------------------------
# # IMPORTANT: the GUI's WNS/TNS come from the Design Timing Summary in
# # report_timing_summary. get_timing_paths can report a different worst
# # path, so read the summary itself to match the GUI exactly.
# report_timing_summary -delay_type min_max -file {out_dir}/post_route_timing.rpt
 
# # Also emit the summary to stdout wrapped in markers so Python can grab
# # the exact same numbers the GUI shows.
# puts "TIMING_SUMMARY_BEGIN"
# report_timing_summary -delay_type min_max -no_detailed_paths
# puts "TIMING_SUMMARY_END"
 
# # --- Utilization (2018.3-safe, count by REF_NAME) ------------------
# set n_lut  [llength [get_cells -hier -filter {{REF_NAME =~ LUT*}}]]
# set n_reg  [llength [get_cells -hier -filter {{REF_NAME =~ FD* || REF_NAME =~ LD*}}]]
# set n_dsp  [llength [get_cells -hier -filter {{REF_NAME =~ DSP*}}]]
# set n_bram [llength [get_cells -hier -filter {{REF_NAME =~ RAMB*}}]]
# puts "METRIC luts=$n_lut"
# puts "METRIC registers=$n_reg"
# puts "METRIC dsps=$n_dsp"
# puts "METRIC bram_prims=$n_bram"
# report_power -file {out_dir}/post_route_power.rpt
# puts "SYNTH_IMPL_DONE"
# """
 
#     with open(tcl_path, "w") as f:
#         f.write(tcl)
 
# def _parse_power(power_rpt_path):
#     """Extract total on-chip power (W) from a Vivado report_power file."""
#     if not os.path.exists(power_rpt_path):
#         return None
#     with open(power_rpt_path, "r") as f:
#         text = f.read()
#     m = re.search(r"Total On-Chip Power\s*\(W\)\s*\|\s*([\d.]+)", text)
#     return float(m.group(1)) if m else None

# def _parse_metrics_from_stdout(stdout):
#     """
#     Pull the 'METRIC key=value' lines the Tcl script printed. These are the
#     authoritative values from Vivado's own timing/utilization engine, so they
#     match the GUI and don't depend on report text layout or part family.
#     """
#     metrics = {}
#     for m in re.finditer(r"METRIC\s+(\w+)=(\S+)", stdout):
#         key, val = m.group(1), m.group(2)
#         try:
#             f = float(val)
#             metrics[key] = int(f) if f.is_integer() else f
#         except ValueError:
#             metrics[key] = None  # Tcl printed empty / non-numeric
#     return metrics
 
 
# def _parse_timing_summary(stdout):
#     """
#     Parse WNS/TNS/WHS/THS from the Design Timing Summary that
#     report_timing_summary prints between the TIMING_SUMMARY markers.
#     This is the SAME table the Vivado GUI's timing panel shows, so the
#     WNS here matches the GUI's WNS exactly.
 
#     The 2018.3 summary looks like:
 
#         Design Timing Summary
#         ---------------------
#         WNS(ns)  TNS(ns)  TNS Failing Endpoints  TNS Total Endpoints  \
#         WHS(ns)  THS(ns)  ...
#         -------  -------  ---------------------  -------------------  ...
#         -0.060  -12.345                     42                 5000  \
#          0.031    0.000  ...
 
#     Returns (wns, tns, whs, ths), any of which may be None.
#     """
#     wns = tns = whs = ths = None
 
#     m = re.search(
#         r"TIMING_SUMMARY_BEGIN(.*?)TIMING_SUMMARY_END",
#         stdout,
#         re.DOTALL,
#     )
#     block = m.group(1) if m else stdout
 
#     # Locate the WNS(ns) ... THS(ns) header row, then take the first numeric
#     # values row after it. This is the Design Timing Summary the GUI shows.
#     header = re.search(r"WNS\(ns\).*?THS\(ns\)", block, re.DOTALL)
#     if header:
#         after = block[header.end():]
#         num = re.search(
#             r"(-?\d+\.\d+)\s+(-?\d+\.\d+)\s+\d+\s+\d+\s+"
#             r"(-?\d+\.\d+)\s+(-?\d+\.\d+)",
#             after,
#         )
#         if num:
#             wns = float(num.group(1))
#             tns = float(num.group(2))
#             whs = float(num.group(3))
#             ths = float(num.group(4))
 
#     return wns, tns, whs, ths
 
 
# def _parse_wns_tns_report(timing_rpt_path):
#     """Fallback: parse WNS/TNS/WHS/THS from the post_route_timing.rpt file."""
#     if not os.path.exists(timing_rpt_path):
#         return None, None, None, None
#     with open(timing_rpt_path, "r") as f:
#         text = f.read()
#     return _parse_timing_summary(text)
 
 
# def _parse_utilization(util_rpt_path):
#     """
#     Backup text parser, only used if the stdout METRIC lines are missing.
#     Handles BOTH 7-series ("Slice LUTs"/"Slice Registers") and UltraScale
#     ("CLB LUTs"/"CLB Registers") naming.
#     """
#     luts = registers = dsps = bram_tiles = None
#     if not os.path.exists(util_rpt_path):
#         return luts, registers, dsps, bram_tiles
 
#     with open(util_rpt_path, "r") as f:
#         text = f.read()
 
#     def find(*labels):
#         for label in labels:
#             m = re.search(
#                 r"\|\s*" + re.escape(label) + r"\s*\|\s*([\d,]+)\s*\|",
#                 text,
#             )
#             if m:
#                 return int(m.group(1).replace(",", ""))
#         return None
 
#     luts = find("Slice LUTs", "CLB LUTs")
#     registers = find("Slice Registers", "CLB Registers")
#     dsps = find("DSPs", "DSP48E1", "DSP48E2", "DSP48 Blocks")
#     bram_tiles = find("Block RAM Tile", "Block RAM Tiles")
#     return luts, registers, dsps, bram_tiles
 
 
# def synthesize_and_implement(
#     Data_width=16,
#     Tw_width=8,
#     N=256,
#     type_fft=0,
#     SimpleMult=0,
#     Fast_DSP=0,
#     carry_save=0,
#     Bram=1,
#     bit_growth=0,
#     output_pipeline_bram=0,
#     part="xc7a200tfbg676-2",
#     clock_period_ns=2.5,
#     clock_port="clock",
#     top=None,
#     out_dir="../Data/vivado_run",
#     max_threads=8,
#     max_dsp=-1,
#     retiming=True,
#     no_dsp=False,
#     no_bram=False
# ):
#     """
#     Runs Vivado synthesis and implementation in batch mode.

#     type_fft: 0 = radix-2 (files in ../Radix-2/), 1 = radix-4 (files in
#     ../Radix-4/). output_pipeline_bram only applies to radix-4 (mirrors
#     the parameter compile_simulation_verilator/xsim already expose for it).
 
#     Returns a dictionary containing:
#         met_timing
#         wns_ns
#         tns_ns
#         whs_ns
#         ths_ns
#         luts
#         registers
#         dsps
#         bram_tiles
 
#     Resource values are taken from the post-route Vivado utilization report.
#     """
#     if type_fft == 0:
#         src_dir = "../Radix-2/"
#     elif type_fft == 1:
#         src_dir = "../Radix-4/"
#     else:
#         raise ValueError(f"unknown type_fft: {type_fft}")

#     os.makedirs(out_dir, exist_ok=True)
 
#     #generate_twiddles(N, Tw_width, type_fft, bit_growth)
#     generate_twiddle_pkg(N, src_dir, type_fft)
 
#     if type_fft == 0:
#         # File read order matches the GUI "No_fast" synth run:
#         #   stage_unit.sv, fft_radix_2_top.sv, Carry_mult.v, butterfly.v,
#         #   delay_buffer.v, delay_reg.v
#         # twiddle_pkg.vh is kept first because this flow generates it and the
#         # RTL includes it; the GUI project uses a committed copy instead.
#         design_files = [
#             f"{src_dir}twiddle_pkg.vh",
#             f"{src_dir}stage_unit.sv",
#             f"{src_dir}fft_radix_2_top.sv",
#             f"{src_dir}Carry_mult.v",
#             f"{src_dir}butterfly.v",
#             f"{src_dir}delay_buffer.v",
#             f"{src_dir}delay_reg.v",
#         ]

#         generics = {
#             "WIDTH": Data_width,
#             "Num_of_samples": N,
#             "Tw_WIDTH": Tw_width,
#             "SimpleMult": SimpleMult,
#             "Fast_DSP": Fast_DSP,
#             "carry_save": carry_save,
#             "Bram": Bram,
#             "bit_growth": bit_growth,
#         }
#     else:
#         # Same design (non-testbench) files as the radix-4 XSIM/Verilator
#         # sim build in FFT_softaware.py's compile_simulation_verilator/xsim
#         # (tb_top_radix_4.v dropped, memory.v used instead of
#         # delay_buffer.v, twiddle_pkg.vh added since synth needs the
#         # generated twiddle-file macros the RTL includes).
#         design_files = [
#             # f"{src_dir}twiddle_pkg.vh",
#             f"{src_dir}stage_unit.sv",
#             f"{src_dir}fft_radix_4_top.sv",
#             f"{src_dir}Carry_mult.v",
#             f"{src_dir}butterfly.v",
#             f"{src_dir}memory.v",
#             f"{src_dir}delay_reg.v",
#         ]

#         generics = {
#             "WIDTH": Data_width,
#             "Num_of_samples": N,
#             "Tw_WIDTH": Tw_width,
#             "SimpleMult": SimpleMult,
#             "Fast_DSP": Fast_DSP,
#             "carry_save": carry_save,
#             "Bram": Bram,
#             "output_pipeline_bram": output_pipeline_bram,
#             "bit_growth": bit_growth,
#         }

#     # Default top-module name kept as "fft_top" for both radices (matches
#     # the value this function already used for radix-2) -- override with
#     # top=... if your radix-4 top-level module is actually named
#     # differently (e.g. "fft_radix_4_top").
#     top_module = top if top is not None else "fft_top"
 
#     xdc_path = os.path.join(out_dir, "constraints.xdc")
#     tcl_path = os.path.join(out_dir, "synth_impl.tcl")
#     log_path = os.path.join(out_dir, "vivado.log")
#     journal_path = os.path.join(out_dir, "vivado.jou")
 
#     _write_constraints(xdc_path, clock_port, clock_period_ns)
#     _write_synth_impl_tcl(
#         tcl_path,
#         design_files,
#         top_module,
#         part,
#         generics,
#         xdc_path,
#         out_dir,
#         max_threads=max_threads,
#         max_dsp=max_dsp,
#         retiming=retiming,
#         no_dsp=no_dsp,
#         no_bram=no_bram
#     )
 
#     if __debug__:
#         print(
#             f"Running Vivado synth+impl (part={part}, "
#             f"clock={clock_period_ns} ns)..."
#         )
    
    
#     vivado_cmd = [
#         "vivado",
#         "-mode",
#         "batch",
#         "-source",
#         tcl_path,
#         "-log",
#         log_path,
#         "-journal",
#         journal_path,
#     ]
 
#     result = subprocess.run(vivado_cmd, capture_output=True, text=True)
 
#     if result.returncode != 0 or "SYNTH_IMPL_DONE" not in result.stdout:
#         print("--- VIVADO SYNTH/IMPL FAILED ---")
#         print("Standard Output:")
#         print(result.stdout)
#         print("Standard Error:")
#         print(result.stderr)
#         print(f"See {log_path} for the full Vivado log.")
#         sys.exit(1)
 
#     # ------------------------------------------------------------------
#     # Read the metrics Tcl emitted on stdout.
#     # ------------------------------------------------------------------
#     metrics = _parse_metrics_from_stdout(result.stdout)
 
#     # Timing comes from the Design Timing Summary (same as the GUI panel),
#     # not from get_timing_paths, so the WNS matches the GUI exactly.
#     wns, tns, whs, ths = _parse_timing_summary(result.stdout)
 
#     # If the summary parse failed for any field, fall back to the text
#     # report on disk, then to any METRIC lines.
#     if wns is None or tns is None:
#         f_wns, f_tns, f_whs, f_ths = _parse_wns_tns_report(
#             os.path.join(out_dir, "post_route_timing.rpt")
#         )
#         wns = wns if wns is not None else f_wns
#         tns = tns if tns is not None else f_tns
#         whs = whs if whs is not None else f_whs
#         ths = ths if ths is not None else f_ths
 
#     # For utilization on Vivado 2018.3 the report_utilization text table is
#     # the authoritative source (matches the GUI's utilization panel exactly),
#     # so prefer it and fall back to the cell-count metrics only if parsing
#     # the report fails.
#     util_rpt = os.path.join(out_dir, "post_route_util.rpt")
#     r_luts, r_regs, r_dsps, r_bram = _parse_utilization(util_rpt)
 
#     luts = r_luts if r_luts is not None else metrics.get("luts")
#     registers = r_regs if r_regs is not None else metrics.get("registers")
#     dsps = r_dsps if r_dsps is not None else metrics.get("dsps")
#     bram_tiles = r_bram if r_bram is not None else metrics.get("bram_prims")
#     power_w = _parse_power(os.path.join(out_dir, "post_route_power.rpt"))
 
#     met_timing = (
#         wns is not None
#         and wns >= 0
#         and (ths is None or ths >= 0)
#     )
 
#     if __debug__:
#         status = "MET" if met_timing else "VIOLATED"
#         print(
#             f"Timing {status}: "
#             f"WNS={wns} ns, TNS={tns} ns, "
#             f"WHS={whs} ns, THS={ths} ns"
#         )
#         print(
#             f"Resources: LUTs={luts}, Registers={registers}, "
#             f"DSPs={dsps}, BRAM Tiles={bram_tiles}, Power={power_w} W"
#         )
#         print(f"Reports written to {out_dir}")
 
#     return {
#         "met_timing": met_timing,
#         "wns_ns": wns,
#         "tns_ns": tns,
#         "whs_ns": whs,
#         "ths_ns": ths,
#         "luts": luts,
#         "registers": registers,
#         "dsps": dsps,
#         "bram_tiles": bram_tiles,
#         "power_w": power_w,
#     }

# import itertools
# from datetime import datetime
# import csv
# import os

# # Assuming synthesize_and_implement and clean_data_folder are imported here

# if __name__ == "__main__":

#     print("Start Time:", datetime.now().strftime("%Y-%m-%d %H:%M:%S"))

#     # Define the parameter space
#     N = [256, 1024, 4096]
#     fft_types   = [0, 1] 
#     simple_mult = [0, 1]
#     fast_dsp    = [0]
#     carry_save  = [0]
#     bram        = [0, 1]

#     # Setup CSV logging
#     data = datetime.now().strftime("%Y-%m-%d_%H-%M-%S")
#     csv_file = f"../Perm_Data/synthesis_results_{data}.csv"
#     with open(csv_file, mode='w', newline='') as f:
#         writer = csv.writer(f)
#         # Write the CSV Header
#         writer.writerow(['N', 'Data_width', 'Tw_width', 'type_fft', 'SimpleMult', 'Fast_DSP', 'carry_save', 'Bram', 
#                          'LUTs', 'Registers', 'DSPs', 'BRAMs', 'WNS_ns', 'TNS_ns', 'Power_W'])

#     # Generate all combinations
#     combinations = itertools.product(N, fft_types, simple_mult, fast_dsp, carry_save, bram)

#     for combo in combinations:
#         c_N, c_type_fft, c_simple_mult, c_fast_dsp, c_carry_save, c_bram = combo
        
#         # 1. Skip conflicting configurations
#         if c_type_fft == 0 and c_bram == 1:
#             print(f"Skipping: N={c_N}, type_fft={c_type_fft}, Bram={c_bram} (Invalid: Radix-2 with Bram=1)")
#             continue  
#         if c_carry_save == 1 and c_bram == 1:
#             print(f"Skipping: N={c_N}, carry_save={c_carry_save}, Bram={c_bram} (Invalid: carry_save=1 with Bram=1)")
#             continue  
#         if c_carry_save == 1 and c_fast_dsp == 1:
#             print(f"Skipping: N={c_N}, carry_save={c_carry_save}, Fast_DSP={c_fast_dsp} (Invalid: carry_save=1 with Fast_DSP=1)")
#             continue  
#         # if c_carry_save == 0 and c_bram == 0 and c_type_fft == 1:
#         #     print(f"Skipping: N={c_N}, carry_save={c_carry_save}, Fast_DSP={c_fast_dsp} (Invalid: carry_save=0 with Fast_DSP=0 and type_fft=1)")
#         #     continue  

#         if c_type_fft == 0:
#             Data_width = 10
#         else:
#             Data_width = 11

#         Tw_width = 9  # Fixed for all configurations

#         # 2. Dynamically set Vivado macro flags (Fixed logic)
#         flag_no_dsp = (c_carry_save == 1) # If carry_save is 1, we don't want to use DSPs

#         flag_no_bram = (c_carry_save == 1 or c_bram == 0) # If carry_save is 1 or Bram is 0, we don't want to use BRAM

#         print("\n" + "="*130)
#         print(f"RUNNING: N={c_N} Data_width={Data_width} Tw_width={Tw_width} type_fft={c_type_fft} SimpleMult={c_simple_mult} Fast_DSP={c_fast_dsp} carry_save={c_carry_save} Bram={c_bram} no_dsp={flag_no_dsp} no_bram={flag_no_bram}")
#         print("="*130)

#         # 3. Try to run synthesis, catch any failures safely
#         try:
#             result = synthesize_and_implement(
#                 Data_width=Data_width,
#                 Tw_width=Tw_width,
#                 N=c_N,
#                 type_fft=c_type_fft,
#                 SimpleMult=c_simple_mult,
#                 Fast_DSP=c_fast_dsp,
#                 carry_save=c_carry_save,
#                 Bram=c_bram,
#                 bit_growth=1,
#                 output_pipeline_bram=1,
#                 part="xc7a200tfbg676-2",
#                 clock_period_ns=10,
#                 clock_port="clock",
#                 top="fft_top",
#                 out_dir="../Data/vivado_run",
#                 no_dsp=flag_no_dsp,
#                 no_bram=flag_no_bram
#             )

#             # Print Success to Console
#             print(f"\n===== VIVADO RESULTS =====")
#             print(f"LUTs       : {result.get('luts', 'N/A')}")
#             print(f"Registers  : {result.get('registers', 'N/A')}")
#             print(f"DSPs       : {result.get('dsps', 'N/A')}") 
#             print(f"BRAMs      : {result.get('bram_tiles', 'N/A')}")
#             print(f"WNS        : {result.get('wns_ns', 'N/A')} ns")
#             print(f"TNS        : {result.get('tns_ns', 'N/A')} ns")
#             print(f"Power      : {result.get('power_w', 'N/A')} W")
#             print(datetime.now().strftime("%Y-%m-%d %H:%M:%S"))

#             # Log Success to CSV
#             with open(csv_file, mode='a', newline='') as f:
#                 writer = csv.writer(f)
#                 writer.writerow([c_N, Data_width, Tw_width, c_type_fft, c_simple_mult, c_fast_dsp, c_carry_save, c_bram,
#                                  result.get('luts', ''), result.get('registers', ''),
#                                  result.get('dsps', ''), result.get('bram_tiles', ''),
#                                  result.get('wns_ns', ''), result.get('tns_ns', ''),
#                                  result.get('power_w', '')])

#         except (Exception, SystemExit) as e:
#             # Print Failure to Console
#             print(f"\n[!] FAIL: Synthesis crashed or called sys.exit()!")
            
#             # Log Failure to CSV
#             with open(csv_file, mode='a', newline='') as f:
#                 writer = csv.writer(f)
#                 writer.writerow([c_N, Data_width, Tw_width, c_type_fft, c_simple_mult, c_fast_dsp, c_carry_save, c_bram,
#                                  'FAIL', 'FAIL', 'FAIL', 'FAIL', 'FAIL', 'FAIL', 'FAIL'])

#     print("\nAll combinations processed. Results saved to:", csv_file)

# import numpy as np
# import math
# import subprocess
# import sys
# import os
# import shutil
# import re
# from datetime import datetime
 
# def clean_data_folder(folder_path="../Data"):
#     """
#     Deletes all files and subdirectories inside the specified folder.
#     """
#     # Convert to an absolute path to prevent accidental deletions in the wrong directory
#     abs_path = os.path.abspath(folder_path)
    
#     # Check if the folder actually exists before trying to clean it
#     if not os.path.exists(abs_path):
#         print(f"Folder not found: {abs_path}. Nothing to clean.")
#         # Optionally create it if you want it to always exist:
#         # os.makedirs(abs_path)
#         return
 
#     print(f"Cleaning folder: {abs_path}...")
    
#     # Loop through everything inside the folder
#     for item_name in os.listdir(abs_path):
#         item_path = os.path.join(abs_path, item_name)
        
#         try:
#             if os.path.isfile(item_path) or os.path.islink(item_path):
#                 os.unlink(item_path)  # Delete the file or link
#             elif os.path.isdir(item_path):
#                 shutil.rmtree(item_path)  # Delete the subdirectory and its contents
#         except Exception as e:
#             print(f"Failed to delete {item_path}. Reason: {e}")
            
#     print("Folder cleaned successfully!")
 
    
# def generate_twiddles(N, twiddle_width, type_fft=0, bit_growth=0):
#     stages = int(math.log2(N))
#     max_stage_num = twiddle_width + 1
#     Current_bits_stages = min(stages, max_stage_num)
#     bit_growth_stages = max(0, stages - max_stage_num)
 
#     k = np.arange(N)
#     twiddles = np.exp(-2j * np.pi * k / N)
 
#     real_file = lambda stage: f"../Data/f_twiddle_real_{stage}.mem"
#     imag_file = lambda stage: f"../Data/f_twiddle_imag_{stage}.mem"
 
#     # =========================================================================
#     # Fallback for No Bit Growth
#     # =========================================================================
#     # Calculate scaling once for the static width
#     fractional_bits = twiddle_width - 1
#     scale_factor = 1 << fractional_bits
#     min_val = -scale_factor
#     max_val = scale_factor - 1
#     mask = (1 << twiddle_width) - 1
 
#     twiddle_real = np.clip(twiddles.real * scale_factor, min_val, max_val).astype(int) & mask
#     twiddle_imag = np.clip(twiddles.imag * scale_factor, min_val, max_val).astype(int) & mask
 
#     for stage in range(1, stages + 1):
#         if (type_fft == 0): 
#             real_q = twiddle_real[0 : N // 2]
#             imag_q = twiddle_imag[0 : N // 2]
 
#             stride = (N // 2) // 2**(stage-1)
#             iter_count = 2**(stage-1)
 
#             temp_real = []
#             temp_imag = []
 
#             for j in range(0, iter_count):
#                 temp_real.append(real_q[stride*j])
#                 temp_imag.append(imag_q[stride*j])
 
#             hex_chars = (twiddle_width + 3) // 4
#             with open(real_file(stage), "w") as f_real:
#                 for value in temp_real:
#                     f_real.write(f"{value:0{hex_chars}X}\n")
 
#             with open(imag_file(stage), "w") as f_imag:
#                 for value in temp_imag:
#                     f_imag.write(f"{value:0{hex_chars}X}\n")
 
#     if __debug__:
#         print(f"Generated twiddles for {stages} stages.")
#         if bit_growth == 1:
#             print(f"Base width: {twiddle_width} bits. Max width: {twiddle_width + bit_growth_stages} bits.")
 
#     # Return the base twiddles for reference
#     return twiddles.real, twiddles.imag
 
# import math
 
 
# def generate_twiddle_pkg(N, src_dir, type_fft=0):
#     """
#     Generate twiddle_pkg.vh with ternary-macro file lookup trees.

#     type_fft = 0 : radix-2  -> log2(N) stages, ONE twiddle pair per stage
#                    macros:  GET_REAL_FILE(idx), GET_IMAG_FILE(idx)

#     type_fft = 1 : radix-4  -> log2(N)/2 stages, THREE twiddle pairs per
#                    stage (W^1, W^2, W^3)
#                    macros:  GET_REAL_FILE_1/2/3(idx)
#                             GET_IMAG_FILE_1/2/3(idx)
#     """
#     if type_fft == 0:
#         stages = int(math.log2(N))
#     elif type_fft == 1:
#         stages = int(math.log2(N)) // 2  # Radix-4 has half the number of stages
#     else:
#         raise ValueError(f"unknown type_fft: {type_fft}")

#     def build_macro(macro_name, path_fn):
#         """Build one ternary lookup tree mapping stage index -> filename."""
#         s = f"`define {macro_name}(idx) \\\n"
#         for stage in range(1, stages + 1):
#             s += f'    ((idx) == {stage-1}) ? "{path_fn(stage)}" : \\\n'
#         s += f'    "{path_fn(1)}"\n\n'  # Default fallback
#         return s

#     pkg_content = ""

#     if type_fft == 0:
#         # ---------------- Radix-2: one twiddle pair per stage -------------
#         real_file = lambda stage: f"../Data/f_twiddle_real_{stage}.mem"
#         imag_file = lambda stage: f"../Data/f_twiddle_imag_{stage}.mem"

#         pkg_content += build_macro("GET_REAL_FILE", real_file)
#         pkg_content += build_macro("GET_IMAG_FILE", imag_file)

#     else:
#         # ---------------- Radix-4: three twiddle pairs per stage ----------
#         # NOTE: these filename patterns must match exactly what
#         # generate_twiddles() writes for the radix-4 case.
#         # Order is stage first, then the twiddle index k (1,2,3).
#         real_file_r4 = lambda k: (
#             lambda stage: f"../Data/f_twiddle_real_{stage}_{k}.mem"
#         )
#         imag_file_r4 = lambda k: (
#             lambda stage: f"../Data/f_twiddle_imag_{stage}_{k}.mem"
#         )

#         for k in (1, 2, 3):
#             pkg_content += build_macro(f"GET_REAL_FILE_{k}", real_file_r4(k))
#             pkg_content += build_macro(f"GET_IMAG_FILE_{k}", imag_file_r4(k))

#     # Write to a header file
#     filepath = f"{src_dir}twiddle_pkg.vh"
#     with open(filepath, "w") as f:
#         f.write(pkg_content)

#     radix = "radix-2" if type_fft == 0 else "radix-4"
#     per_stage = 1 if type_fft == 0 else 3
#     print(
#         f"Generated {filepath} with ternary macros for {stages} {radix} "
#         f"stages ({per_stage} twiddle pair(s) per stage)."
#     )
 
 
# def _write_constraints(xdc_path, clock_port, clock_period_ns):
#     """Writes a minimal XDC with just a clock constraint."""
#     with open(xdc_path, "w") as f:
#         f.write(
#             f"create_clock -period {clock_period_ns} -name sys_clk "
#             f"[get_ports {{{clock_port}}}]\n"
#         )
 
 
# def _write_synth_impl_tcl(tcl_path, design_files, top, part, generics,
#                           xdc_path, out_dir, max_threads=8, max_dsp=-1, retiming=True, no_dsp=False):
#     """
#     Generates a Tcl script that runs synthesis and implementation and
#     produces timing and utilization reports.
#     """
#     generic_flags = " ".join(
#         f"-generic {{{name}={val}}}" for name, val in generics.items()
#     )
 
#     # Read commands replicate the GUI "No_fast" synth run exactly:
#     #   - twiddle_pkg.vh  -> plain read_verilog (NOT -sv)
#     #   - *.sv            -> read_verilog -sv
#     #   - *.v             -> plain read_verilog
#     #   - all in library xil_defaultlib
#     read_lines = []
#     for design_file in design_files:
#         if design_file.endswith(".sv"):
#             read_lines.append(
#                 f"read_verilog -library xil_defaultlib -sv {{{design_file}}}"
#             )
#         else:  # .v and .vh are read as plain Verilog
#             read_lines.append(
#                 f"read_verilog -library xil_defaultlib {{{design_file}}}"
#             )
 
#     read_block = "\n".join(read_lines)
 
#     # Only emit -max_dsp when the caller overrides the default (-1 = unlimited).
#     # Keeping it omitted at the default leaves the synth command byte-identical
#     # to the GUI's.
#     max_dsp_flag = "" if max_dsp == -1 else f" -max_dsp {max_dsp}"
#     retiming_flag = " -retiming" if retiming else ""
#     define_flag = " -verilog_define NO_DSP" if no_dsp else ""
 
#     tcl = f"""
# # ---- Auto-generated synth+impl script ----
# {read_block}
# read_xdc {{{xdc_path}}}
 
# # Number of threads for synth/place/route (2018.3 caps at 8).
# set_param general.maxThreads {max_threads}
 
# # ------------------------------------------------------------------
# # Synthesis -- matches the GUI "Vivado Synthesis Defaults" run exactly.
# # The GUI's generated command is simply:
# #     synth_design -top <top> -part <part> -retiming
# # The many strategy flags (flatten_hierarchy, fanout_limit, etc.) are
# # applied as internal DEFAULTS by that command; spelling them out
# # explicitly changes the result, so we do NOT add them here.
# # -max_dsp caps DSP usage: 0 = force everything to fabric (no DSPs),
# # N = at most N DSPs, -1 = unlimited (default, flag omitted so the
# # command stays byte-identical to the GUI's).
# # ------------------------------------------------------------------
# synth_design -top {top} -part {part} {generic_flags}{retiming_flag}{max_dsp_flag}{define_flag}
# write_checkpoint -force {out_dir}/post_synth.dcp
# report_utilization -file {out_dir}/post_synth_util.rpt
 
# # ------------------------------------------------------------------
# # Implementation -- replicates the GUI "Performance_ExtraTimingOpt"
# # strategy (impl_1) exactly:
# #   opt_design              directive Default   (enabled)
# #   power_opt_design                            (disabled)
# #   place_design            directive ExtraTimingOpt
# #   post_place_power_opt                        (disabled)
# #   phys_opt_design         directive Explore   (enabled, pre-route)
# #   route_design            directive NoTimingRelaxation
# #   post_route_phys_opt                         (disabled)
# # ------------------------------------------------------------------
# opt_design -directive Default
# place_design -directive ExtraTimingOpt
# phys_opt_design -directive Explore
# route_design -directive NoTimingRelaxation
# write_checkpoint -force {out_dir}/post_route.dcp
 
# # Human-readable reports (kept for manual inspection)
# report_timing_summary -file {out_dir}/post_route_timing.rpt
# report_utilization    -file {out_dir}/post_route_util.rpt
 
# # ------------------------------------------------------------------
# # Metrics for Vivado 2018.3.
# # Timing: read the four summary values straight off the timer via
# # report_timing_summary's return string is not stable in 2018.3, so we
# # use timer properties that DO exist in 2018.3.
# # Utilization: count cells by REF_NAME prefix (stable in 2018.3).
# # ------------------------------------------------------------------
 
# # --- Timing (2018.3-safe) ------------------------------------------
# # IMPORTANT: the GUI's WNS/TNS come from the Design Timing Summary in
# # report_timing_summary. get_timing_paths can report a different worst
# # path, so read the summary itself to match the GUI exactly.
# report_timing_summary -delay_type min_max -file {out_dir}/post_route_timing.rpt
 
# # Also emit the summary to stdout wrapped in markers so Python can grab
# # the exact same numbers the GUI shows.
# puts "TIMING_SUMMARY_BEGIN"
# report_timing_summary -delay_type min_max -no_detailed_paths
# puts "TIMING_SUMMARY_END"
 
# # --- Utilization (2018.3-safe, count by REF_NAME) ------------------
# set n_lut  [llength [get_cells -hier -filter {{REF_NAME =~ LUT*}}]]
# set n_reg  [llength [get_cells -hier -filter {{REF_NAME =~ FD* || REF_NAME =~ LD*}}]]
# set n_dsp  [llength [get_cells -hier -filter {{REF_NAME =~ DSP*}}]]
# set n_bram [llength [get_cells -hier -filter {{REF_NAME =~ RAMB*}}]]
# puts "METRIC luts=$n_lut"
# puts "METRIC registers=$n_reg"
# puts "METRIC dsps=$n_dsp"
# puts "METRIC bram_prims=$n_bram"
# report_power -file {out_dir}/post_route_power.rpt
# puts "SYNTH_IMPL_DONE"
# """
 
#     with open(tcl_path, "w") as f:
#         f.write(tcl)
 
# def _parse_power(power_rpt_path):
#     """Extract total on-chip power (W) from a Vivado report_power file."""
#     if not os.path.exists(power_rpt_path):
#         return None
#     with open(power_rpt_path, "r") as f:
#         text = f.read()
#     m = re.search(r"Total On-Chip Power\s*\(W\)\s*\|\s*([\d.]+)", text)
#     return float(m.group(1)) if m else None

# def _parse_metrics_from_stdout(stdout):
#     """
#     Pull the 'METRIC key=value' lines the Tcl script printed. These are the
#     authoritative values from Vivado's own timing/utilization engine, so they
#     match the GUI and don't depend on report text layout or part family.
#     """
#     metrics = {}
#     for m in re.finditer(r"METRIC\s+(\w+)=(\S+)", stdout):
#         key, val = m.group(1), m.group(2)
#         try:
#             f = float(val)
#             metrics[key] = int(f) if f.is_integer() else f
#         except ValueError:
#             metrics[key] = None  # Tcl printed empty / non-numeric
#     return metrics
 
 
# def _parse_timing_summary(stdout):
#     """
#     Parse WNS/TNS/WHS/THS from the Design Timing Summary that
#     report_timing_summary prints between the TIMING_SUMMARY markers.
#     This is the SAME table the Vivado GUI's timing panel shows, so the
#     WNS here matches the GUI's WNS exactly.
 
#     The 2018.3 summary looks like:
 
#         Design Timing Summary
#         ---------------------
#         WNS(ns)  TNS(ns)  TNS Failing Endpoints  TNS Total Endpoints  \
#         WHS(ns)  THS(ns)  ...
#         -------  -------  ---------------------  -------------------  ...
#         -0.060  -12.345                     42                 5000  \
#          0.031    0.000  ...
 
#     Returns (wns, tns, whs, ths), any of which may be None.
#     """
#     wns = tns = whs = ths = None
 
#     m = re.search(
#         r"TIMING_SUMMARY_BEGIN(.*?)TIMING_SUMMARY_END",
#         stdout,
#         re.DOTALL,
#     )
#     block = m.group(1) if m else stdout
 
#     # Locate the WNS(ns) ... THS(ns) header row, then take the first numeric
#     # values row after it. This is the Design Timing Summary the GUI shows.
#     header = re.search(r"WNS\(ns\).*?THS\(ns\)", block, re.DOTALL)
#     if header:
#         after = block[header.end():]
#         num = re.search(
#             r"(-?\d+\.\d+)\s+(-?\d+\.\d+)\s+\d+\s+\d+\s+"
#             r"(-?\d+\.\d+)\s+(-?\d+\.\d+)",
#             after,
#         )
#         if num:
#             wns = float(num.group(1))
#             tns = float(num.group(2))
#             whs = float(num.group(3))
#             ths = float(num.group(4))
 
#     return wns, tns, whs, ths
 
 
# def _parse_wns_tns_report(timing_rpt_path):
#     """Fallback: parse WNS/TNS/WHS/THS from the post_route_timing.rpt file."""
#     if not os.path.exists(timing_rpt_path):
#         return None, None, None, None
#     with open(timing_rpt_path, "r") as f:
#         text = f.read()
#     return _parse_timing_summary(text)
 
 
# def _parse_utilization(util_rpt_path):
#     """
#     Backup text parser, only used if the stdout METRIC lines are missing.
#     Handles BOTH 7-series ("Slice LUTs"/"Slice Registers") and UltraScale
#     ("CLB LUTs"/"CLB Registers") naming.
#     """
#     luts = registers = dsps = bram_tiles = None
#     if not os.path.exists(util_rpt_path):
#         return luts, registers, dsps, bram_tiles
 
#     with open(util_rpt_path, "r") as f:
#         text = f.read()
 
#     def find(*labels):
#         for label in labels:
#             m = re.search(
#                 r"\|\s*" + re.escape(label) + r"\s*\|\s*([\d,]+)\s*\|",
#                 text,
#             )
#             if m:
#                 return int(m.group(1).replace(",", ""))
#         return None
 
#     luts = find("Slice LUTs", "CLB LUTs")
#     registers = find("Slice Registers", "CLB Registers")
#     dsps = find("DSPs", "DSP48E1", "DSP48E2", "DSP48 Blocks")
#     bram_tiles = find("Block RAM Tile", "Block RAM Tiles")
#     return luts, registers, dsps, bram_tiles
 
 
# def synthesize_and_implement(
#     Data_width=16,
#     Tw_width=8,
#     N=256,
#     SimpleMult=0,
#     Fast_DSP=0,
#     carry_save=0,
#     Bram=1,
#     bit_growth=0,
#     part="xc7a200tfbg676-2",
#     clock_period_ns=2.5,
#     clock_port="clock",
#     top="fft_top",
#     out_dir="../Data/vivado_run",
#     max_threads=8,
#     max_dsp=-1,
#     retiming=True,
#     no_dsp=False
# ):
#     """
#     Runs Vivado synthesis and implementation in batch mode.
 
#     Returns a dictionary containing:
#         met_timing
#         wns_ns
#         tns_ns
#         whs_ns
#         ths_ns
#         luts
#         registers
#         dsps
#         bram_tiles
 
#     Resource values are taken from the post-route Vivado utilization report.
#     """
#     src_dir = "../Radix-2/"
#     os.makedirs(out_dir, exist_ok=True)
 
#     generate_twiddles(N, Tw_width, 0, bit_growth)
#     generate_twiddle_pkg(N, src_dir)
 
#     # File read order matches the GUI "No_fast" synth run:
#     #   stage_unit.sv, fft_radix_2_top.sv, Carry_mult.v, butterfly.v,
#     #   delay_buffer.v, delay_reg.v
#     # twiddle_pkg.vh is kept first because this flow generates it and the
#     # RTL includes it; the GUI project uses a committed copy instead.
#     design_files = [
#         f"{src_dir}twiddle_pkg.vh",
#         f"{src_dir}stage_unit.sv",
#         f"{src_dir}fft_radix_2_top.sv",
#         f"{src_dir}Carry_mult.v",
#         f"{src_dir}butterfly.v",
#         f"{src_dir}delay_buffer.v",
#         f"{src_dir}delay_reg.v",
#     ]
 
#     generics = {
#         "WIDTH": Data_width,
#         "Num_of_samples": N,
#         "Tw_WIDTH": Tw_width,
#         "SimpleMult": SimpleMult,
#         "Fast_DSP": Fast_DSP,
#         "carry_save": carry_save,
#         "Bram": Bram,
#         "bit_growth": bit_growth,
#     }
 
#     xdc_path = os.path.join(out_dir, "constraints.xdc")
#     tcl_path = os.path.join(out_dir, "synth_impl.tcl")
#     log_path = os.path.join(out_dir, "vivado.log")
#     journal_path = os.path.join(out_dir, "vivado.jou")
 
#     _write_constraints(xdc_path, clock_port, clock_period_ns)
#     _write_synth_impl_tcl(
#         tcl_path,
#         design_files,
#         top,
#         part,
#         generics,
#         xdc_path,
#         out_dir,
#         max_threads=max_threads,
#         max_dsp=max_dsp,
#         retiming=retiming,
#         no_dsp=no_dsp
#     )
 
#     if __debug__:
#         print(
#             f"Running Vivado synth+impl (part={part}, "
#             f"clock={clock_period_ns} ns)..."
#         )
    
    
#     vivado_cmd = [
#         "vivado",
#         "-mode",
#         "batch",
#         "-source",
#         tcl_path,
#         "-log",
#         log_path,
#         "-journal",
#         journal_path,
#     ]
 
#     result = subprocess.run(vivado_cmd, capture_output=True, text=True)
 
#     if result.returncode != 0 or "SYNTH_IMPL_DONE" not in result.stdout:
#         print("--- VIVADO SYNTH/IMPL FAILED ---")
#         print("Standard Output:")
#         print(result.stdout)
#         print("Standard Error:")
#         print(result.stderr)
#         print(f"See {log_path} for the full Vivado log.")
#         sys.exit(1)
 
#     # ------------------------------------------------------------------
#     # Read the metrics Tcl emitted on stdout.
#     # ------------------------------------------------------------------
#     metrics = _parse_metrics_from_stdout(result.stdout)
 
#     # Timing comes from the Design Timing Summary (same as the GUI panel),
#     # not from get_timing_paths, so the WNS matches the GUI exactly.
#     wns, tns, whs, ths = _parse_timing_summary(result.stdout)
 
#     # If the summary parse failed for any field, fall back to the text
#     # report on disk, then to any METRIC lines.
#     if wns is None or tns is None:
#         f_wns, f_tns, f_whs, f_ths = _parse_wns_tns_report(
#             os.path.join(out_dir, "post_route_timing.rpt")
#         )
#         wns = wns if wns is not None else f_wns
#         tns = tns if tns is not None else f_tns
#         whs = whs if whs is not None else f_whs
#         ths = ths if ths is not None else f_ths
 
#     # For utilization on Vivado 2018.3 the report_utilization text table is
#     # the authoritative source (matches the GUI's utilization panel exactly),
#     # so prefer it and fall back to the cell-count metrics only if parsing
#     # the report fails.
#     util_rpt = os.path.join(out_dir, "post_route_util.rpt")
#     r_luts, r_regs, r_dsps, r_bram = _parse_utilization(util_rpt)
 
#     luts = r_luts if r_luts is not None else metrics.get("luts")
#     registers = r_regs if r_regs is not None else metrics.get("registers")
#     dsps = r_dsps if r_dsps is not None else metrics.get("dsps")
#     bram_tiles = r_bram if r_bram is not None else metrics.get("bram_prims")
#     power_w = _parse_power(os.path.join(out_dir, "post_route_power.rpt"))
 
#     met_timing = (
#         wns is not None
#         and wns >= 0
#         and (ths is None or ths >= 0)
#     )
 
#     if __debug__:
#         status = "MET" if met_timing else "VIOLATED"
#         print(
#             f"Timing {status}: "
#             f"WNS={wns} ns, TNS={tns} ns, "
#             f"WHS={whs} ns, THS={ths} ns"
#         )
#         print(
#             f"Resources: LUTs={luts}, Registers={registers}, "
#             f"DSPs={dsps}, BRAM Tiles={bram_tiles}, Power={power_w} W"
#         )
#         print(f"Reports written to {out_dir}")
 
#     return {
#         "met_timing": met_timing,
#         "wns_ns": wns,
#         "tns_ns": tns,
#         "whs_ns": whs,
#         "ths_ns": ths,
#         "luts": luts,
#         "registers": registers,
#         "dsps": dsps,
#         "bram_tiles": bram_tiles,
#         "power_w": power_w,
#     }

# if __name__ == "__main__":

#     clean_data_folder("../Data")
#     print(datetime.now().strftime("%Y-%m-%d %H:%M:%S"))


#     result = synthesize_and_implement(
#         Data_width=16,
#         Tw_width=9,
#         N=256,
#         SimpleMult=0,
#         Fast_DSP=1,
#         carry_save=0,
#         Bram=0,
#         bit_growth=0,
#         part="xc7a200tfbg676-2",
#         clock_period_ns=2.5,
#         clock_port="clock",
#         top="fft_top",
#         out_dir="../Data/vivado_run"
#     )

#     print("\n===== VIVADO RESULTS =====")
#     print("Setting: SimpleMult=1, Fast_DSP=1, carry_save=0, Bram=0")
#     print(f"LUTs       : {result['luts']}")
#     print(f"Registers  : {result['registers']}")
#     print(f"DSPs       : {result['dsps']}")
#     print(f"BRAMs      : {result['bram_tiles']}")
#     print(f"WNS        : {result['wns_ns']} ns")
#     print(f"TNS        : {result['tns_ns']} ns")
#     print(f"Power      : {result['power_w']} W")
#     print(datetime.now().strftime("%Y-%m-%d %H:%M:%S"))

#     result = synthesize_and_implement(
#         Data_width=16,
#         Tw_width=9,
#         N=256,
#         SimpleMult=1,
#         Fast_DSP=0,
#         carry_save=1,
#         Bram=0,
#         bit_growth=0,
#         part="xc7a200tfbg676-2",
#         clock_period_ns=2.5,
#         clock_port="clock",
#         top="fft_top",
#         out_dir="../Data/vivado_run",
#         retiming=True,
#         no_dsp=True
#     )

#     print("\n===== VIVADO RESULTS =====")
#     print("Setting: SimpleMult=0, Fast_DSP=1, carry_save=0, Bram=0")
#     print(f"LUTs       : {result['luts']}")
#     print(f"Registers  : {result['registers']}")
#     print(f"DSPs       : {result['dsps']}")
#     print(f"BRAMs      : {result['bram_tiles']}")
#     print(f"WNS        : {result['wns_ns']} ns")
#     print(f"TNS        : {result['tns_ns']} ns")
#     print(f"Power      : {result['power_w']} W")
#     print(datetime.now().strftime("%Y-%m-%d %H:%M:%S"))


#     result = synthesize_and_implement(
#         Data_width=11,
#         Tw_width=9,
#         N=256,
#         SimpleMult=1,
#         Fast_DSP=0,
#         carry_save=1,
#         Bram=0,
#         bit_growth=1,
#         part="xc7a200tfbg676-2",
#         clock_period_ns=2.5,
#         clock_port="clock",
#         top="fft_top",
#         out_dir="../Data/vivado_run",
#         max_dsp=0,
#         retiming=True
#     )   

#     print("\n===== VIVADO RESULTS =====")
#     print("Setting: SimpleMult=1, Fast_DSP=0, carry_save=1, Bram=0")
#     print(f"LUTs       : {result['luts']}")
#     print(f"Registers  : {result['registers']}")
#     print(f"DSPs       : {result['dsps']}")
#     print(f"BRAMs      : {result['bram_tiles']}")
#     print(f"WNS        : {result['wns_ns']} ns")
#     print(f"TNS        : {result['tns_ns']} ns")
#     print(f"Power      : {result['power_w']} W")
#     print(datetime.now().strftime("%Y-%m-%d %H:%M:%S"))

#     result = synthesize_and_implement(
#         Data_width=11,
#         Tw_width=9,
#         N=256,
#         SimpleMult=0,
#         Fast_DSP=0,
#         carry_save=1,
#         Bram=0,
#         bit_growth=1,
#         part="xc7a200tfbg676-2",
#         clock_period_ns=2.5,
#         clock_port="clock",
#         top="fft_top",
#         out_dir="../Data/vivado_run",
#         max_dsp=0,
#         retiming=True
#     )

#     print("\n===== VIVADO RESULTS =====")
#     print("Setting: SimpleMult=0, Fast_DSP=0, carry_save=1, Bram=0")
#     print(f"LUTs       : {result['luts']}")
#     print(f"Registers  : {result['registers']}")
#     print(f"DSPs       : {result['dsps']}") 
#     print(f"BRAMs      : {result['bram_tiles']}")
#     print(f"WNS        : {result['wns_ns']} ns")
#     print(f"TNS        : {result['tns_ns']} ns")
#     print(f"Power      : {result['power_w']} W")
#     print(datetime.now().strftime("%Y-%m-%d %H:%M:%S"))

#     result = synthesize_and_implement(
#         Data_width=11,
#         Tw_width=9,
#         N=256,
#         SimpleMult=1,
#         Fast_DSP=0,
#         carry_save=0,
#         Bram=0,
#         bit_growth=1,
#         part="xc7a200tfbg676-2",
#         clock_period_ns=2.5,
#         clock_port="clock",
#         top="fft_top",
#         out_dir="../Data/vivado_run"
#     )

#     print("\n===== VIVADO RESULTS =====")
#     print("Setting: SimpleMult=1, Fast_DSP=0, carry_save=0, Bram=0")
#     print(f"LUTs       : {result['luts']}")
#     print(f"Registers  : {result['registers']}")
#     print(f"DSPs       : {result['dsps']}") 
#     print(f"BRAMs      : {result['bram_tiles']}")
#     print(f"WNS        : {result['wns_ns']} ns")
#     print(f"TNS        : {result['tns_ns']} ns")
#     print(f"Power      : {result['power_w']} W")
#     print(datetime.now().strftime("%Y-%m-%d %H:%M:%S"))

#     result = synthesize_and_implement(
#         Data_width=11,
#         Tw_width=9,
#         N=256,
#         SimpleMult=0,
#         Fast_DSP=0,
#         carry_save=0,
#         Bram=0,
#         bit_growth=1,
#         part="xc7a200tfbg676-2",
#         clock_period_ns=2.5,
#         clock_port="clock",
#         top="fft_top",
#         out_dir="../Data/vivado_run"
#     )

#     print("\n===== VIVADO RESULTS =====")
#     print("Setting: SimpleMult=0, Fast_DSP=0, carry_save=0, Bram=0")
#     print(f"LUTs       : {result['luts']}")
#     print(f"Registers  : {result['registers']}")
#     print(f"DSPs       : {result['dsps']}") 
#     print(f"BRAMs      : {result['bram_tiles']}")
#     print(f"WNS        : {result['wns_ns']} ns")
#     print(f"TNS        : {result['tns_ns']} ns")
#     print(f"Power      : {result['power_w']} W")
#     print(datetime.now().strftime("%Y-%m-%d %H:%M:%S"))

#     result = synthesize_and_implement(
#         Data_width=11,
#         Tw_width=9,
#         N=256,
#         SimpleMult=1,
#         Fast_DSP=0,
#         carry_save=0,
#         Bram=1,
#         bit_growth=1,
#         part="xc7a200tfbg676-2",
#         clock_period_ns=2.5,
#         clock_port="clock",
#         top="fft_top",
#         out_dir="../Data/vivado_run"
#     )

#     print("\n===== VIVADO RESULTS =====")
#     print("Setting: SimpleMult=1, Fast_DSP=0, carry_save=0, Bram=1")
#     print(f"LUTs       : {result['luts']}")
#     print(f"Registers  : {result['registers']}")
#     print(f"DSPs       : {result['dsps']}") 
#     print(f"BRAMs      : {result['bram_tiles']}")
#     print(f"WNS        : {result['wns_ns']} ns")
#     print(f"TNS        : {result['tns_ns']} ns")
#     print(f"Power      : {result['power_w']} W")
#     print(datetime.now().strftime("%Y-%m-%d %H:%M:%S"))

# import numpy as np
# import math
# import subprocess
# import sys
# import os
# import shutil
# import re
# from datetime import datetime
 
# def clean_data_folder(folder_path="../Data"):
#     """
#     Deletes all files and subdirectories inside the specified folder.
#     """
#     # Convert to an absolute path to prevent accidental deletions in the wrong directory
#     abs_path = os.path.abspath(folder_path)
    
#     # Check if the folder actually exists before trying to clean it
#     if not os.path.exists(abs_path):
#         print(f"Folder not found: {abs_path}. Nothing to clean.")
#         # Optionally create it if you want it to always exist:
#         # os.makedirs(abs_path)
#         return
 
#     print(f"Cleaning folder: {abs_path}...")
    
#     # Loop through everything inside the folder
#     for item_name in os.listdir(abs_path):
#         item_path = os.path.join(abs_path, item_name)
        
#         try:
#             if os.path.isfile(item_path) or os.path.islink(item_path):
#                 os.unlink(item_path)  # Delete the file or link
#             elif os.path.isdir(item_path):
#                 shutil.rmtree(item_path)  # Delete the subdirectory and its contents
#         except Exception as e:
#             print(f"Failed to delete {item_path}. Reason: {e}")
            
#     print("Folder cleaned successfully!")
 
    
# def generate_twiddles(N, twiddle_width, type_fft=0, bit_growth=0):
#     stages = int(math.log2(N))
#     max_stage_num = twiddle_width + 1
#     Current_bits_stages = min(stages, max_stage_num)
#     bit_growth_stages = max(0, stages - max_stage_num)
 
#     k = np.arange(N)
#     twiddles = np.exp(-2j * np.pi * k / N)
 
#     real_file = lambda stage: f"../Data/f_twiddle_real_{stage}.mem"
#     imag_file = lambda stage: f"../Data/f_twiddle_imag_{stage}.mem"
 
#     # =========================================================================
#     # Fallback for No Bit Growth
#     # =========================================================================
#     # Calculate scaling once for the static width
#     fractional_bits = twiddle_width - 1
#     scale_factor = 1 << fractional_bits
#     min_val = -scale_factor
#     max_val = scale_factor - 1
#     mask = (1 << twiddle_width) - 1
 
#     twiddle_real = np.clip(twiddles.real * scale_factor, min_val, max_val).astype(int) & mask
#     twiddle_imag = np.clip(twiddles.imag * scale_factor, min_val, max_val).astype(int) & mask
 
#     for stage in range(1, stages + 1):
#         if (type_fft == 0): 
#             real_q = twiddle_real[0 : N // 2]
#             imag_q = twiddle_imag[0 : N // 2]
 
#             stride = (N // 2) // 2**(stage-1)
#             iter_count = 2**(stage-1)
 
#             temp_real = []
#             temp_imag = []
 
#             for j in range(0, iter_count):
#                 temp_real.append(real_q[stride*j])
#                 temp_imag.append(imag_q[stride*j])
 
#             hex_chars = (twiddle_width + 3) // 4
#             with open(real_file(stage), "w") as f_real:
#                 for value in temp_real:
#                     f_real.write(f"{value:0{hex_chars}X}\n")
 
#             with open(imag_file(stage), "w") as f_imag:
#                 for value in temp_imag:
#                     f_imag.write(f"{value:0{hex_chars}X}\n")
 
#     if __debug__:
#         print(f"Generated twiddles for {stages} stages.")
#         if bit_growth == 1:
#             print(f"Base width: {twiddle_width} bits. Max width: {twiddle_width + bit_growth_stages} bits.")
 
#     # Return the base twiddles for reference
#     return twiddles.real, twiddles.imag
 
# import math
 
 
# def generate_twiddle_pkg(N, src_dir, type_fft=0):
#     """
#     Generate twiddle_pkg.vh with ternary-macro file lookup trees.

#     type_fft = 0 : radix-2  -> log2(N) stages, ONE twiddle pair per stage
#                    macros:  GET_REAL_FILE(idx), GET_IMAG_FILE(idx)

#     type_fft = 1 : radix-4  -> log2(N)/2 stages, THREE twiddle pairs per
#                    stage (W^1, W^2, W^3)
#                    macros:  GET_REAL_FILE_1/2/3(idx)
#                             GET_IMAG_FILE_1/2/3(idx)
#     """
#     if type_fft == 0:
#         stages = int(math.log2(N))
#     elif type_fft == 1:
#         stages = int(math.log2(N)) // 2  # Radix-4 has half the number of stages
#     else:
#         raise ValueError(f"unknown type_fft: {type_fft}")

#     def build_macro(macro_name, path_fn):
#         """Build one ternary lookup tree mapping stage index -> filename."""
#         s = f"`define {macro_name}(idx) \\\n"
#         for stage in range(1, stages + 1):
#             s += f'    ((idx) == {stage-1}) ? "{path_fn(stage)}" : \\\n'
#         s += f'    "{path_fn(1)}"\n\n'  # Default fallback
#         return s

#     pkg_content = ""

#     if type_fft == 0:
#         # ---------------- Radix-2: one twiddle pair per stage -------------
#         real_file = lambda stage: f"../Data/f_twiddle_real_{stage}.mem"
#         imag_file = lambda stage: f"../Data/f_twiddle_imag_{stage}.mem"

#         pkg_content += build_macro("GET_REAL_FILE", real_file)
#         pkg_content += build_macro("GET_IMAG_FILE", imag_file)

#     else:
#         # ---------------- Radix-4: three twiddle pairs per stage ----------
#         # NOTE: these filename patterns must match exactly what
#         # generate_twiddles() writes for the radix-4 case.
#         # Order is stage first, then the twiddle index k (1,2,3).
#         real_file_r4 = lambda k: (
#             lambda stage: f"../Data/f_twiddle_real_{stage}_{k}.mem"
#         )
#         imag_file_r4 = lambda k: (
#             lambda stage: f"../Data/f_twiddle_imag_{stage}_{k}.mem"
#         )

#         for k in (1, 2, 3):
#             pkg_content += build_macro(f"GET_REAL_FILE_{k}", real_file_r4(k))
#             pkg_content += build_macro(f"GET_IMAG_FILE_{k}", imag_file_r4(k))

#     # Write to a header file
#     filepath = f"{src_dir}twiddle_pkg.vh"
#     with open(filepath, "w") as f:
#         f.write(pkg_content)

#     radix = "radix-2" if type_fft == 0 else "radix-4"
#     per_stage = 1 if type_fft == 0 else 3
#     print(
#         f"Generated {filepath} with ternary macros for {stages} {radix} "
#         f"stages ({per_stage} twiddle pair(s) per stage)."
#     )
 
 
# def _write_constraints(xdc_path, clock_port, clock_period_ns):
#     """Writes a minimal XDC with just a clock constraint."""
#     with open(xdc_path, "w") as f:
#         f.write(
#             f"create_clock -period {clock_period_ns} -name sys_clk "
#             f"[get_ports {{{clock_port}}}]\n"
#         )
 
 
# def _write_synth_impl_tcl(tcl_path, design_files, top, part, generics,
#                           xdc_path, out_dir, max_threads=8, max_dsp=-1, retiming=True, no_dsp=False, no_bram=False):
#     """
#     Generates a Tcl script that runs synthesis and implementation and
#     produces timing and utilization reports.
#     """
#     generic_flags = " ".join(
#         f"-generic {{{name}={val}}}" for name, val in generics.items()
#     )
 
#     # Read commands replicate the GUI "No_fast" synth run exactly:
#     #   - twiddle_pkg.vh  -> plain read_verilog (NOT -sv)
#     #   - *.sv            -> read_verilog -sv
#     #   - *.v             -> plain read_verilog
#     #   - all in library xil_defaultlib
#     read_lines = []
#     for design_file in design_files:
#         if design_file.endswith(".sv"):
#             read_lines.append(
#                 f"read_verilog -library xil_defaultlib -sv {{{design_file}}}"
#             )
#         else:  # .v and .vh are read as plain Verilog
#             read_lines.append(
#                 f"read_verilog -library xil_defaultlib {{{design_file}}}"
#             )
 
#     read_block = "\n".join(read_lines)
 
#     # Only emit -max_dsp when the caller overrides the default (-1 = unlimited).
#     # Keeping it omitted at the default leaves the synth command byte-identical
#     # to the GUI's.
#     max_dsp_flag = "" if max_dsp == -1 else f" -max_dsp {max_dsp}"
#     retiming_flag = " -retiming" if retiming else ""
#     define_flag = " -verilog_define NO_DSP" if no_dsp else ""
#     define_flag_2 = " -verilog_define NO_BRAM" if no_bram else ""
 
#     tcl = f"""
# # ---- Auto-generated synth+impl script ----
# {read_block}
# read_xdc {{{xdc_path}}}
 
# # Number of threads for synth/place/route (2018.3 caps at 8).
# set_param general.maxThreads {max_threads}
 
# # ------------------------------------------------------------------
# # Synthesis -- matches the GUI "Vivado Synthesis Defaults" run exactly.
# # The GUI's generated command is simply:
# #     synth_design -top <top> -part <part> -retiming
# # The many strategy flags (flatten_hierarchy, fanout_limit, etc.) are
# # applied as internal DEFAULTS by that command; spelling them out
# # explicitly changes the result, so we do NOT add them here.
# # -max_dsp caps DSP usage: 0 = force everything to fabric (no DSPs),
# # N = at most N DSPs, -1 = unlimited (default, flag omitted so the
# # command stays byte-identical to the GUI's).
# # ------------------------------------------------------------------
# synth_design -top {top} -part {part} {generic_flags}{retiming_flag}{max_dsp_flag}{define_flag}{define_flag_2}
# write_checkpoint -force {out_dir}/post_synth.dcp
# report_utilization -file {out_dir}/post_synth_util.rpt
 
# # ------------------------------------------------------------------
# # Implementation -- replicates the GUI "Performance_ExtraTimingOpt"
# # strategy (impl_1) exactly:
# #   opt_design              directive Default   (enabled)
# #   power_opt_design                            (disabled)
# #   place_design            directive ExtraTimingOpt
# #   post_place_power_opt                        (disabled)
# #   phys_opt_design         directive Explore   (enabled, pre-route)
# #   route_design            directive NoTimingRelaxation
# #   post_route_phys_opt                         (disabled)
# # ------------------------------------------------------------------
# opt_design -directive Default
# place_design -directive ExtraTimingOpt
# phys_opt_design -directive Explore
# route_design -directive NoTimingRelaxation
# write_checkpoint -force {out_dir}/post_route.dcp
 
# # Human-readable reports (kept for manual inspection)
# report_timing_summary -file {out_dir}/post_route_timing.rpt
# report_utilization    -file {out_dir}/post_route_util.rpt
 
# # ------------------------------------------------------------------
# # Metrics for Vivado 2018.3.
# # Timing: read the four summary values straight off the timer via
# # report_timing_summary's return string is not stable in 2018.3, so we
# # use timer properties that DO exist in 2018.3.
# # Utilization: count cells by REF_NAME prefix (stable in 2018.3).
# # ------------------------------------------------------------------
 
# # --- Timing (2018.3-safe) ------------------------------------------
# # IMPORTANT: the GUI's WNS/TNS come from the Design Timing Summary in
# # report_timing_summary. get_timing_paths can report a different worst
# # path, so read the summary itself to match the GUI exactly.
# report_timing_summary -delay_type min_max -file {out_dir}/post_route_timing.rpt
 
# # Also emit the summary to stdout wrapped in markers so Python can grab
# # the exact same numbers the GUI shows.
# puts "TIMING_SUMMARY_BEGIN"
# report_timing_summary -delay_type min_max -no_detailed_paths
# puts "TIMING_SUMMARY_END"
 
# # --- Utilization (2018.3-safe, count by REF_NAME) ------------------
# set n_lut  [llength [get_cells -hier -filter {{REF_NAME =~ LUT*}}]]
# set n_reg  [llength [get_cells -hier -filter {{REF_NAME =~ FD* || REF_NAME =~ LD*}}]]
# set n_dsp  [llength [get_cells -hier -filter {{REF_NAME =~ DSP*}}]]
# set n_bram [llength [get_cells -hier -filter {{REF_NAME =~ RAMB*}}]]
# puts "METRIC luts=$n_lut"
# puts "METRIC registers=$n_reg"
# puts "METRIC dsps=$n_dsp"
# puts "METRIC bram_prims=$n_bram"
# report_power -file {out_dir}/post_route_power.rpt
# puts "SYNTH_IMPL_DONE"
# """
 
#     with open(tcl_path, "w") as f:
#         f.write(tcl)
 
# def _parse_power(power_rpt_path):
#     """Extract total on-chip power (W) from a Vivado report_power file."""
#     if not os.path.exists(power_rpt_path):
#         return None
#     with open(power_rpt_path, "r") as f:
#         text = f.read()
#     m = re.search(r"Total On-Chip Power\s*\(W\)\s*\|\s*([\d.]+)", text)
#     return float(m.group(1)) if m else None

# def _parse_metrics_from_stdout(stdout):
#     """
#     Pull the 'METRIC key=value' lines the Tcl script printed. These are the
#     authoritative values from Vivado's own timing/utilization engine, so they
#     match the GUI and don't depend on report text layout or part family.
#     """
#     metrics = {}
#     for m in re.finditer(r"METRIC\s+(\w+)=(\S+)", stdout):
#         key, val = m.group(1), m.group(2)
#         try:
#             f = float(val)
#             metrics[key] = int(f) if f.is_integer() else f
#         except ValueError:
#             metrics[key] = None  # Tcl printed empty / non-numeric
#     return metrics
 
 
# def _parse_timing_summary(stdout):
#     """
#     Parse WNS/TNS/WHS/THS from the Design Timing Summary that
#     report_timing_summary prints between the TIMING_SUMMARY markers.
#     This is the SAME table the Vivado GUI's timing panel shows, so the
#     WNS here matches the GUI's WNS exactly.
 
#     The 2018.3 summary looks like:
 
#         Design Timing Summary
#         ---------------------
#         WNS(ns)  TNS(ns)  TNS Failing Endpoints  TNS Total Endpoints  \
#         WHS(ns)  THS(ns)  ...
#         -------  -------  ---------------------  -------------------  ...
#         -0.060  -12.345                     42                 5000  \
#          0.031    0.000  ...
 
#     Returns (wns, tns, whs, ths), any of which may be None.
#     """
#     wns = tns = whs = ths = None
 
#     m = re.search(
#         r"TIMING_SUMMARY_BEGIN(.*?)TIMING_SUMMARY_END",
#         stdout,
#         re.DOTALL,
#     )
#     block = m.group(1) if m else stdout
 
#     # Locate the WNS(ns) ... THS(ns) header row, then take the first numeric
#     # values row after it. This is the Design Timing Summary the GUI shows.
#     header = re.search(r"WNS\(ns\).*?THS\(ns\)", block, re.DOTALL)
#     if header:
#         after = block[header.end():]
#         num = re.search(
#             r"(-?\d+\.\d+)\s+(-?\d+\.\d+)\s+\d+\s+\d+\s+"
#             r"(-?\d+\.\d+)\s+(-?\d+\.\d+)",
#             after,
#         )
#         if num:
#             wns = float(num.group(1))
#             tns = float(num.group(2))
#             whs = float(num.group(3))
#             ths = float(num.group(4))
 
#     return wns, tns, whs, ths
 
 
# def _parse_wns_tns_report(timing_rpt_path):
#     """Fallback: parse WNS/TNS/WHS/THS from the post_route_timing.rpt file."""
#     if not os.path.exists(timing_rpt_path):
#         return None, None, None, None
#     with open(timing_rpt_path, "r") as f:
#         text = f.read()
#     return _parse_timing_summary(text)
 
 
# def _parse_utilization(util_rpt_path):
#     """
#     Backup text parser, only used if the stdout METRIC lines are missing.
#     Handles BOTH 7-series ("Slice LUTs"/"Slice Registers") and UltraScale
#     ("CLB LUTs"/"CLB Registers") naming.
#     """
#     luts = registers = dsps = bram_tiles = None
#     if not os.path.exists(util_rpt_path):
#         return luts, registers, dsps, bram_tiles
 
#     with open(util_rpt_path, "r") as f:
#         text = f.read()
 
#     def find(*labels):
#         for label in labels:
#             m = re.search(
#                 r"\|\s*" + re.escape(label) + r"\s*\|\s*([\d,]+)\s*\|",
#                 text,
#             )
#             if m:
#                 return int(m.group(1).replace(",", ""))
#         return None
 
#     luts = find("Slice LUTs", "CLB LUTs")
#     registers = find("Slice Registers", "CLB Registers")
#     dsps = find("DSPs", "DSP48E1", "DSP48E2", "DSP48 Blocks")
#     bram_tiles = find("Block RAM Tile", "Block RAM Tiles")
#     return luts, registers, dsps, bram_tiles
 
 
# def synthesize_and_implement(
#     Data_width=16,
#     Tw_width=8,
#     N=256,
#     type_fft=0,
#     SimpleMult=0,
#     Fast_DSP=0,
#     carry_save=0,
#     Bram=1,
#     bit_growth=0,
#     output_pipeline_bram=0,
#     part="xc7a200tfbg676-2",
#     clock_period_ns=2.5,
#     clock_port="clock",
#     top=None,
#     out_dir="../Data/vivado_run",
#     max_threads=8,
#     max_dsp=-1,
#     retiming=True,
#     no_dsp=False,
#     no_bram=False
# ):
#     """
#     Runs Vivado synthesis and implementation in batch mode.

#     type_fft: 0 = radix-2 (files in ../Radix-2/), 1 = radix-4 (files in
#     ../Radix-4/). output_pipeline_bram only applies to radix-4 (mirrors
#     the parameter compile_simulation_verilator/xsim already expose for it).
 
#     Returns a dictionary containing:
#         met_timing
#         wns_ns
#         tns_ns
#         whs_ns
#         ths_ns
#         luts
#         registers
#         dsps
#         bram_tiles
 
#     Resource values are taken from the post-route Vivado utilization report.
#     """
#     if type_fft == 0:
#         src_dir = "../Radix-2/"
#     elif type_fft == 1:
#         src_dir = "../Radix-4/"
#     else:
#         raise ValueError(f"unknown type_fft: {type_fft}")

#     os.makedirs(out_dir, exist_ok=True)
 
#     #generate_twiddles(N, Tw_width, type_fft, bit_growth)
#     generate_twiddle_pkg(N, src_dir, type_fft)
 
#     if type_fft == 0:
#         # File read order matches the GUI "No_fast" synth run:
#         #   stage_unit.sv, fft_radix_2_top.sv, Carry_mult.v, butterfly.v,
#         #   delay_buffer.v, delay_reg.v
#         # twiddle_pkg.vh is kept first because this flow generates it and the
#         # RTL includes it; the GUI project uses a committed copy instead.
#         design_files = [
#             f"{src_dir}twiddle_pkg.vh",
#             f"{src_dir}stage_unit.sv",
#             f"{src_dir}fft_radix_2_top.sv",
#             f"{src_dir}Carry_mult.v",
#             f"{src_dir}butterfly.v",
#             f"{src_dir}delay_buffer.v",
#             f"{src_dir}delay_reg.v",
#         ]

#         generics = {
#             "WIDTH": Data_width,
#             "Num_of_samples": N,
#             "Tw_WIDTH": Tw_width,
#             "SimpleMult": SimpleMult,
#             "Fast_DSP": Fast_DSP,
#             "carry_save": carry_save,
#             "Bram": Bram,
#             "bit_growth": bit_growth,
#         }
#     else:
#         # Same design (non-testbench) files as the radix-4 XSIM/Verilator
#         # sim build in FFT_softaware.py's compile_simulation_verilator/xsim
#         # (tb_top_radix_4.v dropped, memory.v used instead of
#         # delay_buffer.v, twiddle_pkg.vh added since synth needs the
#         # generated twiddle-file macros the RTL includes).
#         design_files = [
#             # f"{src_dir}twiddle_pkg.vh",
#             f"{src_dir}stage_unit.sv",
#             f"{src_dir}fft_radix_4_top.sv",
#             f"{src_dir}Carry_mult.v",
#             f"{src_dir}butterfly.v",
#             f"{src_dir}memory.v",
#             f"{src_dir}delay_reg.v",
#         ]

#         generics = {
#             "WIDTH": Data_width,
#             "Num_of_samples": N,
#             "Tw_WIDTH": Tw_width,
#             "SimpleMult": SimpleMult,
#             "Fast_DSP": Fast_DSP,
#             "carry_save": carry_save,
#             "Bram": Bram,
#             "output_pipeline_bram": output_pipeline_bram,
#             "bit_growth": bit_growth,
#         }

#     # Default top-module name kept as "fft_top" for both radices (matches
#     # the value this function already used for radix-2) -- override with
#     # top=... if your radix-4 top-level module is actually named
#     # differently (e.g. "fft_radix_4_top").
#     top_module = top if top is not None else "fft_top"
 
#     xdc_path = os.path.join(out_dir, "constraints.xdc")
#     tcl_path = os.path.join(out_dir, "synth_impl.tcl")
#     log_path = os.path.join(out_dir, "vivado.log")
#     journal_path = os.path.join(out_dir, "vivado.jou")
 
#     _write_constraints(xdc_path, clock_port, clock_period_ns)
#     _write_synth_impl_tcl(
#         tcl_path,
#         design_files,
#         top_module,
#         part,
#         generics,
#         xdc_path,
#         out_dir,
#         max_threads=max_threads,
#         max_dsp=max_dsp,
#         retiming=retiming,
#         no_dsp=no_dsp,
#         no_bram=no_bram
#     )
 
#     if __debug__:
#         print(
#             f"Running Vivado synth+impl (part={part}, "
#             f"clock={clock_period_ns} ns)..."
#         )
    
    
#     vivado_cmd = [
#         "vivado",
#         "-mode",
#         "batch",
#         "-source",
#         tcl_path,
#         "-log",
#         log_path,
#         "-journal",
#         journal_path,
#     ]
 
#     result = subprocess.run(vivado_cmd, capture_output=True, text=True)
 
#     if result.returncode != 0 or "SYNTH_IMPL_DONE" not in result.stdout:
#         print("--- VIVADO SYNTH/IMPL FAILED ---")
#         print("Standard Output:")
#         print(result.stdout)
#         print("Standard Error:")
#         print(result.stderr)
#         print(f"See {log_path} for the full Vivado log.")
#         sys.exit(1)
 
#     # ------------------------------------------------------------------
#     # Read the metrics Tcl emitted on stdout.
#     # ------------------------------------------------------------------
#     metrics = _parse_metrics_from_stdout(result.stdout)
 
#     # Timing comes from the Design Timing Summary (same as the GUI panel),
#     # not from get_timing_paths, so the WNS matches the GUI exactly.
#     wns, tns, whs, ths = _parse_timing_summary(result.stdout)
 
#     # If the summary parse failed for any field, fall back to the text
#     # report on disk, then to any METRIC lines.
#     if wns is None or tns is None:
#         f_wns, f_tns, f_whs, f_ths = _parse_wns_tns_report(
#             os.path.join(out_dir, "post_route_timing.rpt")
#         )
#         wns = wns if wns is not None else f_wns
#         tns = tns if tns is not None else f_tns
#         whs = whs if whs is not None else f_whs
#         ths = ths if ths is not None else f_ths
 
#     # For utilization on Vivado 2018.3 the report_utilization text table is
#     # the authoritative source (matches the GUI's utilization panel exactly),
#     # so prefer it and fall back to the cell-count metrics only if parsing
#     # the report fails.
#     util_rpt = os.path.join(out_dir, "post_route_util.rpt")
#     r_luts, r_regs, r_dsps, r_bram = _parse_utilization(util_rpt)
 
#     luts = r_luts if r_luts is not None else metrics.get("luts")
#     registers = r_regs if r_regs is not None else metrics.get("registers")
#     dsps = r_dsps if r_dsps is not None else metrics.get("dsps")
#     bram_tiles = r_bram if r_bram is not None else metrics.get("bram_prims")
#     power_w = _parse_power(os.path.join(out_dir, "post_route_power.rpt"))
 
#     met_timing = (
#         wns is not None
#         and wns >= 0
#         and (ths is None or ths >= 0)
#     )
 
#     if __debug__:
#         status = "MET" if met_timing else "VIOLATED"
#         print(
#             f"Timing {status}: "
#             f"WNS={wns} ns, TNS={tns} ns, "
#             f"WHS={whs} ns, THS={ths} ns"
#         )
#         print(
#             f"Resources: LUTs={luts}, Registers={registers}, "
#             f"DSPs={dsps}, BRAM Tiles={bram_tiles}, Power={power_w} W"
#         )
#         print(f"Reports written to {out_dir}")
 
#     return {
#         "met_timing": met_timing,
#         "wns_ns": wns,
#         "tns_ns": tns,
#         "whs_ns": whs,
#         "ths_ns": ths,
#         "luts": luts,
#         "registers": registers,
#         "dsps": dsps,
#         "bram_tiles": bram_tiles,
#         "power_w": power_w,
#     }

# import itertools
# from datetime import datetime
# import csv
# import os

# # Assuming synthesize_and_implement and clean_data_folder are imported here

# if __name__ == "__main__":

#     print("Start Time:", datetime.now().strftime("%Y-%m-%d %H:%M:%S"))

#     # Define the parameter space
#     N = [256, 1024, 4096]
#     fft_types   = [0, 1] 
#     simple_mult = [0, 1]
#     fast_dsp    = [0]
#     carry_save  = [0]
#     bram        = [0, 1]

#     # Setup CSV logging
#     data = datetime.now().strftime("%Y-%m-%d_%H-%M-%S")
#     csv_file = f"../Perm_Data/synthesis_results_{data}.csv"
#     with open(csv_file, mode='w', newline='') as f:
#         writer = csv.writer(f)
#         # Write the CSV Header
#         writer.writerow(['N', 'Data_width', 'Tw_width', 'type_fft', 'SimpleMult', 'Fast_DSP', 'carry_save', 'Bram', 
#                          'LUTs', 'Registers', 'DSPs', 'BRAMs', 'WNS_ns', 'TNS_ns', 'Power_W'])

#     # Generate all combinations
#     combinations = itertools.product(N, fft_types, simple_mult, fast_dsp, carry_save, bram)

#     for combo in combinations:
#         c_N, c_type_fft, c_simple_mult, c_fast_dsp, c_carry_save, c_bram = combo
        
#         # 1. Skip conflicting configurations
#         if c_type_fft == 0 and c_bram == 1:
#             print(f"Skipping: N={c_N}, type_fft={c_type_fft}, Bram={c_bram} (Invalid: Radix-2 with Bram=1)")
#             continue  
#         if c_carry_save == 1 and c_bram == 1:
#             print(f"Skipping: N={c_N}, carry_save={c_carry_save}, Bram={c_bram} (Invalid: carry_save=1 with Bram=1)")
#             continue  
#         if c_carry_save == 1 and c_fast_dsp == 1:
#             print(f"Skipping: N={c_N}, carry_save={c_carry_save}, Fast_DSP={c_fast_dsp} (Invalid: carry_save=1 with Fast_DSP=1)")
#             continue  
#         # if c_carry_save == 0 and c_bram == 0 and c_type_fft == 1:
#         #     print(f"Skipping: N={c_N}, carry_save={c_carry_save}, Fast_DSP={c_fast_dsp} (Invalid: carry_save=0 with Fast_DSP=0 and type_fft=1)")
#         #     continue  

#         if c_type_fft == 0:
#             Data_width = 10
#         else:
#             Data_width = 11

#         Tw_width = 9  # Fixed for all configurations

#         # 2. Dynamically set Vivado macro flags (Fixed logic)
#         flag_no_dsp = (c_carry_save == 1) # If carry_save is 1, we don't want to use DSPs

#         flag_no_bram = (c_carry_save == 1 or c_bram == 0) # If carry_save is 1 or Bram is 0, we don't want to use BRAM

#         print("\n" + "="*130)
#         print(f"RUNNING: N={c_N} Data_width={Data_width} Tw_width={Tw_width} type_fft={c_type_fft} SimpleMult={c_simple_mult} Fast_DSP={c_fast_dsp} carry_save={c_carry_save} Bram={c_bram} no_dsp={flag_no_dsp} no_bram={flag_no_bram}")
#         print("="*130)

#         # 3. Try to run synthesis, catch any failures safely
#         try:
#             result = synthesize_and_implement(
#                 Data_width=Data_width,
#                 Tw_width=Tw_width,
#                 N=c_N,
#                 type_fft=c_type_fft,
#                 SimpleMult=c_simple_mult,
#                 Fast_DSP=c_fast_dsp,
#                 carry_save=c_carry_save,
#                 Bram=c_bram,
#                 bit_growth=1,
#                 output_pipeline_bram=1,
#                 part="xc7a200tfbg676-2",
#                 clock_period_ns=10,
#                 clock_port="clock",
#                 top="fft_top",
#                 out_dir="../Data/vivado_run",
#                 no_dsp=flag_no_dsp,
#                 no_bram=flag_no_bram
#             )

#             # Print Success to Console
#             print(f"\n===== VIVADO RESULTS =====")
#             print(f"LUTs       : {result.get('luts', 'N/A')}")
#             print(f"Registers  : {result.get('registers', 'N/A')}")
#             print(f"DSPs       : {result.get('dsps', 'N/A')}") 
#             print(f"BRAMs      : {result.get('bram_tiles', 'N/A')}")
#             print(f"WNS        : {result.get('wns_ns', 'N/A')} ns")
#             print(f"TNS        : {result.get('tns_ns', 'N/A')} ns")
#             print(f"Power      : {result.get('power_w', 'N/A')} W")
#             print(datetime.now().strftime("%Y-%m-%d %H:%M:%S"))

#             # Log Success to CSV
#             with open(csv_file, mode='a', newline='') as f:
#                 writer = csv.writer(f)
#                 writer.writerow([c_N, Data_width, Tw_width, c_type_fft, c_simple_mult, c_fast_dsp, c_carry_save, c_bram,
#                                  result.get('luts', ''), result.get('registers', ''),
#                                  result.get('dsps', ''), result.get('bram_tiles', ''),
#                                  result.get('wns_ns', ''), result.get('tns_ns', ''),
#                                  result.get('power_w', '')])

#         except (Exception, SystemExit) as e:
#             # Print Failure to Console
#             print(f"\n[!] FAIL: Synthesis crashed or called sys.exit()!")
            
#             # Log Failure to CSV
#             with open(csv_file, mode='a', newline='') as f:
#                 writer = csv.writer(f)
#                 writer.writerow([c_N, Data_width, Tw_width, c_type_fft, c_simple_mult, c_fast_dsp, c_carry_save, c_bram,
#                                  'FAIL', 'FAIL', 'FAIL', 'FAIL', 'FAIL', 'FAIL', 'FAIL'])

#     print("\nAll combinations processed. Results saved to:", csv_file)

import numpy as np
import math
import subprocess
import sys
import os
import itertools
import shutil
import re
from datetime import datetime
 
def clean_data_folder(folder_path="../Data"):
    """
    Deletes all files and subdirectories inside the specified folder.
    """
    # Convert to an absolute path to prevent accidental deletions in the wrong directory
    abs_path = os.path.abspath(folder_path)
    
    # Check if the folder actually exists before trying to clean it
    if not os.path.exists(abs_path):
        print(f"Folder not found: {abs_path}. Nothing to clean.")
        # Optionally create it if you want it to always exist:
        # os.makedirs(abs_path)
        return
 
    print(f"Cleaning folder: {abs_path}...")
    
    # Loop through everything inside the folder
    for item_name in os.listdir(abs_path):
        item_path = os.path.join(abs_path, item_name)
        
        try:
            if os.path.isfile(item_path) or os.path.islink(item_path):
                os.unlink(item_path)  # Delete the file or link
            elif os.path.isdir(item_path):
                shutil.rmtree(item_path)  # Delete the subdirectory and its contents
        except Exception as e:
            print(f"Failed to delete {item_path}. Reason: {e}")
            
    print("Folder cleaned successfully!")
 
    
# ===========================================================================
# CSHM (shift-and-add) encoder
#
# Encodes each twiddle constant as a packed instruction word instead of a
# numeric value, so the hardware multiplies with shifts and adds and needs
# no DSPs. Word layout, slot 0 in the MSBs:
#
#     [ alpha_idx : alpha_bits ][ sign : 1 ][ shift : shift_bits ] x num_slots
#
# cshm_2_keys in the RTL decodes exactly one configuration:
#     alphabets=4 (2-bit index over {1,3,5,7}), num_slots=2, shift_bits=4
# giving a 14-bit key. Other settings need the RTL mux widened.
# ===========================================================================

class CSHMEncoder:
    def __init__(self, bit_width, alphabets=4, num_slots=2, tolerance_per=0.005,
                 max_magnitude=None, allow_nearest=False):
        if isinstance(alphabets, int):
            if alphabets <= 0:
                raise ValueError("alphabets must be > 0")
            alphabets = [2 * n + 1 for n in range(alphabets)]
        self.alphabets = list(alphabets)
        self.bit_width = bit_width
        self.num_slots = num_slots
        self.tolerance_per = tolerance_per
        self.allow_nearest = allow_nearest
        self.max_magnitude = (1 << (bit_width - 1)) if max_magnitude is None else max_magnitude
        self.tolerance = tolerance_per * self.max_magnitude

        single_terms = []
        for alpha in self.alphabets:
            for shift in range(bit_width):
                for sign in (1, -1):
                    single_terms.append((sign * (alpha << shift), sign, alpha, shift))

        self._best = {}
        for combo in itertools.combinations_with_replacement(single_terms, num_slots):
            total = sum(t[0] for t in combo)
            cost = sum(t[3] for t in combo)
            prev = self._best.get(total)
            if prev is None or cost < prev[0]:
                self._best[total] = (cost, combo)
        self._reachable = sorted(self._best.keys())

        self.alpha_bits = math.ceil(math.log2(len(self.alphabets))) if len(self.alphabets) > 1 else 0
        self.shift_bits = max(1, math.ceil(math.log2(bit_width)))
        self.slot_bits = self.alpha_bits + 1 + self.shift_bits
        self.word_bits = self.slot_bits * num_slots

        self._cache = {}
        self.exact = 0
        self.approx = 0
        self.max_abs_error = 0

    @property
    def hex_chars(self):
        return (self.word_bits + 3) // 4

    def _match(self, value):
        cands = [v for v in self._reachable if abs(v - value) <= self.tolerance]
        if cands:
            return min(cands, key=lambda v: abs(v - value))
        if self.allow_nearest:
            return min(self._reachable, key=lambda v: abs(v - value))
        return None

    def prevalidate(self, values):
        """Raise if any value is unreachable, BEFORE anything is written."""
        bad = sorted({int(v) for v in values if self._match(int(v)) is None})
        if bad:
            raise ValueError(
                f"CSHM cannot represent {len(bad)} value(s) with num_slots="
                f"{self.num_slots}, alphabet={self.alphabets}, tolerance_per="
                f"{self.tolerance_per}: {bad[:12]}{' ...' if len(bad) > 12 else ''}. "
                f"Increase num_slots, widen the alphabet, or raise tolerance_per."
            )

    def encode(self, value):
        value = int(value)
        hit = self._cache.get(value)
        if hit is not None:
            return hit
        best = self._match(value)
        if best is None:
            raise ValueError(f"CSHM cannot represent {value} (tolerance {self.tolerance}).")
        word = 0
        for (_v, sign, alpha, shift) in self._best[best][1]:
            slot = (self.alphabets.index(alpha) << (1 + self.shift_bits))
            slot |= (0 if sign > 0 else 1) << self.shift_bits
            slot |= shift
            word = (word << self.slot_bits) | slot
        if best == value:
            self.exact += 1
        else:
            self.approx += 1
            self.max_abs_error = max(self.max_abs_error, abs(best - value))
        self._cache[value] = word
        return word

    def decode(self, word):
        slots = []
        for i in range(self.num_slots):
            sh = self.slot_bits * (self.num_slots - 1 - i)
            slot = (word >> sh) & ((1 << self.slot_bits) - 1)
            shift = slot & ((1 << self.shift_bits) - 1)
            sign = -1 if (slot >> self.shift_bits) & 1 else 1
            idx = (slot >> (self.shift_bits + 1)) & ((1 << self.alpha_bits) - 1) if self.alpha_bits else 0
            slots.append((sign, self.alphabets[idx], shift))
        return slots

    def evaluate(self, word):
        return sum(s * (a << sh) for s, a, sh in self.decode(word))

    def summary(self):
        return (f"CSHM word={self.word_bits}b ({self.num_slots} x "
                f"[alpha:{self.alpha_bits}|sign:1|shift:{self.shift_bits}]) "
                f"| distinct={len(self._cache)} exact={self.exact} "
                f"approx={self.approx} max_err={self.max_abs_error}")


# ---------------------------------------------------------------------------
# CSHM settings -- fixed, because cshm_2_keys in the RTL decodes exactly this
# configuration: 2-bit alphabet index over {1,3,5,7}, 4-bit shift, 2 slots,
# giving a 14-bit key. Changing any of these requires widening the RTL
# alphabet mux and key fields to match, so they are not run-time knobs.
# ---------------------------------------------------------------------------
CSHM_ALPHABETS = 4
CSHM_SLOTS     = 2
CSHM_TOLERANCE = 0.005


def generate_twiddles(N, twiddle_width, type_fft=0, bit_growth=0, cshm=None,
                      data_dir="../Data"):
    """
    Generate the twiddle .mem ROMs.

    cshm:  None        -> raw two's-complement twiddle values (unchanged)
           CSHMEncoder -> packed CSHM instruction words instead

    When encoding, the whole value set is validated before any file is
    written, so an unrepresentable value fails cleanly rather than leaving a
    half-raw / half-encoded ROM set on disk.
    """
    if type_fft == 0:
        stages = int(math.log2(N))
    elif type_fft == 1:
        stages = int(math.log2(N)) // 2   # radix-4: half the stages
    elif type_fft == 2:
        stages = int(math.log2(N))        # split-radix: same as radix-2
    else:
        raise ValueError(f"unknown type_fft: {type_fft}")

    k = np.arange(N)
    twiddles = np.exp(-2j * np.pi * k / N)

    real_file_r2   = lambda s: f"{data_dir}/f_twiddle_real_{s}.mem"
    imag_file_r2   = lambda s: f"{data_dir}/f_twiddle_imag_{s}.mem"
    real_file_r4_1 = lambda s: f"{data_dir}/f_twiddle_real_{s}_1.mem"
    imag_file_r4_1 = lambda s: f"{data_dir}/f_twiddle_imag_{s}_1.mem"
    real_file_r4_2 = lambda s: f"{data_dir}/f_twiddle_real_{s}_2.mem"
    imag_file_r4_2 = lambda s: f"{data_dir}/f_twiddle_imag_{s}_2.mem"
    real_file_r4_3 = lambda s: f"{data_dir}/f_twiddle_real_{s}_3.mem"
    imag_file_r4_3 = lambda s: f"{data_dir}/f_twiddle_imag_{s}_3.mem"

    fractional_bits = twiddle_width - 1
    scale_factor = 1 << fractional_bits
    min_val = -scale_factor
    max_val = scale_factor - 1

    # SIGNED arrays. The raw writer masks on the way out; the CSHM encoder
    # needs the signed value, so masking here would only have to be undone.
    twiddle_real = np.clip(twiddles.real * scale_factor, min_val, max_val).astype(int)
    twiddle_imag = np.clip(twiddles.imag * scale_factor, min_val, max_val).astype(int)

    encoding = cshm is not None
    if encoding:
        cshm.prevalidate(set(twiddle_real.tolist()) | set(twiddle_imag.tolist()))
        out_bits = cshm.word_bits
    else:
        out_bits = twiddle_width

    hex_chars = (out_bits + 3) // 4
    out_mask = (1 << out_bits) - 1

    def dump(path, values):
        with open(path, "w") as f:
            for v in values:
                word = cshm.encode(v) if encoding else int(v)
                f.write(f"{word & out_mask:0{hex_chars}X}\n")

    for stage in range(1, stages + 1):
        if type_fft == 0:
            real_q = twiddle_real[0: N // 2]
            imag_q = twiddle_imag[0: N // 2]
            stride = (N // 2) // 2 ** (stage - 1)
            iter_count = 2 ** (stage - 1)

            dump(real_file_r2(stage), [real_q[stride * j] for j in range(iter_count)])
            dump(imag_file_r2(stage), [imag_q[stride * j] for j in range(iter_count)])

        elif type_fft == 1:
            real_q, imag_q = twiddle_real, twiddle_imag
            stride = (N // 4) // 4 ** (stage - 1)
            iter_count = 4 ** (stage - 1)

            dump(real_file_r4_1(stage), [real_q[stride * j] for j in range(iter_count)])
            dump(imag_file_r4_1(stage), [imag_q[stride * j] for j in range(iter_count)])
            dump(real_file_r4_2(stage), [real_q[stride * j * 2] for j in range(iter_count)])
            dump(imag_file_r4_2(stage), [imag_q[stride * j * 2] for j in range(iter_count)])
            dump(real_file_r4_3(stage), [real_q[stride * j * 3] for j in range(iter_count)])
            dump(imag_file_r4_3(stage), [imag_q[stride * j * 3] for j in range(iter_count)])

        elif type_fft == 2:
            real_q, imag_q = twiddle_real, twiddle_imag
            if stage == 1:
                continue                  # split-radix stage 1 has no twiddle
            stride = 2 ** (stage - 2)
            iter_count = int(N // (2 ** stage))

            dump(real_file_r4_1(stage), [real_q[stride * j] for j in range(iter_count)])
            dump(imag_file_r4_1(stage), [imag_q[stride * j] for j in range(iter_count)])
            dump(real_file_r4_2(stage), [real_q[stride * j * 3] for j in range(iter_count)])
            dump(imag_file_r4_2(stage), [imag_q[stride * j * 3] for j in range(iter_count)])

    if __debug__:
        print(f"Generated twiddles for {stages} stages "
              f"({out_bits}-bit words).")
        if encoding:
            print("  " + cshm.summary())

    return twiddles.real, twiddles.imag


def generate_twiddle_pkg(N, src_dir, type_fft=0):
    """
    Generate twiddle_pkg.vh with ternary-macro file lookup trees.

    type_fft = 0 : radix-2  -> log2(N) stages, ONE twiddle pair per stage
                   macros:  GET_REAL_FILE(idx), GET_IMAG_FILE(idx)

    type_fft = 1 : radix-4  -> log2(N)/2 stages, THREE twiddle pairs per
                   stage (W^1, W^2, W^3)
                   macros:  GET_REAL_FILE_1/2/3(idx)
                            GET_IMAG_FILE_1/2/3(idx)

    type_fft = 2 : split-radix -> log2(N) stages, TWO twiddle pairs per
                   stage (W^1, W^3)
                   macros:  GET_REAL_FILE_1/2(idx)
                            GET_IMAG_FILE_1/2(idx)
    """
    if type_fft == 0:
        stages = int(math.log2(N))
    elif type_fft == 1:
        stages = int(math.log2(N)) // 2  # Radix-4 has half the number of stages
    elif type_fft == 2:
        stages = int(math.log2(N))  # Split-Radix has the same number of stages as Radix-2
    else:
        raise ValueError(f"unknown type_fft: {type_fft}")

    def build_macro(macro_name, path_fn):
        """Build one ternary lookup tree mapping stage index -> filename."""
        s = f"`define {macro_name}(idx) \\\n"
        for stage in range(1, stages + 1):
            s += f'    ((idx) == {stage-1}) ? "{path_fn(stage)}" : \\\n'
        s += f'    "{path_fn(1)}"\n\n'  # Default fallback
        return s

    pkg_content = ""

    if type_fft == 0:
        # ---------------- Radix-2: one twiddle pair per stage -------------
        real_file = lambda stage: f"../Data/f_twiddle_real_{stage}.mem"
        imag_file = lambda stage: f"../Data/f_twiddle_imag_{stage}.mem"

        pkg_content += build_macro("GET_REAL_FILE", real_file)
        pkg_content += build_macro("GET_IMAG_FILE", imag_file)

    else:
        # ------- Radix-4 / split-radix: multiple twiddle pairs per stage --
        # NOTE: these filename patterns must match exactly what
        # generate_twiddles() writes for the corresponding case.
        # Order is stage first, then the twiddle index k.
        # Radix-4 uses k = 1,2,3 (W^1, W^2, W^3); split-radix uses
        # k = 1,2 (W^1, W^3) -- the split-radix RTL only references
        # GET_REAL_FILE_1/2 and GET_IMAG_FILE_1/2.
        real_file_k = lambda k: (
            lambda stage: f"../Data/f_twiddle_real_{stage}_{k}.mem"
        )
        imag_file_k = lambda k: (
            lambda stage: f"../Data/f_twiddle_imag_{stage}_{k}.mem"
        )

        k_range = (1, 2, 3) if type_fft == 1 else (1, 2)

        for k in k_range:
            pkg_content += build_macro(f"GET_REAL_FILE_{k}", real_file_k(k))
            pkg_content += build_macro(f"GET_IMAG_FILE_{k}", imag_file_k(k))

    # Write to a header file
    filepath = f"{src_dir}twiddle_pkg.vh"
    with open(filepath, "w") as f:
        f.write(pkg_content)

    radix = "radix-2" if type_fft == 0 else "radix-4" if type_fft == 1 else "split-radix"
    per_stage = 1 if type_fft == 0 else 3 if type_fft == 1 else 2
    print(
        f"Generated {filepath} with ternary macros for {stages} {radix} "
        f"stages ({per_stage} twiddle pair(s) per stage)."
    )
 
 
def _write_constraints(xdc_path, clock_port, clock_period_ns):
    """Writes a minimal XDC with just a clock constraint."""
    with open(xdc_path, "w") as f:
        f.write(
            f"create_clock -period {clock_period_ns} -name sys_clk "
            f"[get_ports {{{clock_port}}}]\n"
        )
 
 
def _write_synth_impl_tcl(tcl_path, design_files, top, part, generics,
                          xdc_path, out_dir, max_threads=8, max_dsp=-1, retiming=True, no_dsp=False, no_bram=False):
    """
    Generates a Tcl script that runs synthesis and implementation and
    produces timing and utilization reports.
    """
    generic_flags = " ".join(
        f"-generic {{{name}={val}}}" for name, val in generics.items()
    )
 
    # Read commands replicate the GUI "No_fast" synth run exactly:
    #   - twiddle_pkg.vh  -> plain read_verilog (NOT -sv)
    #   - *.sv            -> read_verilog -sv
    #   - *.v             -> plain read_verilog
    #   - all in library xil_defaultlib
    read_lines = []
    for design_file in design_files:
        if design_file.endswith(".sv"):
            read_lines.append(
                f"read_verilog -library xil_defaultlib -sv {{{design_file}}}"
            )
        else:  # .v and .vh are read as plain Verilog
            read_lines.append(
                f"read_verilog -library xil_defaultlib {{{design_file}}}"
            )
 
    read_block = "\n".join(read_lines)
 
    # Only emit -max_dsp when the caller overrides the default (-1 = unlimited).
    # Keeping it omitted at the default leaves the synth command byte-identical
    # to the GUI's.
    max_dsp_flag = "" if max_dsp == -1 else f" -max_dsp {max_dsp}"
    retiming_flag = " -retiming" if retiming else ""
    define_flag = " -verilog_define NO_DSP" if no_dsp else ""
    define_flag_2 = " -verilog_define NO_BRAM" if no_bram else ""
 
    tcl = f"""
# ---- Auto-generated synth+impl script ----
{read_block}
read_xdc {{{xdc_path}}}
 
# Number of threads for synth/place/route (2018.3 caps at 8).
set_param general.maxThreads {max_threads}
 
# ------------------------------------------------------------------
# Synthesis -- matches the GUI "Vivado Synthesis Defaults" run exactly.
# The GUI's generated command is simply:
#     synth_design -top <top> -part <part> -retiming
# The many strategy flags (flatten_hierarchy, fanout_limit, etc.) are
# applied as internal DEFAULTS by that command; spelling them out
# explicitly changes the result, so we do NOT add them here.
# -max_dsp caps DSP usage: 0 = force everything to fabric (no DSPs),
# N = at most N DSPs, -1 = unlimited (default, flag omitted so the
# command stays byte-identical to the GUI's).
# ------------------------------------------------------------------
synth_design -top {top} -part {part} {generic_flags}{retiming_flag}{max_dsp_flag}{define_flag}{define_flag_2}
write_checkpoint -force {out_dir}/post_synth.dcp
report_utilization -file {out_dir}/post_synth_util.rpt
 
# ------------------------------------------------------------------
# Implementation -- replicates the GUI "Performance_ExtraTimingOpt"
# strategy (impl_1) exactly:
#   opt_design              directive Default   (enabled)
#   power_opt_design                            (disabled)
#   place_design            directive ExtraTimingOpt
#   post_place_power_opt                        (disabled)
#   phys_opt_design         directive Explore   (enabled, pre-route)
#   route_design            directive NoTimingRelaxation
#   post_route_phys_opt                         (disabled)
# ------------------------------------------------------------------
opt_design -directive Default
place_design -directive ExtraTimingOpt
phys_opt_design -directive Explore
route_design -directive NoTimingRelaxation
write_checkpoint -force {out_dir}/post_route.dcp
 
# Human-readable reports (kept for manual inspection)
report_timing_summary -file {out_dir}/post_route_timing.rpt
report_utilization    -file {out_dir}/post_route_util.rpt
 
# ------------------------------------------------------------------
# Metrics for Vivado 2018.3.
# Timing: read the four summary values straight off the timer via
# report_timing_summary's return string is not stable in 2018.3, so we
# use timer properties that DO exist in 2018.3.
# Utilization: count cells by REF_NAME prefix (stable in 2018.3).
# ------------------------------------------------------------------
 
# --- Timing (2018.3-safe) ------------------------------------------
# IMPORTANT: the GUI's WNS/TNS come from the Design Timing Summary in
# report_timing_summary. get_timing_paths can report a different worst
# path, so read the summary itself to match the GUI exactly.
report_timing_summary -delay_type min_max -file {out_dir}/post_route_timing.rpt
 
# Also emit the summary to stdout wrapped in markers so Python can grab
# the exact same numbers the GUI shows.
puts "TIMING_SUMMARY_BEGIN"
report_timing_summary -delay_type min_max -no_detailed_paths
puts "TIMING_SUMMARY_END"
 
# --- Utilization (2018.3-safe, count by REF_NAME) ------------------
set n_lut  [llength [get_cells -hier -filter {{REF_NAME =~ LUT*}}]]
set n_reg  [llength [get_cells -hier -filter {{REF_NAME =~ FD* || REF_NAME =~ LD*}}]]
set n_dsp  [llength [get_cells -hier -filter {{REF_NAME =~ DSP*}}]]
set n_bram [llength [get_cells -hier -filter {{REF_NAME =~ RAMB*}}]]
puts "METRIC luts=$n_lut"
puts "METRIC registers=$n_reg"
puts "METRIC dsps=$n_dsp"
puts "METRIC bram_prims=$n_bram"
report_power -file {out_dir}/post_route_power.rpt
puts "SYNTH_IMPL_DONE"
"""
 
    with open(tcl_path, "w") as f:
        f.write(tcl)
 
def _parse_power(power_rpt_path):
    """Extract total on-chip power (W) from a Vivado report_power file."""
    if not os.path.exists(power_rpt_path):
        return None
    with open(power_rpt_path, "r") as f:
        text = f.read()
    m = re.search(r"Total On-Chip Power\s*\(W\)\s*\|\s*([\d.]+)", text)
    return float(m.group(1)) if m else None

def _parse_metrics_from_stdout(stdout):
    """
    Pull the 'METRIC key=value' lines the Tcl script printed. These are the
    authoritative values from Vivado's own timing/utilization engine, so they
    match the GUI and don't depend on report text layout or part family.
    """
    metrics = {}
    for m in re.finditer(r"METRIC\s+(\w+)=(\S+)", stdout):
        key, val = m.group(1), m.group(2)
        try:
            f = float(val)
            metrics[key] = int(f) if f.is_integer() else f
        except ValueError:
            metrics[key] = None  # Tcl printed empty / non-numeric
    return metrics
 
 
def _parse_timing_summary(stdout):
    """
    Parse WNS/TNS/WHS/THS from the Design Timing Summary that
    report_timing_summary prints between the TIMING_SUMMARY markers.
    This is the SAME table the Vivado GUI's timing panel shows, so the
    WNS here matches the GUI's WNS exactly.
 
    The 2018.3 summary looks like:
 
        Design Timing Summary
        ---------------------
        WNS(ns)  TNS(ns)  TNS Failing Endpoints  TNS Total Endpoints  \
        WHS(ns)  THS(ns)  ...
        -------  -------  ---------------------  -------------------  ...
        -0.060  -12.345                     42                 5000  \
         0.031    0.000  ...
 
    Returns (wns, tns, whs, ths), any of which may be None.
    """
    wns = tns = whs = ths = None
 
    m = re.search(
        r"TIMING_SUMMARY_BEGIN(.*?)TIMING_SUMMARY_END",
        stdout,
        re.DOTALL,
    )
    block = m.group(1) if m else stdout
 
    # Locate the WNS(ns) ... THS(ns) header row, then take the first numeric
    # values row after it. This is the Design Timing Summary the GUI shows.
    header = re.search(r"WNS\(ns\).*?THS\(ns\)", block, re.DOTALL)
    if header:
        after = block[header.end():]
        num = re.search(
            r"(-?\d+\.\d+)\s+(-?\d+\.\d+)\s+\d+\s+\d+\s+"
            r"(-?\d+\.\d+)\s+(-?\d+\.\d+)",
            after,
        )
        if num:
            wns = float(num.group(1))
            tns = float(num.group(2))
            whs = float(num.group(3))
            ths = float(num.group(4))
 
    return wns, tns, whs, ths
 
 
def _parse_wns_tns_report(timing_rpt_path):
    """Fallback: parse WNS/TNS/WHS/THS from the post_route_timing.rpt file."""
    if not os.path.exists(timing_rpt_path):
        return None, None, None, None
    with open(timing_rpt_path, "r") as f:
        text = f.read()
    return _parse_timing_summary(text)
 
 
def _parse_utilization(util_rpt_path):
    """
    Backup text parser, only used if the stdout METRIC lines are missing.
    Handles BOTH 7-series ("Slice LUTs"/"Slice Registers") and UltraScale
    ("CLB LUTs"/"CLB Registers") naming.
    """
    luts = registers = dsps = bram_tiles = None
    if not os.path.exists(util_rpt_path):
        return luts, registers, dsps, bram_tiles
 
    with open(util_rpt_path, "r") as f:
        text = f.read()
 
    def find(*labels):
        for label in labels:
            m = re.search(
                r"\|\s*" + re.escape(label) + r"\s*\|\s*([\d,]+)\s*\|",
                text,
            )
            if m:
                return int(m.group(1).replace(",", ""))
        return None
 
    luts = find("Slice LUTs", "CLB LUTs")
    registers = find("Slice Registers", "CLB Registers")
    dsps = find("DSPs", "DSP48E1", "DSP48E2", "DSP48 Blocks")
    bram_tiles = find("Block RAM Tile", "Block RAM Tiles")
    return luts, registers, dsps, bram_tiles
 
 
def synthesize_and_implement(
    Data_width=16,
    Tw_width=8,
    N=256,
    type_fft=0,
    SimpleMult=0,
    Fast_DSP=0,
    carry_save=0,
    Bram=1,
    bit_growth=0,
    output_pipeline_bram=0,
    input_pipeline_bram=0,
    part="xc7a200tfbg676-2",
    clock_period_ns=2.5,
    clock_port="clock",
    top=None,
    out_dir="../Data/vivado_run",
    max_threads=8,
    max_dsp=-1,
    retiming=True,
    no_dsp=False,
    no_bram=False,
    cshm=0
):
    """
    Runs Vivado synthesis and implementation in batch mode.

    type_fft: 0 = radix-2 (files in ../Radix-2/), 1 = radix-4 (files in
    ../Radix-4/), 2 = split-radix (files in ../Radix-split/).
    output_pipeline_bram applies to radix-4 and split-radix;
    input_pipeline_bram applies to split-radix only (mirrors the
    parameters compile_simulation_verilator/xsim already expose).
 
    Returns a dictionary containing:
        met_timing
        wns_ns
        tns_ns
        whs_ns
        ths_ns
        luts
        registers
        dsps
        bram_tiles
 
    Resource values are taken from the post-route Vivado utilization report.
    """
    if type_fft == 0:
        if cshm == 0:
            src_dir = "../Radix-2/"
        else:
            src_dir = "../Radix-2_cshm/"
    elif type_fft == 1:
        if cshm == 0:
            src_dir = "../Radix-4/"
        else:
            src_dir = "../Radix-4_cshm/"
    elif type_fft == 2:
        if cshm == 0:
            src_dir = "../Radix-split/"
        else:
            src_dir = "../Radix-split_cshm/"
    else:
        raise ValueError(f"unknown type_fft: {type_fft}")

    os.makedirs(out_dir, exist_ok=True)

    encoder = None
    if cshm:
        encoder = CSHMEncoder(
            bit_width=Tw_width,
            alphabets=CSHM_ALPHABETS,
            num_slots=CSHM_SLOTS,
            tolerance_per=CSHM_TOLERANCE,
        )
        Key_width = encoder.word_bits
        #generate_twiddles(N, Tw_width, type_fft, bit_growth, cshm=encoder)
    else:
        #generate_twiddles(N, Tw_width, type_fft, bit_growth)
        pass

    # generate_twiddle_pkg(N, src_dir, type_fft)
 
    if type_fft == 0:
        if cshm == 0:
            # File read order matches the GUI "No_fast" synth run:
            #   stage_unit.sv, fft_radix_2_top.sv, Carry_mult.v, butterfly.v,
            #   delay_buffer.v, delay_reg.v
            design_files = [
                f"{src_dir}twiddle_pkg.vh",
                f"{src_dir}stage_unit.sv",
                f"{src_dir}fft_radix_2_top.sv",
                f"{src_dir}Carry_mult.v",
                f"{src_dir}butterfly.v",
                f"{src_dir}delay_buffer.v",
                f"{src_dir}delay_reg.v",
            ]
 
            generics = {
                "WIDTH": Data_width,
                "Num_of_samples": N,
                "Tw_WIDTH": Tw_width,
                "SimpleMult": SimpleMult,
                "Fast_DSP": Fast_DSP,
                "carry_save": carry_save,
                "Bram": Bram,
                "bit_growth": bit_growth,
            }
        else:
            # CSHM: Carry_mult.v replaced by cshm.v; SimpleMult / Fast_DSP /
            # carry_save no longer exist on the CSHM multiplier, so they are
            # not passed. Mirrors compile_simulation_verilator in
            # FFT_softaware.py.
            design_files = [
                f"{src_dir}twiddle_pkg.vh",
                f"{src_dir}stage_unit.sv",
                f"{src_dir}fft_radix_2_top.sv",
                f"{src_dir}cshm.v",
                f"{src_dir}butterfly.v",
                f"{src_dir}delay_buffer.v",
                f"{src_dir}delay_reg.v",
            ]
 
            generics = {
                "WIDTH": Data_width,
                "Num_of_samples": N,
                "Tw_WIDTH": Tw_width,
                "Bram": Bram,
                "bit_growth": bit_growth,
                "KEY_WIDTH": Key_width,
            }
 
    elif type_fft == 1:
        if cshm == 0:
            design_files = [
                # f"{src_dir}twiddle_pkg.vh",
                f"{src_dir}stage_unit.sv",
                f"{src_dir}fft_radix_4_top.sv",
                f"{src_dir}Carry_mult.v",
                f"{src_dir}butterfly.v",
                f"{src_dir}memory.v",
                f"{src_dir}delay_reg.v",
            ]
 
            generics = {
                "WIDTH": Data_width,
                "Num_of_samples": N,
                "Tw_WIDTH": Tw_width,
                "SimpleMult": SimpleMult,
                "Fast_DSP": Fast_DSP,
                "carry_save": carry_save,
                "Bram": Bram,
                "output_pipeline_bram": output_pipeline_bram,
                "bit_growth": bit_growth,
            }
        else:
            design_files = [
                # f"{src_dir}twiddle_pkg.vh",
                f"{src_dir}stage_unit.sv",
                f"{src_dir}fft_radix_4_top.sv",
                f"{src_dir}cshm.v",
                f"{src_dir}butterfly.v",
                f"{src_dir}memory.v",
                f"{src_dir}delay_reg.v",
            ]
 
            generics = {
                "WIDTH": Data_width,
                "Num_of_samples": N,
                "Tw_WIDTH": Tw_width,
                "Bram": Bram,
                "output_pipeline_bram": output_pipeline_bram,
                "bit_growth": bit_growth,
                "KEY_WIDTH": Key_width,
            }
 
    else:
        if cshm == 0:
            design_files = [
                # f"{src_dir}twiddle_pkg.vh",
                f"{src_dir}split_fft_top.v",
                f"{src_dir}first_stage.v",
                f"{src_dir}second_stage.v",
                f"{src_dir}third_stage_fsm.v",
                f"{src_dir}second_to_last_stage.v",
                f"{src_dir}last_stage.v",
                f"{src_dir}fsm_control_unit.v",
                f"{src_dir}fsm_control_unit_last_stage.v",
                f"{src_dir}memory_first_stage.v",
                f"{src_dir}memory_second_stage.v",
                f"{src_dir}memory_third_stage.v",
                f"{src_dir}complex_multiplier.v",
                f"{src_dir}butterfly.v",
                f"{src_dir}delay_reg.v",
                f"{src_dir}Carry_mult.v",
            ]
 
            # split_fft_top's OWN parameter names -- "N" not Num_of_samples,
            # "SIMPLE_MULT" not SimpleMult.
            generics = {
                "WIDTH": Data_width,
                "Tw_WIDTH": Tw_width,
                "N": N,
                "SIMPLE_MULT": SimpleMult,
                "Fast_DSP": Fast_DSP,
                "input_pipeline_bram": input_pipeline_bram,
                "output_pipeline_bram": output_pipeline_bram,
                "carry_save": carry_save,
                "Bram": Bram
            }
        else:
            design_files = [
                # f"{src_dir}twiddle_pkg.vh",
                f"{src_dir}split_fft_top.v",
                f"{src_dir}first_stage.v",
                f"{src_dir}second_stage.v",
                f"{src_dir}third_stage_fsm.v",
                f"{src_dir}second_to_last_stage.v",
                f"{src_dir}last_stage.v",
                f"{src_dir}fsm_control_unit.v",
                f"{src_dir}fsm_control_unit_last_stage.v",
                f"{src_dir}memory_first_stage.v",
                f"{src_dir}memory_second_stage.v",
                f"{src_dir}memory_third_stage.v",
                f"{src_dir}complex_multiplier.v",
                f"{src_dir}butterfly.v",
                f"{src_dir}delay_reg.v",
                f"{src_dir}cshm.v",
            ]
 
            generics = {
                "WIDTH": Data_width,
                "Tw_WIDTH": Tw_width,
                "N": N,
                "input_pipeline_bram": input_pipeline_bram,
                "output_pipeline_bram": output_pipeline_bram,
                "Bram": Bram,
                "KEY_WIDTH": Key_width,
            }

    # Default top-module name per FFT type -- override with top=...
    # if your top-level module is actually named differently.
    if top is not None:
        top_module = top
    elif type_fft == 2:
        top_module = "split_fft_top"
    else:
        top_module = "fft_top"
 
    xdc_path = os.path.join(out_dir, "constraints.xdc")
    tcl_path = os.path.join(out_dir, "synth_impl.tcl")
    log_path = os.path.join(out_dir, "vivado.log")
    journal_path = os.path.join(out_dir, "vivado.jou")
 
    _write_constraints(xdc_path, clock_port, clock_period_ns)
    _write_synth_impl_tcl(
        tcl_path,
        design_files,
        top_module,
        part,
        generics,
        xdc_path,
        out_dir,
        max_threads=max_threads,
        max_dsp=max_dsp,
        retiming=retiming,
        no_dsp=no_dsp,
        no_bram=no_bram
    )
 
    if __debug__:
        print(
            f"Running Vivado synth+impl (part={part}, "
            f"clock={clock_period_ns} ns)..."
        )
    
    
    vivado_cmd = [
        "vivado",
        "-mode",
        "batch",
        "-source",
        tcl_path,
        "-log",
        log_path,
        "-journal",
        journal_path,
    ]
 
    result = subprocess.run(vivado_cmd, capture_output=True, text=True)
 
    if result.returncode != 0 or "SYNTH_IMPL_DONE" not in result.stdout:
        print("--- VIVADO SYNTH/IMPL FAILED ---")
        print("Standard Output:")
        print(result.stdout)
        print("Standard Error:")
        print(result.stderr)
        print(f"See {log_path} for the full Vivado log.")
        sys.exit(1)
 
    # ------------------------------------------------------------------
    # Read the metrics Tcl emitted on stdout.
    # ------------------------------------------------------------------
    metrics = _parse_metrics_from_stdout(result.stdout)
 
    # Timing comes from the Design Timing Summary (same as the GUI panel),
    # not from get_timing_paths, so the WNS matches the GUI exactly.
    wns, tns, whs, ths = _parse_timing_summary(result.stdout)
 
    # If the summary parse failed for any field, fall back to the text
    # report on disk, then to any METRIC lines.
    if wns is None or tns is None:
        f_wns, f_tns, f_whs, f_ths = _parse_wns_tns_report(
            os.path.join(out_dir, "post_route_timing.rpt")
        )
        wns = wns if wns is not None else f_wns
        tns = tns if tns is not None else f_tns
        whs = whs if whs is not None else f_whs
        ths = ths if ths is not None else f_ths
 
    # For utilization on Vivado 2018.3 the report_utilization text table is
    # the authoritative source (matches the GUI's utilization panel exactly),
    # so prefer it and fall back to the cell-count metrics only if parsing
    # the report fails.
    util_rpt = os.path.join(out_dir, "post_route_util.rpt")
    r_luts, r_regs, r_dsps, r_bram = _parse_utilization(util_rpt)
 
    luts = r_luts if r_luts is not None else metrics.get("luts")
    registers = r_regs if r_regs is not None else metrics.get("registers")
    dsps = r_dsps if r_dsps is not None else metrics.get("dsps")
    bram_tiles = r_bram if r_bram is not None else metrics.get("bram_prims")
    power_w = _parse_power(os.path.join(out_dir, "post_route_power.rpt"))
 
    met_timing = (
        wns is not None
        and wns >= 0
        and (ths is None or ths >= 0)
    )
 
    if __debug__:
        status = "MET" if met_timing else "VIOLATED"
        print(
            f"Timing {status}: "
            f"WNS={wns} ns, TNS={tns} ns, "
            f"WHS={whs} ns, THS={ths} ns"
        )
        print(
            f"Resources: LUTs={luts}, Registers={registers}, "
            f"DSPs={dsps}, BRAM Tiles={bram_tiles}, Power={power_w} W"
        )
        print(f"Reports written to {out_dir}")
 
    return {
        "met_timing": met_timing,
        "wns_ns": wns,
        "tns_ns": tns,
        "whs_ns": whs,
        "ths_ns": ths,
        "luts": luts,
        "registers": registers,
        "dsps": dsps,
        "bram_tiles": bram_tiles,
        "power_w": power_w,
        "cshm": bool(cshm),
        "cshm_word_bits": (encoder.word_bits if encoder else None),
        "cshm_approx": (encoder.approx if encoder else None),
        "cshm_max_err": (encoder.max_abs_error if encoder else None),
    }

import itertools
from datetime import datetime
import csv
import os

# Assuming synthesize_and_implement and clean_data_folder are imported here

if __name__ == "__main__":

    print("Start Time:", datetime.now().strftime("%Y-%m-%d %H:%M:%S"))

    # Define the parameter space
    N = [256]
    fft_types   = [0, 1, 2]   # 0 = radix-2, 1 = radix-4, 2 = split-radix
    simple_mult = [0]
    fast_dsp    = [0]
    carry_save  = [0]
    bram        = [0]
    cshm_modes  = [1]   # 0 = DSP/carry-save multipliers, 1 = CSHM shift-add

    # Setup CSV logging
    data = datetime.now().strftime("%Y-%m-%d_%H-%M-%S")
    csv_file = f"../Perm_Data/synthesis_results_{data}.csv"
    with open(csv_file, mode='w', newline='') as f:
        writer = csv.writer(f)
        # Write the CSV Header
        writer.writerow(['N', 'Data_width', 'Tw_width', 'type_fft', 'SimpleMult', 'Fast_DSP', 'carry_save', 'Bram',
                         'CSHM', 
                         'LUTs', 'Registers', 'DSPs', 'BRAMs', 'WNS_ns', 'TNS_ns', 'Power_W'])

    # Generate all combinations
    combinations = itertools.product(N, fft_types, simple_mult, fast_dsp, carry_save, bram, cshm_modes)

    for combo in combinations:
        c_N, c_type_fft, c_simple_mult, c_fast_dsp, c_carry_save, c_bram, c_cshm = combo

        # CSHM replaces the multiplier entirely, so SimpleMult / Fast_DSP /
        # carry_save no longer select anything. Run CSHM once per (N, type,
        # Bram) instead of once per dead multiplier combination.
        if c_cshm == 1 and not (c_simple_mult == simple_mult[0]
                                and c_fast_dsp == fast_dsp[0]
                                and c_carry_save == 0):
            continue
        
        # 1. Skip conflicting configurations
        if c_type_fft == 0 and c_bram == 1:
            print(f"Skipping: N={c_N}, type_fft={c_type_fft}, Bram={c_bram} (Invalid: Radix-2 with Bram=1)")
            continue  
        if c_carry_save == 1 and c_bram == 1:
            print(f"Skipping: N={c_N}, carry_save={c_carry_save}, Bram={c_bram} (Invalid: carry_save=1 with Bram=1)")
            continue  
        if c_carry_save == 1 and c_fast_dsp == 1:
            print(f"Skipping: N={c_N}, carry_save={c_carry_save}, Fast_DSP={c_fast_dsp} (Invalid: carry_save=1 with Fast_DSP=1)")
            continue  
        if c_carry_save == 0 and c_cshm == 0 and c_bram == 0 and c_type_fft == 2:
            print(f"Skipping: N={c_N}, carry_save={c_carry_save}, Fast_DSP={c_fast_dsp} (Invalid: carry_save=0 with Fast_DSP=0 and type_fft=1)")
            continue  

        if c_type_fft == 0:
            Data_width = 10
        elif c_type_fft == 1:
            Data_width = 11
        elif c_type_fft == 2:
            Data_width = 17

        Tw_width = 9  # Fixed for all configurations

        # 2. Dynamically set Vivado macro flags (Fixed logic)
        flag_no_dsp = (c_carry_save == 1) # If carry_save is 1, we don't want to use DSPs

        flag_no_bram = (c_carry_save == 1 or c_bram == 0) # If carry_save is 1 or Bram is 0, we don't want to use BRAM

        input_pipeline_bram = 1
        output_pipeline_bram = 1

        if(c_fast_dsp == 1):
            input_pipeline_bram = 1
            output_pipeline_bram = 1
        elif(c_carry_save == 1):
            input_pipeline_bram = 1
            output_pipeline_bram = 0
        else:
            input_pipeline_bram = 0
            output_pipeline_bram = 0

        print("\n" + "="*170)
        print(f"RUNNING: N={c_N} Data_width={Data_width} Tw_width={Tw_width} type_fft={c_type_fft} CSHM={c_cshm} SimpleMult={c_simple_mult} Fast_DSP={c_fast_dsp} carry_save={c_carry_save} Bram={c_bram} no_dsp={flag_no_dsp} no_bram={flag_no_bram} input_pipeline_bram={input_pipeline_bram} output_pipeline_bram={output_pipeline_bram}")
        print("="*170)

        # 3. Try to run synthesis, catch any failures safely
        try:
            result = synthesize_and_implement(
                Data_width=Data_width,
                Tw_width=Tw_width,
                N=c_N,
                type_fft=c_type_fft,
                SimpleMult=c_simple_mult,
                Fast_DSP=c_fast_dsp,
                carry_save=c_carry_save,
                Bram=c_bram,
                bit_growth=1,
                output_pipeline_bram=output_pipeline_bram,
                input_pipeline_bram=input_pipeline_bram,
                part="xc7a200tfbg676-2",
                clock_period_ns=2.5,
                clock_port="clock",
                # top left unset so synthesize_and_implement picks the
                # right top module per type_fft ("fft_top" for radix-2/4,
                # "split_fft_top" for split-radix). Hardcoding "fft_top"
                # here would break the split-radix runs.
                top=None,
                out_dir="../Data/vivado_run",
                no_dsp=flag_no_dsp,
                no_bram=flag_no_bram,
                cshm=c_cshm
            )

            # Print Success to Console
            print(f"\n===== VIVADO RESULTS =====")
            print(f"LUTs       : {result.get('luts', 'N/A')}")
            print(f"Registers  : {result.get('registers', 'N/A')}")
            print(f"DSPs       : {result.get('dsps', 'N/A')}") 
            print(f"BRAMs      : {result.get('bram_tiles', 'N/A')}")
            print(f"WNS        : {result.get('wns_ns', 'N/A')} ns")
            print(f"TNS        : {result.get('tns_ns', 'N/A')} ns")
            print(f"Power      : {result.get('power_w', 'N/A')} W")
            print(datetime.now().strftime("%Y-%m-%d %H:%M:%S"))

            # Log Success to CSV
            with open(csv_file, mode='a', newline='') as f:
                writer = csv.writer(f)
                writer.writerow([c_N, Data_width, Tw_width, c_type_fft, c_simple_mult, c_fast_dsp, c_carry_save, c_bram,
                                 c_cshm,
                                 result.get('luts', ''), result.get('registers', ''),
                                 result.get('dsps', ''), result.get('bram_tiles', ''),
                                 result.get('wns_ns', ''), result.get('tns_ns', ''),
                                 result.get('power_w', '')])

        except (Exception, SystemExit) as e:
            # Print Failure to Console
            print(f"\n[!] FAIL: Synthesis crashed or called sys.exit()!")
            
            # Log Failure to CSV
            with open(csv_file, mode='a', newline='') as f:
                writer = csv.writer(f)
                writer.writerow([c_N, Data_width, Tw_width, c_type_fft, c_simple_mult, c_fast_dsp, c_carry_save, c_bram,
                                 c_cshm, '', '', '',
                                 'FAIL', 'FAIL', 'FAIL', 'FAIL', 'FAIL', 'FAIL', 'FAIL'])

    print("\nAll combinations processed. Results saved to:", csv_file)