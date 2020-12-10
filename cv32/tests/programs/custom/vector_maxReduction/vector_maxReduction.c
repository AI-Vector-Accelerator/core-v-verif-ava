#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

unsigned int max_reduction_e8_m1(){
    int8_t output;
    int vlen=4*1;
    printf("Starting max_reduction_e8_m1 Test\n");

    asm volatile (
        "vsetvli t0, %1, e8, m1, d1 \n\t"     	
	    "vmv.v.i v1, 0	        \n\t"		
        "vmv.v.i v4, 4         \n\t"
        "vmv.v.i v5, 10       \n\t"
        "vmv.v.i v6, 12        \n\t"
        "vmv.v.i v7, 15        \n\t"
        "vsetvli t0, %1, e8, m1\n\t"
        "vredmax.vs v1, v4, v1 \n\t"
        "vmv.x.s %0, v1"
        : "=r" (output)
        : "r" (vlen)
    );

    if(output != 4) {
        printf("Test FAIL! Output: %d\n", output);
        return(1);
    }else {
        printf("Test PASS! Output: %d\n", output);
        return(0);
    }
}

unsigned int max_reduction_e8_m2(){
    int8_t output;
    int vlen=4*2;
    printf("Starting max_reduction_e8_m2 Test\n");

    asm volatile (
        "vsetvli t0, %1, e8, m1, d1 \n\t"     	
	    "vmv.v.i v1, 0	        \n\t"			
        "vmv.v.i v4, 4         \n\t"
        "vmv.v.i v5, 10       \n\t"
        "vmv.v.i v6, 12        \n\t"
        "vmv.v.i v7, 15        \n\t"
        "vsetvli t0, %1, e8, m2\n\t"
        "vredmax.vs v1, v4, v1 \n\t"
        "vmv.x.s %0, v1"
        : "=r" (output)
        : "r" (vlen)
    );

    if(output != 10) {
        printf("Test FAIL! Output: %d\n", output);
        return(1);
    }else {
        printf("Test PASS! Output: %d\n", output);
        return(0);
    }
}

unsigned int max_reduction_e8_m4(){
    int8_t output;
    int vlen=4*4;
    printf("Starting max_reduction_e8_m4 Test\n");

    asm volatile (
        "vsetvli t0, %1, e8, m1, d1 \n\t"     	
	    "vmv.v.i v1, 0	        \n\t"		
        "vmv.v.i v4, 4         \n\t"
        "vmv.v.i v5, 10       \n\t"
        "vmv.v.i v6, 12        \n\t"
        "vmv.v.i v7, 15        \n\t"
        "vsetvli t0, %1, e8, m4\n\t"
        "vredmax.vs v1, v4, v1 \n\t"
        "vmv.x.s %0, v1"
        : "=r" (output)
        : "r" (vlen)
    );

    if(output != 15) {
        printf("Test FAIL! Output: %d\n", output);
        return(1);
    }else {
        printf("Test PASS! Output: %d\n", output);
        return(0);
    }
}

//----------------------------------------------------------------------


unsigned int max_reduction_e16_m1(){
    int8_t output;
    int vlen=2*1;
    printf("Starting max_reduction_e16_m1 Test\n");

    asm volatile (
        "vsetvli t0, %1, e16, m1, d1 \n\t"     	
	    "vmv.v.i v1, 0	        \n\t"		
        "vmv.v.i v4, 4         \n\t"
        "vmv.v.i v5, 10       \n\t"
        "vmv.v.i v6, 12        \n\t"
        "vmv.v.i v7, 15        \n\t"
        "vsetvli t0, %1, e16, m1\n\t"
        "vredmax.vs v1, v4, v1 \n\t"
        "vmv.x.s %0, v1"
        : "=r" (output)
        : "r" (vlen)
    );

    if(output != 4) {
        printf("Test FAIL! Output: %d\n", output);
        return(1);
    }else {
        printf("Test PASS! Output: %d\n", output);
        return(0);
    }
}

unsigned int max_reduction_e16_m2(){
    int8_t output;
    int vlen=2*2;
    printf("Starting max_reduction_e16_m2 Test\n");

    asm volatile (
        "vsetvli t0, %1, e16, m1, d1 \n\t"     	
	    "vmv.v.i v1, 0	        \n\t"			
        "vmv.v.i v4, 4         \n\t"
        "vmv.v.i v5, 10       \n\t"
        "vmv.v.i v6, 12        \n\t"
        "vmv.v.i v7, 15        \n\t"
        "vsetvli t0, %1, e16, m2\n\t"
        "vredmax.vs v1, v4, v1 \n\t"
        "vmv.x.s %0, v1"
        : "=r" (output)
        : "r" (vlen)
    );

    if(output != 10) {
        printf("Test FAIL! Output: %d\n", output);
        return(1);
    }else {
        printf("Test PASS! Output: %d\n", output);
        return(0);
    }
}

