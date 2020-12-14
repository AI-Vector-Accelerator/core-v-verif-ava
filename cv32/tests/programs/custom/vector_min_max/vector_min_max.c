#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


int min_test_e8_m1(uint8_t vlen)
{
    printf("Starting Min e8 m1 Test...");
    uint8_t output;
    asm volatile (
        "li t1,8\n\t"
        "vsetvli t2, %1, e8\n\t"
        "vmv.v.i v1, 10\n\t"
        "vmin.vx v1, v1, t1\n\t"
        "vmv.x.s %0, v1"
        : "=r" (output)
        : "r" (vlen)
    );

    printf("Test Complete! Output: %d\n", output);
    if(output != 8)
    {
        printf("FAIL\n");
        return(1);
    }
    else
        return(0);

}

int min_test_e8_m2(uint8_t vlen)
{
    printf("Starting Min e8 m2 Test...");
    uint8_t output0, output1;
    asm volatile (
        "li t1,8\n\t"
        "vsetvli t2, %2, e8\n\t"
        "vmv.v.i v2, 10\n\t"
        "vmv.v.i v3, 8\n\t"
        "vsetvli t2, %2, e8, m2\n\t"
        "vmin.vx v4, v2, t1\n\t"
        "vsetvli t2, %1, e8\n\t"
        "vmv.x.s %0, v4\n\t"
        "vmv.x.s %1, v5"
        : "=r" (output0), "=r" (output1)
        : "r" (vlen)
    );

    printf("Test Complete! Output: v4: %d\tv5: %d\n", output0, output1);
    if(output0 != 8 || output1 != 8)
    {
        printf("FAIL\n");
        return(1);
    }
    else
        return(0);

}

int min_test_e8_m4(uint8_t vlen)
{
    printf("Starting Min e8 m4 Test...");
    uint8_t output0, output1, output2, output3;
    asm volatile (
        "li t1,8\n\t"
        "vsetvli t2, %4, e8\n\t"
        "vmv.v.i v4, 10\n\t"
        "vmv.v.i v5, 12\n\t"
        "vmv.v.i v6, 1\n\t"
        "vmv.v.i v7, 6\n\t"
        "vsetvli t2, %4, e8, m4\n\t"
        "vmin.vx v8, v4, t1\n\t"
        "vsetvli t2, %4, e8\n\t"
        "vmv.x.s %0, v8\n\t"
        "vmv.x.s %1, v9\n\t"
        "vmv.x.s %2, v10\n\t"
        "vmv.x.s %3, v11\n\t"
        : "=r" (output0), "=r" (output1), "=r" (output2), "=r" (output3)
        : "r" (vlen)
    );

    printf("Test Complete! Output: v8: %d\tv9: %d\tv10: %d\tv11: %d\n", output0, output1, output2, output3);
    if(output0 != 8 || output1 != 8 || output2 != 1 || output3 != 6)
    {
        printf("FAIL\n");
        return(1);
    }
    else
        return(0);
}



int max_test_e8_m1(uint8_t vlen)
{
    printf("Starting Max e8 m1 Test...");
    uint8_t output;
    asm volatile (
        "li t1,8\n\t"
        "vsetvli t2, %1, e8\n\t"
        "vmv.v.i v1, 10\n\t"
        "vmax.vx v1,v1, t1\n\t"
        "vmv.x.s %0, v1"
        : "=r" (output)
        : "r" (vlen)
    );

    printf("Test Complete! Output: %d\n", output);
    if(output != 10)
    {
        printf("FAIL\n");
        return(1);
    }
    else
        return(0);

}

int max_test_e8_m2(uint8_t vlen)
{
    printf("Starting Max e8 m2 Test...");
    uint8_t output0, output1;
    asm volatile (
        "li t1,8\n\t"
        "vsetvli t2, %2, e8\n\t"
        "vmv.v.i v2, 10\n\t"
        "vmv.v.i v3, 7\n\t"
        "vsetvli t2, %2, e8, m2\n\t"
        "vmax.vx v4, v2, t1\n\t"
        "vsetvli t2, %2, e8\n\t"
        "vmv.x.s %0, v4\n\t"
        "vmv.x.s %1, v5"
        : "=r" (output0), "=r" (output1)
        : "r" (vlen)
    );

    printf("Test Complete! Output: v4: %d\tv5: %d\n", output0, output1);
    if(output0 != 10 || output1 != 8)
    {
        printf("FAIL\n");
        return(1);
    }
    else
        return(0);

}

