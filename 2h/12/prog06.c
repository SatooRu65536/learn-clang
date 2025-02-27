#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct elem {
  int num;
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
  Elem *current = root;
  Elem *prev = NULL;
  Elem *new_elem = (Elem *)malloc(sizeof(Elem));
  new_elem->num = num;

  while (current != NULL) {
    if (current->num > num) {
      break;
    }

    prev = current;
    current = current->next;
  }

  new_elem->next = current;  // new_elem の次に current を挿入

  // 空の場合は new_elem が root として返す
  if (prev == NULL) return new_elem;

  prev->next = new_elem;  // prev の次に new_elem を挿入
  return root;
}

Elem *delete_elem(Elem *root, int delnum) {
  Elem *current = root;
  Elem *prev = NULL;

  while (current != NULL) {
    // 削除する要素でない場合
    if (current->num != delnum) {
      prev = current;
      current = current->next;
      continue;
    }

    if (prev == NULL)
      root = current->next;
    else
      prev->next = current->next;

    free(current);
    break;
  }

  return root;
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

  root = add_elem(root, 4);
  root = add_elem(root, 2);
  root = add_elem(root, 1);
  root = add_elem(root, 5);
  root = add_elem(root, 9);
  root = add_elem(root, 65536);

  print_list(root);

  printf("\n--delete 2--\n");
  delete_elem(root, 2);
  print_list(root);

  free_list(root);

  return 0;
}