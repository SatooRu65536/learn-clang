#include <stdio.h>
#define LOOP_NUM 100
#define FOO_RATIO 2
#define BAR_RATIO 3

int main(void) {
  for (int i = 1; i <= LOOP_NUM; i++) {
    printf("hoge");

    if (i % FOO_RATIO == 0) printf("foo");
    if (i % BAR_RATIO == 0) printf("bar");
    printf("\n");
  }

  return 0;
}