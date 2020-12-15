#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// void vector_test_grouped_add(int8_t N, int8_t* output, int8_t* vect1, int8_t* vect2)
// {
//     int t0 =0;
    
//     printf("N: %d\tt0: %d\n", N, t0); 
//     asm volatile (
//         "vect_add: vsetvli %4, %3, e8, m1, d1 \n\t"
//         "vle.v v1, (%1)\n\t"
//         "   slli t5, %4, 2\n\t"
//         "   sub %3, %3, %4\n\t"
//         "   add %1, %1, t5\n\t"
//         "vle.v v2, (%2)\n\t"
//         "   add %2, %2, t5\n\t"
//         "vadd.vv v3, v1, v2\n\t"
//         "vse.v v3, (%0)\n\t"
//         "   add %0, %0, t5\n\t"
//         "bnez %3, vect_add\n\t"

//         : "+r" (output), "+r" (vect1), "+r" (vect2), "+r" (N) 
//         : "r" (t0), "m" (*vect1), "m" (*vect2)
//     );
//     printf("N: %d\tt0: %d\n", N, t0);
// }


int add_vv_test_e8_m1(void)
{
    uint8_t result;
    asm volatile (
        "li t1, 64 \n\t"
        "vsetvli t0, t1, e8, m1 \n\t"
        "vmv.v.i v1, 8 \n\t"
        "vmv.v.i v2, 7 \n\t"
        "vadd.vv v3, v1, v2 \n\t"
        "vmv.x.s %0, v3"
        : "=r" (result) 
    );

    if(result != 15)
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

int add_vv_test_e8_m2(void)
{
    uint8_t result0 = 0, result1 = 0;
    asm volatile (
        "li t1, 64 \n\t"
        "vsetvli t0, t1, e8, m1 \n\t"
        "vmv.v.i v2, 8 \n\t"
        "vmv.v.i v3, 7 \n\t"
        "vmv.v.i v4, 5 \n\t"
        "vmv.v.i v5, 4 \n\t"
        "vsetvli t0, t1, e8, m2 \n\t"
        "vadd.vv v6, v2, v4 \n\t"
        "vsetvli t0, t1, e8, m1 \n\t"
        "vmv.x.s %0, v6\n\t"
        "vmv.x.s %1, v7\n\t"
        : "=r" (result0), "=r" (result1)
    );

    if(result0 != 13 || result1 != 11)
    {
        printf("Test Failed! Results: %d\t%d\n", result0, result1);
        return(1);
    }
    else
    {
        printf("Pass: %d\t%d\n", result0, result1);
        return(0);
    }
}

int add_vv_test_e8_m4(void)
{
    uint8_t result0, result1, result2, result3;
    asm volatile (
        "li t1, 64 \n\t"
        "vsetvli t0, t1, e8, m1 \n\t"
        "vmv.v.i v4, 8 \n\t"
        "vmv.v.i v5, 7 \n\t"
        "vmv.v.i v6, 5 \n\t"
        "vmv.v.i v7, 4 \n\t"
        "vmv.v.i v8, 12 \n\t"
        "vmv.v.i v9, 3 \n\t"
        "vmv.v.i v10, 9 \n\t"
        "vmv.v.i v11, 1 \n\t"
        "vsetvli t0, t1, e8, m4 \n\t"
        "vadd.vv v12, v4, v8 \n\t"
        "vsetvli t0, t1, e8, m1 \n\t"
        "vmv.x.s %0, v12\n\t"
        "vmv.x.s %1, v13\n\t"
        "vmv.x.s %2, v14\n\t"
        "vmv.x.s %3, v15\n\t"
        : "=r" (result0), "=r" (result1), "=r" (result2), "=r" (result3)
    );

    if(result0 != 20 || result1 != 10 || result2 != 14 || result3 != 5)
    {
        printf("Test Failed! Results: %d %d %d %d\n", result0, result1, result2, result3);
        return(1);
    }
    else
    {
        printf("Pass: %d %d %d %d\n", result0, result1, result2, result3);
        return(0);
    }
}


int add_vv_test_e16_m1(void)
{
    uint8_t result;
    asm volatile (
        "li t1, 64 \n\t"
        "vsetvli t0, t1, e16, m1 \n\t"
        "vmv.v.i v1, 8 \n\t"
        "vmv.v.i v2, 7 \n\t"
        "vadd.vv v3, v1, v2 \n\t"
        "vmv.x.s %0, v3"
        : "=r" (result) 
    );

    if(result != 15)
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



int add_vv_test_e16_m2(void)
{
    uint8_t result0 = 0, result1 = 0;
    asm volatile (
        "li t1, 64 \n\t"
        "vsetvli t0, t1, e16, m1 \n\t"
        "vmv.v.i v2, 8 \n\t"
        "vmv.v.i v3, 7 \n\t"
        "vmv.v.i v4, 5 \n\t"
        "vmv.v.i v5, 4 \n\t"
        "vsetvli t0, t1, e16, m2 \n\t"
        "vadd.vv v6, v2, v4 \n\t"
        "vsetvli t0, t1, e16, m1 \n\t"
        "vmv.x.s %0, v6\n\t"
        "vmv.x.s %1, v7\n\t"
        : "=r" (result0), "=r" (result1)
    );

    if(result0 != 13 || result1 != 11)
    {
        printf("Test Failed! Results: %d\t%d\n", result0, result1);
        return(1);
    }
    else
    {
        printf("Pass: %d\t%d\n", result0, result1);
        return(0);
    }
}

int add_vv_test_e16_m4(void)
{
    uint8_t result0, result1, result2, result3;
    asm volatile (
        "li t1, 64 \n\t"
        "vsetvli t0, t1, e16, m1 \n\t"
        "vmv.v.i v4, 8 \n\t"
        "vmv.v.i v5, 7 \n\t"
        "vmv.v.i v6, 5 \n\t"
        "vmv.v.i v7, 4 \n\t"
        "vmv.v.i v8, 12 \n\t"
        "vmv.v.i v9, 3 \n\t"
        "vmv.v.i v10, 9 \n\t"
        "vmv.v.i v11, 1 \n\t"
        "vsetvli t0, t1, e16, m4 \n\t"
        "vadd.vv v12, v4, v8 \n\t"
        "vsetvli t0, t1, e16, m1 \n\t"
        "vmv.x.s %0, v12\n\t"
        "vmv.x.s %1, v13\n\t"
        "vmv.x.s %2, v14\n\t"
        "vmv.x.s %3, v15\n\t"
        : "=r" (result0), "=r" (result1), "=r" (result2), "=r" (result3)
    );

    if(result0 != 20 || result1 != 10 || result2 != 14 || result3 != 5)
    {
        printf("Test Failed! Results: %d %d %d %d\n", result0, result1, result2, result3);
        return(1);
    }
    else
    {
        printf("Pass: %d %d %d %d\n", result0, result1, result2, result3);
        return(0);
    }
}

int add_vv_test_e32_m1(void)
{
    uint8_t result;
    asm volatile (
        "li t1, 64 \n\t"
        "vsetvli t0, t1, e32, m1 \n\t"
        "vmv.v.i v1, 8 \n\t"
        "vmv.v.i v2, 7 \n\t"
        "vadd.vv v3, v1, v2 \n\t"
        "vmv.x.s %0, v3"
        : "=r" (result) 
    );

    if(result != 15)
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

int add_vv_test_e32_m2(void)
{
    uint8_t result0 = 0, result1 = 0;
    asm volatile (
        "li t1, 64 \n\t"
        "vsetvli t0, t1, e32, m1 \n\t"
        "vmv.v.i v2, 8 \n\t"
        "vmv.v.i v3, 7 \n\t"
        "vmv.v.i v4, 5 \n\t"
        "vmv.v.i v5, 4 \n\t"
        "vsetvli t0, t1, e32, m2 \n\t"
        "vadd.vv v6, v2, v4 \n\t"
        "vsetvli t0, t1, e32, m1 \n\t"
        "vmv.x.s %0, v6\n\t"
        "vmv.x.s %1, v7\n\t"
        : "=r" (result0), "=r" (result1)
    );

    if(result0 != 13 || result1 != 11)
    {
        printf("Test Failed! Results: %d\t%d\n", result0, result1);
        return(1);
    }
    else
    {
        printf("Pass: %d\t%d\n", result0, result1);
        return(0);
    }
}

int add_vv_test_e32_m4(void)
{
    uint8_t result0, result1, result2, result3;
    asm volatile (
        "li t1, 64 \n\t"
        "vsetvli t0, t1, e32, m1 \n\t"
        "vmv.v.i v4, 8 \n\t"
        "vmv.v.i v5, 7 \n\t"
        "vmv.v.i v6, 5 \n\t"
        "vmv.v.i v7, 4 \n\t"
        "vmv.v.i v8, 12 \n\t"
        "vmv.v.i v9, 3 \n\t"
        "vmv.v.i v10, 9 \n\t"
        "vmv.v.i v11, 1 \n\t"
        "vsetvli t0, t1, e32, m4 \n\t"
        "vadd.vv v12, v4, v8 \n\t"
        "vsetvli t0, t1, e32, m1 \n\t"
        "vmv.x.s %0, v12\n\t"
        "vmv.x.s %1, v13\n\t"
        "vmv.x.s %2, v14\n\t"
        "vmv.x.s %3, v15\n\t"
        : "=r" (result0), "=r" (result1), "=r" (result2), "=r" (result3)
    );

    if(result0 != 20 || result1 != 10 || result2 != 14 || result3 != 5)
    {
        printf("Test Failed! Results: %d %d %d %d\n", result0, result1, result2, result3);
        return(1);
    }
    else
    {
        printf("Pass: %d %d %d %d\n", result0, result1, result2, result3);
        return(0);
    }
}


int add_vx_test_e8_m1(void)
{  
    uint8_t addend = 23;
    uint8_t result;
    asm volatile (
        "li t1, 64 \n\t"
        "vsetvli t0, t1, e8, m1 \n\t"
        "vmv.v.i v1, 8 \n\t"
        "vadd.vx v3, v1, %1 \n\t"
        "vmv.x.s %0, v3"
        : "=r" (result) 
        : "r"  (addend)
    );

    if(result != 31)
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

int add_vx_test_e8_m2(void)
{  
    uint8_t addend = 23;
    uint8_t result0, result1;
    asm volatile (
        "li t1, 64 \n\t"
        "vsetvli t0, t1, e8, m1 \n\t"
        "vmv.v.i v2, 8 \n\t"
        "vmv.v.i v3, 12 \n\t"
        "vsetvli t0, t1, e8, m2\n\t"
        "vadd.vx v6, v2, %2 \n\t"
        "vsetvli t0, t1, e8, m1 \n\t"
        "vmv.x.s %0, v6\n\t"
        "vmv.x.s %1, v7\n\t"
        : "=r" (result0), "=r" (result1) 
        : "r"  (addend)
    );

    if(result0 != 31 || result1 != 35)
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

int add_vx_test_e8_m4(void)
{  
    uint8_t addend = 23;
    uint8_t result0, result1, result2, result3;
    asm volatile (
        "li t1, 64 \n\t"
        "vsetvli t0, t1, e8, m1 \n\t"
        "vmv.v.i v4, 8 \n\t"
        "vmv.v.i v5, 1 \n\t"
        "vmv.v.i v6, 3 \n\t"
        "vmv.v.i v7, 15 \n\t"
        "vsetvli t0, t1, e8, m4\n\t"
        "vadd.vx v8, v4, %4  \n\t"
        "vsetvli t0, t1, e8, m1 \n\t"
        "vmv.x.s %0, v8\n\t"
        "vmv.x.s %1, v9\n\t"
        "vmv.x.s %2, v10\n\t"
        "vmv.x.s %3, v11\n\t"
        : "=r" (result0), "=r" (result1), "=r" (result2), "=r" (result3)
        : "r"  (addend)
    );

    if(result0 != 31 || result1 != 24 || result2 != 26 || result3 != 38)
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


int add_vx_test_e16_m1(void)
{  
    uint8_t addend = 23;
    uint8_t result;
    asm volatile (
        "li t1, 64 \n\t"
        "vsetvli t0, t1, e16, m1 \n\t"
        "vmv.v.i v1, 8 \n\t"
        "vadd.vx v3, v1, %1 \n\t"
        "vmv.x.s %0, v3"
        : "=r" (result) 
        : "r"  (addend)
    );

    if(result != 31)
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

int add_vx_test_e16_m2(void)
{  
    uint8_t addend = 23;
    uint8_t result0, result1;
    asm volatile (
        "li t1, 64 \n\t"
        "vsetvli t0, t1, e16, m1 \n\t"
        "vmv.v.i v2, 8 \n\t"
        "vmv.v.i v3, 12 \n\t"
        "vsetvli t0, t1, e16, m2\n\t"
        "vadd.vx v6, v2, %2 \n\t"
        "vsetvli t0, t1, e16, m1 \n\t"
        "vmv.x.s %0, v6\n\t"
        "vmv.x.s %1, v7\n\t"
        : "=r" (result0), "=r" (result1) 
        : "r"  (addend)
    );

    if(result0 != 31 || result1 != 35)
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

int add_vx_test_e16_m4(void)
{  
    uint8_t addend = 23;
    uint8_t result0, result1, result2, result3;
    asm volatile (
        "li t1, 64 \n\t"
        "vsetvli t0, t1, e16, m1 \n\t"
        "vmv.v.i v4, 8 \n\t"
        "vmv.v.i v5, 1 \n\t"
        "vmv.v.i v6, 3 \n\t"
        "vmv.v.i v7, 15 \n\t"
        "vsetvli t0, t1, e16, m4\n\t"
        "vadd.vx v8, v4, %4  \n\t"
        "vsetvli t0, t1, e16, m1 \n\t"
        "vmv.x.s %0, v8\n\t"
        "vmv.x.s %1, v9\n\t"
        "vmv.x.s %2, v10\n\t"
        "vmv.x.s %3, v11\n\t"
        : "=r" (result0), "=r" (result1), "=r" (result2), "=r" (result3)
        : "r"  (addend)
    );

    if(result0 != 31 || result1 != 24 || result2 != 26 || result3 != 38)
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


int add_vx_test_e32_m1(void)
{  
    uint8_t addend = 23;
    uint8_t result;
    asm volatile (
        "li t1, 64 \n\t"
        "vsetvli t0, t1, e32, m1 \n\t"
        "vmv.v.i v1, 8 \n\t"
        "vadd.vx v3, v1, %1 \n\t"
        "vmv.x.s %0, v3"
        : "=r" (result) 
        : "r"  (addend)
    );

    if(result != 31)
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

int add_vx_test_e32_m2(void)
{  
    uint8_t addend = 23;
    uint8_t result0, result1;
    asm volatile (
        "li t1, 64 \n\t"
        "vsetvli t0, t1, e32, m1 \n\t"
        "vmv.v.i v2, 8 \n\t"
        "vmv.v.i v3, 12 \n\t"
        "vsetvli t0, t1, e32, m2\n\t"
        "vadd.vx v6, v2, %2 \n\t"
        "vsetvli t0, t1, e32, m1 \n\t"
        "vmv.x.s %0, v6\n\t"
        "vmv.x.s %1, v7\n\t"
        : "=r" (result0), "=r" (result1) 
        : "r"  (addend)
    );

    if(result0 != 31 || result1 != 35)
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

int add_vx_test_e32_m4(void)
{  
    uint8_t addend = 23;
    uint8_t result0, result1, result2, result3;
    asm volatile (
        "li t1, 64 \n\t"
        "vsetvli t0, t1, e32, m1 \n\t"
        "vmv.v.i v4, 8 \n\t"
        "vmv.v.i v5, 1 \n\t"
        "vmv.v.i v6, 3 \n\t"
        "vmv.v.i v7, 15 \n\t"
        "vsetvli t0, t1, e32, m4\n\t"
        "vadd.vx v8, v4, %4  \n\t"
        "vsetvli t0, t1, e32, m1 \n\t"
        "vmv.x.s %0, v8\n\t"
        "vmv.x.s %1, v9\n\t"
        "vmv.x.s %2, v10\n\t"
        "vmv.x.s %3, v11\n\t"
        : "=r" (result0), "=r" (result1), "=r" (result2), "=r" (result3)
        : "r"  (addend)
    );

    if(result0 != 31 || result1 != 24 || result2 != 26 || result3 != 38)
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



int sadd_vv_nsat_test_e8_m1(void)
{
    uint8_t result;
    asm volatile (
        "li t1, 64 \n\t"
        "vsetvli t0, t1, e8, m1 \n\t"
        "vmv.v.i v1, 8 \n\t"
        "vmv.v.i v2, 7 \n\t"
        "vsadd.vv v3, v1, v2 \n\t"
        "vmv.x.s %0, v3"
        : "=r" (result) 
    );

    if(result != 15)
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

int sadd_vv_nsat_test_e8_m2(void)
{
    uint8_t result0 = 0, result1 = 0;
    asm volatile (
        "li t1, 64 \n\t"
        "vsetvli t0, t1, e8, m1 \n\t"
        "vmv.v.i v2, 8 \n\t"
        "vmv.v.i v3, 7 \n\t"
        "vmv.v.i v4, 5 \n\t"
        "vmv.v.i v5, 4 \n\t"
        "vsetvli t0, t1, e8, m2 \n\t"
        "vsadd.vv v6, v2, v4 \n\t"
        "vsetvli t0, t1, e8, m1 \n\t"
        "vmv.x.s %0, v6\n\t"
        "vmv.x.s %1, v7\n\t"
        : "=r" (result0), "=r" (result1)
    );

    if(result0 != 13 || result1 != 11)
    {
        printf("Test Failed! Results: %d\t%d\n", result0, result1);
        return(1);
    }
    else
    {
        printf("Pass: %d\t%d\n", result0, result1);
        return(0);
    }
}

int sadd_vv_nsat_test_e8_m4(void)
{
    uint8_t result0, result1, result2, result3;
    asm volatile (
        "li t1, 64 \n\t"
        "vsetvli t0, t1, e8, m1 \n\t"
        "vmv.v.i v4, 8 \n\t"
        "vmv.v.i v5, 7 \n\t"
        "vmv.v.i v6, 5 \n\t"
        "vmv.v.i v7, 4 \n\t"
        "vmv.v.i v8, 12 \n\t"
        "vmv.v.i v9, 3 \n\t"
        "vmv.v.i v10, 9 \n\t"
        "vmv.v.i v11, 1 \n\t"
        "vsetvli t0, t1, e8, m4 \n\t"
        "vsadd.vv v12, v4, v8 \n\t"
        "vsetvli t0, t1, e8, m1 \n\t"
        "vmv.x.s %0, v12\n\t"
        "vmv.x.s %1, v13\n\t"
        "vmv.x.s %2, v14\n\t"
        "vmv.x.s %3, v15\n\t"
        : "=r" (result0), "=r" (result1), "=r" (result2), "=r" (result3)
    );

    if(result0 != 20 || result1 != 10 || result2 != 14 || result3 != 5)
    {
        printf("Test Failed! Results: %d %d %d %d\n", result0, result1, result2, result3);
        return(1);
    }
    else
    {
        printf("Pass: %d %d %d %d\n", result0, result1, result2, result3);
        return(0);
    }
}


int sadd_vv_nsat_test_e16_m1(void)
{
    uint8_t result;
    asm volatile (
        "li t1, 64 \n\t"
        "vsetvli t0, t1, e16, m1 \n\t"
        "vmv.v.i v1, 8 \n\t"
        "vmv.v.i v2, 7 \n\t"
        "vsadd.vv v3, v1, v2 \n\t"
        "vmv.x.s %0, v3"
        : "=r" (result) 
    );

    if(result != 15)
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

int sadd_vv_nsat_test_e16_m2(void)
{
    uint8_t result0 = 0, result1 = 0;
    asm volatile (
        "li t1, 64 \n\t"
        "vsetvli t0, t1, e16, m1 \n\t"
        "vmv.v.i v2, 8 \n\t"
        "vmv.v.i v3, 7 \n\t"
        "vmv.v.i v4, 5 \n\t"
        "vmv.v.i v5, 4 \n\t"
        "vsetvli t0, t1, e16, m2 \n\t"
        "vsadd.vv v6, v2, v4 \n\t"
        "vsetvli t0, t1, e16, m1 \n\t"
        "vmv.x.s %0, v6\n\t"
        "vmv.x.s %1, v7\n\t"
        : "=r" (result0), "=r" (result1)
    );

    if(result0 != 13 || result1 != 11)
    {
        printf("Test Failed! Results: %d\t%d\n", result0, result1);
        return(1);
    }
    else
    {
        printf("Pass: %d\t%d\n", result0, result1);
        return(0);
    }
}

int sadd_vv_nsat_test_e16_m4(void)
{
    uint8_t result0, result1, result2, result3;
    asm volatile (
        "li t1, 64 \n\t"
        "vsetvli t0, t1, e16, m1 \n\t"
        "vmv.v.i v4, 8 \n\t"
        "vmv.v.i v5, 7 \n\t"
        "vmv.v.i v6, 5 \n\t"
        "vmv.v.i v7, 4 \n\t"
        "vmv.v.i v8, 12 \n\t"
        "vmv.v.i v9, 3 \n\t"
        "vmv.v.i v10, 9 \n\t"
        "vmv.v.i v11, 1 \n\t"
        "vsetvli t0, t1, e16, m4 \n\t"
        "vsadd.vv v12, v4, v8 \n\t"
        "vsetvli t0, t1, e16, m1 \n\t"
        "vmv.x.s %0, v12\n\t"
        "vmv.x.s %1, v13\n\t"
        "vmv.x.s %2, v14\n\t"
        "vmv.x.s %3, v15\n\t"
        : "=r" (result0), "=r" (result1), "=r" (result2), "=r" (result3)
    );

    if(result0 != 20 || result1 != 10 || result2 != 14 || result3 != 5)
    {
        printf("Test Failed! Results: %d %d %d %d\n", result0, result1, result2, result3);
        return(1);
    }
    else
    {
        printf("Pass: %d %d %d %d\n", result0, result1, result2, result3);
        return(0);
    }
}


int sadd_vv_nsat_test_e32_m1(void)
{
    uint8_t result;
    asm volatile (
        "li t1, 64 \n\t"
        "vsetvli t0, t1, e32, m1 \n\t"
        "vmv.v.i v1, 8 \n\t"
        "vmv.v.i v2, 7 \n\t"
        "vsadd.vv v3, v1, v2 \n\t"
        "vmv.x.s %0, v3"
        : "=r" (result) 
    );

    if(result != 15)
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

int sadd_vv_nsat_test_e32_m2(void)
{
    uint8_t result0 = 0, result1 = 0;
    asm volatile (
        "li t1, 64 \n\t"
        "vsetvli t0, t1, e32, m1 \n\t"
        "vmv.v.i v2, 8 \n\t"
        "vmv.v.i v3, 7 \n\t"
        "vmv.v.i v4, 5 \n\t"
        "vmv.v.i v5, 4 \n\t"
        "vsetvli t0, t1, e32, m2 \n\t"
        "vsadd.vv v6, v2, v4 \n\t"
        "vsetvli t0, t1, e32, m1 \n\t"
        "vmv.x.s %0, v6\n\t"
        "vmv.x.s %1, v7\n\t"
        : "=r" (result0), "=r" (result1)
    );

    if(result0 != 13 || result1 != 11)
    {
        printf("Test Failed! Results: %d\t%d\n", result0, result1);
        return(1);
    }
    else
    {
        printf("Pass: %d\t%d\n", result0, result1);
        return(0);
    }
}

int sadd_vv_nsat_test_e32_m4(void)
{
    uint8_t result0, result1, result2, result3;
    asm volatile (
        "li t1, 64 \n\t"
        "vsetvli t0, t1, e32, m1 \n\t"
        "vmv.v.i v4, 8 \n\t"
        "vmv.v.i v5, 7 \n\t"
        "vmv.v.i v6, 5 \n\t"
        "vmv.v.i v7, 4 \n\t"
        "vmv.v.i v8, 12 \n\t"
        "vmv.v.i v9, 3 \n\t"
        "vmv.v.i v10, 9 \n\t"
        "vmv.v.i v11, 1 \n\t"
        "vsetvli t0, t1, e32, m4 \n\t"
        "vsadd.vv v12, v4, v8 \n\t"
        "vsetvli t0, t1, e32, m1 \n\t"
        "vmv.x.s %0, v12\n\t"
        "vmv.x.s %1, v13\n\t"
        "vmv.x.s %2, v14\n\t"
        "vmv.x.s %3, v15\n\t"
        : "=r" (result0), "=r" (result1), "=r" (result2), "=r" (result3)
    );

    if(result0 != 20 || result1 != 10 || result2 != 14 || result3 != 5)
    {
        printf("Test Failed! Results: %d %d %d %d\n", result0, result1, result2, result3);
        return(1);
    }
    else
    {
        printf("Pass: %d %d %d %d\n", result0, result1, result2, result3);
        return(0);
    }
}



int sadd_vv_sat_test_e8_m1(void)
{
    int result;
    asm volatile (
        "li t1, 64 \n\t"
        "vsetvli t0, t1, e8, m1 \n\t"
        "li t2, 127\n\t"
        "li t3, 127\n\t"
        "vmv.v.x v1, t2 \n\t"
        "vmv.v.x v2, t3 \n\t"
        "vsadd.vv v3, v1, v2 \n\t"
        "vmv.x.s %0, v3"
        : "=r" (result) 
    );

    if(result != 127)
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

int sadd_vv_sat_test_e8_m2(void)
{
    uint8_t result0 = 0, result1 = 0;
    asm volatile (
        "li t1, 64 \n\t"
        "vsetvli t0, t1, e8, m1 \n\t"
        "vmv.v.i v2, 8 \n\t"
        "vmv.v.i v3, 7 \n\t"
        "vmv.v.i v4, 5 \n\t"
        "li t2, 125\n\t"
        "vmv.v.x v5, t2\n\t"
        "vsetvli t0, t1, e8, m2 \n\t"
        "vsadd.vv v6, v2, v4 \n\t"
        "vsetvli t0, t1, e8, m1 \n\t"
        "vmv.x.s %0, v6\n\t"
        "vmv.x.s %1, v7\n\t"
        : "=r" (result0), "=r" (result1)
    );

    if(result0 != 13 || result1 != 127)
    {
        printf("Test Failed! Results: %d\t%d\n", result0, result1);
        return(1);
    }
    else
    {
        printf("Pass: %d\t%d\n", result0, result1);
        return(0);
    }
}

int sadd_vv_sat_test_e8_m4(void)
{
    uint8_t result0, result1, result2, result3;
    asm volatile (
        "li t1, 64 \n\t"
        "vsetvli t0, t1, e8, m1 \n\t"
        "vmv.v.i v4, 8 \n\t"
        "vmv.v.i v5, 7 \n\t"
        "vmv.v.i v6, 5 \n\t"
        "vmv.v.i v7, 4 \n\t"
        "vmv.v.i v8, 12 \n\t"
        "vmv.v.i v9, 3 \n\t"
        "vmv.v.i v10, 9 \n\t"
        "li t2, 124\n\t"
        "vmv.v.x v11, t2\n\t"
        "vsetvli t0, t1, e8, m4 \n\t"
        "vsadd.vv v12, v4, v8 \n\t"
        "vsetvli t0, t1, e8, m1 \n\t"
        "vmv.x.s %0, v12\n\t"
        "vmv.x.s %1, v13\n\t"
        "vmv.x.s %2, v14\n\t"
        "vmv.x.s %3, v15\n\t"
        : "=r" (result0), "=r" (result1), "=r" (result2), "=r" (result3)
    );

    if(result0 != 20 || result1 != 10 || result2 != 14 || result3 != 127)
    {
        printf("Test Failed! Results: %d %d %d %d\n", result0, result1, result2, result3);
        return(1);
    }
    else
    {
        printf("Pass: %d %d %d %d\n", result0, result1, result2, result3);
        return(0);
    }
}


int sadd_vv_sat_test_e16_m1(void)
{
    int result;
    asm volatile (
        "li t1, 64 \n\t"
        "vsetvli t0, t1, e16, m1 \n\t"
        "li t2, 12000\n\t"
        "li t3, 25000\n\t"
        "vmv.v.x v1, t2 \n\t"
        "vmv.v.x v2, t3 \n\t"
        "vsadd.vv v3, v1, v2 \n\t"
        "vmv.x.s %0, v3"
        : "=r" (result) 
    );

    if(result != 32767)
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

int sadd_vv_sat_test_e16_m2(void)
{
    int result0 = 0, result1 = 0;
    asm volatile (
        "li t1, 64 \n\t"
        "vsetvli t0, t1, e16, m1 \n\t"
        "vmv.v.i v2, 8 \n\t"
        "vmv.v.i v3, 7 \n\t"
        "vmv.v.i v4, 5 \n\t"
        "li t2, 32763\n\t"
        "vmv.v.x v5, t2\n\t"
        "vsetvli t0, t1, e16, m2 \n\t"
        "vsadd.vv v6, v2, v4 \n\t"
        "vsetvli t0, t1, e16, m1 \n\t"
        "vmv.x.s %0, v6\n\t"
        "vmv.x.s %1, v7\n\t"
        : "=r" (result0), "=r" (result1)
    );

    if(result0 != 13 || result1 != 32767)
    {
        printf("Test Failed! Results: %d %d\n", result0, result1);
        return(1);
    }
    else
    {
        printf("Pass: %d %d\n", result0, result1);
        return(0);
    }
}

int sadd_vv_sat_test_e16_m4(void)
{
    int result0, result1, result2, result3;
    asm volatile (
        "li t1, 64 \n\t"
        "vsetvli t0, t1, e16, m1 \n\t"
        "vmv.v.i v4, 8 \n\t"
        "vmv.v.i v5, 7 \n\t"
        "vmv.v.i v6, 5 \n\t"
        "vmv.v.i v7, 4 \n\t"
        "vmv.v.i v8, 12 \n\t"
        "vmv.v.i v9, 3 \n\t"
        "vmv.v.i v10, 9 \n\t"
        "li t2, 32765\n\t"
        "vmv.v.x v11, t2\n\t"
        "vsetvli t0, t1, e16, m4 \n\t"
        "vsadd.vv v12, v4, v8 \n\t"
        "vsetvli t0, t1, e16, m1 \n\t"
        "vmv.x.s %0, v12\n\t"
        "vmv.x.s %1, v13\n\t"
        "vmv.x.s %2, v14\n\t"
        "vmv.x.s %3, v15\n\t"
        : "=r" (result0), "=r" (result1), "=r" (result2), "=r" (result3)
    );

    if(result0 != 20 || result1 != 10 || result2 != 14 || result3 != 32767)
    {
        printf("Test Failed! Results: %d %d %d %d\n", result0, result1, result2, result3);
        return(1);
    }
    else
    {
        printf("Pass: %d %d %d %d\n", result0, result1, result2, result3);
        return(0);
    }
}

int sadd_vv_sat_test_e32_m1(void)
{
    int result;
    asm volatile (
        "li t1, 64 \n\t"
        "vsetvli t0, t1, e32, m1 \n\t"
        "li t2, 1000000000\n\t"
        "li t3, 1200000000\n\t"
        "vmv.v.x v1, t2 \n\t"
        "vmv.v.x v2, t3 \n\t"
        "vsadd.vv v3, v1, v2 \n\t"
        "vmv.x.s %0, v3"
        : "=r" (result) 
    );

    if(result != 2147483647)
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

int sadd_vv_sat_test_e32_m2(void)
{
    int result0 = 0, result1 = 0;
    asm volatile (
        "li t1, 64 \n\t"
        "vsetvli t0, t1, e32, m1 \n\t"
        "vmv.v.i v2, 8 \n\t"
        "vmv.v.i v3, 7 \n\t"
        "vmv.v.i v4, 5 \n\t"
        "li t2, 2147483643\n\t"
        "vmv.v.x v5, t2\n\t"
        "vsetvli t0, t1, e32, m2 \n\t"
        "vsadd.vv v6, v2, v4 \n\t"
        "vsetvli t0, t1, e32, m1 \n\t"
        "vmv.x.s %0, v6\n\t"
        "vmv.x.s %1, v7\n\t"
        : "=r" (result0), "=r" (result1)
    );

    if(result0 != 13 || result1 != 2147483647)
    {
        printf("Test Failed! Results: %d %d\n", result0, result1);
        return(1);
    }
    else
    {
        printf("Pass: %d %d\n", result0, result1);
        return(0);
    }
}

int sadd_vv_sat_test_e32_m4(void)
{
    int result0, result1, result2, result3;
    asm volatile (
        "li t1, 64 \n\t"
        "vsetvli t0, t1, e32, m1 \n\t"
        "vmv.v.i v4, 8 \n\t"
        "vmv.v.i v5, 7 \n\t"
        "vmv.v.i v6, 5 \n\t"
        "vmv.v.i v7, 4 \n\t"
        "vmv.v.i v8, 12 \n\t"
        "vmv.v.i v9, 3 \n\t"
        "vmv.v.i v10, 9 \n\t"
        "li t2, 2147483645\n\t"
        "vmv.v.x v11, t2\n\t"
        "vsetvli t0, t1, e32, m4 \n\t"
        "vsadd.vv v12, v4, v8 \n\t"
        "vsetvli t0, t1, e32, m1 \n\t"
        "vmv.x.s %0, v12\n\t"
        "vmv.x.s %1, v13\n\t"
        "vmv.x.s %2, v14\n\t"
        "vmv.x.s %3, v15\n\t"
        : "=r" (result0), "=r" (result1), "=r" (result2), "=r" (result3)
    );

    if(result0 != 20 || result1 != 10 || result2 != 14 || result3 != 2147483647)
    {
        printf("Test Failed! Results: %d %d %d %d\n", result0, result1, result2, result3);
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
    printf("Testing Vector Addition\n\n");

    int errors = 0;

    printf("vadd.vv\n");
    errors += add_vv_test_e8_m1();
    errors += add_vv_test_e8_m2();
    errors += add_vv_test_e8_m4();
    errors += add_vv_test_e16_m1();
    errors += add_vv_test_e16_m2();
    errors += add_vv_test_e16_m4();
    errors += add_vv_test_e32_m1();
    errors += add_vv_test_e32_m2();
    errors += add_vv_test_e32_m4();
    printf("\n");
    printf("vadd.vx\n");
    errors += add_vx_test_e8_m1();
    errors += add_vx_test_e8_m2();
    errors += add_vx_test_e8_m4();
    errors += add_vx_test_e16_m1();
    errors += add_vx_test_e16_m2();
    errors += add_vx_test_e16_m4();
    errors += add_vx_test_e32_m1();
    errors += add_vx_test_e32_m2();
    errors += add_vx_test_e32_m4();
    printf("\n");
    printf("vsadd.vv - Non-saturating\n");
    errors += sadd_vv_nsat_test_e8_m1();
    errors += sadd_vv_nsat_test_e8_m2();
    errors += sadd_vv_nsat_test_e8_m4();
    errors += sadd_vv_nsat_test_e16_m1();
    errors += sadd_vv_nsat_test_e16_m2();
    errors += sadd_vv_nsat_test_e16_m4();
    errors += sadd_vv_nsat_test_e32_m1();
    errors += sadd_vv_nsat_test_e32_m2();
    errors += sadd_vv_nsat_test_e32_m4();
    printf("\n");
    printf("vsadd.vv - Saturating\n");
    errors += sadd_vv_sat_test_e8_m1();
    errors += sadd_vv_sat_test_e8_m2();
    errors += sadd_vv_sat_test_e8_m4();
    errors += sadd_vv_sat_test_e16_m1();
    errors += sadd_vv_sat_test_e16_m2();
    errors += sadd_vv_sat_test_e16_m4();
    errors += sadd_vv_sat_test_e32_m1();
    errors += sadd_vv_sat_test_e32_m2();
    errors += sadd_vv_sat_test_e32_m4();
    
    if(errors > 0)
    {
        printf("\nErrors Detected!\nError Count: %d\n", errors);
        return(EXIT_FAILURE);
    }

    printf("\nAll Tests Completed\nNo Errors Detected!\n");

    return(EXIT_SUCCESS);

}