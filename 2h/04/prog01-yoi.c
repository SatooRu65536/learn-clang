#include <stdio.h>

void swap(int *pa, int *pb) {
  int temp = *pa;
  *pa = *pb;
  *pb = temp;
  printf("SWAP:%d,%d\n", *pa, *pb);
}

int main(void) {
  int a = 10;
  int b = 20;

  printf("MAIN:%d,%d\n", a, b);
  swap(&a, &b);
  printf("MAIN:%d,%d\n", a, b);

  return 0;
}