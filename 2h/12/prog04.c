#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct elem {
  int num;  // データ部
  struct elem *next;
} Elem;

void print_list(Elem *root) {
  Elem *p = root;
  while (p != NULL) {
    printf("%d\n", p->num);
    p = p->next;
  }
}

Elem *add_elem(Elem *root, int num) {
  Elem *new_elem = (Elem *)malloc(sizeof(Elem));

  new_elem->num = num;
  new_elem->next = root;

  return new_elem;
}

void free_list(Elem *root) {
  Elem *p = root;
  while (p != NULL) {
    Elem *tmp = p->next;
    free(p);
    p = tmp;
  }
}

int main(void) {
  Elem *root = NULL;  // 先頭のポインタを用意

  root = add_elem(root, 40);
  root = add_elem(root, 30);
  root = add_elem(root, 20);
  root = add_elem(root, 10);

  print_list(root);

  free_list(root);

  return 0;
}