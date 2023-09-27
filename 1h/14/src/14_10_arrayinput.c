#include <stdio.h>

int main(void) {
  int height[5];
  double average;

  for (int i = 0; i < 5; i++) {
    printf("%d人目の身長? ", i + 1);
    scanf("%d", &height[i]);
  }

  average = (height[0] + height[1] + height[2]) / 3.0;
  printf("平均身長 = %f\n", average);

  return 0;
}