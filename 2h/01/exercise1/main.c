#include <math.h>
#include <stdio.h>

double getCircumference(int r) { return 2 * M_PI * r; }

double getArea(int r) { return r * r * M_PI; }

int main(void) {
  int r;

  printf("半径: ");
  scanf("%d", &r);

  printf("円周: %f\n", getCircumference(r));
  printf("面積: %f\n", getArea(r));

  return 0;
}