int max_test_e8_m4(uint8_t vlen)
{
    printf("Starting Max e8 m4 Test...");
    uint8_t output0, output1, output2, output3;
    uint8_t len;
    asm volatile (
        "li t1,8\n\t"
        "vsetvli %4, %5, e8\n\t"
        "vmv.v.i v4, 10\n\t"
        "vmv.v.i v5, 12\n\t"
        "vmv.v.i v6, 1\n\t"
        "vmv.v.i v7, 6\n\t"
        "vsetvli %4, %5, e8, m4\n\t"
        "vmax.vx v8, v4, t1\n\t"
        "vsetvli %4, %5, e8\n\t"
        "vmv.x.s %0, v8\n\t"
        "vmv.x.s %1, v9\n\t"
        "vmv.x.s %2, v10\n\t"
        "vmv.x.s %3, v11\n\t"
        : "=r" (output0), "=r" (output1), "=r" (output2), "=r" (output3), "=r" (len)
        : "r" (vlen)
    );


    printf("Test Complete! Output: v12: %d\tv13: %d\tv14: %d\tv15: %d\n", output0, output1, output2, output3);
    if(output0 != 10 || output1 != 12 || output2 != 8 || output3 != 8)
    {
        printf("FAIL\n");
        return(1);
    }
    else
    {
        return(0);
    }
}




int min_test_e16_m1(uint8_t vlen)
{
    printf("Starting Min e16 m1 Test...");
    uint8_t output;
    asm volatile (
        "li t1,8\n\t"
        "vsetvli t2, %1, e16\n\t"
        "vmv.v.i v1, 10\n\t"
        "vmin.vx v1, v1, t1\n\t"
        "vmv.x.s %0, v1"
        : "=r" (output)
        : "r" (vlen)
    );

    printf("Test Complete! Output: %d\n", output);
    if(output != 8)
    {
        printf("FAIL\n");
        return(1);
    }
    else
        return(0);

}

int min_test_e16_m2(uint8_t vlen)
{
    printf("Starting Min e16 m2 Test...");
    uint8_t output0, output1;
    asm volatile (
        "li t1,8\n\t"
        "vsetvli t2, %2, e16\n\t"
        "vmv.v.i v2, 10\n\t"
        "vmv.v.i v3, 7\n\t"
        "vsetvli t2, %2, e16, m2\n\t"
        "vmin.vx v4, v2, t1\n\t"
        "vsetvli t2, %2, e16\n\t"
        "vmv.x.s %0, v4\n\t"
        "vmv.x.s %1, v5"
        : "=r" (output0), "=r" (output1)
        : "r" (vlen)
    );

    printf("Test Complete! Output: v4: %d\tv5: %d\n", output0, output1);
    if(output0 != 8 || output1 != 7)
    {
        printf("FAIL\n");
        return(1);
    }
    else
        return(0);

}

int min_test_e16_m4(uint8_t vlen)
{
    printf("Starting Min e16 m4 Test...");
    uint8_t output0, output1, output2, output3;
    asm volatile (
        "li t1,8\n\t"
        "vsetvli t2, %4, e16\n\t"
        "vmv.v.i v4, 10\n\t"
        "vmv.v.i v5, 12\n\t"
        "vmv.v.i v6, 1\n\t"
        "vmv.v.i v7, 6\n\t"
        "vsetvli t2, %4, e16, m4\n\t"
        "vmin.vx v8, v4, t1\n\t"
        "vsetvli t2, %4, e16\n\t"
        "vmv.x.s %0, v8\n\t"
        "vmv.x.s %1, v9\n\t"
        "vmv.x.s %2, v10\n\t"
        "vmv.x.s %3, v11\n\t"
        : "=r" (output0), "=r" (output1), "=r" (output2), "=r" (output3)
        : "r" (vlen)
    );

    printf("Test Complete! Output: v8: %d\tv9: %d\tv10: %d\tv11: %d\n", output0, output1, output2, output3);
    if(output0 != 8 || output1 != 8 || output2 != 1 || output3 != 6)
    {
        printf("FAIL\n");
        return(1);
    }
    else
        return(0);
}



int max_test_e16_m1(uint8_t vlen)
{
    printf("Starting Max e16 m1 Test...");
    uint8_t output;
    asm volatile (
        "li t1,8\n\t"
        "vsetvli t2, %1, e16\n\t"
        "vmv.v.i v1, 10\n\t"
        "vmax.vx v1, v1, t1\n\t"
        "vmv.x.s %0, v1"
        : "=r" (output)
        : "r" (vlen)
    );

    printf("Test Complete! Output: %d\n", output);
    if(output != 10)
    {
        printf("FAIL\n");
        return(1);
    }
    else
        return(0);

}

