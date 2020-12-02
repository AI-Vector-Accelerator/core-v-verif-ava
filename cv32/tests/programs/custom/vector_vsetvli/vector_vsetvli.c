#include <stdio.h>
#include <stdlib.h>

uint8_t vsetvli_e8_m1 (uint8_t avl)
{
    uint8_t new_vl;
    asm volatile (
        "vsetvli %0, %1, e8, m1"
        : "=r" (new_vl)
        : "r" (avl)
    );

    return new_vl;
}

uint8_t vsetvli_e8_m2 (uint8_t avl)
{
    uint8_t new_vl;
    asm volatile (
        "vsetvli %0, %1, e8, m2"
        : "=r" (new_vl)
        : "r" (avl)
    );

    return new_vl;
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

uint8_t vsetvli_e16_m1 (uint8_t avl)
{
    uint8_t new_vl;
    asm volatile (
        "vsetvli %0, %1, e16, m1"
        : "=r" (new_vl)
        : "r" (avl)
    );

    return new_vl;
}

uint8_t vsetvli_e16_m2 (uint8_t avl)
{
    uint8_t new_vl;
    asm volatile (
        "vsetvli %0, %1, e16, m2"
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

uint8_t vsetvli_e32_m1 (uint8_t avl)
{
    uint8_t new_vl;
    asm volatile (
        "vsetvli %0, %1, e32, m1"
        : "=r" (new_vl)
        : "r" (avl)
    );

    return new_vl;
}

uint8_t vsetvli_e32_m2 (uint8_t avl)
{
    uint8_t new_vl;
    asm volatile (
        "vsetvli %0, %1, e32, m2"
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

uint8_t check_new_vl(uint8_t avl, uint8_t max_vl, uint8_t new_vl)
{
    printf("AVL: %d max_vl: %d new_vl: %d\n", avl, max_vl, new_vl);
    if (avl > max_vl)
    {
        if (new_vl == max_vl)
            return 1;
        else
            return 0;
    }
    else
    {
        if (new_vl == avl)
            return 1;
        else
            return 0;
    }

}

int main(int argc, char *argv[])
{
    uint8_t new_vl;
    uint8_t avl_values[5] = {1, 4, 7, 16, 56};

    for (uint8_t i=0; i<5; i++)
    {
        // printf("%d\n", avl_values[i]);
        // printf("%d\n", i);


        printf("Checking 8b\n");
        new_vl = vsetvli_e8_m1(avl_values[i]);
        if (!check_new_vl(avl_values[i], 4, new_vl))
            return EXIT_FAILURE;
        new_vl = vsetvli_e8_m2(avl_values[i]);
        if (!check_new_vl(avl_values[i], 8, new_vl))
            return EXIT_FAILURE;
        new_vl = vsetvli_e8_m4(avl_values[i]);
        if (!check_new_vl(avl_values[i], 16, new_vl))
            return EXIT_FAILURE;

        printf("Checking 16b\n");
        new_vl = vsetvli_e16_m1(avl_values[i]);
        if (!check_new_vl(avl_values[i], 2, new_vl))
            return EXIT_FAILURE;
        new_vl = vsetvli_e16_m2(avl_values[i]);
        if (!check_new_vl(avl_values[i], 4, new_vl))
            return EXIT_FAILURE;
        new_vl = vsetvli_e16_m4(avl_values[i]);
        if (!check_new_vl(avl_values[i], 8, new_vl))
            return EXIT_FAILURE;

        printf("Checking 32b\n");
        new_vl = vsetvli_e32_m1(avl_values[i]);
        if (!check_new_vl(avl_values[i], 1, new_vl))
            return EXIT_FAILURE;
        new_vl = vsetvli_e32_m2(avl_values[i]);
        if (!check_new_vl(avl_values[i], 2, new_vl))
            return EXIT_FAILURE;
        new_vl = vsetvli_e32_m4(avl_values[i]);
        if (!check_new_vl(avl_values[i], 4, new_vl))
            return EXIT_FAILURE;




        // printf("Checking 8b\n");
        // new_vl = vsetvli_e8_m1(7);
        // if (!check_new_vl(7, 4, new_vl))
        //     return EXIT_FAILURE;
        // new_vl = vsetvli_e8_m2(7);
        // if (!check_new_vl(7, 8, new_vl))
        //     return EXIT_FAILURE;
        // new_vl = vsetvli_e8_m4(7);
        // if (!check_new_vl(7, 16, new_vl))
        //     return EXIT_FAILURE;

        // printf("Checking 16b\n");
        // new_vl = vsetvli_e16_m1(7);
        // if (!check_new_vl(7, 2, new_vl))
        //     return EXIT_FAILURE;
        // new_vl = vsetvli_e16_m2(7);
        // if (!check_new_vl(7, 4, new_vl))
        //     return EXIT_FAILURE;
        // new_vl = vsetvli_e16_m4(7);
        // if (!check_new_vl(7, 8, new_vl))
        //     return EXIT_FAILURE;

        // printf("Checking 32b\n");
        // new_vl = vsetvli_e32_m1(7);
        // if (!check_new_vl(7, 1, new_vl))
        //     return EXIT_FAILURE;
        // new_vl = vsetvli_e32_m2(7);
        // if (!check_new_vl(7, 2, new_vl))
        //     return EXIT_FAILURE;
        // new_vl = vsetvli_e32_m4(7);
        // if (!check_new_vl(7, 4, new_vl))
        //     return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;

    // if (avl > max_vl)
    // {
    //     if (new_vl == max_vl)
    //         return EXIT_SUCCESS;
    //     else
    //         return EXIT_FAILURE;
    // }
    // else
    // {
    //     if (new_vl == avl)
    //         return EXIT_SUCCESS;
    //     else
    //         return EXIT_FAILURE;
    // }
}
