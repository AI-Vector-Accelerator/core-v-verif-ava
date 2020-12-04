#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


int shift_left_test_e8(uint8_t vlen) 
{
    printf("Starting Left Shift e8 Test...");
    uint8_t output;
    asm volatile (
        "vsetvli t2, %1, e8\n\t"
        "vmv.v.i v1, 4\n\t"
        "vsll.vi v1, v1, 1\n\t"
        "vmv.x.s %0, v1"
        : "=r" (output)
        : "r" (vlen)
    );

    printf("Test Complete!\n");
    if(output != 8)
        return(0);
    else
        return(1);
    
}


int shift_right_test_e8(uint8_t vlen) 
{
    printf("Starting Left Shift e8 Test...");
    uint8_t output;
    asm volatile (
        "vsetvli t2, %1, e8\n\t"
        "vmv.v.i v1, 4\n\t"
        "vsrl.vi v1, v1, 1\n\t"
        "vmv.x.s %0, v1"
        : "=r" (output)
        : "r" (vlen)
    );

    printf("Test Complete!\n");
    if(output != 2)
        return(0);
    else
        return(1);

}


int shift_left_test_e16(uint8_t vlen) 
{
    printf("Starting Left Shift e16 Test...");
    uint8_t output;
    asm volatile (
        "vsetvli t2, %1, e16\n\t"
        "vmv.v.i v1, 4\n\t"
        "vsll.vi v1, v1, 1\n\t"
        "vmv.x.s %0, v1"
        : "=r" (output)
        : "r" (vlen)
    );

    printf("Test Complete!\n");
    if(output != 8)
        return(0);
    else
        return(1);
    
}


int shift_right_test_e16(uint8_t vlen) 
{
    printf("Starting Left Shift e16 Test...");
    uint8_t output;
    asm volatile (
        "vsetvli t2, %1, e16\n\t"
        "vmv.v.i v1, 4\n\t"
        "vsrl.vi v1, v1, 1\n\t"
        "vmv.x.s %0, v1"
        : "=r" (output)
        : "r" (vlen)
    );

    printf("Test Complete!\n");
    if(output != 2)
        return(0);
    else
        return(1);

}


int shift_left_test_e32(uint8_t vlen) 
{
    printf("Starting Left Shift e32 Test...");
    uint8_t output;
    asm volatile (
        "vsetvli t2, %1, e32\n\t"
        "vmv.v.i v1, 4\n\t"
        "vsll.vi v1, v1, 1\n\t"
        "vmv.x.s %0, v1"
        : "=r" (output)
        : "r" (vlen)
    );

    printf("Test Complete!\n");
    if(output != 8)
        return(0);
    else
        return(1);
    
}


int shift_right_test_e32(uint8_t vlen) 
{
    printf("Starting Left Shift e32 Test...");
    uint8_t output;
    asm volatile (
        "vsetvli t2, %1, e32\n\t"
        "vmv.v.i v1, 4\n\t"
        "vsrl.vi v1, v1, 1\n\t"
        "vmv.x.s %0, v1"
        : "=r" (output)
        : "r" (vlen)
    );

    printf("Test Complete!\n");
    if(output != 2)
        return(0);
    else
        return(1);

}



int main(int argc, char *argv[])
{
    printf("Beginning Vector Shift Test...\n\n");

    int errors = 0;

    errors += shift_left_test_e8(4);
    errors += shift_right_test_e8(4);

    errors += shift_left_test_e16(4);
    errors += shift_right_test_e16(4);

    errors += shift_left_test_e32(4);
    errors += shift_right_test_e32(4);

    if(errors > 0)
        return(EXIT_FAILURE);

    printf("All Tests Completed!\n");

    return(EXIT_SUCCESS);
}