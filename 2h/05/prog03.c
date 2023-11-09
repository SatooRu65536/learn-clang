#include <stdio.h>

int main(void) {
  int i ;
  char a[][5] = {"LISP", "C", "Ada"};
  char *p[] = {"PAUL", "X", "MAC"};

  int l_a = sizeof(a) / sizeof(a[0]);
  printf("l_a = %d\n", l_a);
  for (i = 0; i < l_a; i++) {
    printf("a[%d] = \"%s\"\n", i, a[i]);
  }

  int l_p = sizeof(p) / sizeof(p[0]);
  for (i = 0; i < l_p; i++) {
    printf("p[%d] = \"%s\"\n", i, p[i]);
  }

  return 0;
}