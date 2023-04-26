#include <stdio.h>

int main(int argc, const char* argv[]) {
  int a, b;

  printf("a b? ");
  scanf("%d %d", &a, &b);
  printf("perimeter = %d", a * 2 + b * 2);
  printf("area = %d", a * b);

  return 0;
}
