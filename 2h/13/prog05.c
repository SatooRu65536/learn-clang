#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

Melem *addMelem(Melem *root, char *name, int height, int weight) {
  // メモリの確保
  Melem *new = (Melem *)malloc(sizeof(Melem));

  // 文字列のコピー
  strcpy(new->name, name);
  // 変数の定義
  new->height = height;
  new->weight = weight;
  new->next = root;

  // 次の最初になるものを返す
  return new;
}

void freeMelem(Melem *root) {
  if (root->next != NULL) freeMelem(root->next);
  free(root);
}

int main(void) {
  Melem *root = NULL;

  root = addMelem(root, "hoge", 170, 60);
  root = addMelem(root, "fuga", 180, 70);
  root = addMelem(root, "piyo", 190, 80);

  printMelem(root);

  freeMelem(root);

  return 0;
}