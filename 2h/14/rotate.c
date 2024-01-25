#include <stdio.h>

unsigned rrotate(unsigned x, int n) {
  int w = sizeof(int) << 3;
  return (x >> n) | (x << (w - n));
}

unsigned lrotate(unsigned x, int n) {
  int w = sizeof(int) << 3;
  return (x << n) | (x >> (w - n));
}

void printbin(unsigned int x) {
  if (x < 1) return;
  printbin(x >> 1);
  printf("%d", x&1);
}

int main(void) {
  unsigned x;

  scanf("%u", &x);
  printbin(x);
  printf("\n");
  printbin(rrotate(x, 1));
  printf("\n");
  printbin(lrotate(x, 1));

  return 0;
}