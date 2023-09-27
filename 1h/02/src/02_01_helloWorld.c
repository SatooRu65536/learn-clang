#include <stdio.h>

int main(int argc, const char* argv[]) {
  int char_codes[] = {72, 101, 108, 108, 111, 44, 32,
                      87, 111, 114, 108, 100, 33, 10};

  for (int i = 0; i < 14; i++) printf("%c", char_codes[i]);

  return 0;
}