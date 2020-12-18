#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>

uint32_t compact_int16_t_to_uint32_t(int16_t *input){
    uint32_t output=0;
    for(unsigned int i=0;i<sizeof(int32_t)/sizeof(int16_t);i++){
        output +=  (uint16_t)input[i]<<(i*CHAR_BIT*sizeof(int16_t)) ;
    }
    return output;
}

uint32_t compact_int8_t_to_uint32_t(int8_t *input){
    uint32_t output=0;
    for(unsigned int i=0;i<sizeof(int32_t)/sizeof(int8_t);i++){
        output +=  (uint8_t)input[i]<<(i*CHAR_BIT*sizeof(int8_t)) ;
    }
    return output;
}

unsigned int max_reduction_e8_m1(){
    int vlen=sizeof(int32_t)/sizeof(int8_t)*1;
    int8_t output, input[vlen],minimum=SCHAR_MIN,golden_output;
    uint32_t temp_v[vlen*sizeof(int8_t)/sizeof(int32_t)];
    
    printf("Starting max_reduction_e8_m1 Test\n");
    golden_output=minimum;
    printf("Input : ");
    for(unsigned int i=0;i<vlen;i++){
        input[i]=rand();
        if(input[i]>golden_output){golden_output=input[i];}
        printf(" %d ",input[i]);
    }
    printf("\n");
    for(unsigned int i=0;i<vlen*sizeof(int8_t)/sizeof(int32_t);i++){
        temp_v[i]=compact_int8_t_to_uint32_t(&input[i*sizeof(int32_t)/sizeof(int8_t)]);
    }
    
    asm volatile (
        "vsetvli t0, %1, e32, m1, d1 \n\t"     	
	    "vmv.v.x v1, %2	        \n\t"		
        "vmv.v.x v4, %3         \n\t"
        "vsetvli t0, %1, e8, m1\n\t"
        "vredmax.vs v1, v4, v1 \n\t"
        "vmv.x.s %0, v1"
        : "=r" (output) 
        : "r" (vlen) ,"r" (minimum), "r" (temp_v[0])
    );

    if(output != golden_output) {
        printf("Test FAIL! Output: %d\n\n", output);
        return(1);
    }else {
        printf("Test PASS! Output: %d\n\n", output);
        return(0);
    }
}

unsigned int max_reduction_e8_m2(){
    int vlen=sizeof(int32_t)/sizeof(int8_t)*2;
    int8_t output, input[vlen],minimum=SCHAR_MIN,golden_output;
    uint32_t temp_v[vlen*sizeof(int8_t)/sizeof(int32_t)];
 
    printf("Starting max_reduction_e8_m2 Test\n");
    golden_output=minimum;
    printf("Input : ");
    for(unsigned int i=0;i<vlen;i++){
        input[i]=rand();
        if(input[i]>golden_output){golden_output=input[i];}
        printf(" %d ",input[i]);
    }
    printf("\n");
    for(unsigned int i=0;i<vlen*sizeof(int8_t)/sizeof(int32_t);i++){
        temp_v[i]=compact_int8_t_to_uint32_t(&input[i*sizeof(int32_t)/sizeof(int8_t)]);
    }
    
    asm volatile (
        "vsetvli t0, %1, e32, m1, d1 \n\t"     	
	    "vmv.v.x v1, %2	        \n\t"		
        "vmv.v.x v4, %3         \n\t"
        "vmv.v.x v5, %4       \n\t"
        "vsetvli t0, %1, e8, m2\n\t"
        "vredmax.vs v1, v4, v1 \n\t"
        "vmv.x.s %0, v1"
        : "=r" (output) 
        : "r" (vlen) ,"r" (minimum), "r" (temp_v[0]),"r" (temp_v[1])
    );

    if(output != golden_output) {
        printf("Test FAIL! Output: %d\n\n", output);
        return(1);
    }else {
        printf("Test PASS! Output: %d\n\n", output);
        return(0);
    }
}

unsigned int max_reduction_e8_m4(){
    int vlen=sizeof(int32_t)/sizeof(int8_t)*4;
    int8_t output, input[vlen],minimum=SCHAR_MIN,golden_output;
    uint32_t temp_v[vlen*sizeof(int8_t)/sizeof(int32_t)];
 
    printf("Starting max_reduction_e8_m4 Test\n");
    golden_output=minimum;
    printf("Input : ");
    for(unsigned int i=0;i<vlen;i++){
        input[i]=rand();
        if(input[i]>golden_output){golden_output=input[i];}
        printf(" %d ",input[i]);
    }
    printf("\n");
    for(unsigned int i=0;i<vlen*sizeof(int8_t)/sizeof(int32_t);i++){
        temp_v[i]=compact_int8_t_to_uint32_t(&input[i*sizeof(int32_t)/sizeof(int8_t)]);
    }
    
    asm volatile (
        "vsetvli t0, %1, e32, m1, d1 \n\t"     	
	    "vmv.v.x v1, %2	        \n\t"		
        "vmv.v.x v4, %3         \n\t"
        "vmv.v.x v5, %4       \n\t"
        "vmv.v.x v6, %5        \n\t"
        "vmv.v.x v7, %6        \n\t"
        "vsetvli t0, %1, e8, m4\n\t"
        "vredmax.vs v1, v4, v1 \n\t"
        "vmv.x.s %0, v1"
        : "=r" (output) 
        : "r" (vlen) ,"r" (minimum), "r" (temp_v[0]),"r" (temp_v[1]),"r" (temp_v[2]),"r" (temp_v[3])
    );

    if(output != golden_output) {
        printf("Test FAIL! Output: %d\n\n", output);
        return(1);
    }else {
        printf("Test PASS! Output: %d\n\n", output);
        return(0);
    }
}

