#include <stdio.h>

int main(int argc, const char* argv[]) {
  int total, legs;
  int crane, tortoise;

  printf("total? ");
  scanf("%d", &total);
  printf("legs? ");
  scanf("%d", &legs);

  tortoise = (legs / 2) - total;
  crane = total - tortoise;

  if ((total == tortoise + crane) && (legs == 2 * crane + 4 * tortoise)) {
    printf("crane = %d, tortoise = %d\n", crane, tortoise);
  } else {
    printf("cannot be combined\n");
  }

  return 0;
}
