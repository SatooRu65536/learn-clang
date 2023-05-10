#include <stdio.h>

int main(int argc, const char* argv[]) {
  int height, weight;
  double standardWeight, bmi;

  printf("height? ");
  scanf("%d", &height);

  printf("weight? ");
  scanf("%d", &weight);

  standardWeight = (height - 100) * 0.9;
  bmi = weight / (height * 0.01 * height * 0.01);

  printf("standardWeight = %f\n", standardWeight);
  printf("BMI = %f\n", bmi);

  return 0;
}
