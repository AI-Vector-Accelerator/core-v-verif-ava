#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


int shift_left_test_e8_m1(uint8_t vlen)
{
    printf("Starting Left Shift e8 m1 Test...");
    uint8_t output;
    asm volatile (
        "vsetvli t2, %1, e8\n\t"
        "vmv.v.i v1, 4\n\t"
        "vsll.vi v1, v1, 1\n\t"
        "vmv.x.s %0, v1"
        : "=r" (output)
        : "r" (vlen)
    );

    if(output != 8) {
        printf("Test FAIL! Output: %d\n", output);
        return(1);
    } else {
        printf("Test PASS! Output: %d\n", output);
        return(0);
    }


}

int shift_left_test_e8_m2(uint8_t vlen)
{
    printf("Starting Left Shift e8 m2 Test...");
    uint8_t output0, output1;
    asm volatile (
        "vsetvli t2, %2, e8\n\t"
        "vmv.v.i v2, 2\n\t"
        "vmv.v.i v3, 4\n\t"
        "vsetvli t2, %2, e8, m2\n\t"
        "vsll.vi v4, v2, 1\n\t"
        "vsetvli t2, %2, e8\n\t"
        "vmv.x.s %0, v4\n\t"
        "vmv.x.s %1, v5"
        : "=r" (output0), "=r" (output1)
        : "r" (vlen)
    );

    if(output0 != 4 || output1 != 8) {
        printf("Test FAIL! Output: v4: %d\tv5: %d\n", output0, output1);
        return(1);
    } else {
        printf("Test PASS! Output: v4: %d\tv5: %d\n", output0, output1);
        return(0);
    }

}

int shift_left_test_e8_m4(uint8_t vlen)
{
    printf("Starting Left Shift e8 m4 Test...");
    uint8_t output0, output1, output2, output3;
    asm volatile (
        "vsetvli t2, %4, e8\n\t"
        "vmv.v.i v4, 1\n\t"
        "vmv.v.i v5, 2\n\t"
        "vmv.v.i v6, 4\n\t"
        "vmv.v.i v7, 8\n\t"
        "vsetvli t2, %4, e8, m4\n\t"
        "vsll.vi v8, v4, 1\n\t"
        "vsetvli t2, %4, e8\n\t"
        "vmv.x.s %0, v8\n\t"
        "vmv.x.s %1, v9\n\t"
        "vmv.x.s %2, v10\n\t"
        "vmv.x.s %3, v11\n\t"
        : "=r" (output0), "=r" (output1), "=r" (output2), "=r" (output3)
        : "r" (vlen)
    );

    if(output0 != 2 || output1 != 4 || output2 != 8 || output3 != 16) {
        printf("Test FAIL! Output: v8: %d\tv9: %d\tv10: %d\tv11: %d\n", output0, output1, output2, output3);
        return(1);
    } else {
        printf("Test PASS! Output: v8: %d\tv9: %d\tv10: %d\tv11: %d\n", output0, output1, output2, output3);
        return(0);
    }
}



int shift_right_test_e8_m1(uint8_t vlen)
{
    printf("Starting Right Shift e8 m1 Test...");
    uint8_t output;
    asm volatile (
        "vsetvli t2, %1, e8\n\t"
        "vmv.v.i v1, 4\n\t"
        "vsrl.vi v1, v1, 1\n\t"
        "vmv.x.s %0, v1"
        : "=r" (output)
        : "r" (vlen)
    );

    if(output != 2) {
        printf("Test FAIL! Output: %d\n", output);
        return(1);
    } else {
        printf("Test PASS! Output: %d\n", output);
        return(0);
    }

}

