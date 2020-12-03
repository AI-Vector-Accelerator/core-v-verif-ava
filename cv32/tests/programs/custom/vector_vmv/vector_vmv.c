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

int main(int argc, char *argv[])
{
    uint8_t avl = 16;
    int retrieved;

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

////////////////////////////////////////////////////////////
    avl = 5;
    printf("Checking 16b\n");
    vsetvli_e16_m4(avl);

    asm volatile (
        "vmv.v.i v4, 14"
    );

    retrieved = vmv_x_s();

    printf("Retrieved value: %d\n", retrieved);

    if (retrieved != 14)
        return EXIT_FAILURE;

////////////////////////////////////////////////////////////
    avl = 3;
    printf("Checking 32b\n");
    vsetvli_e32_m4(avl);

    asm volatile (
        "vmv.v.i v4, 4"
    );

    retrieved = vmv_x_s();

    printf("Retrieved value: %d\n", retrieved);

    if (retrieved != 4)
        return EXIT_FAILURE;

////////////////////////////////////////////////////////////

    return EXIT_SUCCESS;
}