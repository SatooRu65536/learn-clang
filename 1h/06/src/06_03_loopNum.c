#include <stdio.h>

int main(void) {
  int i, n;

  printf("n? ");
  scanf("%d", &n);

  for (i = 0; i < n; i++) printf("Hello, World!\n");

  return 0;
}
