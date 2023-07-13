#include <stdio.h>

int subOf(int, int);

int main(void) {
  // 宣言, 変数は必ず初期化を行う
  int a = 5;
  int b = 10;
  int res;

  res = subOf(a, b);
  printf("%d - %d = %d\n", a, b, res);
  return 0;
}

int subOf(int a, int b) { return a - b; }