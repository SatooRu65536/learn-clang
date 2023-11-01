#include <stdio.h>

int main(void) {
  int x = 100;
  int y = 200;

  printf("x,y %d,%d\n", x, y);

  int *px = &x;
  int *py = &y;

  *px = 15;
  *py = 25;

  printf("x,y %d,%d\n", x, y);

  return 0;
}