unsigned int max_reduction_e16_m4(){
    int8_t output;
    int vlen=2*4;
    printf("Starting max_reduction_e16_m4 Test\n");

    asm volatile (
        "vsetvli t0, %1, e16, m1, d1 \n\t"     	
	    "vmv.v.i v1, 0	        \n\t"		
        "vmv.v.i v4, 4         \n\t"
        "vmv.v.i v5, 10       \n\t"
        "vmv.v.i v6, 12        \n\t"
        "vmv.v.i v7, 15        \n\t"
        "vsetvli t0, %1, e16, m4\n\t"
        "vredmax.vs v1, v4, v1 \n\t"
        "vmv.x.s %0, v1"
        : "=r" (output)
        : "r" (vlen)
    );

    if(output != 15) {
        printf("Test FAIL! Output: %d\n", output);
        return(1);
    }else {
        printf("Test PASS! Output: %d\n", output);
        return(0);
    }
}


//----------------------------------------------------------------------


unsigned int max_reduction_e32_m1(){
    int8_t output;
    int vlen=1*1;
    printf("Starting max_reduction_e32_m1 Test\n");

    asm volatile (
        "vsetvli t0, %1, e32, m1, d1 \n\t"     	
	    "vmv.v.i v1, 0	        \n\t"		
        "vmv.v.i v4, 4         \n\t"
        "vmv.v.i v5, 10       \n\t"
        "vmv.v.i v6, 12        \n\t"
        "vmv.v.i v7, 15        \n\t"
        "vsetvli t0, %1, e32, m1\n\t"
        "vredmax.vs v1, v4, v1 \n\t"
        "vmv.x.s %0, v1"
        : "=r" (output)
        : "r" (vlen)
    );

    if(output != 4) {
        printf("Test FAIL! Output: %d\n", output);
        return(1);
    }else {
        printf("Test PASS! Output: %d\n", output);
        return(0);
    }
}

unsigned int max_reduction_e32_m2(){
    int8_t output;
    int vlen=1*2;
    printf("Starting max_reduction_e32_m2 Test\n");

    asm volatile (
        "vsetvli t0, %1, e32, m1, d1 \n\t"     	
	    "vmv.v.i v1, 0	        \n\t"			
        "vmv.v.i v4, 4         \n\t"
        "vmv.v.i v5, 10       \n\t"
        "vmv.v.i v6, 12        \n\t"
        "vmv.v.i v7, 15        \n\t"
        "vsetvli t0, %1, e32, m2\n\t"
        "vredmax.vs v1, v4, v1 \n\t"
        "vmv.x.s %0, v1"
        : "=r" (output)
        : "r" (vlen)
    );

    if(output != 10) {
        printf("Test FAIL! Output: %d\n", output);
        return(1);
    }else {
        printf("Test PASS! Output: %d\n", output);
        return(0);
    }
}

unsigned int max_reduction_e32_m4(){
    int8_t output;
    int vlen=1*4;
    printf("Starting max_reduction_e32_m4 Test\n");

    asm volatile (
        "vsetvli t0, %1, e32, m1, d1 \n\t"     	
	    "vmv.v.i v1, 0	        \n\t"		
        "vmv.v.i v4, 4         \n\t"
        "vmv.v.i v5, 10       \n\t"
        "vmv.v.i v6, 12        \n\t"
        "vmv.v.i v7, 15        \n\t"
        "vsetvli t0, %1, e32, m4\n\t"
        "vredmax.vs v1, v4, v1 \n\t"
        "vmv.x.s %0, v1"
        : "=r" (output)
        : "r" (vlen)
    );

    if(output != 15) {
        printf("Test FAIL! Output: %d\n", output);
        return(1);
    }else {
        printf("Test PASS! Output: %d\n", output);
        return(0);
    }
}






int main(void){
    unsigned int errors = 0;
    printf("Max reduction testbench\n\n");

    errors+=max_reduction_e8_m1();
    errors+=max_reduction_e8_m2();
    errors+=max_reduction_e8_m4();

    errors+=max_reduction_e16_m1();
    errors+=max_reduction_e16_m2();
    errors+=max_reduction_e16_m4();

    errors+=max_reduction_e32_m1();
    errors+=max_reduction_e32_m2();
    errors+=max_reduction_e32_m4();

    if(errors > 0){
        printf("\nErrors Detected!\nError Count: %d\n", errors);
        return(EXIT_FAILURE);
    }
    printf("\nAll Tests Completed\nNo Errors Detected!\n");
    return(EXIT_SUCCESS);
}

// riscv32-unknown-elf-gcc -Os -g -static -mabi=ilp32 -march=rv32imcv -Wall -pedantic   -o test_spike.elf          -L lib/ -lcv-verif -T lib/link.ld vector_maxReduction.c
// spike  --isa=RV32IMCV    --varch=vlen:32,elen:32,slen:32  /opt/riscv/riscv32-unknown-elf/bin/pk test_spike.elf 
