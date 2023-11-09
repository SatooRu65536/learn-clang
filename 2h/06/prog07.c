#include <stdio.h>

int main(void) {
  FILE* fp = fopen("number.txt", "a");

  for (int i = 0; i < 100; i++) {
    fprintf(fp, "%d\n", 100 + i);
  }
}