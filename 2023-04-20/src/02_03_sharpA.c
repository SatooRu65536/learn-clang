#include <stdio.h>

int main(int argc, const char* argv[]) {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 9; j++) {
      if (j == 4 - i || 4 + i == j)
        printf("#");
      else if (i == 3 && j > 1 && j < 8)
        printf("#");
      else
        printf(" ");
    }
    printf("\n");
  }

  /*
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 9; j++) {
      // Aの左右の空白をかく
      if (j < 4 - i || 4 + i < j) printf(" ");

      // Aの中の空白をかく
      else if (j > 4 - i && j < 4 + i && i != 3)
        printf(" ");

      else
        printf("#");
    }
    printf("\n");
  }
  */

  return 0;
}
