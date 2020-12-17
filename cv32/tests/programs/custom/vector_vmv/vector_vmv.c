#include <stdio.h>
#include <stdlib.h>

int vmv_x_s()
{
    int scalar;

    asm volatile (
        "vmv.x.s %0, v4"
        : "=r" (scalar)
    );

    return scalar;
}

uint8_t vsetvli_e8_m4 (uint8_t avl)
{
    uint8_t new_vl;
    asm volatile (
        "vsetvli %0, %1, e8, m4"
        : "=r" (new_vl)
        : "r" (avl)
    );

    return new_vl;
}

uint8_t vsetvli_e16_m4 (uint8_t avl)
{
    uint8_t new_vl;
    asm volatile (
        "vsetvli %0, %1, e16, m4"
        : "=r" (new_vl)
        : "r" (avl)
    );

    return new_vl;
}

uint8_t vsetvli_e32_m4 (uint8_t avl)
{
    uint8_t new_vl;
    asm volatile (
        "vsetvli %0, %1, e32, m4"
        : "=r" (new_vl)
        : "r" (avl)
    );

    return new_vl;
}

void vmv_v_x (int n)
{
    asm volatile (
        "vmv.v.x v4, %0"
        :
        : "r" (n)
    );
}

int main(int argc, char *argv[])
{
    uint8_t avl = 16;
    int retrieved;
    int retrieved2;

////////////////////////////////////////////////////////////
    printf("Checking 8b\n");
    vsetvli_e8_m4(avl);

    asm volatile (
        "vmv.v.i v4, 7"
    );

    retrieved = vmv_x_s();

    printf("Retrieved value: %d\n", retrieved);

    if (retrieved != 7)
        return EXIT_FAILURE;

    vmv_v_x(-8);

    retrieved2 = vmv_x_s();

    printf("Retrieved value: %d\n", retrieved2);

    if (retrieved2 != -8)
        return EXIT_FAILURE;

////////////////////////////////////////////////////////////
    avl = 5;
    printf("Checking 16b\n");
    vsetvli_e16_m4(avl);

    asm volatile (
        "vmv.v.i v4, -14"
    );

    retrieved = vmv_x_s();

    printf("Retrieved value: %d\n", retrieved);

    if (retrieved != -14)
        return EXIT_FAILURE;

    vmv_v_x(13);

    retrieved2 = vmv_x_s();

    printf("Retrieved value: %d\n", retrieved2);

    if (retrieved2 != 13)
        return EXIT_FAILURE;

////////////////////////////////////////////////////////////
    avl = 3;
    printf("Checking 32b\n");
    vsetvli_e32_m4(avl);

    asm volatile (
        "vmv.v.i v4, -4"
    );

    retrieved = vmv_x_s();

    printf("Retrieved value: %d\n", retrieved);

    if (retrieved != -4)
        return EXIT_FAILURE;

    vmv_v_x(5);

    retrieved2 = vmv_x_s();

    printf("Retrieved value: %d\n", retrieved2);

    if (retrieved2 != 5)
        return EXIT_FAILURE;

////////////////////////////////////////////////////////////

    return EXIT_SUCCESS;
}
