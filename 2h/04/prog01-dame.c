#include <stdio.h>

void dameSwap(int a, int b) {
  int temp = a;
  a = b;
  b = temp;
  printf("DAMESWAP:%d,%d\n", a, b);
}

int main(void) {
  int a = 10;
  int b = 20;

  printf("MAIN:%d,%d\n", a, b);
  dameSwap(a, b);
  printf("MAIN:%d,%d\n", a, b);

  return 0;
}