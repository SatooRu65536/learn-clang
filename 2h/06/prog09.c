#include <stdio.h>
#define MAX 256

int main(void) {
  FILE* fp = fopen("meibo.txt", "a");

  for (int i = 0; i < 100; i++) {
    char name[MAX];
    scanf("%s", name);
    if (name[0] == '!') break;
    fprintf(fp, "%s\n", name);
  }
}