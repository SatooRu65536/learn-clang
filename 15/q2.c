#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_MAX 256

typedef struct passenger {
  char type[16];
  double age;
  char gender[16];
  int survival;
} Passenger;

Passenger *parsePassenger(char line[LINE_MAX]) {
  Passenger *new_p = (Passenger *)malloc(sizeof(Passenger));

  strcpy(new_p->type, strtok(line, ","));
  new_p->age = atof(strtok(NULL, ","));
  strcpy(new_p->gender, strtok(NULL, ","));
  new_p->survival = atoi(strtok(NULL, "\n"));

  return new_p;
}

void dispPassenger(Passenger p) {
  printf("乗船クラス：%s, ", p.type);
  printf("年齢：%f, ", p.age);
  printf("性別：%s, ", p.gender);
  printf("生還: %d\n", p.survival);
}

int main(void) {
  char line[] = "1st,0.92,male,1\n";
  Passenger p = *parsePassenger(line);
  dispPassenger(p);
  return 0;
}