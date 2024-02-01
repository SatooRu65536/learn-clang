#include <stdio.h>
#define MAX 256

int main(void) {
  char line[MAX];
  FILE* fp = fopen("titanic.csv", "r");

  if (fp == NULL) {
    printf("File not found.\n");
    return 1;
  }

  while (fgets(line, MAX, fp) != NULL) {
    printf("%s", line);
  }

  fclose(fp);

  return 0;
}