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

    printf("Test Complete! Output: %d\n", output);
    if(output != 8)
        return(1);
    else
        return(0);
    
}


int shift_right_test_e8(uint8_t vlen) 
{
    printf("Starting Right Shift e8 Test...");
    uint8_t output;
    asm volatile (
        "vsetvli t2, %1, e8\n\t"
        "vmv.v.i v1, 4\n\t"
        "vsrl.vi v1, v1, 1\n\t"
        "vmv.x.s %0, v1"
        : "=r" (output)
        : "r" (vlen)
    );

    printf("Test Complete! Output: %d\n", output);
    if(output != 2)
        return(1);
    else
        return(0);

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

    printf("Test Complete! Output: %d\n", output);
    if(output != 8)
        return(1);
    else
        return(0);
    
}


int shift_right_test_e16(uint8_t vlen) 
{
    printf("Starting Right Shift e16 Test...");
    uint8_t output;
    asm volatile (
        "vsetvli t2, %1, e16\n\t"
        "vmv.v.i v1, 4\n\t"
        "vsrl.vi v1, v1, 1\n\t"
        "vmv.x.s %0, v1"
        : "=r" (output)
        : "r" (vlen)
    );

    printf("Test Complete! Output: %d\n", output);
    if(output != 2)
        return(1);
    else
        return(0);

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

    printf("Test Complete! Output: %d\n", output);
    if(output != 8)
        return(1);
    else
        return(0);
    
}


int shift_right_test_e32(uint8_t vlen) 
{
    printf("Starting Right Shift e32 Test...");
    uint8_t output;
    asm volatile (
        "vsetvli t2, %1, e32\n\t"
        "vmv.v.i v1, 4\n\t"
        "vsrl.vi v1, v1, 1\n\t"
        "vmv.x.s %0, v1"
        : "=r" (output)
        : "r" (vlen)
    );

    printf("Test Complete! Output: %d\n", output);
    if(output != 2)
        return(1);
    else
        return(0);

}



int main(int argc, char *argv[])
{
    printf("Beginning Vector Shift Test...\n\n");
    printf("This program writes the number 4 into a vector register\n");
    printf("then either shifts it left or right.\n");
    printf("This is performed for 8, 16, and 32 bit wide vector registers.\n");
    printf("This gives a total of 6 tests.\n\n");


    int errors = 0;

    errors += shift_left_test_e8(4);
    errors += shift_right_test_e8(4);

    errors += shift_left_test_e16(4);
    errors += shift_right_test_e16(4);

    errors += shift_left_test_e32(4);
    errors += shift_right_test_e32(4);

    if(errors > 0)
    {
        printf("\nErrors Detected!\nError Count: %d\n", errors);
        return(EXIT_FAILURE);
    }

    printf("\nAll Tests Completed\nNo Errors Detected!\n");

    return(EXIT_SUCCESS);
}