#include <stdio.h>

int main(int argc, const char* argv[]) {
  int a = 6;
  int b = 4;
  int c = 2;

  printf("%d - (%d / %d) = %d\n", a, b, c, a - (b / c));

  return 0;
}
