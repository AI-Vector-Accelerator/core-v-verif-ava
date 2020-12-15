#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int sub_vv_test_e8_m1(void)
{
    int result;
    asm volatile (
        "li t1, 7 \n\t"
        "vsetvli t0, t1, e8, m1 \n\t"
        "vmv.v.i v1, 15 \n\t"
        "vmv.v.i v2, 7 \n\t"
        "vsub.vv v3, v1, v2 \n\t"
        "vmv.x.s %0, v3"
        : "=r" (result) 
    );

    if(result != 8)
    {
        printf("Fail: %d\n", result);
        return(1);
    }
    else
    {
        printf("Pass: %d\n", result);
        return(0);
    }
}

int sub_vv_test_e8_m2(void)
{
    int result0, result1;
    asm volatile (
        "li t1, 7 \n\t"
        "vsetvli t0, t1, e8, m1 \n\t"
        "vmv.v.i v2, 15 \n\t"
        "vmv.v.i v3, 7 \n\t"
        "vmv.v.i v4, 2 \n\t"
        "vmv.v.i v5, 4 \n\t"
        "vsetvli t0, t1, e8, m2 \n\t"
        "vsub.vv v2, v2, v4 \n\t"
        "vsetvli t0, t1, e8, m1 \n\t"
        "vmv.x.s %0, v2\n\t"
        "vmv.x.s %1, v3\n\t"
        : "=r" (result0), "=r" (result1)
    );

    if(result0 != 13 || result1 != 3)
    {
        printf("Fail: %d %d\n", result0, result1);
        return(1);
    }
    else
    {
        printf("Pass: %d %d\n", result0, result1);
        return(0);
    }
}

int sub_vv_test_e8_m4(void)
{
    int result0, result1, result2, result3;
    asm volatile (
        "li t1, 15 \n\t"
        "vsetvli t0, t1, e8, m1 \n\t"
        "vmv.v.i v4, 15 \n\t"
        "vmv.v.i v5, 7 \n\t"
        "vmv.v.i v6, 2 \n\t"
        "vmv.v.i v7, 4 \n\t"
        "vmv.v.i v8, 15 \n\t"
        "vmv.v.i v9, 13 \n\t"
        "vmv.v.i v10, 5 \n\t"
        "vmv.v.i v11, 8 \n\t"
        "vsetvli t0, t1, e8, m4 \n\t"
        "vsub.vv v4, v4, v8 \n\t"
        "vsetvli t0, t1, e8, m1 \n\t"
        "vmv.x.s %0, v4 \n\t"
        "vmv.x.s %1, v5 \n\t"
        "vmv.x.s %2, v6 \n\t"
        "vmv.x.s %3, v7 \n\t"
        : "=r" (result0), "=r" (result1), "=r" (result2), "=r" (result3)
    );

    if(result0 != 0 || result1 != -6 || result2 != -3 || result3 != -4)
    {
        printf("Fail: %d %d %d %d\n", result0, result1, result2, result3);
        return(1);
    }
    else
    {
        printf("Pass: %d %d %d %d\n", result0, result1, result2, result3);
        return(0);
    }
}


int sub_vv_test_e16_m1(void)
{
    int result;
    asm volatile (
        "li t1, 5 \n\t"
        "vsetvli t0, t1, e16, m1 \n\t"
        "vmv.v.i v1, 15 \n\t"
        "vmv.v.i v2, 7 \n\t"
        "vsub.vv v3, v1, v2 \n\t"
        "vmv.x.s %0, v3"
        : "=r" (result) 
    );

    if(result != 8)
    {
        printf("Fail: %d\n", result);
        return(1);
    }
    else
    {
        printf("Pass: %d\n", result);
        return(0);
    }
}

int sub_vv_test_e16_m2(void)
{
    int result0, result1;
    asm volatile (
        "li t1, 7 \n\t"
        "vsetvli t0, t1, e16, m1 \n\t"
        "vmv.v.i v2, 15 \n\t"
        "vmv.v.i v3, 7 \n\t"
        "vmv.v.i v4, 2 \n\t"
        "vmv.v.i v5, 4 \n\t"
        "vsetvli t0, t1, e16, m2 \n\t"
        "vsub.vv v2, v2, v4 \n\t"
        "vsetvli t0, t1, e16, m1 \n\t"
        "vmv.x.s %0, v2\n\t"
        "vmv.x.s %1, v3\n\t"
        : "=r" (result0), "=r" (result1)
    );

    if(result0 != 13 || result1 != 3)
    {
        printf("Fail: %d %d\n", result0, result1);
        return(1);
    }
    else
    {
        printf("Pass: %d %d\n", result0, result1);
        return(0);
    }
}

