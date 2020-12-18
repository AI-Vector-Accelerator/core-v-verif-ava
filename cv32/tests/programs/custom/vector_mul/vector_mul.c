#include <stdio.h>
#include <stdlib.h>

int vmul_vv_test_e8_m1(uint8_t vlen)
{
    printf("Starting smul e8 m1 Test...");
    int8_t output;
    asm volatile (
        "vsetvli t2, %1, e8, m1\n\t"
        "vmv.v.i v1, -5\n\t"
        "vmv.v.i v2, 5\n\t"
        "vmul.vv v1, v1, v2\n\t"
        "vmv.x.s %0, v1"
        : "=r" (output)
        : "r" (vlen)
    );

    printf("Test Complete! Output: %d\n", output);
    if(output != -25)
    {
       printf("FAIL\n");
       return(1);
    }
    else
    {
       printf("PASS\n");
       return(0);
    }

}

int vmul_vv_test_e8_m2(uint8_t vlen)
{
    printf("Starting smul e8 m2 Test...");
    int8_t output0, output1;
    asm volatile (
        "vsetvli t2, %1, e8, m1\n\t"
        "vmv.v.i v2, 6\n\t"
        "vmv.v.i v3, -6\n\t"
        "vmv.v.i v4, 6\n\t"
        "vmv.v.i v5, 6\n\t"
        "vsetvli t2, %2, e8, m2\n\t"
        "vmul.vv v6, v2, v4\n\t"
        "vsetvli t2, %2, e8\n\t"
        "vmv.x.s %0, v6\n\t"
        "vmv.x.s %1, v7"
        : "=r" (output0), "=r" (output1)
        : "r" (vlen)
    );


    if(output0 != 36 || output1 != -36)
    {
        printf("Test Complete! FAIL Output: v4: %d\tv5: %d\n", output0, output1);
       return(1);
    }
    else
    {
         printf("Test Complete! PASS Output: v4: %d\tv5: %d\n", output0, output1);
       return(0);
    }

}

int vmul_vv_test_e8_m4(uint8_t vlen)
{
    printf("Starting smul e8 m4 Test...");
    int8_t output0, output1, output2, output3;
    asm volatile (
        "vsetvli t2, %4, e8, m1\n\t"
        "vmv.v.i v4, -6\n\t"
        "vmv.v.i v5, -5\n\t"
        "vmv.v.i v6, -4\n\t"
        "vmv.v.i v7, -3\n\t"
        "vmv.v.i v8, 5\n\t"
        "vmv.v.i v9, 5\n\t"
        "vmv.v.i v10, 5\n\t"
        "vmv.v.i v11, 5\n\t"
        "vsetvli t2, %4, e8, m4\n\t"
        "vmul.vv v12, v4, v8\n\t"
        "vsetvli t2, %4, e8\n\t"
        "vmv.x.s %0, v12\n\t"
        "vmv.x.s %1, v13\n\t"
        "vmv.x.s %2, v14\n\t"
        "vmv.x.s %3, v15\n\t"
        : "=r" (output0), "=r" (output1), "=r" (output2), "=r" (output3)
        : "r" (vlen)
    );

    printf("Test Complete! Output: v8: %d\tv9: %d\tv10: %d\tv11: %d\n", output0, output1, output2, output3);
    if(output0 != -30 || output1 != -25 || output2 != -20 || output3 != -15)
    {
       printf("FAIL\n");
       return(1);
    }
    else
    {
       printf("PASS\n");
       return(0);
    }
}

int vwmul_vv_test_e8_m1(uint8_t vlen)
{
    printf("Starting wmulv e8 m1 Test...");
    int16_t output;
    asm volatile (
        "vsetvli t2, %1, e8, m1\n\t"
        "vmv.v.i v1, -16\n\t"
        "vmv.v.i v2, 14\n\t"
        "vsetvli t2, %1, e8, m1\n\t"
        "vwmul.vv v4, v1, v2\n\t"
        "vsetvli t2, %1, e16\n\t"
        "vmv.x.s %0, v4"
        : "=r" (output)
        : "r" (vlen)
    );

    printf("Test Complete! Output: %d\n", output);
    if(output !=  -224)
    {
       printf("FAIL\n");
       return(1);
    }
    else
    {
       printf("PASS\n");
       return(0);
    }

}

