#include <stdio.h>
#define MAX 256
int main(void) {
  FILE* fp = fopen("number.txt", "w");

  for (int i = 0; i < 100; i++) {
    fprintf(fp, "%d\n", i);
  }
}