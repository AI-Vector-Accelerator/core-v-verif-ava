#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int compare_int8_vectors(int8_t vect1[], int8_t vect2[], int len)
{
    for(int i = 0; i < len; i++)
        if(vect1[i] != vect2[i])
        {
            return(1);
        }
            
    return(0);
}

int compare_int16_vectors(int16_t vect1[], int16_t vect2[], int len)
{
    for(int i = 0; i < len; i++)
        if(vect1[i] != vect2[i])
        {
            return(1);
        }
            
    return(0);
}

int compare_int32_vectors(int32_t vect1[], int32_t vect2[], int len)
{
    for(int i = 0; i < len; i++)
        if(vect1[i] != vect2[i])
        {
            return(1);
        }
            
    return(0);
}


int vse_v_test_e8_m1(void)
{
    int vect_len = 4;
    int8_t vect_in[4] = {1, -2, 3, -4}; 
    int8_t vect_out[4] = {0};

    asm volatile (
        "li t1, 19 \n\t"
        "vsetvli t0, t1, e8, m1 \n\t"
        "vle.v v1, (%1) \n\t"
        "vse.v v1, (%0)"
        :
        : "r" (vect_out), "r"  (vect_in)
    );

    int test_fail = compare_int8_vectors(vect_out, vect_in, vect_len);

    if(test_fail)
    {
        printf("Fail\n");
    }
    else
    {
        printf("  Pass\n");
    }

    int i;
    printf("    vect_in:  ");
    for(i = 0; i < vect_len; i++)
        printf("%d ", vect_in[i]);

    printf("\n");

    printf("    vect_out: ");
    for(i = 0; i < vect_len; i++)
        printf("%d ", vect_out[i]);

    printf("\n");

    return(test_fail);
}

int vse_v_test_e8_m2(void)
{
    int vect_len = 8;
    int8_t vect_in[8] = {1, -2, 3, -4, 5, -6, 7, -8}; 
    int8_t vect_out[9] = {0};

    asm volatile (
        "li t1, 19 \n\t"
        "vsetvli t0, t1, e8, m2 \n\t"
        "vle.v v2, (%1) \n\t"
        "vse.v v2, (%0)"
        :
        : "r" (vect_out), "r"  (vect_in)
    );

    int test_fail = compare_int8_vectors(vect_out, vect_in, vect_len);

    if(test_fail)
    {
        printf("Fail\n");
    }
    else
    {
        printf("  Pass\n");
    }

    int i;
    printf("    vect_in:  ");
    for(i = 0; i < vect_len; i++)
        printf("%d ", vect_in[i]);

    printf("\n");

    printf("    vect_out: ");
    for(i = 0; i < vect_len; i++)
        printf("%d ", vect_out[i]);

    printf("\n");

    return(test_fail);
}

int vse_v_test_e8_m4(void)
{
    int vect_len = 16;
    int8_t vect_in[16] = {1, -2, 3, -4, 5, -6, 7, -8, 9, -10, 11, -12, 13, -14, 15, -16}; 
    int8_t vect_out[16] = {0};

    asm volatile (
        "li t1, 19 \n\t"
        "vsetvli t0, t1, e8, m4 \n\t"
        "vle.v v4, (%1) \n\t"
        "vse.v v4, (%0)"
        :
        : "r" (vect_out), "r"  (vect_in)
    );

    int test_fail = compare_int8_vectors(vect_out, vect_in, vect_len);

    if(test_fail)
    {
        printf("Fail\n");
    }
    else
    {
        printf("  Pass\n");
    }

    int i;
    printf("    vect_in:  ");
    for(i = 0; i < vect_len; i++)
        printf("%d ", vect_in[i]);

    printf("\n");

    printf("    vect_out: ");
    for(i = 0; i < vect_len; i++)
        printf("%d ", vect_out[i]);

    printf("\n");

    return(test_fail);
}



int vse_v_test_e16_m1(void)
{
    int vect_len = 2;
    int16_t vect_in[2] = {1, -2}; 
    int16_t vect_out[2] = {0};

    asm volatile (
        "li t1, 19 \n\t"
        "vsetvli t0, t1, e16, m1 \n\t"
        "vle.v v1, (%1) \n\t"
        "vse.v v1, (%0)"
        :
        : "r" (vect_out), "r"  (vect_in)
    );

    int test_fail = compare_int16_vectors(vect_out, vect_in, vect_len);

    if(test_fail)
    {
        printf("Fail\n");
    }
    else
    {
        printf("  Pass\n");
    }

    int i;
    printf("    vect_in:  ");
    for(i = 0; i < vect_len; i++)
        printf("%d ", vect_in[i]);

    printf("\n");

    printf("    vect_out: ");
    for(i = 0; i < vect_len; i++)
        printf("%d ", vect_out[i]);

    printf("\n");

    return(test_fail);
}

int vse_v_test_e16_m2(void)
{
    int vect_len = 4;
    int16_t vect_in[4] = {1, -2, 3, -4}; 
    int16_t vect_out[4] = {0};

    asm volatile (
        "li t1, 19 \n\t"
        "vsetvli t0, t1, e16, m2 \n\t"
        "vle.v v2, (%1) \n\t"
        "vse.v v2, (%0)"
        :
        : "r" (vect_out), "r"  (vect_in)
    );

    int test_fail = compare_int16_vectors(vect_out, vect_in, vect_len);

    if(test_fail)
    {
        printf("Fail\n");
    }
    else
    {
        printf("  Pass\n");
    }

    int i;
    printf("    vect_in:  ");
    for(i = 0; i < vect_len; i++)
        printf("%d ", vect_in[i]);

    printf("\n");

    printf("    vect_out: ");
    for(i = 0; i < vect_len; i++)
        printf("%d ", vect_out[i]);

    printf("\n");

    return(test_fail);
}

