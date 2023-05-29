#include <stdio.h>
#define SWAP(a, b) (a += b, b = a - b, a -= b)

int main(void) {
  int x = 0;
  int y = 0;
  int z = 0;

  printf("x y z? ");
  scanf("%d %d %d", &x, &y, &z);

  if (x > y) SWAP(x, y);
  if (x > z) SWAP(x, z);
  if (y > z) SWAP(y, z);

  printf("%d %d %d\n", x, y, z);
  return 0;
}