int vwmul_vv_test_e8_m2(uint8_t vlen)
{
    printf("Starting wmulv e8 m2 Test...");
    int16_t output0, output1;
    asm volatile (
        "vsetvli t2, %2, e8, m1\n\t"
        "vmv.v.i v2, -16\n\t"
        "vmv.v.i v3, -16\n\t"
        "vmv.v.i v4, 14\n\t"
        "vmv.v.i v5, 14\n\t"
        "vsetvli t2, %2, e8, m2\n\t"
        "vwmul.vv v8, v2, v4\n\t"
        "vsetvli t2, %2, e16\n\t"
        "vmv.x.s %0, v8\n\t"
        "vmv.x.s %1, v9"
        : "=r" (output0), "=r" (output1)
        : "r" (vlen)
    );


    if(output0 !=  -224 || output1 !=  -224)
    {
       printf("Test Complete! FAIL Output: v4: %d\tv5: %d\n", output0, output1);
       return(1);
    }
    else
    {
        printf("Test Complete! PASS Output: v4: %d\tv5: %d\n", output0, output1);
       return(0);
    }

}

int vwmul_vv_test_e8_m4(uint8_t vlen)
{
    printf("Starting wmulv e8 m4 Test...");
    int16_t output0, output1, output2, output3;
    asm volatile (
        "vsetvli t2, %4, e8, m1\n\t"
        "vmv.v.i v4, -16\n\t"
        "vmv.v.i v5, -16\n\t"
        "vmv.v.i v6, -16\n\t"
        "vmv.v.i v7, -16\n\t"
        "vmv.v.i v8, 14\n\t"
        "vmv.v.i v9, 14\n\t"
        "vmv.v.i v10, 14\n\t"
        "vmv.v.i v11, 14\n\t"
        "vsetvli t2, %4, e8, m4\n\t"
        "vwmul.vv v16, v8, v4\n\t"
        "vsetvli t2, %4, e16\n\t"
        "vmv.x.s %0, v16\n\t"
        "vmv.x.s %1, v17\n\t"
        "vmv.x.s %2, v18\n\t"
        "vmv.x.s %3, v19\n\t"
        : "=r" (output0), "=r" (output1), "=r" (output2), "=r" (output3)
        : "r" (vlen)
    );

    printf("Test Complete! Output: v8: %d\tv9: %d\tv10: %d\tv11: %d\n", output0, output1, output2, output3);
    if(output0 != -224 || output1 != -224 || output2 != -224 || output3 != -224)
    {
       printf("FAIL\n");
       return(1);
    }
    else
    {
       printf("PASS\n");
       return(0);
    }
}

int vwmul_vx_test_e8_m1(uint8_t vlen)
{
    printf("Starting wmul e8 m1 Test...");
    int16_t output;
    asm volatile (
        "li t1,-16\n\t"
        "vsetvli t2, %1, e8, m1\n\t"
        "vmv.v.i v1, 10\n\t"
        "vwmul.vx v2, v1, t1\n\t"
        "vsetvli t0, %1, e16,m1\n\t"
        "vmv.x.s %0, v2"
        : "=r" (output)
        : "r" (vlen)
    );

    printf("Test Complete! Output: %d\n", output);
    if(output != -160)
    {
       printf("FAIL\n");
       return(1);
    }
    else
    {
       printf("PASS\n");
       return(0);
    }

}

int vwmul_vx_test_e8_m2(uint8_t vlen)
{
    printf("Starting wmul e8 m2 Test...");
    int16_t output0, output1;
    asm volatile (
        "li t1,-16\n\t"
        "vsetvli t2, %1, e8, m1\n\t"
        "vmv.v.i v2, 10\n\t"
        "vmv.v.i v3, 10\n\t"
        "vsetvli t2, %2, e8, m2\n\t"
        "vwmul.vx v4, v2, t1\n\t"
        "vsetvli t2, %2, e16\n\t"
        "vmv.x.s %0, v4\n\t"
        "vmv.x.s %1, v5"
        : "=r" (output0), "=r" (output1)
        : "r" (vlen)
    );


    if(output0 != -160 || output1 != -160)
    {
       printf("Test Complete! FAIL Output: v4: %d\tv5: %d\n", output0, output1);
       return(1);
    }
    else
    {
        printf("Test Complete! PASS Output: v4: %d\tv5: %d\n", output0, output1);
       return(0);
    }

}

