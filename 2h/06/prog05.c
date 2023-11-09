#include <stdio.h>
#define MAX 256

int main(void) {
  char line[MAX];
  FILE* fp = fopen("meibo.txt", "r");

  while (fgets(line, MAX, fp) != NULL) {
    printf("%s", line);
  }
}