int vse_v_test_e16_m4(void)
{
    int vect_len = 8;
    int16_t vect_in[8] = {1, -2, 3, -4, 5, -6, 7, -8}; 
    int16_t vect_out[8] = {0};

    asm volatile (
        "li t1, 19 \n\t"
        "vsetvli t0, t1, e16, m4 \n\t"
        "vle.v v4, (%1) \n\t"
        "vse.v v4, (%0)"
        :
        : "r" (vect_out), "r"  (vect_in)
    );

    int test_fail = compare_int16_vectors(vect_out, vect_in, vect_len);

    if(test_fail)
    {
        printf("Fail\n");
    }
    else
    {
        printf("  Pass\n");
    }

    int i;
    printf("    vect_in:  ");
    for(i = 0; i < vect_len; i++)
        printf("%d ", vect_in[i]);

    printf("\n");

    printf("    vect_out: ");
    for(i = 0; i < vect_len; i++)
        printf("%d ", vect_out[i]);

    printf("\n");

    return(test_fail);
}



int vse_v_test_e32_m1(void)
{
    int vect_len = 1;
    int32_t vect_in[1] = {1}; 
    int32_t vect_out[1] = {0};

    asm volatile (
        "li t1, 19 \n\t"
        "vsetvli t0, t1, e32, m1 \n\t"
        "vmv.v.x v1, %1 \n\t"
        "vse.v v1, (%0)"
        :
        : "r" (vect_out), "r" (vect_in[0])
    );

    int test_fail = compare_int32_vectors(vect_out, vect_in, vect_len);

    if(test_fail)
    {
        printf("Fail\n");
    }
    else
    {
        printf("  Pass\n");
    }

    int i;
    printf("    vect_in:  ");
    for(i = 0; i < vect_len; i++)
        printf("%ld ", vect_in[i]);

    printf("\n");

    printf("    vect_out: ");
    for(i = 0; i < vect_len; i++)
        printf("%ld ", vect_out[i]);

    printf("\n");

    return(test_fail);
}

int vse_v_test_e32_m2(void)
{
    int vect_len = 2;
    int32_t vect_in[2] = {1, -2}; 
    int32_t vect_out[2] = {0};

    asm volatile (
        "li t1, 19 \n\t"
        "vsetvli t0, t1, e32, m1 \n\t"
        "vmv.v.x v2, %1 \n\t"
        "vmv.v.x v3, %2 \n\t"
        "vsetvli t0, t1, e32, m2 \n\t"
        "vse.v v2, (%0)"
        :
        : "r" (vect_out), "r" (vect_in[0]), "r" (vect_in[1])
    );

    int test_fail = compare_int32_vectors(vect_out, vect_in, vect_len);

    if(test_fail)
    {
        printf("Fail\n");
    }
    else
    {
        printf("  Pass\n");
    }

    int i;
    printf("    vect_in:  ");
    for(i = 0; i < vect_len; i++)
        printf("%ld ", vect_in[i]);

    printf("\n");

    printf("    vect_out: ");
    for(i = 0; i < vect_len; i++)
        printf("%ld ", vect_out[i]);

    printf("\n");

    return(test_fail);
}

int vse_v_test_e32_m4(void)
{
    int vect_len = 4;
    int32_t vect_in[4] = {1, -2, 3, -4}; 
    int32_t vect_out[4] = {0};

    asm volatile (
        "li t1, 5 \n\t"
        "vsetvli t0, t1, e32, m1 \n\t"
        "vmv.v.x v4, %1 \n\t"
        "vmv.v.x v5, %2 \n\t"
        "vmv.v.x v6, %3 \n\t"
        "vmv.v.x v7, %4 \n\t"
        "vsetvli t0, t1, e32, m4 \n\t"
        "vse.v v4, (%0)"
        :
        : "r" (vect_out), "r" (vect_in[0]), "r" (vect_in[1]), "r" (vect_in[2]), "r" (vect_in[3])
    );

    int test_fail = compare_int32_vectors(vect_out, vect_in, vect_len);

    if(test_fail)
    {
        printf("Fail\n");
    }
    else
    {
        printf("  Pass\n");
    }

    int i;
    printf("    vect_in:  ");
    for(i = 0; i < vect_len; i++)
        printf("%ld ", vect_in[i]);

    printf("\n");

    printf("    vect_out: ");
    for(i = 0; i < vect_len; i++)
        printf("%ld ", vect_out[i]);

    printf("\n");

    return(test_fail);
}


int main()
{
    int errors = 0;

    printf("\nvse - 32-bit\n");
    errors += vse_v_test_e32_m1();
    errors += vse_v_test_e32_m2();
    errors += vse_v_test_e32_m4();

    printf("\nvse - 8-bit\n");
    errors += vse_v_test_e8_m1();
    errors += vse_v_test_e8_m2();
    errors += vse_v_test_e8_m4();

    printf("\nvse - 16-bit\n");
    errors += vse_v_test_e16_m1();
    errors += vse_v_test_e16_m2();
    errors += vse_v_test_e16_m4();


    if(errors > 0)
    {
        printf("\nErrors Detected!\nError Count: %d\n", errors);
        return(EXIT_FAILURE);
    }

    printf("\nAll Tests Completed\nNo Errors Detected!\n");

    return(EXIT_SUCCESS);
}