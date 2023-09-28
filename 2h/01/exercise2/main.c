#include <math.h>
#include <stdio.h>

#define INTERVAL_DEG 10

int main(void) {
  int deg = 0;

  do {
    double rad = deg * M_PI / 180;
    printf("%d, %f\n", deg, sin(rad));

    deg += INTERVAL_DEG;
  } while (deg <= 360);

  return 0;
}