int max_test_e16_m2(uint8_t vlen)
{
    printf("Starting Max e16 m2 Test...");
    uint8_t output0, output1;
    asm volatile (
        "li t1,8\n\t"
        "vsetvli t2, %2, e16\n\t"
        "vmv.v.i v2, 10\n\t"
        "vmv.v.i v3, 7\n\t"
        "vsetvli t2, %2, e16, m2\n\t"
        "vmax.vx v4, v2, t1\n\t"
        "vsetvli t2, %2, e16\n\t"
        "vmv.x.s %0, v4\n\t"
        "vmv.x.s %1, v5"
        : "=r" (output0), "=r" (output1)
        : "r" (vlen)
    );

    printf("Test Complete! Output: v4: %d\tv5: %d\n", output0, output1);
    if(output0 != 10 || output1 != 8)
    {
        printf("FAIL\n");
        return(1);
    }
    else
        return(0);

}

int max_test_e16_m4(uint8_t vlen)
{
    printf("Starting Max e16 m4 Test...");
    uint8_t output0, output1, output2, output3;
    uint8_t len;
    asm volatile (
        "li t1,8\n\t"
        "vsetvli %4, %5, e16\n\t"
        "vmv.v.i v4, 10\n\t"
        "vmv.v.i v5, 12\n\t"
        "vmv.v.i v6, 1\n\t"
        "vmv.v.i v7, 6\n\t"
        "vsetvli %4, %5, e16, m4\n\t"
        "vmax.vx v8, v4, t1\n\t"
        "vsetvli t2, %5, e16\n\t"
        "vmv.x.s %0, v8\n\t"
        "vmv.x.s %1, v9\n\t"
        "vmv.x.s %2, v10\n\t"
        "vmv.x.s %3, v11\n\t"
        : "=r" (output0), "=r" (output1), "=r" (output2), "=r" (output3), "=r" (len)
        : "r" (vlen)
    );


    printf("Test Complete! Output: v12: %d\tv13: %d\tv14: %d\tv15: %d\n", output0, output1, output2, output3);
    if(output0 != 10 || output1 != 12 || output2 != 8 || output3 != 8)
    {
        printf("FAIL\n");
        return(1);
    }
    else
    {
        return(0);
    }
}


