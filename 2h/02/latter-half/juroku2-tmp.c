#include <stdio.h>

unsigned long int print16(unsigned long int *x) {
  unsigned long int n = *x % 16;
  if (*x >= 16) n = print16(&n);

  printf("> %lu\n", n);
  switch (n) {
    case 0:
      break;
    case 10:
      printf("A");
      break;
    case 11:
      printf("B");
      break;
    case 12:
      printf("C");
      break;
    case 13:
      printf("D");
      break;
    case 14:
      printf("E");
      break;
    case 15:
      printf("F");
      break;
    default:
      printf("%lu", *x);
  }
  
  return *x - n;
}

int main(void) {
  unsigned long int n;

  scanf("%ld", &n);
  print16(&n);
  printf("\n");

  return 0;
}