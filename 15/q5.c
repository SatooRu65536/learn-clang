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
  Passenger *passengers = (Passenger *)malloc(sizeof(Passenger) * 1000);

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

  int survivors_nums[] = {0, 0};  // [男性, 女性]
  int gender_nums[] = {0, 0};     // [男性, 女性]
  for (int i = 0; i < passenger_num; i++) {
    if (strcmp(passengers[i].gender, "male") == 0) {  // 男性
      gender_nums[0] += 1;
      if (passengers[i].survival == 1) survivors_nums[0] += 1;
    } else {  // 女性
      gender_nums[1] += 1;
      if (passengers[i].survival == 1) survivors_nums[1] += 1;
    }
  }

  double male_survivors_ratio = survivors_nums[0] / (double)gender_nums[0];
  double female_survivors_ratio = survivors_nums[1] / (double)gender_nums[1];

  printf("男性生還割合：%f％, ", male_survivors_ratio * 100);
  printf("女性生還割合：%f％\n", female_survivors_ratio * 100);

  free(passengers);
  return 0;
}