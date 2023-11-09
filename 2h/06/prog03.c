#include <math.h>
#include <stdio.h>

int main(void) {
  int x1 = 100;
  int y1 = 10;
  int x2 = 200;
  int y2 = 50;

  double distance = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
  printf("Distance: %f\n", distance);

  return 0;
}