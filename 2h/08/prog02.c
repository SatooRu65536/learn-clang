#include <stdio.h>

typedef struct location {
  double latitude;
  double longitude;
  char address[128];
} Location;

void printLocation(char* locationName, Location location) {
  printf("%s: ", locationName);
  printf("緯度: %f, 経度: %f, ", location.latitude, location.longitude);
  printf("住所: %s\n", location.address);
}

int main(int argc, const char* argv[]) {
  Location ait = {35.18480, 137.111525,
                  "〒470-0356 愛知県豊田市八草町八千草１２４７"};
  Location meiden = {35.1778635, 136.9464276,
                     "〒464-0083 愛知県名古屋市千種区若水３丁目２−１２"};

  printLocation("愛知工業大学", ait);
  printLocation("名電", meiden);

  return 0;
}