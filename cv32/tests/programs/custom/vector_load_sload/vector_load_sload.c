#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/* When 8-bit elements are loaded into the 32-bit vector registers, they are placed
 * 4 elements per register. This function takes a 32-bit integer taken from a vector
 * register and extracts the 4 elements from it.
 */
void vector_reg_to_8_bit(
    int8_t* element3, 
    int8_t* element2, 
    int8_t* element1, 
    int8_t* element0, 
    int32_t vect_reg
)
{
    *element0 = vect_reg & 0x000000FF;
    *element1 = (vect_reg & 0x0000FF00) >> 8;
    *element2 = (vect_reg & 0x00FF0000) >> 16;
    *element3 = (vect_reg & 0xFF000000) >> 24;
}

/* When 16-bit elements are loaded into the 32-bit vector registers, they are placed
 * 2 elements per register. This function takes a 32-bit integer taken from a vector
 * register and extracts the 2 elements from it.
 */
void vector_reg_to_16_bit(
    int16_t* element1, 
    int16_t* element0, 
    int32_t vect_reg
)
{
    *element0 = vect_reg & 0x0000FFFF;
    *element1 = (vect_reg & 0xFFFF0000) >> 16;
}



int vle_v_test_e8_m1(void)
{
    int8_t test_vect[16] = {1, -2, 3, -4, 5, -6, 7, -8, 9, -10, 11, -12, 13, -14, 15, -16}; 

    int32_t register0;
    asm volatile (
        "li t1, 19 \n\t"
        "vsetvli t0, t1, e8, m1 \n\t"
        "vle.v v1, (%1) \n\t"
        "vsetvli t0, t1, e32, m1 \n\t"
        "vmv.x.s %0, v1 \n\t"
        : "=r" (register0)
        : "r"  (test_vect)
    );

    int8_t element0, element1, element2, element3;

    vector_reg_to_8_bit(&element3, &element2, &element1, &element0, register0);

    if(element0 != 1 || element1 != -2 || element2 != 3 || element3 != -4)
    {
        printf("Fail: %d %d %d %d\n", element0, element1, element2, element3);
        return(1);
    }
    else
    {
        printf("Pass: %d %d %d %d\n", element0, element1, element2, element3);
        return(0);
    }
}


int vle_v_test_e8_m2(void)
{
    int8_t test_vect[16] = {1, -2, 3, -4, 5, -6, 7, -8, 9, -10, 11, -12, 13, -14, 15, -16};

    int32_t register0, register1;
    asm volatile (
        "li t1, 11 \n\t"
        "vsetvli t0, t1, e8, m2 \n\t"
        "vle.v v2, (%2) \n\t"
        "vsetvli t0, t1, e32, m1 \n\t"
        "vmv.x.s %0, v2 \n\t"
        "vmv.x.s %1, v3 \n\t"
        : "=r" (register0), "=r" (register1)
        : "r"  (test_vect)
    );

    int8_t elm0, elm1, elm2, elm3, elm4, elm5, elm6, elm7;

    vector_reg_to_8_bit(&elm3, &elm2, &elm1, &elm0, register0);
    vector_reg_to_8_bit(&elm7, &elm6, &elm5, &elm4, register1);

    int first_register_fail = (elm0 != 1 || elm1 != -2 || elm2 != 3 || elm3 != -4);
    int second_register_fail = (elm4 != 5 || elm5 != -6 || elm6 != 7 || elm7 != -8);

    if(first_register_fail || second_register_fail)
    {
        printf("Fail: %d %d %d %d %d %d %d %d\n", elm0, elm1, elm2, elm3, elm4, elm5, elm6, elm7);
        return(1);
    }
    else
    {
        printf("Pass: %d %d %d %d %d %d %d %d\n", elm0, elm1, elm2, elm3, elm4, elm5, elm6, elm7);
        return(0);
    }
}


