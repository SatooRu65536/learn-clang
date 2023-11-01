#include <stdio.h>

void swap(int *pa, int *pb) {
  int temp = *pa;
  *pa = *pb;
  *pb = temp;
}

void sort(int *pa, int *pb) {
  if (*pa > *pb) swap(pa, pb);
}

void bubble(int *arr, int num) {
  for (int i = num - 1; i > 0; i--) {
    for (int j = 0; j < i; j++) {
      sort(arr + j, arr + j + 1);
    }
  }
}

int main(void) {
  int array[] = {10, 5, 4, 20, 31, 12};
  const int num = sizeof array / sizeof(int);
  bubble(array, num);

  for (int i = 0; i < num; i++) {
    printf("%d\n", array[i]);
  }

  return 0;
}