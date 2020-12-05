// Copyright 2018 Robert Balas <balasr@student.ethz.ch>
// Copyright and related rights are licensed under the Solderpad Hardware
// License, Version 0.51 (the "License"); you may not use this file except in
// compliance with the License.  You may obtain a copy of the License at
// http://solderpad.org/licenses/SHL-0.51. Unless required by applicable law
// or agreed to in writing, software, hardware and materials distributed under
// this License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
// CONDITIONS OF ANY KIND, either express or implied. See the License for the
// specific language governing permissions and limitations under the License.

// Wrapper for a CV32E40P testbench, containing CV32E40P, Memory and stdout peripheral
// Contributor: Robert Balas <balasr@student.ethz.ch>
// Module renamed from riscv_wrapper to cv32e40p_tb_wrapper because (1) the
// name of the core changed, and (2) the design has a cv32e40p_wrapper module.
//
// SPDX-License-Identifier: Apache-2.0 WITH SHL-0.51

module cv32e40p_tb_wrapper
    #(parameter // Parameters used by TB
                INSTR_RDATA_WIDTH = 32,
                RAM_ADDR_WIDTH    = 20,
                BOOT_ADDR         = 'h80,
                DM_HALTADDRESS    = 32'h1A11_0800,
                HART_ID           = 32'h0000_0000,
                // Parameters used by DUT
                PULP_XPULP        = 0,
                PULP_CLUSTER      = 0,
                FPU               = 0,
                PULP_ZFINX        = 0,
                NUM_MHPMCOUNTERS  = 1,
                GDP_NVPE          = 1 )
    (input logic         clk_i,
     input logic         rst_ni,

     input logic         fetch_enable_i,
     output logic        tests_passed_o,
     output logic        tests_failed_o,
     output logic [31:0] exit_value_o,
     output logic        exit_valid_o
    );

    // signals connecting core to memory
    logic                         instr_req;
    logic                         instr_gnt;
    logic                         instr_rvalid;
    logic [31:0]                  instr_addr;
    logic [INSTR_RDATA_WIDTH-1:0] instr_rdata;

    // Data crossbar slave 1
    logic                         data_req_xbr_s1;
    logic                         data_gnt_xbr_s1;
    logic                         data_rvalid_xbr_s1;
    logic [31:0]                  data_addr_xbr_s1;
    logic                         data_we_xbr_s1;
    logic [3:0]                   data_be_xbr_s1;
    logic [31:0]                  data_rdata_xbr_s1;
    logic [31:0]                  data_wdata_xbr_s1;
    // Data crossbar master 1 (CPU)
    logic                         data_req_xbr_m1;
    logic                         data_gnt_xbr_m1;
    logic                         data_rvalid_xbr_m1;
    logic [31:0]                  data_addr_xbr_m1;
    logic                         data_we_xbr_m1;
    logic [3:0]                   data_be_xbr_m1;
    logic [31:0]                  data_rdata_xbr_m1;
    logic [31:0]                  data_wdata_xbr_m1;
    // Data crossbar master 2 (NVPE)
    logic                         data_req_xbr_m2;
    logic                         data_gnt_xbr_m2;
    logic                         data_rvalid_xbr_m2;
    logic [31:0]                  data_addr_xbr_m2;
    logic                         data_we_xbr_m2;
    logic [3:0]                   data_be_xbr_m2;
    logic [31:0]                  data_rdata_xbr_m2;
    logic [31:0]                  data_wdata_xbr_m2;


    logic [2:0][31:0]             apu_operands;
    logic [5:0]                   apu_op;
    logic [14:0]                  apu_flags;
    logic                         apu_req;
    // response channel
    logic                         apu_rvalid;
    logic [31:0]                  apu_result;
    logic [5:0]                   apu_flags_r;
    logic                         apu_gnt;

    // signals to debug unit
    logic                         debug_req;

    // irq signals (not used)
    logic [0:31]                  irq;
    logic [0:4]                   irq_id_in;
    logic                         irq_ack;
    logic [0:4]                   irq_id_out;
    logic                         irq_sec;

    // interrupts (only timer for now)
    assign irq_sec     = '0;

	// core log reports parameter usage and illegal instructions to the logfile
    cv32e40p_core_log
     #(
          .PULP_XPULP            ( PULP_XPULP            ),
          .PULP_CLUSTER          ( PULP_CLUSTER          ),
          .FPU                   ( FPU                   ),
          .PULP_ZFINX            ( PULP_ZFINX            ),
          .NUM_MHPMCOUNTERS      ( NUM_MHPMCOUNTERS      ))
    core_log_i(
          .clk_i              ( cv32e40p_core_i.id_stage_i.clk              ),
          .is_decoding_i      ( cv32e40p_core_i.id_stage_i.is_decoding_o    ),
          .illegal_insn_dec_i ( cv32e40p_core_i.id_stage_i.illegal_insn_dec ),
          .hart_id_i          ( cv32e40p_core_i.hart_id_i                   ),
          .pc_id_i            ( cv32e40p_core_i.pc_id                       )
      );

    // instantiate the core
    cv32e40p_core #(
                 .PULP_XPULP       (PULP_XPULP),
                 .PULP_CLUSTER     (PULP_CLUSTER),
                 .FPU              (FPU),
                 .PULP_ZFINX       (PULP_ZFINX),
                 .NUM_MHPMCOUNTERS (NUM_MHPMCOUNTERS),
                 .GDP_NVPE         (GDP_NVPE)
                )
    cv32e40p_core_i
        (
         .clk_i                  ( clk_i                 ),
         .rst_ni                 ( rst_ni                ),

         .pulp_clock_en_i        ( '1                    ),
         .scan_cg_en_i           ( '0                    ),

         .boot_addr_i            ( BOOT_ADDR             ),
         .dm_halt_addr_i         ( DM_HALTADDRESS        ),
         .hart_id_i              ( HART_ID               ),

         .instr_req_o            ( instr_req             ),
         .instr_gnt_i            ( instr_gnt             ),
         .instr_rvalid_i         ( instr_rvalid          ),
         .instr_addr_o           ( instr_addr            ),
         .instr_rdata_i          ( instr_rdata           ),

         .data_req_o             ( data_req_xbr_m1       ),
         .data_gnt_i             ( data_gnt_xbr_m1       ),
         .data_rvalid_i          ( data_rvalid_xbr_m1    ),
         .data_we_o              ( data_we_xbr_m1        ),
         .data_be_o              ( data_be_xbr_m1        ),
         .data_addr_o            ( data_addr_xbr_m1      ),
         .data_wdata_o           ( data_wdata_xbr_m1     ),
         .data_rdata_i           ( data_rdata_xbr_m1     ),

         .apu_req_o              ( apu_req               ),
         .apu_gnt_i              ( apu_gnt               ),
         .apu_operands_o         ( apu_operands          ),
         .apu_op_o               ( apu_op                ),
         .apu_flags_o            ( apu_flags             ),
         .apu_rvalid_i           ( apu_rvalid            ),
         .apu_result_i           ( apu_result            ),
         .apu_flags_i            ( apu_flags_r           ), // APU_NUSFLAGS_CPU

         // Interrupts verified in UVM environment
         .irq_i                  ( {32'b0}            ),
         .irq_ack_o              ( irq_ack               ),
         .irq_id_o               ( irq_id_out            ),

         .debug_req_i            ( debug_req ),

         .fetch_enable_i         ( fetch_enable_i        ),
         .core_sleep_o           ( core_sleep_o          )
       );

    // this handles read to RAM and memory mapped pseudo peripherals
    mm_ram
        #(.RAM_ADDR_WIDTH (RAM_ADDR_WIDTH),
          .INSTR_RDATA_WIDTH (INSTR_RDATA_WIDTH))
    ram_i
        (.clk_i          ( clk_i                                     ),
         .rst_ni         ( rst_ni                                    ),
         .dm_halt_addr_i ( DM_HALTADDRESS                            ),

         .instr_req_i    ( instr_req                                 ),
         .instr_addr_i   ( { {10{1'b0}},
                             instr_addr[RAM_ADDR_WIDTH-1:0]
                           }                                         ),
         .instr_rdata_o  ( instr_rdata                               ),
         .instr_rvalid_o ( instr_rvalid                              ),
         .instr_gnt_o    ( instr_gnt                                 ),

         .data_req_i     ( data_req_xbr_s1                           ),
         .data_addr_i    ( data_addr_xbr_s1                          ),
         .data_we_i      ( data_we_xbr_s1                            ),
         .data_be_i      ( data_be_xbr_s1                            ),
         .data_wdata_i   ( data_wdata_xbr_s1                         ),
         .data_rdata_o   ( data_rdata_xbr_s1                         ),
         .data_rvalid_o  ( data_rvalid_xbr_s1                        ),
         .data_gnt_o     ( data_gnt_xbr_s1                           ),

         // TODO: Interrupts need to be re-done
         .irq_id_i       ( irq_id_out                                ),
         .irq_ack_i      ( irq_ack                                   ),
         .irq_o          ( irq                                       ),

         .debug_req_o    ( debug_req                                 ),

         .pc_core_id_i   ( cv32e40p_core_i.pc_id                     ),

         .tests_passed_o ( tests_passed_o                            ),
         .tests_failed_o ( tests_failed_o                            ),
         .exit_valid_o   ( exit_valid_o                              ),
         .exit_value_o   ( exit_value_o                              ));

    cv32e40n_data_xbar xbar_mux
       (.clk_i                  ( clk_i                     ),
        .rst_ni                 ( rst_ni                    ),

        .data_req_xbr_s1_o      ( data_req_xbr_s1           ),
        .data_gnt_xbr_s1_i      ( data_gnt_xbr_s1           ),
        .data_rvalid_xbr_s1_i   ( data_rvalid_xbr_s1        ),
        .data_addr_xbr_s1_o     ( data_addr_xbr_s1          ),
        .data_we_xbr_s1_o       ( data_we_xbr_s1            ),
        .data_be_xbr_s1_o       ( data_be_xbr_s1            ),
        .data_rdata_xbr_s1_i    ( data_rdata_xbr_s1         ),
        .data_wdata_xbr_s1_o    ( data_wdata_xbr_s1         ),

        .data_req_xbr_m1_i      ( data_req_xbr_m1           ),
        .data_gnt_xbr_m1_o      ( data_gnt_xbr_m1           ),
        .data_rvalid_xbr_m1_o   ( data_rvalid_xbr_m1        ),
        .data_addr_xbr_m1_i     ( data_addr_xbr_m1          ),
        .data_we_xbr_m1_i       ( data_we_xbr_m1            ),
        .data_be_xbr_m1_i       ( data_be_xbr_m1            ),
        .data_rdata_xbr_m1_o    ( data_rdata_xbr_m1         ),
        .data_wdata_xbr_m1_i    ( data_wdata_xbr_m1         ),

        .data_req_xbr_m2_i      ( data_req_xbr_m2           ),
        .data_gnt_xbr_m2_o      ( data_gnt_xbr_m2           ),
        .data_rvalid_xbr_m2_o   ( data_rvalid_xbr_m2        ),
        .data_addr_xbr_m2_i     ( data_addr_xbr_m2          ),
        .data_we_xbr_m2_i       ( data_we_xbr_m2            ),
        .data_be_xbr_m2_i       ( data_be_xbr_m2            ),
        .data_rdata_xbr_m2_o    ( data_rdata_xbr_m2         ),
        .data_wdata_xbr_m2_i    ( data_wdata_xbr_m2         ));

    accelerator_top a_top
       (.apu_result(apu_result),
        .apu_flags_o(apu_flags_r),
        .apu_gnt(apu_gnt),
        .apu_rvalid(apu_rvalid),
        .clk(clk_i),
        .n_reset(rst_ni),
        .apu_req(apu_req),
        .apu_operands_i(apu_operands),
        .apu_op(apu_op),
        .apu_flags_i(apu_flags),
        .data_req_o(data_req_xbr_m2),
        .data_gnt_i(data_gnt_xbr_m2),
        .data_rvalid_i(data_rvalid_xbr_m2),
        .data_we_o(data_we_xbr_m2),
        .data_be_o(data_be_xbr_m2),
        .data_addr_o(data_addr_xbr_m2),
        .data_wdata_o(data_wdata_xbr_m2),
        .data_rdata_i(data_rdata_xbr_m2));

endmodule // cv32e40p_tb_wrapper