int vwmul_vx_test_e8_m4(uint8_t vlen)
{
    printf("Starting wmul e8 m4 Test...");
    int16_t output0, output1, output2, output3;
    uint8_t len;
    asm volatile (
        "li t1,-16\n\t"
        "vsetvli t2, %4, e8, m1\n\t"
        "vmv.v.i v4, 10\n\t"
        "vmv.v.i v5, 10\n\t"
        "vmv.v.i v6, 10\n\t"
        "vmv.v.i v7, 10\n\t"
        "vsetvli  t2, %4, e8, m4\n\t"
        "vwmul.vx v8, v4, t1\n\t"
        "vsetvli t2, %4, e16\n\t"
        "vmv.x.s %0, v8\n\t"
        "vmv.x.s %1, v9\n\t"
        "vmv.x.s %2, v10\n\t"
        "vmv.x.s %3, v11\n\t"
        : "=r" (output0), "=r" (output1), "=r" (output2), "=r" (output3), "=r" (len)
        : "r" (vlen)
    );


    if(output0 != -160 || output1 != -160 || output2 != -160 || output3 != -160)
    {
        printf("FAIL\n");
        printf("Test Complete! Output: v12: %d\tv13: %d\tv14: %d\tv15: %d\n", output0, output1, output2, output3);
        return(1);
    }
    else
    {
        printf("PASS\n");
        printf("Test Complete! Output: v12: %d\tv13: %d\tv14: %d\tv15: %d\n", output0, output1, output2, output3);
        return(0);
    }
}




int vmul_vv_test_e16_m1(uint8_t vlen)
{
    printf("Starting smul e16 m1 Test...");
    int16_t output;
    asm volatile (
        "vsetvli t2, %1, e16, m1\n\t"
        "vmv.v.i v1, -5\n\t"
        "vmv.v.i v2, 5\n\t"
        "vmul.vv v3, v1, v2\n\t"
        "vmv.x.s %0, v3"
        : "=r" (output)
        : "r" (vlen)
    );

    printf("Test Complete! Output: %d\n", output);
    if(output != -25)
    {
       printf("FAIL\n");
       return(1);
    }
    else
    {
       printf("PASS\n");
       return(0);
    }

}

int vmul_vv_test_e16_m2(uint8_t vlen)
{
    printf("Starting smul e16 m2 Test...");
    int16_t output0, output1;
    asm volatile (
        "vsetvli t2, %2, e16, m1\n\t"
        "vmv.v.i v2, -5\n\t"
        "vmv.v.i v3, -5\n\t"
        "vmv.v.i v4, 5\n\t"
        "vmv.v.i v5, 5\n\t"
        "vsetvli t2, %2, e16, m2\n\t"
        "vmul.vv v6, v2, v4\n\t"
        "vsetvli t2, %2, e16\n\t"
        "vmv.x.s %0, v6\n\t"
        "vmv.x.s %1, v7"
        : "=r" (output0), "=r" (output1)
        : "r" (vlen)
    );

    printf("Test Complete! Output: v4: %d\tv5: %d\n", output0, output1);
    if(output0 != -25 || output1 != -25)
    {
       printf("FAIL\n");
       return(1);
    }
    else
    {
       printf("PASS\n");
       return(0);
    }

}