int shift_right_test_e8_m2(uint8_t vlen)
{
    printf("Starting Right Shift e8 m2 Test...");
    uint8_t output0, output1;
    asm volatile (
        "vsetvli t2, %2, e8\n\t"
        "vmv.v.i v2, 2\n\t"
        "vmv.v.i v3, 4\n\t"
        "vsetvli t2, %2, e8, m2\n\t"
        "vsrl.vi v4, v2, 1\n\t"
        "vsetvli t2, %2, e8\n\t"
        "vmv.x.s %0, v4\n\t"
        "vmv.x.s %1, v5"
        : "=r" (output0), "=r" (output1)
        : "r" (vlen)
    );

    if(output0 != 1 || output1 != 2) {
        printf("Test FAIL! Output: v4: %d\tv5: %d\n", output0, output1);
        return(1);
    } else {
        printf("Test PASS! Output: v4: %d\tv5: %d\n", output0, output1);
        return(0);
    }

}

int shift_right_test_e8_m4(uint8_t vlen)
{
    printf("Starting Right Shift e8 m4 Test...");
    uint8_t output0, output1, output2, output3;
    asm volatile (
        "vsetvli t2, %4, e8\n\t"
        "vmv.v.i v4, 1\n\t"
        "vmv.v.i v5, 2\n\t"
        "vmv.v.i v6, 4\n\t"
        "vmv.v.i v7, 8\n\t"
        "vsetvli t2, %4, e8, m4\n\t"
        "vsrl.vi v8, v4, 1\n\t"
        "vsetvli t2, %4, e8\n\t"
        "vmv.x.s %0, v8\n\t"
        "vmv.x.s %1, v9\n\t"
        "vmv.x.s %2, v10\n\t"
        "vmv.x.s %3, v11\n\t"
        : "=r" (output0), "=r" (output1), "=r" (output2), "=r" (output3)
        : "r" (vlen)
    );

    if(output0 != 0 || output1 != 1 || output2 != 2 || output3 != 4) {
        printf("Test FAIL! Output: v8: %d\tv9: %d\tv10: %d\tv11: %d\n", output0, output1, output2, output3);
        return(1);
    } else {
        printf("Test PASS! Output: v8: %d\tv9: %d\tv10: %d\tv11: %d\n", output0, output1, output2, output3);
        return(0);
    }
}




int shift_left_test_e16_m1(uint8_t vlen)
{
    printf("Starting Left Shift e16 m1 Test...");
    uint8_t output;
    asm volatile (
        "vsetvli t2, %1, e16\n\t"
        "vmv.v.i v1, 4\n\t"
        "vsll.vi v1, v1, 1\n\t"
        "vmv.x.s %0, v1"
        : "=r" (output)
        : "r" (vlen)
    );

    if(output != 8) {
        printf("Test FAIL! Output: %d\n", output);
        return(1);
    } else {
        printf("Test PASS! Output: %d\n", output);
        return(0);
    }
}

int shift_left_test_e16_m2(uint8_t vlen)
{
    printf("Starting Left Shift e16 m2 Test...");
    uint8_t output0, output1;
    asm volatile (
        "vsetvli t2, %2, e16\n\t"
        "vmv.v.i v2, 2\n\t"
        "vmv.v.i v3, 4\n\t"
        "vsetvli t2, %2, e16, m2\n\t"
        "vsll.vi v4, v2, 1\n\t"
        "vsetvli t2, %2, e16\n\t"
        "vmv.x.s %0, v4\n\t"
        "vmv.x.s %1, v5"
        : "=r" (output0), "=r" (output1)
        : "r" (vlen)
    );

    if(output0 != 4 || output1 != 8) {
        printf("Test FAIL! Output: v4: %d\tv5: %d\n", output0, output1);
        return(1);
    } else {
        printf("Test PASS! Output: v4: %d\tv5: %d\n", output0, output1);
        return(0);
    }
}

