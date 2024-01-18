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

Melem *readFile(Melem *root, char *filename) {
  FILE *file;
  char line[256];

  file = fopen(filename, "r");
  if (file == NULL) {
    printf("ファイルを開けませんでした。\n");
    return root;
  }

  char name[64];
  int height, weight;
  // ファイルから1行ずつ読み込む
  while (fgets(line, sizeof(line), file) != NULL) {
    strcpy(name, strtok(line, ","));
    height = atoi(strtok(NULL, ","));
    weight = atoi(strtok(NULL, ","));
    root = addMelem(root, name, height, weight);
  }
  fclose(file);

  return root;
}

int main(void) {
  Melem *root = NULL;

  root = readFile(root, "meibo.csv");

  printMelem(root);
  freeMelem(root);

  return 0;
}