int sub_vv_test_e16_m4(void)
{
    int result0, result1, result2, result3;
    asm volatile (
        "li t1, 15 \n\t"
        "vsetvli t0, t1, e16, m1 \n\t"
        "vmv.v.i v4, 15 \n\t"
        "vmv.v.i v5, 7 \n\t"
        "vmv.v.i v6, 2 \n\t"
        "vmv.v.i v7, 4 \n\t"
        "vmv.v.i v8, 15 \n\t"
        "vmv.v.i v9, 13 \n\t"
        "vmv.v.i v10, 5 \n\t"
        "vmv.v.i v11, 8 \n\t"
        "vsetvli t0, t1, e16, m4 \n\t"
        "vsub.vv v4, v4, v8 \n\t"
        "vsetvli t0, t1, e16, m1 \n\t"
        "vmv.x.s %0, v4 \n\t"
        "vmv.x.s %1, v5 \n\t"
        "vmv.x.s %2, v6 \n\t"
        "vmv.x.s %3, v7 \n\t"
        : "=r" (result0), "=r" (result1), "=r" (result2), "=r" (result3)
    );

    if(result0 != 0 || result1 != -6 || result2 != -3 || result3 != -4)
    {
        printf("Fail: %d %d %d %d\n", result0, result1, result2, result3);
        return(1);
    }
    else
    {
        printf("Pass: %d %d %d %d\n", result0, result1, result2, result3);
        return(0);
    }
}


int sub_vv_test_e32_m1(void)
{
    int result;
    asm volatile (
        "li t1, 3 \n\t"
        "vsetvli t0, t1, e32, m1 \n\t"
        "vmv.v.i v1, 15 \n\t"
        "vmv.v.i v2, 7 \n\t"
        "vsub.vv v3, v1, v2 \n\t"
        "vmv.x.s %0, v3"
        : "=r" (result) 
    );

    if(result != 8)
    {
        printf("Fail: %d\n", result);
        return(1);
    }
    else
    {
        printf("Pass: %d\n", result);
        return(0);
    }
}

int sub_vv_test_e32_m2(void)
{
    int result0, result1;
    asm volatile (
        "li t1, 7 \n\t"
        "vsetvli t0, t1, e32, m1 \n\t"
        "vmv.v.i v2, 15 \n\t"
        "vmv.v.i v3, 7 \n\t"
        "vmv.v.i v4, 2 \n\t"
        "vmv.v.i v5, 4 \n\t"
        "vsetvli t0, t1, e32, m2 \n\t"
        "vsub.vv v2, v2, v4 \n\t"
        "vsetvli t0, t1, e32, m1 \n\t"
        "vmv.x.s %0, v2\n\t"
        "vmv.x.s %1, v3\n\t"
        : "=r" (result0), "=r" (result1)
    );

    if(result0 != 13 || result1 != 3)
    {
        printf("Fail: %d %d\n", result0, result1);
        return(1);
    }
    else
    {
        printf("Pass: %d %d\n", result0, result1);
        return(0);
    }
}

int sub_vv_test_e32_m4(void)
{
    int result0, result1, result2, result3;
    asm volatile (
        "li t1, 15 \n\t"
        "vsetvli t0, t1, e32, m1 \n\t"
        "vmv.v.i v4, 15 \n\t"
        "vmv.v.i v5, 7 \n\t"
        "vmv.v.i v6, 2 \n\t"
        "vmv.v.i v7, 4 \n\t"
        "vmv.v.i v8, 15 \n\t"
        "vmv.v.i v9, 13 \n\t"
        "vmv.v.i v10, 5 \n\t"
        "vmv.v.i v11, 8 \n\t"
        "vsetvli t0, t1, e32, m4 \n\t"
        "vsub.vv v4, v4, v8 \n\t"
        "vsetvli t0, t1, e32, m1 \n\t"
        "vmv.x.s %0, v4 \n\t"
        "vmv.x.s %1, v5 \n\t"
        "vmv.x.s %2, v6 \n\t"
        "vmv.x.s %3, v7 \n\t"
        : "=r" (result0), "=r" (result1), "=r" (result2), "=r" (result3)
    );

    if(result0 != 0 || result1 != -6 || result2 != -3 || result3 != -4)
    {
        printf("Fail: %d %d %d %d\n", result0, result1, result2, result3);
        return(1);
    }
    else
    {
        printf("Pass: %d %d %d %d\n", result0, result1, result2, result3);
        return(0);
    }
}


int main(void)
{
    int errors = 0;

    printf("\nsub.vv\n");
    errors += sub_vv_test_e8_m1();
    errors += sub_vv_test_e8_m2();
    errors += sub_vv_test_e8_m4();
    errors += sub_vv_test_e16_m1();
    errors += sub_vv_test_e16_m2();
    errors += sub_vv_test_e16_m4();
    errors += sub_vv_test_e32_m1();
    errors += sub_vv_test_e32_m2();
    errors += sub_vv_test_e32_m4();

    
    if(errors > 0)
    {
        printf("\nErrors Detected!\nError Count: %d\n", errors);
        return(EXIT_FAILURE);
    }

    printf("\nAll Tests Completed\nNo Errors Detected!\n");

    return(EXIT_SUCCESS);
}