int shift_left_test_e16_m4(uint8_t vlen)
{
    printf("Starting Left Shift e16 m4 Test...");
    uint8_t output0, output1, output2, output3;
    asm volatile (
        "vsetvli t2, %4, e16\n\t"
        "vmv.v.i v4, 1\n\t"
        "vmv.v.i v5, 2\n\t"
        "vmv.v.i v6, 4\n\t"
        "vmv.v.i v7, 8\n\t"
        "vsetvli t2, %4, e16, m4\n\t"
        "vsll.vi v8, v4, 1\n\t"
        "vsetvli t2, %4, e16\n\t"
        "vmv.x.s %0, v8\n\t"
        "vmv.x.s %1, v9\n\t"
        "vmv.x.s %2, v10\n\t"
        "vmv.x.s %3, v11\n\t"
        : "=r" (output0), "=r" (output1), "=r" (output2), "=r" (output3)
        : "r" (vlen)
    );

    if(output0 != 2 || output1 != 4 || output2 != 8 || output3 != 16) {
        printf("Test FAIL! Output: v8: %d\tv9: %d\tv10: %d\tv11: %d\n", output0, output1, output2, output3);
        return(1);
    } else {
        printf("Test PASS! Output: v8: %d\tv9: %d\tv10: %d\tv11: %d\n", output0, output1, output2, output3);
        return(0);
    }
}



int shift_right_test_e16_m1(uint8_t vlen)
{
    printf("Starting Right Shift e16 m1 Test...");
    uint8_t output;
    asm volatile (
        "vsetvli t2, %1, e16\n\t"
        "vmv.v.i v1, 4\n\t"
        "vsrl.vi v1, v1, 1\n\t"
        "vmv.x.s %0, v1"
        : "=r" (output)
        : "r" (vlen)
    );

    if(output != 2) {
        printf("Test FAIL! Output: %d\n", output);
        return(1);
    } else {
        printf("Test PASS! Output: %d\n", output);
        return(0);
    }
}

int shift_right_test_e16_m2(uint8_t vlen)
{
    printf("Starting Right Shift e16 m2 Test...");
    uint8_t output0, output1;
    asm volatile (
        "vsetvli t2, %2, e16\n\t"
        "vmv.v.i v2, 2\n\t"
        "vmv.v.i v3, 4\n\t"
        "vsetvli t2, %2, e16, m2\n\t"
        "vsrl.vi v4, v2, 1\n\t"
        "vsetvli t2, %2, e16\n\t"
        "vmv.x.s %0, v4\n\t"
        "vmv.x.s %1, v5"
        : "=r" (output0), "=r" (output1)
        : "r" (vlen)
    );

    if(output0 != 1 || output1 != 2) {
        printf("Test FAIL! Output: v4: %d\tv5: %d\n", output0, output1);
        return(1);
    } else {
        printf("Test PASS! Output: v4: %d\tv5: %d\n", output0, output1);
        return(0);
    }
}

int shift_right_test_e16_m4(uint8_t vlen)
{
    printf("Starting Right Shift e16 m4 Test...");
    uint8_t output0, output1, output2, output3;
    asm volatile (
        "vsetvli t2, %4, e16\n\t"
        "vmv.v.i v4, 1\n\t"
        "vmv.v.i v5, 2\n\t"
        "vmv.v.i v6, 4\n\t"
        "vmv.v.i v7, 8\n\t"
        "vsetvli t2, %4, e16, m4\n\t"
        "vsrl.vi v8, v4, 1\n\t"
        "vsetvli t2, %4, e16\n\t"
        "vmv.x.s %0, v8\n\t"
        "vmv.x.s %1, v9\n\t"
        "vmv.x.s %2, v10\n\t"
        "vmv.x.s %3, v11\n\t"
        : "=r" (output0), "=r" (output1), "=r" (output2), "=r" (output3)
        : "r" (vlen)
    );

    if(output0 != 0 || output1 != 1 || output2 != 2 || output3 != 4) {
        printf("Test FAIL! Output: v8: %d\tv9: %d\tv10: %d\tv11: %d\n", output0, output1, output2, output3);
        return(1);
    } else {
        printf("Test PASS! Output: v8: %d\tv9: %d\tv10: %d\tv11: %d\n", output0, output1, output2, output3);
        return(0);
    }
}