int vle_v_test_e8_m4(void)
{
    int8_t test_vect[16] = {1, -2, 3, -4, 5, -6, 7, -8, 9, -10, 11, -12, 13, -14, 15, -16};

    int32_t register0, register1, register2, register3;
    asm volatile (
        "li t1, 34 \n\t"
        "vsetvli t0, t1, e8, m4 \n\t"
        "vle.v v4, (%4) \n\t"
        "vsetvli t0, t1, e32, m1 \n\t"
        "vmv.x.s %0, v4 \n\t"
        "vmv.x.s %1, v5 \n\t"
        "vmv.x.s %2, v6 \n\t"
        "vmv.x.s %3, v7 \n\t"
        : "=r" (register0), "=r" (register1), "=r" (register2), "=r" (register3)
        : "r"  (test_vect)
    );

    int8_t elm0, elm1, elm2, elm3, elm4, elm5, elm6, elm7;
    int8_t elm8, elm9, elm10, elm11, elm12, elm13, elm14, elm15;

    vector_reg_to_8_bit(&elm3, &elm2, &elm1, &elm0, register0);
    vector_reg_to_8_bit(&elm7, &elm6, &elm5, &elm4, register1);
    vector_reg_to_8_bit(&elm11, &elm10, &elm9, &elm8, register2);
    vector_reg_to_8_bit(&elm15, &elm14, &elm13, &elm12, register3);

    int first_register_fail = (elm0 != 1 || elm1 != -2 || elm2 != 3 || elm3 != -4);
    int second_register_fail = (elm4 != 5 || elm5 != -6 || elm6 != 7 || elm7 != -8);
    int third_register_fail = (elm8 != 9 || elm9 != -10 || elm10 != 11 || elm11 != -12);
    int fourth_register_fail = (elm12 != 13 || elm13 != -14 || elm14 != 15 || elm15 != -16);

    if(first_register_fail || second_register_fail || third_register_fail || fourth_register_fail)
    {
        printf(
            "Fail: %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n", 
            elm0, elm1, elm2, elm3, elm4, elm5, elm6, elm7,
            elm8, elm9, elm10, elm11, elm12, elm13, elm14, elm15
        );

        return(1);
    }
    else
    {
        printf(
            "Pass: %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n", 
            elm0, elm1, elm2, elm3, elm4, elm5, elm6, elm7,
            elm8, elm9, elm10, elm11, elm12, elm13, elm14, elm15
        );

        return(0);
    }
}


int vlse_v_test_e8_m1(void)
{
    int8_t test_vect[16] = {1, -2, 3, -4, 5, -6, 7, -8, 9, -10, 11, -12, 13, -14, 15, -16}; 

    int32_t register0;
    asm volatile (
        "li t1, 64 \n\t"
        "vsetvli t0, t1, e8, m1 \n\t"
        "li t2, 4 \n\t"                 // Load every 4th element
        "vlse.v v1, (%1), t2 \n\t"      // Data is stored in bytes so no need to shift
        "vsetvli t0, t1, e32, m1\n\t"
        "vmv.x.s %0, v1 \n\t"
        : "=r" (register0)
        : "r"  (test_vect)
    );

    int8_t element0, element1, element2, element3;

    vector_reg_to_8_bit(&element3, &element2, &element1, &element0, register0);

    if(element0 != 1 || element1 != 5 || element2 != 9 || element3 != 13)
    {
        printf("Fail: %d %d %d %d\n", element0, element1, element2, element3);
        return(1);
    }
    else
    {
        printf("Pass: %d %d %d %d\n", element0, element1, element2, element3);
        return(0);
    }
}


int vlse_v_test_e8_m2(void)
{
    int8_t test_vect[24] = {
        1, -2, 3, -4, 5, -6, 7, -8, 9, -10, 11, -12, 13, -14, 15, -16,
        17, -18, 19, -20, 21, -22, 23, -24
    };

    int32_t register0, register1;
    asm volatile (
        "li t1, 64 \n\t"
        "vsetvli t0, t1, e8, m2 \n\t"
        "li t2, 3 \n\t"                 // Load every 3rd element
        "vlse.v v2, (%2), t2 \n\t"
        "vsetvli t0, t1, e32, m1 \n\t"
        "vmv.x.s %0, v2 \n\t"
        "vmv.x.s %1, v3 \n\t"
        : "=r" (register0), "=r" (register1)
        : "r"  (test_vect)
    );

    int8_t elm0, elm1, elm2, elm3, elm4, elm5, elm6, elm7;

    vector_reg_to_8_bit(&elm3, &elm2, &elm1, &elm0, register0);
    vector_reg_to_8_bit(&elm7, &elm6, &elm5, &elm4, register1);

    int first_register_fail = (elm0 != 1 || elm1 != -4 || elm2 != 7 || elm3 != -10);
    int second_register_fail = (elm4 != 13 || elm5 != -16 || elm6 != 19 || elm7 != -22);

    if(first_register_fail || second_register_fail)
    {
        printf("Fail: %d %d %d %d %d %d %d %d\n", elm0, elm1, elm2, elm3, elm4, elm5, elm6, elm7);
        return(1);
    }
    else
    {
        printf("Pass: %d %d %d %d %d %d %d %d\n", elm0, elm1, elm2, elm3, elm4, elm5, elm6, elm7);
        return(0);
    }
}


