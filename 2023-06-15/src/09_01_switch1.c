#include <stdio.h>

int main(void) {
  int n;

  printf("n? ");
  scanf("%d", &n);

  switch (n) {
    case 1:
      printf("AAA\n");
      break;

    case 2:
      printf("BBB\n");
      break;

    default:
      printf("Dеfaultです.\n");
      break;
  }

  return 0;
}