#include <stdio.h>

int main(void) {
  int x = 0;
  int y = 0;

  printf("x y? ");
  scanf("%d %d", &x, &y);
  if (x < y) {
    printf("%d %d\n", x, y);
  } else {
    x += y;
    y = x - y;
    x -= y;
    printf("%d %d\n", x, y);
  }

  return 0;
}
