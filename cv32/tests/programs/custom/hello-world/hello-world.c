#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint8_t vect_vsetvli(uint8_t avl) {
  uint8_t vlen_o; 

  asm volatile (
    "vsetvli %0, %1, e32, m4\n\t"
    : "=r" (vlen_o) : "r" (avl)
  );

  return vlen_o;
}

void vect_loadVector32(int N, int8_t* ptr, uint32_t stride) {
    asm volatile (  
      "vsetvli t0, a0, e8, m2\n\t"
      "vlse.v v4, (%2), %0\n\t"
      "vlse.v v8, (%1), %0\n\t"
      "vadd.vv v12, v4, v8\n\t"
      //"vsrl.vi v8, v4, 1\n\t"
      :: "r" (stride), "r" (ptr), "r" (ptr+1)
    );
}

void vstore_test(int32_t* ptr) {
    __asm__ (
      "vse.v v7, (a1)"
    );
}

int main(int argc, char *argv[])
{
  printf("\nRunning Test\n");
  // Test vector instruction

  int8_t a[16] = {123, 32, 16, 23,
                   78, 32, 12, 24, 
                   64, 35, 74,  3, 
                    9,  3,  1,  5};

  //vect_vsetvli(4);
  vect_loadVector32(8, a, 2);

  printf("\nTest Complete\n");
  return EXIT_SUCCESS;
}
