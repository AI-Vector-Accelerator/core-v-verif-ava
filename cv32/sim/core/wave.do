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
add wave -noupdate /tb_top/cv32e40p_tb_wrapper_i/a_top/vd_data_src
add wave -noupdate -group {APU interface} /tb_top/cv32e40p_tb_wrapper_i/a_top/apu_req
add wave -noupdate -group {APU interface} /tb_top/cv32e40p_tb_wrapper_i/a_top/apu_gnt
add wave -noupdate -group {APU interface} /tb_top/cv32e40p_tb_wrapper_i/a_top/apu_op
add wave -noupdate -group {APU interface} -expand /tb_top/cv32e40p_tb_wrapper_i/a_top/apu_operands_i
add wave -noupdate -group {APU interface} /tb_top/cv32e40p_tb_wrapper_i/a_top/apu_flags_i
add wave -noupdate -group {APU interface} /tb_top/cv32e40p_tb_wrapper_i/a_top/apu_result
add wave -noupdate -group {APU interface} /tb_top/cv32e40p_tb_wrapper_i/a_top/apu_rvalid
add wave -noupdate -group {APU interface} /tb_top/cv32e40p_tb_wrapper_i/a_top/apu_flags_o
add wave -noupdate -group {Instruction state} /tb_top/cv32e40p_tb_wrapper_i/a_top/vdec0/state
add wave -noupdate -group {Instruction state} /tb_top/cv32e40p_tb_wrapper_i/a_top/vdec0/next_state
add wave -noupdate -group {Instruction state} /tb_top/cv32e40p_tb_wrapper_i/a_top/vdec0/elements_to_write
add wave -noupdate -group {Instruction state} /tb_top/cv32e40p_tb_wrapper_i/a_top/vdec0/cycle_count
add wave -noupdate -group {Instruction state} /tb_top/cv32e40p_tb_wrapper_i/a_top/vdec0/max_cycle_count
add wave -noupdate -group {Instruction state} /tb_top/cv32e40p_tb_wrapper_i/a_top/vdec0/multi_cycle_instr
add wave -noupdate -group {Instruction state} /tb_top/cv32e40p_tb_wrapper_i/a_top/vdec0/vl_zero_indexed
add wave -noupdate -group {Instruction state} /tb_top/cv32e40p_tb_wrapper_i/a_top/vdec0/funct3
add wave -noupdate -group {Instruction state} /tb_top/cv32e40p_tb_wrapper_i/a_top/vdec0/major_opcode
add wave -noupdate -group {Instruction state} /tb_top/cv32e40p_tb_wrapper_i/a_top/vdec0/funct6
add wave -noupdate -group {Instruction state} /tb_top/cv32e40p_tb_wrapper_i/a_top/vdec0/source1
add wave -noupdate -group {Instruction state} /tb_top/cv32e40p_tb_wrapper_i/a_top/vdec0/source2
add wave -noupdate -group {Instruction state} /tb_top/cv32e40p_tb_wrapper_i/a_top/vdec0/destination
add wave -noupdate -group {Instruction state} /tb_top/cv32e40p_tb_wrapper_i/a_top/vdec0/mop
add wave -noupdate -group {Instruction state} -expand /tb_top/cv32e40p_tb_wrapper_i/a_top/vdec0/reg_apu_operands
add wave -noupdate -group {Vector registers} /tb_top/cv32e40p_tb_wrapper_i/a_top/vreg0/vregs
add wave -noupdate -group {Vector registers} -radix binary /tb_top/cv32e40p_tb_wrapper_i/a_top/vreg0/wr_en0
add wave -noupdate -group {Vector registers} -radix binary /tb_top/cv32e40p_tb_wrapper_i/a_top/vreg0/wr_en1
add wave -noupdate -group {Vector registers} -radix binary /tb_top/cv32e40p_tb_wrapper_i/a_top/vreg0/wr_en2
add wave -noupdate -group {Vector registers} -radix binary /tb_top/cv32e40p_tb_wrapper_i/a_top/vreg0/wr_en3
add wave -noupdate -group {Vector registers} /tb_top/cv32e40p_tb_wrapper_i/a_top/vreg0/vs1_addr
add wave -noupdate -group {Vector registers} /tb_top/cv32e40p_tb_wrapper_i/a_top/vreg0/vs2_addr
add wave -noupdate -group {Vector registers} /tb_top/cv32e40p_tb_wrapper_i/a_top/vreg0/vd_addr
add wave -noupdate -group {Vector registers} /tb_top/cv32e40p_tb_wrapper_i/a_top/vreg0/eff_vsew
add wave -noupdate -group {Vector registers} /tb_top/cv32e40p_tb_wrapper_i/a_top/vreg0/write
add wave -noupdate -group {Vector registers} /tb_top/cv32e40p_tb_wrapper_i/a_top/vreg0/vd_data
add wave -noupdate -group {Arithmetic stage} /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/arith_output
add wave -noupdate -group {Arithmetic stage} /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/replicated_scalar
add wave -noupdate -group {Arithmetic stage} /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/op
add wave -noupdate -group {Arithmetic stage} /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/saturate_mode
add wave -noupdate -group {Arithmetic stage} /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/output_mode
add wave -noupdate -group {Arithmetic stage} /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/operand_select
add wave -noupdate -group {Arithmetic stage} /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/widening
add wave -noupdate -group {Arithmetic stage} /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/mul_us
add wave -noupdate -group {Arithmetic stage} /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/reduction_intermediate_reg
add wave -noupdate -group {Arithmetic stage} /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe0_out
add wave -noupdate -group {Arithmetic stage} /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe1_out
add wave -noupdate -group {Arithmetic stage} /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe2_out
add wave -noupdate -group {Arithmetic stage} /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe3_out
add wave -noupdate -group {Arithmetic stage} -group pe0 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe0/out
add wave -noupdate -group {Arithmetic stage} -group pe0 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe0/a
add wave -noupdate -group {Arithmetic stage} -group pe0 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe0/b
add wave -noupdate -group {Arithmetic stage} -group pe0 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe0/c
add wave -noupdate -group {Arithmetic stage} -group pe0 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe0/mult_a
add wave -noupdate -group {Arithmetic stage} -group pe0 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe0/mult_b
add wave -noupdate -group {Arithmetic stage} -group pe0 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe0/mult_wide
add wave -noupdate -group {Arithmetic stage} -group pe0 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe0/selected_mult_out
add wave -noupdate -group {Arithmetic stage} -group pe0 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe0/add_out
add wave -noupdate -group {Arithmetic stage} -group pe0 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe0/add_a
add wave -noupdate -group {Arithmetic stage} -group pe0 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe0/add_b
add wave -noupdate -group {Arithmetic stage} -group pe0 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe0/addend
add wave -noupdate -group {Arithmetic stage} -group pe0 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe0/arith_result
add wave -noupdate -group {Arithmetic stage} -group pe0 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe0/macc
add wave -noupdate -group {Arithmetic stage} -group pe0 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe0/subtract
add wave -noupdate -group {Arithmetic stage} -group pe0 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe0/sign_ext_a
add wave -noupdate -group {Arithmetic stage} -group pe0 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe0/sign_ext_b
add wave -noupdate -group {Arithmetic stage} -group pe0 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe0/sign_ext_c
add wave -noupdate -group {Arithmetic stage} -group pe0 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe0/sat_result
add wave -noupdate -group {Arithmetic stage} -group pe0 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe0/sat8_result
add wave -noupdate -group {Arithmetic stage} -group pe0 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe0/sat16_result
add wave -noupdate -group {Arithmetic stage} -group pe0 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe0/sat32_result
add wave -noupdate -group {Arithmetic stage} -group pe1 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe1/out
add wave -noupdate -group {Arithmetic stage} -group pe1 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe1/a
add wave -noupdate -group {Arithmetic stage} -group pe1 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe1/b
add wave -noupdate -group {Arithmetic stage} -group pe1 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe1/c
add wave -noupdate -group {Arithmetic stage} -group pe1 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe1/mult_a
add wave -noupdate -group {Arithmetic stage} -group pe1 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe1/mult_b
add wave -noupdate -group {Arithmetic stage} -group pe1 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe1/mult_wide
add wave -noupdate -group {Arithmetic stage} -group pe1 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe1/selected_mult_out
add wave -noupdate -group {Arithmetic stage} -group pe1 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe1/add_out
add wave -noupdate -group {Arithmetic stage} -group pe1 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe1/add_a
add wave -noupdate -group {Arithmetic stage} -group pe1 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe1/add_b
add wave -noupdate -group {Arithmetic stage} -group pe1 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe1/addend
add wave -noupdate -group {Arithmetic stage} -group pe1 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe1/arith_result
add wave -noupdate -group {Arithmetic stage} -group pe1 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe1/macc
add wave -noupdate -group {Arithmetic stage} -group pe1 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe1/subtract
add wave -noupdate -group {Arithmetic stage} -group pe1 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe1/sign_ext_a
add wave -noupdate -group {Arithmetic stage} -group pe1 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe1/sign_ext_b
add wave -noupdate -group {Arithmetic stage} -group pe1 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe1/sign_ext_c
add wave -noupdate -group {Arithmetic stage} -group pe1 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe1/sat_result
add wave -noupdate -group {Arithmetic stage} -group pe1 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe1/sat8_result
add wave -noupdate -group {Arithmetic stage} -group pe1 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe1/sat16_result
add wave -noupdate -group {Arithmetic stage} -group pe1 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe1/sat32_result
add wave -noupdate -group {Arithmetic stage} -group pe2 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe2/out
add wave -noupdate -group {Arithmetic stage} -group pe2 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe2/a
add wave -noupdate -group {Arithmetic stage} -group pe2 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe2/b
add wave -noupdate -group {Arithmetic stage} -group pe2 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe2/c
add wave -noupdate -group {Arithmetic stage} -group pe2 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe2/mult_a
add wave -noupdate -group {Arithmetic stage} -group pe2 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe2/mult_b
add wave -noupdate -group {Arithmetic stage} -group pe2 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe2/mult_wide
add wave -noupdate -group {Arithmetic stage} -group pe2 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe2/selected_mult_out
add wave -noupdate -group {Arithmetic stage} -group pe2 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe2/add_out
add wave -noupdate -group {Arithmetic stage} -group pe2 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe2/add_a
add wave -noupdate -group {Arithmetic stage} -group pe2 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe2/add_b
add wave -noupdate -group {Arithmetic stage} -group pe2 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe2/addend
add wave -noupdate -group {Arithmetic stage} -group pe2 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe2/arith_result
add wave -noupdate -group {Arithmetic stage} -group pe2 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe2/macc
add wave -noupdate -group {Arithmetic stage} -group pe2 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe2/subtract
add wave -noupdate -group {Arithmetic stage} -group pe2 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe2/sign_ext_a
add wave -noupdate -group {Arithmetic stage} -group pe2 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe2/sign_ext_b
add wave -noupdate -group {Arithmetic stage} -group pe2 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe2/sign_ext_c
add wave -noupdate -group {Arithmetic stage} -group pe2 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe2/sat_result
add wave -noupdate -group {Arithmetic stage} -group pe2 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe2/sat8_result
add wave -noupdate -group {Arithmetic stage} -group pe2 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe2/sat16_result
add wave -noupdate -group {Arithmetic stage} -group pe2 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe2/sat32_result
add wave -noupdate -group {Arithmetic stage} -group pe3 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe3/out
add wave -noupdate -group {Arithmetic stage} -group pe3 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe3/a
add wave -noupdate -group {Arithmetic stage} -group pe3 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe3/b
add wave -noupdate -group {Arithmetic stage} -group pe3 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe3/c
add wave -noupdate -group {Arithmetic stage} -group pe3 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe3/mult_a
add wave -noupdate -group {Arithmetic stage} -group pe3 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe3/mult_b
add wave -noupdate -group {Arithmetic stage} -group pe3 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe3/mult_wide
add wave -noupdate -group {Arithmetic stage} -group pe3 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe3/selected_mult_out
add wave -noupdate -group {Arithmetic stage} -group pe3 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe3/add_out
add wave -noupdate -group {Arithmetic stage} -group pe3 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe3/add_a
add wave -noupdate -group {Arithmetic stage} -group pe3 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe3/add_b
add wave -noupdate -group {Arithmetic stage} -group pe3 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe3/addend
add wave -noupdate -group {Arithmetic stage} -group pe3 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe3/arith_result
add wave -noupdate -group {Arithmetic stage} -group pe3 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe3/macc
add wave -noupdate -group {Arithmetic stage} -group pe3 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe3/subtract
add wave -noupdate -group {Arithmetic stage} -group pe3 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe3/sign_ext_a
add wave -noupdate -group {Arithmetic stage} -group pe3 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe3/sign_ext_b
add wave -noupdate -group {Arithmetic stage} -group pe3 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe3/sign_ext_c
add wave -noupdate -group {Arithmetic stage} -group pe3 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe3/sat_result
add wave -noupdate -group {Arithmetic stage} -group pe3 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe3/sat8_result
add wave -noupdate -group {Arithmetic stage} -group pe3 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe3/sat16_result
add wave -noupdate -group {Arithmetic stage} -group pe3 /tb_top/cv32e40p_tb_wrapper_i/a_top/arith_stage0/pe3/sat32_result
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
add wave -noupdate -group VLSU /tb_top/cv32e40p_tb_wrapper_i/a_top/vlsu0/vs_wdata_o
add wave -noupdate -group VLSU /tb_top/cv32e40p_tb_wrapper_i/a_top/vlsu0/vd_offset
add wave -noupdate -group VLSU /tb_top/cv32e40p_tb_wrapper_i/a_top/vlsu0/ib_select
add wave -noupdate -group VLSU /tb_top/cv32e40p_tb_wrapper_i/a_top/vlsu0/be_gen
add wave -noupdate -group VLSU /tb_top/cv32e40p_tb_wrapper_i/a_top/vlsu0/next_el_pre
add wave -noupdate -group VLSU /tb_top/cv32e40p_tb_wrapper_i/a_top/vlsu0/next_el_addr
add wave -noupdate -group VLSU /tb_top/cv32e40p_tb_wrapper_i/a_top/vlsu0/cycle_addr
add wave -noupdate -group VLSU /tb_top/cv32e40p_tb_wrapper_i/a_top/vlsu0/stride
add wave -noupdate -group VLSU /tb_top/cv32e40p_tb_wrapper_i/a_top/vlsu0/cycle_bytes
add wave -noupdate -group VLSU /tb_top/cv32e40p_tb_wrapper_i/a_top/vlsu0/current_state
add wave -noupdate -group VLSU /tb_top/cv32e40p_tb_wrapper_i/a_top/vlsu0/next_state
add wave -noupdate -group VLSU /tb_top/cv32e40p_tb_wrapper_i/a_top/vlsu0/byte_track
add wave -noupdate -group VLSU /tb_top/cv32e40p_tb_wrapper_i/a_top/vlsu0/byte_track_next
add wave -noupdate -group VLSU /tb_top/cv32e40p_tb_wrapper_i/a_top/vlsu0/cycle_load
add wave -noupdate -group VLSU /tb_top/cv32e40p_tb_wrapper_i/a_top/vlsu0/cycle_addr_inc
add wave -noupdate -group VLSU /tb_top/cv32e40p_tb_wrapper_i/a_top/vlsu0/store_cycles_inc
add wave -noupdate -group VLSU /tb_top/cv32e40p_tb_wrapper_i/a_top/vlsu0/store_cycle_bytes
add wave -noupdate -group VLSU /tb_top/cv32e40p_tb_wrapper_i/a_top/vlsu0/store_cycle_be
add wave -noupdate -group VLSU /tb_top/cv32e40p_tb_wrapper_i/a_top/vlsu0/store_cycles
add wave -noupdate -group VLSU /tb_top/cv32e40p_tb_wrapper_i/a_top/vlsu0/store_cycles_cnt
add wave -noupdate -group VLSU -group {Temporary register} /tb_top/cv32e40p_tb_wrapper_i/a_top/vlsu0/tr/byte_enable_valid
add wave -noupdate -group VLSU -group {Temporary register} /tb_top/cv32e40p_tb_wrapper_i/a_top/vlsu0/tr/read_data_valid
add wave -noupdate -group VLSU -group {Temporary register} /tb_top/cv32e40p_tb_wrapper_i/a_top/vlsu0/tr/clear_register
add wave -noupdate -group VLSU -group {Temporary register} /tb_top/cv32e40p_tb_wrapper_i/a_top/vlsu0/tr/memory_read_i
add wave -noupdate -group VLSU -group {Temporary register} /tb_top/cv32e40p_tb_wrapper_i/a_top/vlsu0/tr/byte_enable_i
add wave -noupdate -group VLSU -group {Temporary register} /tb_top/cv32e40p_tb_wrapper_i/a_top/vlsu0/tr/byte_select_i
add wave -noupdate -group VLSU -group {Temporary register} /tb_top/cv32e40p_tb_wrapper_i/a_top/vlsu0/tr/wide_vd_o
add wave -noupdate -group VLSU -group {Temporary register} /tb_top/cv32e40p_tb_wrapper_i/a_top/vlsu0/tr/byte_enable_reg
add wave -noupdate -group VLSU -group {Temporary register} /tb_top/cv32e40p_tb_wrapper_i/a_top/vlsu0/tr/temp_reg
add wave -noupdate -group VLSU -group {Temporary register} /tb_top/cv32e40p_tb_wrapper_i/a_top/vlsu0/tr/memory_read_bytes
add wave -noupdate -group VLSU -group {Temporary register} /tb_top/cv32e40p_tb_wrapper_i/a_top/vlsu0/tr/memory_read_packed
add wave -noupdate -group VLSU -group {Temporary register} /tb_top/cv32e40p_tb_wrapper_i/a_top/vlsu0/tr/packed_set
add wave -noupdate -divider RAM
add wave -noupdate /tb_top/cv32e40p_tb_wrapper_i/ram_i/instr_req_i
add wave -noupdate /tb_top/cv32e40p_tb_wrapper_i/ram_i/instr_addr_i
add wave -noupdate /tb_top/cv32e40p_tb_wrapper_i/ram_i/instr_rdata_o
add wave -noupdate /tb_top/cv32e40p_tb_wrapper_i/ram_i/instr_rvalid_o
add wave -noupdate /tb_top/cv32e40p_tb_wrapper_i/ram_i/instr_gnt_o
add wave -noupdate /tb_top/cv32e40p_tb_wrapper_i/ram_i/data_req_i
add wave -noupdate /tb_top/cv32e40p_tb_wrapper_i/ram_i/data_addr_i
add wave -noupdate /tb_top/cv32e40p_tb_wrapper_i/ram_i/data_we_i
add wave -noupdate /tb_top/cv32e40p_tb_wrapper_i/ram_i/data_be_i
add wave -noupdate /tb_top/cv32e40p_tb_wrapper_i/ram_i/data_wdata_i
add wave -noupdate /tb_top/cv32e40p_tb_wrapper_i/ram_i/data_rdata_o
add wave -noupdate /tb_top/cv32e40p_tb_wrapper_i/ram_i/data_rvalid_o
add wave -noupdate /tb_top/cv32e40p_tb_wrapper_i/ram_i/data_gnt_o
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {19070 ns} 0}
quietly wave cursor active 1
configure wave -namecolwidth 441
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
WaveRestoreZoom {18855 ns} {19280 ns}
