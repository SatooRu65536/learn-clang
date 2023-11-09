#include <math.h>
#include <stdio.h>

double area(int r) { return M_PI * r * r; }

double circumference(int r) { return 2 * M_PI * r; }

int main(void) {
  int r = 10;

  printf("Area: %f\n", area(r));
  printf("Circumference: %f\n", circumference(r));

  return 0;
}