//----------------------------------------------------------------------


unsigned int max_reduction_e16_m1(){
    int vlen=sizeof(int32_t)/sizeof(int16_t)*1;
    int16_t output, input[vlen],minimum=SHRT_MIN,golden_output;
    uint32_t temp_v[vlen*sizeof(int16_t)/sizeof(int32_t)];
 
    printf("Starting max_reduction_e16_m1 Test\n");
    golden_output=minimum;
    printf("Input : ");
    for(unsigned int i=0;i<vlen;i++){
        input[i]=rand();
        if(input[i]>golden_output){golden_output=input[i];}
        printf(" %d ",input[i]);
    }
    printf("\n");
    for(unsigned int i=0;i<vlen*sizeof(int16_t)/sizeof(int32_t);i++){
        temp_v[i]=compact_int16_t_to_uint32_t(&input[i*sizeof(int32_t)/sizeof(int16_t)]);
    }
    
    asm volatile (
        "vsetvli t0, %1, e32, m1, d1 \n\t"     	
	    "vmv.v.x v1, %2	        \n\t"		
        "vmv.v.x v4, %3         \n\t"
        "vsetvli t0, %1, e16, m1\n\t"
        "vredmax.vs v1, v4, v1 \n\t"
        "vmv.x.s %0, v1"
        : "=r" (output) 
        : "r" (vlen) ,"r" (minimum), "r" (temp_v[0])
    );

    if(output != golden_output) {
        printf("Test FAIL! Output: %d\n\n", output);
        return(1);
    }else {
        printf("Test PASS! Output: %d\n\n", output);
        return(0);
    }
}

unsigned int max_reduction_e16_m2(){
    int vlen=sizeof(int32_t)/sizeof(int16_t)*2;
    int16_t output, input[vlen],minimum=SHRT_MIN,golden_output;
    uint32_t temp_v[vlen*sizeof(int16_t)/sizeof(int32_t)];
 
    printf("Starting max_reduction_e16_m2 Test\n");
    golden_output=minimum;
    printf("Input : ");
    for(unsigned int i=0;i<vlen;i++){
        input[i]=rand();
        if(input[i]>golden_output){golden_output=input[i];}
        printf(" %d ",input[i]);
    }
    printf("\n");
    for(unsigned int i=0;i<vlen*sizeof(int16_t)/sizeof(int32_t);i++){
        temp_v[i]=compact_int16_t_to_uint32_t(&input[i*sizeof(int32_t)/sizeof(int16_t)]);
    }
   
    asm volatile (
        "vsetvli t0, %1, e32, m1, d1 \n\t"     	
	    "vmv.v.x v1, %2	        \n\t"		
        "vmv.v.x v4, %3         \n\t"
        "vmv.v.x v5, %4       \n\t"
        "vsetvli t0, %1, e16, m2\n\t"
        "vredmax.vs v1, v4, v1 \n\t"
        "vmv.x.s %0, v1"
        : "=r" (output) 
        : "r" (vlen) ,"r" (minimum), "r" (temp_v[0]),"r" (temp_v[1])
    );

    if(output != golden_output) {
        printf("Test FAIL! Output: %d\n\n", output);
        return(1);
    }else {
        printf("Test PASS! Output: %d\n\n", output);
        return(0);
    }
}

