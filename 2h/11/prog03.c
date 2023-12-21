#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  int n = 10;

  int prev_x = 1;
  int x = 1;

  for (int k = 0; k < 10; k++) {
    printf("%d\n", prev_x);
    int tmp = x;
    x += prev_x;
    prev_x = tmp;
  }

  return 0;
}