int vlse_v_test_e8_m4(void)
{
    int8_t test_vect[34] = {
        1, -2, 3, -4, 5, -6, 7, -8, 9, -10, 11, -12, 13, -14, 15, -16,
        17, -18, 19, -20, 21, -22, 23, -24, 25, -26, 27, -28, 29, -30, 
        31, 32
    };

    int32_t register0, register1, register2, register3;
    asm volatile (
        "li t1, 34 \n\t"
        "vsetvli t0, t1, e8, m4 \n\t"
        "li t2, 2 \n\t"                 // Load every 2rd element
        "vlse.v v4, (%4), t2 \n\t"
        "vsetvli t0, t1, e32, m1 \n\t"
        "vmv.x.s %0, v4 \n\t"
        "vmv.x.s %1, v5 \n\t"
        "vmv.x.s %2, v6 \n\t"
        "vmv.x.s %3, v7 \n\t"
        : "=r" (register0), "=r" (register1), "=r" (register2), "=r" (register3)
        : "r"  (test_vect)
    );

    int8_t elm0, elm1, elm2, elm3, elm4, elm5, elm6, elm7;
    int8_t elm8, elm9, elm10, elm11, elm12, elm13, elm14, elm15;

    vector_reg_to_8_bit(&elm3, &elm2, &elm1, &elm0, register0);
    vector_reg_to_8_bit(&elm7, &elm6, &elm5, &elm4, register1);
    vector_reg_to_8_bit(&elm11, &elm10, &elm9, &elm8, register2);
    vector_reg_to_8_bit(&elm15, &elm14, &elm13, &elm12, register3);

    int first_register_fail = (elm0 != 1 || elm1 != 3 || elm2 != 5 || elm3 != 7);
    int second_register_fail = (elm4 != 9 || elm5 != 11 || elm6 != 13 || elm7 != 15);
    int third_register_fail = (elm8 != 17 || elm9 != 19 || elm10 != 21 || elm11 != 23);
    int fourth_register_fail = (elm12 != 25 || elm13 != 27 || elm14 != 29 || elm15 != 31);

    if(first_register_fail || second_register_fail || third_register_fail || fourth_register_fail)
    {
        printf(
            "Fail: %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n", 
            elm0, elm1, elm2, elm3, elm4, elm5, elm6, elm7,
            elm8, elm9, elm10, elm11, elm12, elm13, elm14, elm15
        );

        return(1);
    }
    else
    {
        printf(
            "Pass: %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n", 
            elm0, elm1, elm2, elm3, elm4, elm5, elm6, elm7,
            elm8, elm9, elm10, elm11, elm12, elm13, elm14, elm15
        );

        return(0);
    }
}


int vle_v_test_e16_m1(void)
{
    int16_t test_vect[16] = {1, -2, 3, -4, 5, -6, 7, -8, 9, -10, 11, -12, 13, -14, 15, -16}; 

    int32_t register0;
    asm volatile (
        "li t1, 19 \n\t"
        "vsetvli t0, t1, e16, m1 \n\t"
        "vle.v v1, (%1) \n\t"
        "vsetvli t0, t1, e32, m1 \n\t"
        "vmv.x.s %0, v1 \n\t"
        : "=r" (register0)
        : "r"  (test_vect)
    );

    int16_t element0, element1;

    vector_reg_to_16_bit(&element1, &element0, register0);

    if(element0 != 1 || element1 != -2)
    {
        printf("Fail: %d %d\n", element0, element1);
        return(1);
    }
    else
    {
        printf("Pass: %d %d\n", element0, element1);
        return(0);
    }
}


