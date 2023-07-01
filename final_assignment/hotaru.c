#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int main(void) {
  char set_time[9] = "21:00";
  time_t t;
  struct tm tm;
  char now[9];

  while (1) {
    t = time(NULL);
    localtime_r(&t, &tm);
    sprintf(now, "%02d:%02d", tm.tm_hour, tm.tm_min);

    if (strcmp(now, set_time) == 0) system("mpg321 ./hotaru.mp3");

    sleep(50);
  }

  return 0;
}