int shift_left_test_e32_m1(uint8_t vlen)
{
    printf("Starting Left Shift e32 m1 Test...");
    uint8_t output;
    asm volatile (
        "vsetvli t2, %1, e32\n\t"
        "vmv.v.i v1, 4\n\t"
        "vsll.vi v1, v1, 1\n\t"
        "vmv.x.s %0, v1"
        : "=r" (output)
        : "r" (vlen)
    );

    if(output != 8) {
        printf("Test FAIL! Output: %d\n", output);
        return(1);
    } else {
        printf("Test PASS! Output: %d\n", output);
        return(0);
    }
}

int shift_left_test_e32_m2(uint8_t vlen)
{
    printf("Starting Left Shift e32 m2 Test...");
    uint8_t output0, output1;
    asm volatile (
        "vsetvli t2, %2, e32\n\t"
        "vmv.v.i v2, 2\n\t"
        "vmv.v.i v3, 4\n\t"
        "vsetvli t2, %2, e32, m2\n\t"
        "vsll.vi v4, v2, 1\n\t"
        "vsetvli t2, %2, e32\n\t"
        "vmv.x.s %0, v4\n\t"
        "vmv.x.s %1, v5"
        : "=r" (output0), "=r" (output1)
        : "r" (vlen)
    );

    if(output0 != 4 || output1 != 8) {
        printf("Test FAIL! Output: v4: %d\tv5: %d\n", output0, output1);
        return(1);
    } else {
        printf("Test PASS! Output: v4: %d\tv5: %d\n", output0, output1);
        return(0);
    }
}

int shift_left_test_e32_m4(uint8_t vlen)
{
    printf("Starting Left Shift e32 m4 Test...");
    uint8_t output0, output1, output2, output3;
    asm volatile (
        "vsetvli t2, %4, e32\n\t"
        "vmv.v.i v4, 1\n\t"
        "vmv.v.i v5, 2\n\t"
        "vmv.v.i v6, 4\n\t"
        "vmv.v.i v7, 8\n\t"
        "vsetvli t2, %4, e32, m4\n\t"
        "vsll.vi v8, v4, 1\n\t"
        "vsetvli t2, %4, e32\n\t"
        "vmv.x.s %0, v8\n\t"
        "vmv.x.s %1, v9\n\t"
        "vmv.x.s %2, v10\n\t"
        "vmv.x.s %3, v11\n\t"
        : "=r" (output0), "=r" (output1), "=r" (output2), "=r" (output3)
        : "r" (vlen)
    );

    if(output0 != 2 || output1 != 4 || output2 != 8 || output3 != 16) {
        printf("Test FAIL! Output: v8: %d\tv9: %d\tv10: %d\tv11: %d\n", output0, output1, output2, output3);
        return(1);
    } else {
        printf("Test PASS! Output: v8: %d\tv9: %d\tv10: %d\tv11: %d\n", output0, output1, output2, output3);
        return(0);
    }
}



int shift_right_test_e32_m1(uint8_t vlen)
{
    printf("Starting Right Shift e32 m1 Test...");
    uint8_t output;
    asm volatile (
        "vsetvli t2, %1, e32\n\t"
        "vmv.v.i v1, 4\n\t"
        "vsrl.vi v1, v1, 1\n\t"
        "vmv.x.s %0, v1"
        : "=r" (output)
        : "r" (vlen)
    );

    if(output != 2) {
        printf("Test FAIL! Output: %d\n", output);
        return(1);
    } else {
        printf("Test PASS! Output: %d\n", output);
        return(0);
    }
}

