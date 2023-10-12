#include <stdio.h>

void print16(unsigned int x);

int main(void) {
  unsigned int n;

  scanf("%d", &n);
  unsigned int n4 = n / 16 / 16 / 16 % 16;
  unsigned int n3 = n / 16 / 16 % 16;
  unsigned int n2 = n / 16 % 16;
  unsigned int n1 = n % 16;

  print16(n4);
  print16(n3);
  print16(n2);
  print16(n1);
  printf("\n");

  return 0;
}

void print16(unsigned int x) {
  switch (x) {
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
      printf("%d", x);
  }
}