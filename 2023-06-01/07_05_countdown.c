#include <stdio.h>

int main(void) {
  int n = 0;

  printf("n? ");
  scanf("%d", &n);

  for (int i = 0; i < n; i++) printf("%d\n", n - i);

  return 0;
}