int shift_right_test_e32_m2(uint8_t vlen)
{
    printf("Starting Right Shift e32 m2 Test...");
    uint8_t output0, output1;
    asm volatile (
        "vsetvli t2, %2, e32\n\t"
        "vmv.v.i v2, 2\n\t"
        "vmv.v.i v3, 4\n\t"
        "vsetvli t2, %2, e32, m2\n\t"
        "vsrl.vi v4, v2, 1\n\t"
        "vsetvli t2, %2, e32\n\t"
        "vmv.x.s %0, v4\n\t"
        "vmv.x.s %1, v5"
        : "=r" (output0), "=r" (output1)
        : "r" (vlen)
    );

    if(output0 != 1 || output1 != 2) {
        printf("Test FAIL! Output: v4: %d\tv5: %d\n", output0, output1);
        return(1);
    } else {
        printf("Test PASS! Output: v4: %d\tv5: %d\n", output0, output1);
        return(0);
    }

}

int shift_right_test_e32_m4(uint8_t vlen)
{
    printf("Starting Right Shift e32 m4 Test...");
    uint8_t output0, output1, output2, output3;
    asm volatile (
        "vsetvli t2, %4, e32\n\t"
        "vmv.v.i v4, 1\n\t"
        "vmv.v.i v5, 2\n\t"
        "vmv.v.i v6, 4\n\t"
        "vmv.v.i v7, 8\n\t"
        "vsetvli t2, %4, e32, m4\n\t"
        "vsrl.vi v8, v4, 1\n\t"
        "vsetvli t2, %4, e32\n\t"
        "vmv.x.s %0, v8\n\t"
        "vmv.x.s %1, v9\n\t"
        "vmv.x.s %2, v10\n\t"
        "vmv.x.s %3, v11\n\t"
        : "=r" (output0), "=r" (output1), "=r" (output2), "=r" (output3)
        : "r" (vlen)
    );

    if(output0 != 0 || output1 != 1 || output2 != 2 || output3 != 4) {
        printf("Test FAIL! Output: v8: %d\tv9: %d\tv10: %d\tv11: %d\n", output0, output1, output2, output3);
        return(1);
    } else {
        printf("Test PASS! Output: v8: %d\tv9: %d\tv10: %d\tv11: %d\n", output0, output1, output2, output3);
        return(0);
    }
}


int main(int argc, char *argv[])
{
    printf("Beginning Vector Shift Test...\n\n");
    // printf("This program writes the number 4 into a vector register\n");
    // printf("then either shifts it left or right.\n");
    // printf("This is performed for 8, 16, and 32 bit wide vector registers.\n");
    // printf("This gives a total of 6 tests.\n\n");


    int errors = 0;

    errors += shift_left_test_e8_m1(64);
    errors += shift_left_test_e8_m2(64);
    errors += shift_left_test_e8_m4(64);
    printf("\n");
    errors += shift_right_test_e8_m1(64);
    errors += shift_right_test_e8_m2(64);
    errors += shift_right_test_e8_m4(64);
    printf("\n\n");
    errors += shift_left_test_e16_m1(64);
    errors += shift_left_test_e16_m2(64);
    errors += shift_left_test_e16_m4(64);
    printf("\n");
    errors += shift_right_test_e16_m1(64);
    errors += shift_right_test_e16_m2(64);
    errors += shift_right_test_e16_m4(64);
    printf("\n\n");
    errors += shift_left_test_e32_m1(64);
    errors += shift_left_test_e32_m2(64);
    errors += shift_left_test_e32_m4(64);
    printf("\n");
    errors += shift_right_test_e32_m1(64);
    errors += shift_right_test_e32_m2(64);
    errors += shift_right_test_e32_m4(64);



    if(errors > 0)
    {
        printf("\nErrors Detected!\nError Count: %d\n", errors);
        return(EXIT_FAILURE);
    }

    printf("\nAll Tests Completed\nNo Errors Detected!\n");

    return(EXIT_SUCCESS);
}