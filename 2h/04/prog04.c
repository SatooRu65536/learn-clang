#include <stdio.h>

int main(void) {
  int arr[5] = {1, 2, 3, 4, 5};
  int *pa = arr;

  printf("%p\n", pa);

  for (int i = 1; i < 5; i++) {
    printf("%p\n", pa + i);
  }

  return 0;
}