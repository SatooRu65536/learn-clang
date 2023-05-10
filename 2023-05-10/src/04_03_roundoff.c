#include <stdio.h>

int main(int argc, const char* argv[]) {
  double dx;
  int nx;

  printf("dx? ");
  scanf("%lf", &dx);
  nx = dx;

  printf("dx/2 = %f\n", dx / 2);
  printf("nx = %d\n", nx);
  printf("nx/2 = %d\n", nx/2);

  return 0;
}