int vmul_vv_test_e16_m4(uint8_t vlen)
{
    printf("Starting smul e16 m4 Test...");
    int16_t output0, output1, output2, output3;
    asm volatile (
        "vsetvli t2, %4, e16, m1\n\t"
        "vmv.v.i v4, -5\n\t"
        "vmv.v.i v5, -5\n\t"
        "vmv.v.i v6, -5\n\t"
        "vmv.v.i v7, -5\n\t"
        "vmv.v.i v8, 5\n\t"
        "vmv.v.i v9, 5\n\t"
        "vmv.v.i v10, 5\n\t"
        "vmv.v.i v11, 5\n\t"
        "vsetvli t2, %4, e16, m4\n\t"
        "vmul.vv v12, v4, v8\n\t"
        "vsetvli t2, %4, e16\n\t"
        "vmv.x.s %0, v12\n\t"
        "vmv.x.s %1, v13\n\t"
        "vmv.x.s %2, v14\n\t"
        "vmv.x.s %3, v15\n\t"
        : "=r" (output0), "=r" (output1), "=r" (output2), "=r" (output3)
        : "r" (vlen)
    );

    printf("Test Complete! Output: v8: %d\tv9: %d\tv10: %d\tv11: %d\n", output0, output1, output2, output3);
    if(output0 != -25 || output1 != -25 || output2 != -25 || output3 != -25)
    {
       printf("FAIL\n");
       return(1);
    }
    else
    {
       printf("PASS\n");
       return(0);
    }
}



int vwmul_vv_test_e16_m1(uint8_t vlen)
{
    printf("Starting wmulv e16 m1 Test...");
    int32_t output;
    asm volatile (
        "vsetvli t2, %1, e16, m1\n\t"
        "vmv.v.i v1, -16\n\t"
        "vmv.v.i v2, 14\n\t"
        "vsetvli t2, %1, e16, m1\n\t"
        "vwmul.vv v4, v1, v2\n\t"
        "vsetvli t2, %1, e32\n\t"
        "vmv.x.s %0, v4"
        : "=r" (output)
        : "r" (vlen)
    );

    printf("Test Complete! Output: %ld\n", output);
    if(output !=  -224)
    {
       printf("FAIL\n");
       return(1);
    }
    else
    {
       printf("PASS\n");
       return(0);
    }

}

int vwmul_vv_test_e16_m2(uint8_t vlen)
{
    printf("Starting wmulv e16 m2 Test...");
    int32_t output0, output1;
    asm volatile (
        "vsetvli t2, %2, e16, m1\n\t"
        "vmv.v.i v2, -16\n\t"
        "vmv.v.i v3, -16\n\t"
        "vmv.v.i v4, 14\n\t"
        "vmv.v.i v5, 14\n\t"
        "vsetvli t2, %2, e16, m2\n\t"
        "vwmul.vv v8, v2, v4\n\t"
        "vsetvli t2, %2, e32\n\t"
        "vmv.x.s %0, v8\n\t"
        "vmv.x.s %1, v9"
        : "=r" (output0), "=r" (output1)
        : "r" (vlen)
    );

    printf("Test Complete! Output: v4: %ld\tv5: %ld\n", output0, output1);
    if(output0 !=  -224|| output1 !=  -224)
    {
       printf("FAIL\n");
       return(1);
    }
    else
    {
       printf("PASS\n");
       return(0);
    }

}

int vwmul_vv_test_e16_m4(uint8_t vlen)
{
    printf("Starting wmulv e16 m4 Test...");
    int32_t output0, output1, output2, output3;
    asm volatile (
        "vsetvli t2, %4, e16, m1\n\t"
        "vmv.v.i v4, -16\n\t"
        "vmv.v.i v5, -16\n\t"
        "vmv.v.i v6, -16\n\t"
        "vmv.v.i v7, -16\n\t"
        "vmv.v.i v8, 14\n\t"
        "vmv.v.i v9, 14\n\t"
        "vmv.v.i v10, 14\n\t"
        "vmv.v.i v11, 14\n\t"
        "vsetvli t2, %4, e16, m4\n\t"
        "vwmul.vv v16, v4, v8\n\t"
        "vmv.x.s %0, v16\n\t"
        "vmv.x.s %1, v17\n\t"
        "vmv.x.s %2, v18\n\t"
        "vmv.x.s %3, v19\n\t"
        : "=r" (output0), "=r" (output1), "=r" (output2), "=r" (output3)
        : "r" (vlen)
    );

    printf("Test Complete! Output: v8: %ld\tv9: %ld\tv10: %ld\tv11: %ld\n", output0, output1, output2, output3);
    if(output0 !=  -224 || output1 !=  -224 || output2 !=  -224 || output3 != -224)
    {
       printf("FAIL\n");
       return(1);
    }
    else
    {
       printf("PASS\n");
       return(0);
    }
}



