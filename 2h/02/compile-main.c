#include <stdio.h>

extern int sub(int);

int b;

int main() {
  b = 10;
  printf("%d\n", sub(5));
}