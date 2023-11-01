#include <stdio.h>

void times10(int *p, int num) {
  for (int i = 0; i < num; i++) {
    *(p + i) *= 10;
  }
}

int main(void) {
  int a[5] = {10, 20, 30, 40, 50};
  int b[4] = {3, 4, 5, 6};

  const int numA = sizeof a / sizeof(int);
  const int numB = sizeof b / sizeof(int);

  times10(a, numA);
  times10(b, numB);

  for (int i = 0; i < numA; i++) printf("%d\n", a[i]);
  for (int i = 0; i < numB; i++) printf("%d\n", b[i]);

  return 0;
}