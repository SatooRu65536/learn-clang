#include <stdio.h>

int main(void) {
  int x = 0;
  int i = 0;
  int max = 0;

  for (int i = 1; i <= 5; i++) {
    printf("%d? ", i);
    scanf("%d", &x);

    if (x > max) max = x;
  }

  printf("max = %d\n", max);
  return 0;
}
