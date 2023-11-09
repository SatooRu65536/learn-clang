#include <stdio.h>
#include <string.h>
#include <time.h>

void swap_str_ptr(char **a, char **b) {
  char *tmp = *a;
  *a = *b;
  *b = tmp;
}

void sort_str_ptr(char **a, char **b) {
  if (strlen(*a) > strlen(*b)) {
    swap_str_ptr(a, b);
  }
}

void bubble_str_ptr(char **list, int n) {
  for (int i = n - 1; i > 0; i--) {
    for (int j = 0; j < i; j++) {
      sort_str_ptr(&list[j], &list[j + 1]);
    }
  }
}

int main(void) {
  char *list[] = {"fugagaga",
                  "hoge",
                  "abc",
                  "xy",
                  "a",
                  "satooru",
                  "tanakakakuei",
                  "ebifurai",
                  "takoyaki",
                  "tukutukuboushi",
                  "karaage",
                  "javascriptgasuki",
                  "pythonhakataganai",
                  "castleniikitai",
                  "penguiniscute",
                  "c",
                  "usadapekora",
                  "tekitounamojiretsu",
                  "samuraiengineer",
                  "formatternokaigyougakiniiranai"};

  int n = sizeof(list) / sizeof(list[0]);

  printf("Before:\n");
  for (int i = 0; i < n; i++) {
    printf(" %s\n", list[i]);
  }

  bubble_str_ptr(list, n);

  printf("\n");
  printf("After:\n");
  for (int i = 0; i < n; i++) {
    printf(" %s\n", list[i]);
  }

  long cpu_time = clock();
  double sec = (double)cpu_time / CLOCKS_PER_SEC;

  printf("\n\x1b[32m");
  printf("CPU time (clock): %ld\n", cpu_time);
  printf("CPU time (sec): %fs\n", sec);

  return 0;
}