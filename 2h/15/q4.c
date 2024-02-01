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

void parsePassenger(Passenger *new_p, char line[LINE_MAX]) {
  strcpy(new_p->type, strtok(line, ","));
  new_p->age = atof(strtok(NULL, ","));
  strcpy(new_p->gender, strtok(NULL, ","));
  new_p->survival = atoi(strtok(NULL, "\n"));
}

void dispPassenger(Passenger p) {
  printf("乗船クラス：%s, ", p.type);
  printf("年齢：%f, ", p.age);
  printf("性別：%s, ", p.gender);
  printf("生還: %d\n", p.survival);
}

int main(void) {
  int passenger_num = 0;
  Passenger *passengers = (Passenger *)malloc(sizeof(Passenger));

  char line[LINE_MAX];
  FILE *fp = fopen("titanic.csv", "r");
  if (fp == NULL) {
    printf("File not found.\n");
    return 1;
  }

  while (fgets(line, LINE_MAX, fp) != NULL) {
    passenger_num += 1;
    int size = (passenger_num + 1) * sizeof(Passenger);
    if ((passengers = (Passenger *)realloc(passengers, size)) == NULL) {
      printf("No enough memory.\n");
      exit(1);
    }
    parsePassenger(&passengers[passenger_num - 1], line);
  }
  fclose(fp);

  int survivors_num = 0;
  for (int i = 0; i < passenger_num; i++) {
    if (passengers[i].survival == 1) survivors_num += 1;
  }

  printf("生還者数：%d, ", survivors_num);
  printf("死亡者数：%d\n", passenger_num - survivors_num);

  free(passengers);
  return 0;
}