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



int sub_vx_test_e8_m1(void)
{  
    int subend = 23;
    int result;
    asm volatile (
        "li t1, 3 \n\t"
        "vsetvli t0, t1, e8, m1 \n\t"
        "vmv.v.i v1, 8 \n\t"
        "vsub.vx v3, v1, %1 \n\t"
        "vmv.x.s %0, v3"
        : "=r" (result) 
        : "r"  (subend)
    );

    if(result != -15)
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

int sub_vx_test_e16_m1(void)
{  
    int subend = 23;
    int result;
    asm volatile (
        "li t1, 4 \n\t"
        "vsetvli t0, t1, e16, m1 \n\t"
        "vmv.v.i v1, 8 \n\t"
        "vsub.vx v3, v1, %1 \n\t"
        "vmv.x.s %0, v3"
        : "=r" (result) 
        : "r"  (subend)
    );

    if(result != -15)
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

int sub_vx_test_e32_m1(void)
{  
    int subend = 23;
    int result;
    asm volatile (
        "li t1, 3 \n\t"
        "vsetvli t0, t1, e32, m1 \n\t"
        "vmv.v.i v1, 8 \n\t"
        "vsub.vx v3, v1, %1 \n\t"
        "vmv.x.s %0, v3"
        : "=r" (result) 
        : "r"  (subend)
    );

    if(result != -15)
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




int main(void)
{
    int errors = 0;

    printf("\nsub.vv\n");
    errors += sub_vv_test_e8_m1();
    errors += sub_vv_test_e16_m1();
    errors += sub_vv_test_e32_m1();
    printf("\nsub.vx\n");
    errors += sub_vx_test_e8_m1();
    errors += sub_vx_test_e16_m1();
    errors += sub_vx_test_e32_m1();


    printf("\nErrors: %d\n", errors);
    
    if(errors > 0)
        return(EXIT_FAILURE);
    else
        return(EXIT_SUCCESS);
}