int vwmul_vx_test_e16_m1(uint8_t vlen)
{
    printf("Starting wmul e16 m1 Test...");
    int32_t output;
    asm volatile (
        "li t1,-16\n\t"
        "vsetvli t2, %1, e16, m1\n\t"
        "vmv.v.i v1, 10\n\t"
        "vwmul.vx v2, v1, t1\n\t"
        "vsetvli t2, %1, e32\n\t"
        "vmv.x.s %0, v2"
        : "=r" (output)
        : "r" (vlen)
    );

    printf("Test Complete! Output: %ld\n", output);
    if(output != -160)
    {
       printf("FAIL\n");
       return(1);
    }
    else
    {
       printf("PASS\n");
       return(0);
    }

}

int vwmul_vx_test_e16_m2(uint8_t vlen)
{
    printf("Starting wmul e16 m2 Test...");
    int32_t output0, output1;
    asm volatile (
        "li t1,-16\n\t"
        "vsetvli t2, %2, e16\n\t"
        "vmv.v.i v2, 10\n\t"
        "vmv.v.i v3, 10\n\t"
        "vsetvli t2, %2, e16, m2\n\t"
        "vwmul.vx v4, v2, t1\n\t"
        "vsetvli t2, %2, e32\n\t"
        "vmv.x.s %0, v4\n\t"
        "vmv.x.s %1, v5"
        : "=r" (output0), "=r" (output1)
        : "r" (vlen)
    );

    printf("Test Complete! Output: v4: %ld\tv5: %ld\n", output0, output1);
    if(output0 != -160 || output1 != -160)
    {
       printf("FAIL\n");
       return(1);
    }
    else
    {
       printf("PASS\n");
       return(0);
    }

}

int vwmul_vx_test_e16_m4(uint8_t vlen)
{
    printf("Starting wmul e16 m4 Test...");
    int32_t output0, output1, output2, output3;
    uint8_t len;
    asm volatile (
        "li t1,-16\n\t"
        "vsetvli t2, %4, e16, m1\n\t"
        "vmv.v.i v4, 10\n\t"
        "vmv.v.i v5, 10\n\t"
        "vmv.v.i v6, 10\n\t"
        "vmv.v.i v7, 10\n\t"
        "vsetvli  %4, %4, e16, m4\n\t"
        "vwmul.vx v8, v4, t1\n\t"
        "vsetvli t2, %4, e32\n\t"
        "vmv.x.s %0, v8\n\t"
        "vmv.x.s %1, v9\n\t"
        "vmv.x.s %2, v10\n\t"
        "vmv.x.s %3, v11\n\t"
        : "=r" (output0), "=r" (output1), "=r" (output2), "=r" (output3), "=r" (len)
        : "r" (vlen)
    );


    if(output0 != -160 || output1 !=  -160  || output2 !=  -160  || output3 !=  -160 )
    {
        printf("FAIL\n");
        printf("Test Complete! Output: v12: %ld\tv13: %ld\tv14: %ld\tv15: %ld\n", output0, output1, output2, output3);
        return(1);
    }
    else
    {
        printf("PASS\n");
        printf("Test Complete! Output: v12: %ld\tv13: %ld\tv14: %ld\tv15: %ld\n", output0, output1, output2, output3);
        return(0);
    }
}


int vmul_vv_test_e32_m1(uint8_t vlen)
{
    printf("Starting smul e32 m1 Test...");
    int32_t output;
    asm volatile (
        "vsetvli t2, %1, e32, m1\n\t"
        "vmv.v.i v1, -5\n\t"
        "vmv.v.i v2, 5\n\t"
        "vmul.vv v3, v1, v2\n\t"
        "vmv.x.s %0, v3"
        : "=r" (output)
        : "r" (vlen)
    );

    printf("Test Complete! Output: %ld\n", output);
    if(output != -25)
    {
       printf("FAIL\n");
       return(1);
    }
    else
    {
       printf("PASS\n");
       return(0);
    }

}

