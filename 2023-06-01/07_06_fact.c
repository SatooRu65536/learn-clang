#include <stdio.h>

int main(int argc, const char* argv[]) {
  int x = 0;
  int n = 0;
  int tmp = 0;

  printf("x n? ");
  scanf("%d %d", &x, &n);

  tmp = x;
  for (int i = 1; i < n; i++) tmp *= x;

  printf("%d^%d = %d\n", x, n, tmp);

  return 0;
}
