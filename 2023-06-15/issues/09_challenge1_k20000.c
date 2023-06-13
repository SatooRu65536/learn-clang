#include <stdio.h>

int main(void) {
  char ch = ' ';
  int isPlus = 1;
  int sum = 0;
  int n;

  printf("equation? ");
  while (ch != '=') {
    ch = getchar();

    switch (ch) {
      case ' ':
      case '=':
      case '\n':
      case '\t':
        break;

      case '+':
        isPlus = 1;
        break;

      case '-':
        isPlus = 0;
        break;

      default:
        n = (int)ch - 48;
        sum += isPlus ? n : -n;

        break;
    }
  }
  printf("answer: %d\n", sum);

  return 0;
}
