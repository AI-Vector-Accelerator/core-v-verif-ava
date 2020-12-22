#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int vle_v_test_e32_m1(void)
{
    int32_t test_vect[6] = {-2343234, 2, 3, 4, 99 -53}; 

    int32_t element0;
    asm volatile (
        "li t1, 1 \n\t"
        "vsetvli t0, t1, e32, m1 \n\t"
        "vle.v v1, (%1) \n\t"
        "vmv.x.s %0, v1 \n\t"
        : "=r" (element0)
        : "r"  (test_vect)
    );

    if(element0 != -2343234)
    {
        printf("Fail: %ld\n", element0);
        return(1);
    }
    else
    {
        printf("Pass: %ld\n", element0);
        return(0);
    }
}

int vle_v_test_e32_m2(void)
{
    int32_t test_vect[6] = {-2343234, 2, 3, 4, 99 -53}; 

    int32_t element0, element1;
    asm volatile (
        "li t1, 11 \n\t"
        "vsetvli t0, t1, e32, m2 \n\t"
        "vle.v v2, (%2) \n\t"
        "vsetvli t0, t1, e32, m1 \n\t"
        "vmv.x.s %0, v2 \n\t"
        "vmv.x.s %1, v3 \n\t"
        : "=r" (element0), "=r" (element1)
        : "r"  (test_vect)
    );

    if(element0 != -2343234 || element1 != 2)
    {
        printf("Fail: %ld %ld\n", element0, element1);
        return(1);
    }
    else
    {
        printf("Pass: %ld %ld\n", element0, element1);
        return(0);
    }
}

int vle_v_test_e32_m4(void)
{
    int32_t test_vect[6] = {-2343234, 2, 3, 4, 99 -53}; 

    int32_t element0, element1, element2, element3;
    asm volatile (
        "li t1, 9 \n\t"
        "vsetvli t0, t1, e32, m4 \n\t"
        "vle.v v4, (%4) \n\t"
        "vsetvli t0, t1, e32, m1 \n\t"
        "vmv.x.s %0, v4 \n\t"
        "vmv.x.s %1, v5 \n\t"
        "vmv.x.s %2, v6 \n\t"
        "vmv.x.s %3, v7 \n\t"
        : "=r" (element0), "=r" (element1), "=r" (element2), "=r" (element3)
        : "r"  (test_vect)
    );

    if(element0 != -2343234 || element1 != 2 || element2 != 3 || element3 != 4)
    {
        printf("Fail: %ld %ld %ld %ld\n", element0, element1, element2, element3);
        return(1);
    }
    else
    {
        printf("Pass: %ld %ld %ld %ld\n", element0, element1, element2, element3);
        return(0);
    }
}



int vlse_v_test_e32_m1(void)
{
    int32_t test_vect[16] = {1, -2, 3, -4, 5, -6, 7, -8, 9, -10, 11, -12, 13, -14, 15, -16}; 

    int32_t element0;
    asm volatile (
        "li t1, 1 \n\t"
        "vsetvli t0, t1, e32, m1 \n\t"
        "li t2, 4 \n\t"                 // Load every 4th element
        "slli t2, t2, 2 \n\t"           // Convert no. of registers into no. of bytes
        "vlse.v v1, (%1), t2 \n\t"
        "vmv.x.s %0, v1 \n\t"
        : "=r" (element0)
        : "r"  (test_vect)
    );

    if(element0 != 1)
    {
        printf("Fail: %ld\n", element0);
        return(1);
    }
    else
    {
        printf("Pass: %ld\n", element0);
        return(0);
    }
}

int vlse_v_test_e32_m2(void)
{
    int32_t test_vect[16] = {1, -2, 3, -4, 5, -6, 7, -8, 9, -10, 11, -12, 13, -14, 15, -16}; 

    int32_t element0, element1;
    asm volatile (
        "li t1, 64 \n\t"
        "vsetvli t0, t1, e32, m2 \n\t"
        "li t2, 3 \n\t"                 // Load every 3rd element
        "slli t2, t2, 2 \n\t"           // Convert no. of registers into no. of bytes
        "vlse.v v2, (%2), t2 \n\t"
        "vsetvli t0, t1, e32, m1 \n\t"
        "vmv.x.s %0, v2 \n\t"
        "vmv.x.s %1, v3 \n\t"
        : "=r" (element0), "=r" (element1)
        : "r"  (test_vect)
    );

    if(element0 != 1 || element1 != -4)
    {
        printf("Fail: %ld %ld\n", element0, element1);
        return(1);
    }
    else
    {
        printf("Pass: %ld %ld\n", element0, element1);
        return(0);
    }
}

int vlse_v_test_e32_m4(void)
{
    int32_t test_vect[16] = {1, -2, 3, -4, 5, -6, 7, -8, 9, -10, 11, -12, 13, -14, 15, -16}; 

    int32_t element0, element1, element2, element3;
    asm volatile (
        "li t1, 64 \n\t"
        "vsetvli t0, t1, e32, m4 \n\t"
        "li t2, 2 \n\t"                 // Load every 2nd element
        "slli t2, t2, 2 \n\t"           // Convert no. of registers into no. of bytes
        "vlse.v v4, (%4), t2 \n\t"
        "vsetvli t0, t1, e32, m1 \n\t"
        "vmv.x.s %0, v4 \n\t"
        "vmv.x.s %1, v5 \n\t"
        "vmv.x.s %2, v6 \n\t"
        "vmv.x.s %3, v7 \n\t"
        : "=r" (element0), "=r" (element1), "=r" (element2), "=r" (element3)
        : "r"  (test_vect)
    );

    if(element0 != 1 || element1 != 3 || element2 != 5 || element3 != 7)
    {
        printf("Fail: %ld %ld %ld %ld\n", element0, element1, element2, element3);
        return(1);
    }
    else
    {
        printf("Pass: %ld %ld %ld %ld\n", element0, element1, element2, element3);
        return(0);
    }
}


int main()
{
    int errors = 0;

    printf("\nvle.v - 32-bit\n");
    errors += vle_v_test_e32_m1();
    errors += vle_v_test_e32_m2();
    errors += vle_v_test_e32_m4();
    
    printf("\nvlse.v - 32-bit\n");
    errors += vlse_v_test_e32_m1();
    errors += vlse_v_test_e32_m2();
    errors += vlse_v_test_e32_m4();


    if(errors > 0)
    {
        printf("\nErrors Detected!\nError Count: %d\n", errors);
        return(EXIT_FAILURE);
    }

    printf("\nAll Tests Completed\nNo Errors Detected!\n");

    return(EXIT_SUCCESS);

    return(0);
}