int vle_v_test_e16_m2(void)
{
    int16_t test_vect[16] = {1, -2, 3, -4, 5, -6, 7, -8, 9, -10, 11, -12, 13, -14, 15, -16};

    int32_t register0, register1;
    asm volatile (
        "li t1, 11 \n\t"
        "vsetvli t0, t1, e16, m2 \n\t"
        "vle.v v2, (%2) \n\t"
        "vsetvli t0, t1, e32, m1 \n\t"
        "vmv.x.s %0, v2 \n\t"
        "vmv.x.s %1, v3 \n\t"
        : "=r" (register0), "=r" (register1)
        : "r"  (test_vect)
    );

    int16_t elm0, elm1, elm2, elm3;

    vector_reg_to_16_bit(&elm1, &elm0, register0);
    vector_reg_to_16_bit(&elm3, &elm2, register1);

    int first_register_fail = (elm0 != 1 || elm1 != -2);
    int second_register_fail = (elm2 != 3 || elm3 != -4);

    if(first_register_fail || second_register_fail)
    {
        printf("Fail: %d %d %d %d\n", elm0, elm1, elm2, elm3);
        return(1);
    }
    else
    {
        printf("Pass: %d %d %d %d\n", elm0, elm1, elm2, elm3);
        return(0);
    }
}


int vle_v_test_e16_m4(void)
{
    int16_t test_vect[16] = {1, -2, 3, -4, 5, -6, 7, -8, 9, -10, 11, -12, 13, -14, 15, -16};

    int32_t register0, register1, register2, register3;
    asm volatile (
        "li t1, 34 \n\t"
        "vsetvli t0, t1, e16, m4 \n\t"
        "vle.v v4, (%4) \n\t"
        "vsetvli t0, t1, e32, m1 \n\t"
        "vmv.x.s %0, v4 \n\t"
        "vmv.x.s %1, v5 \n\t"
        "vmv.x.s %2, v6 \n\t"
        "vmv.x.s %3, v7 \n\t"
        : "=r" (register0), "=r" (register1), "=r" (register2), "=r" (register3)
        : "r"  (test_vect)
    );

    int16_t elm0, elm1, elm2, elm3, elm4, elm5, elm6, elm7;

    vector_reg_to_16_bit(&elm1, &elm0, register0); 
    vector_reg_to_16_bit(&elm3, &elm2, register1);
    vector_reg_to_16_bit(&elm5, &elm4, register2);
    vector_reg_to_16_bit(&elm7, &elm6, register3);

    int first_register_fail = (elm0 != 1 || elm1 != -2);
    int second_register_fail = (elm2 != 3 || elm3 != -4);
    int third_register_fail = (elm4 != 5 || elm5 != -6);
    int fourth_register_fail = (elm6 != 7 || elm7 != -8);

    if(first_register_fail || second_register_fail || third_register_fail || fourth_register_fail)
    {
        printf(
            "Fail: %d %d %d %d %d %d %d %d\n", 
            elm0, elm1, elm2, elm3, elm4, elm5, elm6, elm7
        );

        return(1);
    }
    else
    {
        printf(
            "Pass: %d %d %d %d %d %d %d %d\n", 
            elm0, elm1, elm2, elm3, elm4, elm5, elm6, elm7
        );

        return(0);
    }
}


int vlse_v_test_e16_m1(void)
{
    int16_t test_vect[16] = {1, -2, 3, -4, 5, -6, 7, -8, 9, -10, 11, -12, 13, -14, 15, -16}; 

    int32_t register0;
    asm volatile (
        "li t1, 19 \n\t"
        "vsetvli t0, t1, e16, m1 \n\t"
        "li t2, 7 \n\t"                 // Set a stride lenght of 7 elements
        "slli t2, t2, 1 \n\t"            // Convert elements to bytes
        "vlse.v v1, (%1), t2\n\t"
        "vsetvli t0, t1, e32, m1 \n\t"
        "vmv.x.s %0, v1 \n\t"
        : "=r" (register0)
        : "r"  (test_vect)
    );

    int16_t element0, element1;

    vector_reg_to_16_bit(&element1, &element0, register0);

    if(element0 != 1 || element1 != -8)
    {
        printf("Fail: %d %d\n", element0, element1);
        return(1);
    }
    else
    {
        printf("Pass: %d %d\n", element0, element1);
        return(0);
    }
}


