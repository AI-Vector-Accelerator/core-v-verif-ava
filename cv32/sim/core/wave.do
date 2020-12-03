onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate /tb_top/cv32e40p_tb_wrapper_i/cv32e40p_core_i/clk_i
add wave -noupdate /tb_top/cv32e40p_tb_wrapper_i/cv32e40p_core_i/rst_ni
add wave -noupdate /tb_top/cv32e40p_tb_wrapper_i/cv32e40p_core_i/fetch_enable
add wave -noupdate /tb_top/cv32e40p_tb_wrapper_i/cv32e40p_core_i/id_stage_i/register_file_i/mem
add wave -noupdate -divider Accelerator
add wave -noupdate /tb_top/cv32e40p_tb_wrapper_i/a_top/vl
add wave -noupdate /tb_top/cv32e40p_tb_wrapper_i/a_top/vsew
add wave -noupdate /tb_top/cv32e40p_tb_wrapper_i/a_top/vlmul
add wave -noupdate /tb_top/cv32e40p_tb_wrapper_i/a_top/scalar_operand1
add wave -noupdate /tb_top/cv32e40p_tb_wrapper_i/a_top/scalar_operand2
add wave -noupdate /tb_top/cv32e40p_tb_wrapper_i/a_top/immediate_operand
add wave -noupdate /tb_top/cv32e40p_tb_wrapper_i/a_top/vreg0/vregs
add wave -noupdate -group {Vector reg controls} /tb_top/cv32e40p_tb_wrapper_i/a_top/vreg0/vs1_addr0
add wave -noupdate -group {Vector reg controls} /tb_top/cv32e40p_tb_wrapper_i/a_top/vreg0/vs2_addr0
add wave -noupdate -group {Vector reg controls} /tb_top/cv32e40p_tb_wrapper_i/a_top/vreg0/vd_addr0
add wave -noupdate -group {Vector reg controls} -radix binary /tb_top/cv32e40p_tb_wrapper_i/a_top/vreg0/wr_en0
add wave -noupdate -group {Vector reg controls} -radix binary /tb_top/cv32e40p_tb_wrapper_i/a_top/vreg0/wr_en1
add wave -noupdate -group {Vector reg controls} -radix binary /tb_top/cv32e40p_tb_wrapper_i/a_top/vreg0/wr_en2
add wave -noupdate -group {Vector reg controls} -radix binary /tb_top/cv32e40p_tb_wrapper_i/a_top/vreg0/wr_en3
add wave -noupdate -group {Instruction components} /tb_top/cv32e40p_tb_wrapper_i/a_top/vdec0/immediate_operand
add wave -noupdate -group {Instruction components} /tb_top/cv32e40p_tb_wrapper_i/a_top/vdec0/funct3
add wave -noupdate -group {Instruction components} /tb_top/cv32e40p_tb_wrapper_i/a_top/vdec0/major_opcode
add wave -noupdate -group {Instruction components} /tb_top/cv32e40p_tb_wrapper_i/a_top/vdec0/funct6
add wave -noupdate -group {Instruction components} /tb_top/cv32e40p_tb_wrapper_i/a_top/vdec0/source1
add wave -noupdate -group {Instruction components} /tb_top/cv32e40p_tb_wrapper_i/a_top/vdec0/source2
add wave -noupdate -group {Instruction components} /tb_top/cv32e40p_tb_wrapper_i/a_top/vdec0/destination
add wave -noupdate -group {Instruction state} /tb_top/cv32e40p_tb_wrapper_i/a_top/vdec0/state
add wave -noupdate -group {Instruction state} /tb_top/cv32e40p_tb_wrapper_i/a_top/vdec0/next_state
add wave -noupdate -group {Instruction state} /tb_top/cv32e40p_tb_wrapper_i/a_top/vdec0/cycle_count
add wave -noupdate -group {Instruction state} /tb_top/cv32e40p_tb_wrapper_i/a_top/vdec0/max_cycle_count
add wave -noupdate -group {Instruction state} /tb_top/cv32e40p_tb_wrapper_i/a_top/vdec0/multi_cycle_instr
add wave -noupdate -group {Instruction state} /tb_top/cv32e40p_tb_wrapper_i/a_top/vdec0/elements_to_write
add wave -noupdate -group {Instruction state} /tb_top/cv32e40p_tb_wrapper_i/a_top/vdec0/vl_zero_indexed
add wave -noupdate -group {APU interface} /tb_top/cv32e40p_tb_wrapper_i/a_top/apu_req
add wave -noupdate -group {APU interface} /tb_top/cv32e40p_tb_wrapper_i/a_top/apu_gnt
add wave -noupdate -group {APU interface} /tb_top/cv32e40p_tb_wrapper_i/a_top/apu_op
add wave -noupdate -group {APU interface} -expand /tb_top/cv32e40p_tb_wrapper_i/a_top/apu_operands_i
add wave -noupdate -group {APU interface} /tb_top/cv32e40p_tb_wrapper_i/a_top/apu_flags_i
add wave -noupdate -group {APU interface} /tb_top/cv32e40p_tb_wrapper_i/a_top/apu_result
add wave -noupdate -group {APU interface} /tb_top/cv32e40p_tb_wrapper_i/a_top/apu_rvalid
add wave -noupdate -group {APU interface} /tb_top/cv32e40p_tb_wrapper_i/a_top/apu_flags_o
add wave -noupdate -group {CSR internal signals} /tb_top/cv32e40p_tb_wrapper_i/a_top/vcsrs0/avl_in
add wave -noupdate -group {CSR internal signals} /tb_top/cv32e40p_tb_wrapper_i/a_top/vcsrs0/vtype_in
add wave -noupdate -group {CSR internal signals} /tb_top/cv32e40p_tb_wrapper_i/a_top/vcsrs0/write
add wave -noupdate -group {CSR internal signals} /tb_top/cv32e40p_tb_wrapper_i/a_top/vcsrs0/saturate_flag
add wave -noupdate -group {CSR internal signals} /tb_top/cv32e40p_tb_wrapper_i/a_top/vcsrs0/preserve_vl
add wave -noupdate -group {CSR internal signals} /tb_top/cv32e40p_tb_wrapper_i/a_top/vcsrs0/set_vl_max
add wave -noupdate -group {CSR internal signals} /tb_top/cv32e40p_tb_wrapper_i/a_top/vcsrs0/csrs
add wave -noupdate -group {CSR internal signals} /tb_top/cv32e40p_tb_wrapper_i/a_top/vcsrs0/vl_next
add wave -noupdate -group {CSR internal signals} /tb_top/cv32e40p_tb_wrapper_i/a_top/vcsrs0/max_vl
add wave -noupdate -group {CSR internal signals} /tb_top/cv32e40p_tb_wrapper_i/a_top/vcsrs0/per_reg
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {62828 ns} 0}
quietly wave cursor active 1
configure wave -namecolwidth 392
configure wave -valuecolwidth 100
configure wave -justifyvalue left
configure wave -signalnamewidth 0
configure wave -snapdistance 10
configure wave -datasetprefix 0
configure wave -rowmargin 4
configure wave -childrowmargin 2
configure wave -gridoffset 0
configure wave -gridperiod 1
configure wave -griddelta 40
configure wave -timeline 0
configure wave -timelineunits ns
update
WaveRestoreZoom {62743 ns} {62941 ns}
