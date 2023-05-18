#include <stdio.h>

int main(void) {
  int a, b;

  printf("a? ");
  scanf("%d", &a);
  printf("b? ");
  scanf("%d", &b);

  if (a > 0) {
    if (b == 0)
      printf("A\n");
    else if (b > 0)
      printf("B\n");
    else if (b < 0)
      printf("C\n");
  } else {
    printf("D\n");
  }

  return 0;
}
