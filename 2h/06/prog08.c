#include <stdio.h>

int main(void) {
  FILE* fp = fopen("prime.txt", "w");

  for (int i = 2; i <= 100; i++) {
    for (int j = 2; j <= i; j++) {
      if (j == i) fprintf(fp, "%d\n", i);
      else if (i % j == 0) break;
    }
  }
}