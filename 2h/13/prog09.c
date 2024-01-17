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
  if (root == NULL) return;
  printf("%s %d %d\n", root->name, root->height, root->weight);
  if (root->next != NULL) printMelem(root->next);
}

Melem *addMelem(Melem *root, char *name, int height, int weight) {
  Melem *next = root;
  Melem *prev = NULL;

  // ここでprevとnextを決める。
  while (next != NULL) {
    if (strcmp(next->name, name) >= 0) break;
    prev = next;
    next = next->next;
  }

  if (next != NULL && strcmp(next->name, name) == 0) {
    next->height = height;
    next->weight = weight;
    return root;
  }

  Melem *new = (Melem *)malloc(sizeof(Melem));
  strcpy(new->name, name);
  new->height = height;
  new->weight = weight;

  new->next = next;

  if (prev == NULL) return new;

  prev->next = new;
  return root;
}

Melem *deleteMelem(Melem *root, char *name) {
  Melem *next = root;
  Melem *prev = NULL;

  while (next != NULL) {
    if (strcmp(next->name, name) == 0) break;
    prev = next;
    next = next->next;
  }

  if (next == NULL) return root;

  if (prev == NULL) {
    root = next->next;
  } else {
    prev->next = next->next;
  }

  free(next);
  return root;
}

void freeMelem(Melem *root) {
  if (root->next != NULL) freeMelem(root->next);
  free(root);
}

int main(void) {
  Melem *root = NULL;

  char input[128];
  char *cmd;
  char name[64];
  int height, weight;

  printf("a: 追加, d: 削除, p: 表示, q: 終了\n");

  do {
    // 改行までを取得
    printf("cmd: ");
    scanf("%[^\n]", input);

    // 先頭の文字を取得
    cmd = strtok(input, " ");

    switch (*cmd) {
      case 'a':
        strcpy(name, strtok(NULL, ","));
        height = atoi(strtok(NULL, ","));
        weight = atoi(strtok(NULL, ","));
        root = addMelem(root, name, height, weight);
        break;
      case 'd':
        strcpy(name, strtok(NULL, ""));
        root = deleteMelem(root, name);
        break;
      case 'p':
        printMelem(root);
        break;
      case 'q':
        break;
    }
    getchar();
  } while (*cmd != 'q');

  freeMelem(root);

  return 0;
}