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
add wave -noupdate -expand -group {APU interface} /tb_top/cv32e40p_tb_wrapper_i/a_top/apu_req
add wave -noupdate -expand -group {APU interface} /tb_top/cv32e40p_tb_wrapper_i/a_top/apu_gnt
add wave -noupdate -expand -group {APU interface} /tb_top/cv32e40p_tb_wrapper_i/a_top/apu_op
add wave -noupdate -expand -group {APU interface} -expand /tb_top/cv32e40p_tb_wrapper_i/a_top/apu_operands_i
add wave -noupdate -expand -group {APU interface} /tb_top/cv32e40p_tb_wrapper_i/a_top/apu_flags_i
add wave -noupdate -expand -group {APU interface} /tb_top/cv32e40p_tb_wrapper_i/a_top/apu_result
add wave -noupdate -expand -group {APU interface} /tb_top/cv32e40p_tb_wrapper_i/a_top/apu_rvalid
add wave -noupdate -expand -group {APU interface} /tb_top/cv32e40p_tb_wrapper_i/a_top/apu_flags_o
add wave -noupdate /tb_top/cv32e40p_tb_wrapper_i/a_top/vreg0/vregs
add wave -noupdate -expand -group {CSR internal signals} /tb_top/cv32e40p_tb_wrapper_i/a_top/vcsrs0/avl_in
add wave -noupdate -expand -group {CSR internal signals} /tb_top/cv32e40p_tb_wrapper_i/a_top/vcsrs0/vtype_in
add wave -noupdate -expand -group {CSR internal signals} /tb_top/cv32e40p_tb_wrapper_i/a_top/vcsrs0/write
add wave -noupdate -expand -group {CSR internal signals} /tb_top/cv32e40p_tb_wrapper_i/a_top/vcsrs0/saturate_flag
add wave -noupdate -expand -group {CSR internal signals} /tb_top/cv32e40p_tb_wrapper_i/a_top/vcsrs0/preserve_vl
add wave -noupdate -expand -group {CSR internal signals} /tb_top/cv32e40p_tb_wrapper_i/a_top/vcsrs0/set_vl_max
add wave -noupdate -expand -group {CSR internal signals} /tb_top/cv32e40p_tb_wrapper_i/a_top/vcsrs0/csrs
add wave -noupdate -expand -group {CSR internal signals} /tb_top/cv32e40p_tb_wrapper_i/a_top/vcsrs0/vl_next
add wave -noupdate -expand -group {CSR internal signals} /tb_top/cv32e40p_tb_wrapper_i/a_top/vcsrs0/max_vl
add wave -noupdate -expand -group {CSR internal signals} /tb_top/cv32e40p_tb_wrapper_i/a_top/vcsrs0/per_reg
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {47859 ns} 0}
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
WaveRestoreZoom {47480 ns} {48273 ns}
