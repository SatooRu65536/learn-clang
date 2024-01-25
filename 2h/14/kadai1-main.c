#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void yomiage(long long n, int keta);
void printThousands(long long x);
void printKeta(long long n);
void printKansuji(long long n);

int main() {
  char ss[256];
  long long n;

  printf("Number ? ");
  fgets(ss, sizeof(ss), stdin);

  n = atoll(ss);

  if (n < 0) {
    printf("負の数なので絶対値に変換します\n");
    n *= -1;
  }

  printf("%lld = ", n);

  if (n > 9999999999999999)
    printf("読めません\n");
  else if (n == 0)
    printf("零");
  else
    yomiage(n, 5);

  printf("\n");

  return 0;
}

void yomiage(long long n, int keta) {
  if (n > 10000) {
    yomiage(n / 10000, keta + 4);
    printKeta(keta);
  }

  printThousands(n % 10000);
}

void printThousands(long long x) {
  for (int keta = 4; keta > 0; keta--) {
    int n = pow(10, keta - 1);
    printKansuji(x / n);
    if (x / n != 0) printKeta(keta);
    x %= n;
  }
}

void printKeta(long long keta) {
  switch (keta) {
    case 2:
      printf("十");
      break;
    case 3:
      printf("百");
      break;
    case 4:
      printf("千");
      break;
    case 5:
      printf("万");
      break;
    case 9:
      printf("億");
      break;
  }
}

void printKansuji(long long n) {
  switch (n) {
    case 1:
      printf("一");
      break;
    case 2:
      printf("二");
      break;
    case 3:
      printf("三");
      break;
    case 4:
      printf("四");
      break;
    case 5:
      printf("五");
      break;
    case 6:
      printf("六");
      break;
    case 7:
      printf("七");
      break;
    case 8:
      printf("八");
      break;
    case 9:
      printf("九");
      break;
  }
}
