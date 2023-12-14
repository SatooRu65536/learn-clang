#include <stdio.h>

typedef struct position {
  double latitude;
  double longitude;
  char address[100];
} Position;

void print_position(Position p) {
  printf("緯度: %f\n", p.latitude);
  printf("経度: %f\n", p.longitude);
  printf("住所: %s\n", p.address);
}

int main() {
  Position p1 = {35.18378, 137.11355, "愛知県豊田市八草町八千草1247-1"};
  Position p2 = {35.17856, 136.94899, "愛知県名古屋市千種区北千種3丁目4-46"};

  print_position(p1);
  print_position(p2);

  return 0;
}