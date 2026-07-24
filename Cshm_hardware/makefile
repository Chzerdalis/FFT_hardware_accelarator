# Toolchain variables
COMPILER = iverilog
SIMULATOR = vvp
VIEWER = surfer

# Grab all Verilog files in the folder
SOURCES = *.v

# ==========================================
# DESIGN 1: 2-Slot Architecture
# ==========================================
TOP1    = tb_cshm_2_keys
TARGET1 = sim_2_slots.vvp
WAVE1   = wave_2_slots.vcd

# ==========================================
# DESIGN 2: 3-Slot Architecture
# ==========================================
TOP2    = tb_cshm_3_keys
TARGET2 = sim_3_slots.vvp
WAVE2   = wave_3_slots.vcd

# ==========================================
# Commands
# ==========================================

# Default command runs both sequentially
all: run1 run2

# --- 2-Slot Targets ---
compile1:
	$(COMPILER) -s $(TOP1) -o $(TARGET1) $(SOURCES)

run1: compile1
	$(SIMULATOR) $(TARGET1)

wave1:
	$(VIEWER) $(WAVE1) &

# --- 3-Slot Targets ---
compile2:
	$(COMPILER) -s $(TOP2) -o $(TARGET2) $(SOURCES)

run2: compile2
	$(SIMULATOR) $(TARGET2)

wave2:
	$(VIEWER) $(WAVE2) &

# --- Cleanup ---
clean:
	rm -f *.vvp *.vcd