unsigned int max_reduction_e16_m4(){
    int vlen=sizeof(int32_t)/sizeof(int16_t)*4;
    int16_t output, input[vlen],minimum=SHRT_MIN,golden_output;
    uint32_t temp_v[vlen*sizeof(int16_t)/sizeof(int32_t)];
 
    printf("Starting max_reduction_e16_m4 Test\n");
    golden_output=minimum;
    printf("Input : ");
    for(unsigned int i=0;i<vlen;i++){
        input[i]=rand();
        if(input[i]>golden_output){golden_output=input[i];}
        printf(" %d ",input[i]);
    }
    printf("\n");
    for(unsigned int i=0;i<vlen*sizeof(int16_t)/sizeof(int32_t);i++){
        temp_v[i]=compact_int16_t_to_uint32_t(&input[i*sizeof(int32_t)/sizeof(int16_t)]);
    }
    
    asm volatile (
        "vsetvli t0, %1, e32, m1, d1 \n\t"     	
	    "vmv.v.x v1, %2	        \n\t"		
        "vmv.v.x v4, %3         \n\t"
        "vmv.v.x v5, %4       \n\t"
        "vmv.v.x v6, %5        \n\t"
        "vmv.v.x v7, %6        \n\t"
        "vsetvli t0, %1, e16, m4\n\t"
        "vredmax.vs v1, v4, v1 \n\t"
        "vmv.x.s %0, v1"
        : "=r" (output) 
        : "r" (vlen) ,"r" (minimum), "r" (temp_v[0]),"r" (temp_v[1]),"r" (temp_v[2]),"r" (temp_v[3])
    );

    if(output != golden_output) {
        printf("Test FAIL! Output: %d\n\n", output);
        return(1);
    }else {
        printf("Test PASS! Output: %d\n\n", output);
        return(0);
    }}


//----------------------------------------------------------------------


unsigned int max_reduction_e32_m1(){
    int vlen=1;
    int32_t output, input[vlen],minimum=INT_MIN,golden_output;
    
    printf("Starting max_reduction_e32_m1 Test\n"); 
    golden_output=minimum;
    printf("Input : ");
    for(unsigned int i=0;i<vlen;i++){
        input[i]=rand();
        if(input[i]>golden_output){golden_output=input[i];}
        printf(" %ld ",input[i]);
    }
    printf("\n");

    asm volatile (
        "vsetvli t0, %1, e32, m1, d1 \n\t"     	
	    "vmv.v.x v1, %2	        \n\t"		
        "vmv.v.x v4, %3         \n\t"
        "vsetvli t0, %1, e32, m1\n\t"
        "vredmax.vs v1, v4, v1 \n\t"
        "vmv.x.s %0, v1"
        : "=r" (output) 
        : "r" (vlen) ,"r" (minimum), "r" (input[0])
    );

    if(output != golden_output) {
        printf("Test FAIL! Output: %ld\n\n", output);
        return(1);
    }else {
        printf("Test PASS! Output: %ld\n\n", output);
        return(0);
    }
}

unsigned int max_reduction_e32_m2(){
    int vlen=2;
    int32_t output, input[vlen],minimum=INT_MIN,golden_output;
    
    printf("Starting max_reduction_e32_m2 Test\n");
    golden_output=minimum;
    printf("Input : ");
    for(unsigned int i=0;i<vlen;i++){
        input[i]=rand();
        if(input[i]>golden_output){golden_output=input[i];}
        printf(" %ld ",input[i]);
    }
    printf("\n"); 
   
    asm volatile (
        "vsetvli t0, %1, e32, m1, d1 \n\t"     	
	    "vmv.v.x v1, %2	        \n\t"		
        "vmv.v.x v4, %3         \n\t"
        "vmv.v.x v5, %4       \n\t"
        "vsetvli t0, %1, e32, m2\n\t"
        "vredmax.vs v1, v4, v1 \n\t"
        "vmv.x.s %0, v1"
        : "=r" (output) 
        : "r" (vlen) ,"r" (minimum), "r" (input[0]),"r" (input[1])
    );

    if(output != golden_output) {
        printf("Test FAIL! Output: %ld\n\n", output);
        return(1);
    }else {
        printf("Test PASS! Output: %ld\n\n", output);
        return(0);
    }
}

unsigned int max_reduction_e32_m4(){
    int vlen=4;
    int32_t output, input[vlen],minimum=INT_MIN,golden_output;
    
    printf("Starting max_reduction_e32_m4 Test\n");
    golden_output=minimum;
    printf("Input : ");
    for(unsigned int i=0;i<vlen;i++){
        input[i]=rand();
        if(input[i]>golden_output){golden_output=input[i];}
        printf(" %ld ",input[i]);
    }
    printf("\n");

    asm volatile (
        "vsetvli t0, %1, e32, m1, d1 \n\t"     	
	    "vmv.v.x v1, %2	        \n\t"		
        "vmv.v.x v4, %3         \n\t"
        "vmv.v.x v5, %4       \n\t"
        "vmv.v.x v6, %5        \n\t"
        "vmv.v.x v7, %6        \n\t"
        "vsetvli t0, %1, e32, m4\n\t"
        "vredmax.vs v1, v4, v1 \n\t"
        "vmv.x.s %0, v1"
        : "=r" (output) 
        : "r" (vlen) ,"r" (minimum), "r" (input[0]),"r" (input[1]),"r" (input[2]),"r" (input[3])
    );

    if(output != golden_output) {
        printf("Test FAIL! Output: %ld\n\n", output);
        return(1);
    }else {
        printf("Test PASS! Output: %ld\n\n", output);
        return(0);
    }
}
//----------------------------------------------------------------------





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