int min_test_e32_m1(uint8_t vlen)
{
    printf("Starting Min e32 m1 Test...");
    uint8_t output;
    asm volatile (
        "li t1,8\n\t"
        "vsetvli t2, %1, e32\n\t"
        "vmv.v.i v1, 10\n\t"
        "vmin.vx v1, v1, t1\n\t"
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

int min_test_e32_m2(uint8_t vlen)
{
    printf("Starting Min e32 m2 Test...");
    uint8_t output0, output1;
    asm volatile (
        "li t1,8\n\t"
        "vsetvli t2, %2, e32\n\t"
        "vmv.v.i v2, 10\n\t"
        "vmv.v.i v3, 7\n\t"
        "vsetvli t2, %2, e32, m2\n\t"
        "vmin.vx v4, v2, t1\n\t"
        "vsetvli t2, %2, e32\n\t"
        "vmv.x.s %0, v4\n\t"
        "vmv.x.s %1, v5"
        : "=r" (output0), "=r" (output1)
        : "r" (vlen)
    );

    printf("Test Complete! Output: v4: %d\tv5: %d\n", output0, output1);
    if(output0 != 8 || output1 != 7)
    {
        printf("FAIL\n");
        return(1);
    }
    else
        return(0);

}

int min_test_e32_m4(uint8_t vlen)
{
    printf("Starting Min e32 m4 Test...");
    uint8_t output0, output1, output2, output3;
    asm volatile (
        "li t1,8\n\t"
        "vsetvli t2, %4, e32\n\t"
        "vmv.v.i v4, 10\n\t"
        "vmv.v.i v5, 12\n\t"
        "vmv.v.i v6, 1\n\t"
        "vmv.v.i v7, 6\n\t"
        "vsetvli t2, %4, e32, m4\n\t"
        "vmin.vx v8, v4, t1\n\t"
        "vsetvli t2, %4, e32\n\t"
        "vmv.x.s %0, v8\n\t"
        "vmv.x.s %1, v9\n\t"
        "vmv.x.s %2, v10\n\t"
        "vmv.x.s %3, v11\n\t"
        : "=r" (output0), "=r" (output1), "=r" (output2), "=r" (output3)
        : "r" (vlen)
    );

    printf("Test Complete! Output: v8: %d\tv9: %d\tv10: %d\tv11: %d\n", output0, output1, output2, output3);
    if(output0 != 8 || output1 != 8 || output2 != 1 || output3 != 6)
    {
        printf("FAIL\n");
        return(1);
    }
    else
        return(0);
}



int max_test_e32_m1(uint8_t vlen)
{
    printf("Starting Max e32 m1 Test...");
    uint8_t output;
    asm volatile (
        "li t1,8\n\t"
        "vsetvli t2, %1, e32\n\t"
        "vmv.v.i v1, 10\n\t"
        "vmax.vx v1, v1, t1\n\t"
        "vmv.x.s %0, v1"
        : "=r" (output)
        : "r" (vlen)
    );

    printf("Test Complete! Output: %d\n", output);
    if(output != 10)
    {
        printf("FAIL\n");
        return(1);
    }
    else
        return(0);

}

int max_test_e32_m2(uint8_t vlen)
{
    printf("Starting Max e32 m2 Test...");
    uint8_t output0, output1;
    asm volatile (
        "li t1,8\n\t"
        "vsetvli t2, %2, e32\n\t"
        "vmv.v.i v2, 10\n\t"
        "vmv.v.i v3, 7\n\t"
        "vsetvli t2, %2, e32, m2\n\t"
        "vmax.vx v4, v2, t1\n\t"
        "vsetvli t2, %2, e32\n\t"
        "vmv.x.s %0, v4\n\t"
        "vmv.x.s %1, v5"
        : "=r" (output0), "=r" (output1)
        : "r" (vlen)
    );

    printf("Test Complete! Output: v4: %d\tv5: %d\n", output0, output1);
    if(output0 != 10 || output1 != 8)
    {
        printf("FAIL\n");
        return(1);
    }
    else
        return(0);

}

int max_test_e32_m4(uint8_t vlen)
{
    printf("Starting Max e32 m4 Test...");
    uint8_t output0, output1, output2, output3;
    uint8_t len;
    asm volatile (
        "li t1,8\n\t"
        "vsetvli %4, %5, e32\n\t"
        "vmv.v.i v4, 10\n\t"
        "vmv.v.i v5, 12\n\t"
        "vmv.v.i v6, 1\n\t"
        "vmv.v.i v7, 6\n\t"
        "vsetvli %4, %5, e32, m4\n\t"
        "vmax.vx v8, v4, t1\n\t"
        "vsetvli t2, %5, e32\n\t"
        "vmv.x.s %0, v8\n\t"
        "vmv.x.s %1, v9\n\t"
        "vmv.x.s %2, v10\n\t"
        "vmv.x.s %3, v11\n\t"
        : "=r" (output0), "=r" (output1), "=r" (output2), "=r" (output3), "=r" (len)
        : "r" (vlen)
    );

    printf("Test Complete! Output: v12: %d\tv13: %d\tv14: %d\tv15: %d\n", output0, output1, output2, output3);
    if(output0 != 10 || output1 != 12 || output2 != 8 || output3 != 8)
    {
        printf("FAIL\n");
        return(1);
    }
    else
    {
        return(0);
    }
}


int main(int argc, char *argv[])
{
    printf("Beginning Vector Min Max Test...\n\n");
    // printf("This program writes the number 8 into a t1\n");
    // printf("then it gets min or maxed with 10\n");
    // printf("This is performed for 8, 16, and 32 bit wide vector registers.\n");
    // printf("This gives a total of 6 tests.\n\n");


    int errors = 0;

    errors += min_test_e8_m1(64);
    errors += min_test_e8_m2(64);
    errors += min_test_e8_m4(64);
    printf("\n");
    errors += max_test_e8_m1(64);
    errors += max_test_e8_m2(64);
    errors += max_test_e8_m4(64);
    printf("\n\n");
    errors += min_test_e16_m1(64);
    errors += min_test_e16_m2(64);
    errors += min_test_e16_m4(64);
    printf("\n");
    errors += max_test_e16_m1(64);
    errors += max_test_e16_m2(64);
    errors += max_test_e16_m4(64);
    printf("\n\n");
    errors += min_test_e32_m1(64);
    errors += min_test_e32_m2(64);
    errors += min_test_e32_m4(64);
    printf("\n");
    errors += max_test_e32_m1(64);
    errors += max_test_e32_m2(64);
    errors += max_test_e32_m4(64);



    if(errors > 0)
    {
        printf("\nErrors Detected!\nError Count: %d\n", errors);
        return(EXIT_FAILURE);
    }

    printf("\nAll Tests Completed\nNo Errors Detected!\n");

    return(EXIT_SUCCESS);
}