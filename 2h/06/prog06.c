#include <stdio.h>
#define MAX 256
int main(void) {
  FILE* fp = fopen("number.txt", "w");

  if (fp == NULL) {
    printf("File not found.\n");
    return 1;
  }

  for (int i = 0; i < 100; i++) {
    fprintf(fp, "%d\n", i);
  }

  fclose(fp);

  return 0;
}