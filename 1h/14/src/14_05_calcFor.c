#include <stdio.h>

int main(void) {
  int n;

  printf("n? ");
  scanf("%d", &n);

  int sum = 0;
  for (int i = 1; i <= n; i++) sum += i;
  printf("1から%dまでの和は %d\n", n, sum);

  return 0;
}