int vlse_v_test_e16_m2(void)
{
    int16_t test_vect[34] = {
        1, -2, 3, -4, 5, -6, 7, -8, 9, -10, 11, -12, 13, -14, 15, -16,
        17, -18, 19, -20, 21, -22, 23, -24, 25, -26, 27, -28, 29, -30, 
        31, 32
    };

    int32_t register0, register1;
    asm volatile (
        "li t1, 11 \n\t"
        "vsetvli t0, t1, e16, m2 \n\t"
        "li t2, 5 \n\t"                 // Set a stride lenght of 5 elements
        "slli t2, t2, 1 \n\t"           // Convert elements to bytes
        "vlse.v v2, (%2), t2\n\t"
        "vsetvli t0, t1, e32, m1 \n\t"
        "vmv.x.s %0, v2 \n\t"
        "vmv.x.s %1, v3 \n\t"
        : "=r" (register0), "=r" (register1)
        : "r"  (test_vect)
    );

    int16_t elm0, elm1, elm2, elm3;

    vector_reg_to_16_bit(&elm1, &elm0, register0);
    vector_reg_to_16_bit(&elm3, &elm2, register1);

    int first_register_fail = (elm0 != 1 || elm1 != -6);
    int second_register_fail = (elm2 != 11 || elm3 != -16);

    if(first_register_fail || second_register_fail)
    {
        printf("Fail: %d %d %d %d\n", elm0, elm1, elm2, elm3);
        return(1);
    }
    else
    {
        printf("Pass: %d %d %d %d\n", elm0, elm1, elm2, elm3);
        return(0);
    }
}


int vlse_v_test_e16_m4(void)
{
    int16_t test_vect[16] = {1, -2, 3, -4, 5, -6, 7, -8, 9, -10, 11, -12, 13, -14, 15, -16};

    int32_t register0, register1, register2, register3;
    asm volatile (
        "li t1, 34 \n\t"
        "vsetvli t0, t1, e16, m4 \n\t"
        "li t2, 1 \n\t"                 // Set a stride lenght of 1 elements
        "slli t2, t2, 1 \n\t"           // Convert elements to bytes
        "vlse.v v4, (%4), t2\n\t"
        "vsetvli t0, t1, e32, m1 \n\t"
        "vmv.x.s %0, v4 \n\t"
        "vmv.x.s %1, v5 \n\t"
        "vmv.x.s %2, v6 \n\t"
        "vmv.x.s %3, v7 \n\t"
        : "=r" (register0), "=r" (register1), "=r" (register2), "=r" (register3)
        : "r"  (test_vect)
    );

    int16_t elm0, elm1, elm2, elm3, elm4, elm5, elm6, elm7;

    vector_reg_to_16_bit(&elm1, &elm0, register0); 
    vector_reg_to_16_bit(&elm3, &elm2, register1);
    vector_reg_to_16_bit(&elm5, &elm4, register2);
    vector_reg_to_16_bit(&elm7, &elm6, register3);

    int first_register_fail = (elm0 != 1 || elm1 != -2);
    int second_register_fail = (elm2 != 3 || elm3 != -4);
    int third_register_fail = (elm4 != 5 || elm5 != -6);
    int fourth_register_fail = (elm6 != 7 || elm7 != -8);

    if(first_register_fail || second_register_fail || third_register_fail || fourth_register_fail)
    {
        printf(
            "Fail: %d %d %d %d %d %d %d %d\n", 
            elm0, elm1, elm2, elm3, elm4, elm5, elm6, elm7
        );

        return(1);
    }
    else
    {
        printf(
            "Pass: %d %d %d %d %d %d %d %d\n", 
            elm0, elm1, elm2, elm3, elm4, elm5, elm6, elm7
        );

        return(0);
    }
}



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

    printf("\nvle.v - 8-bit\n");
    errors += vle_v_test_e8_m1();
    errors += vle_v_test_e8_m2();
    errors += vle_v_test_e8_m4();

    printf("\nvlse.v - 8-bit\n");
    errors += vlse_v_test_e8_m1();
    errors += vlse_v_test_e8_m2();
    errors += vlse_v_test_e8_m4();

    printf("\nvle.v - 16-bit\n");
    errors += vle_v_test_e16_m1();
    errors += vle_v_test_e16_m2();
    errors += vle_v_test_e16_m4();

    printf("\nvlse.v - 16-bit\n");
    errors += vlse_v_test_e16_m1();
    errors += vlse_v_test_e16_m2();
    errors += vlse_v_test_e16_m4();

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
