#include <stdio.h>

typedef struct melem {
  char name[64];
  int height;
  int weight;
  struct melem *next;
} Melem;

void printMelem(Melem *root) {
  printf("%s %d %d\n", root->name, root->height, root->weight);
  if (root->next != NULL) printMelem(root->next);
}

int main(void) {
  Melem *root = NULL;

  Melem m1 = {"hoge", 170, 60, root};
  root = &m1;

  Melem m2 = {"fuga", 180, 70, root};
  root = &m2;

  Melem m3 = {"piyo", 190, 80, root};
  root = &m3;

  printMelem(root);

  return 0;
}