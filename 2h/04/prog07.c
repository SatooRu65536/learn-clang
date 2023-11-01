#include <stdio.h>

void times10(int *p, int length) {
  for (int i = 0; i < length; i++) {
    *(p + i) *= 10;
  }
}

int main(void) {
  int a[5] = {10, 20, 30, 40, 50};
  int b[4] = {3, 4, 5, 6};

  times10(a, 5);
  times10(b, 4);

  for (int i = 0; i < 5; i++) {
    printf("%d\n", a[i]);
  }
  for (int i = 0; i < 4; i++) {
    printf("%d\n", a[i]);
  }

  return 0;
}