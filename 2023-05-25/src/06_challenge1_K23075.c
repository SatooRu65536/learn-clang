#include <stdio.h>

int isPrimeNumber(int n) {
  if (n <= 1 || n % 2 == 0) return 0;

  for (int i = 3; i <= n / 2; i += 2) {
    if (n % i == 0) return 0;
  }

  return 1;
}

int main(void) {
  int n;

  printf("n? ");
  scanf("%d", &n);

  if (isPrimeNumber(n))
    printf("素数です\n");
  else
    printf("素数ではありません\n");

  return 0;
}
