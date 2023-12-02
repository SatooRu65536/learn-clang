#include <stdio.h>

struct student {
  char name[64];
  int age;
  char id[10];
  int degree;
};

void printStudent(struct student s) {
  printf("Name: %s, ", s.name);
  printf("Age: %d, ", s.age);
  printf("ID: %s, ", s.id);
  printf("Degree: %d\n", s.degree);
}

int main(int argc, const char *argv[]) {
  struct student s1 = {"satou satoru", 19, "k23076", 1};
  struct student s2 = {"yamada yama", 20, "k23077", 2};
  struct student s3 = {"toyama ryuki", 22, "b23714", 1};
  struct student s4 = {"penguin cute", 13, "k23075", 1};

  printStudent(s1);
  printStudent(s2);
  printStudent(s3);
  printStudent(s4);

  return 0;
}