int vmul_vv_test_e32_m2(uint8_t vlen)
{
    printf("Starting smul e32 m2 Test...");
    int32_t output0, output1;
    asm volatile (

        "vsetvli t2, %2, e32, m1\n\t"
        "vmv.v.i v2, -5\n\t"
        "vmv.v.i v3, -5\n\t"
        "vmv.v.i v4, 5\n\t"
        "vmv.v.i v5, 5\n\t"
        "vsetvli t2, %2, e32, m2\n\t"
        "vmul.vv v6, v2, v4\n\t"
        "vsetvli t2, %2, e32\n\t"
        "vmv.x.s %0, v6\n\t"
        "vmv.x.s %1, v7"
        : "=r" (output0), "=r" (output1)
        : "r" (vlen)
    );

    printf("Test Complete! Output: v4: %ld\tv5: %ld\n", output0, output1);
    if(output0 != -25 || output1 != -25)
    {
       printf("FAIL\n");
       return(1);
    }
    else
    {
       printf("PASS\n");
       return(0);
    }

}

int vmul_vv_test_e32_m4(uint8_t vlen)
{
    printf("Starting smul e32 m4 Test...");
    int32_t output0, output1, output2, output3;
    asm volatile (
        "vsetvli t2, %4, e32\n\t"
        "vmv.v.i v4, -5\n\t"
        "vmv.v.i v5, -5\n\t"
        "vmv.v.i v6, -5\n\t"
        "vmv.v.i v7, -5\n\t"
        "vmv.v.i v8, 5\n\t"
        "vmv.v.i v9, 5\n\t"
        "vmv.v.i v10, 5\n\t"
        "vmv.v.i v11, 5\n\t"
        "vsetvli t2, %4, e32, m4\n\t"
        "vmul.vv v16, v4, v8\n\t"
        "vsetvli t2, %4, e32\n\t"
        "vmv.x.s %0, v16\n\t"
        "vmv.x.s %1, v17\n\t"
        "vmv.x.s %2, v18\n\t"
        "vmv.x.s %3, v19\n\t"
        : "=r" (output0), "=r" (output1), "=r" (output2), "=r" (output3)
        : "r" (vlen)
    );

    printf("Test Complete! Output: v16: %ld\tv17: %ld\tv18: %ld\tv19: %ld\n", output0, output1, output2, output3);
    if(output0 != -25 || output1 != -25 || output2 != -25 || output3 != -25)
    {
       printf("FAIL\n");
       return(1);
    }
    else
    {
       printf("PASS\n");
       return(0);
    }

}



int main(int argc, char *argv[])
{
    printf("Beginning Vector Mul Test...\n\n");
    printf("This is performed for 8, 16, and 32 bit wide vector registers.\n");
    printf("This gives a total of 6 tests.\n\n");


    int errors = 0;

    errors += vmul_vv_test_e8_m1(64);
    errors += vmul_vv_test_e8_m2(64);
    errors += vmul_vv_test_e8_m4(64);
    printf("\n");
    errors += vwmul_vv_test_e8_m1(64);
    errors += vwmul_vv_test_e8_m2(64);
    errors += vwmul_vv_test_e8_m4(64);
    printf("\n\n");
    errors += vwmul_vx_test_e8_m1(64);
    errors += vwmul_vx_test_e8_m2(64);
    errors += vwmul_vx_test_e8_m4(64);
    printf("\n");
    errors += vmul_vv_test_e16_m1(64);
    errors += vmul_vv_test_e16_m2(64);
    errors += vmul_vv_test_e16_m4(64);
    printf("\n");
    errors += vwmul_vv_test_e16_m1(64);
    errors += vwmul_vv_test_e16_m2(64);
    errors += vwmul_vv_test_e16_m4(64);
    printf("\n");
    errors += vwmul_vx_test_e16_m1(64);
    errors += vwmul_vx_test_e16_m2(64);
    errors += vwmul_vx_test_e16_m4(64);
    printf("\n\n");
    errors += vmul_vv_test_e32_m1(64);
    errors += vmul_vv_test_e32_m2(64);
    errors += vmul_vv_test_e32_m4(64);




    if(errors > 0)
    {
        printf("\nErrors Detected!\nError Count: %d\n", errors);
        return(EXIT_FAILURE);
    }

    printf("\nAll Tests Completed\nNo Errors Detected!\n");

    return(EXIT_SUCCESS);
}

