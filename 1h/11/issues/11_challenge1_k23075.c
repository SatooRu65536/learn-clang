#include <stdio.h>

int main(void) {
  int index = 0;
  char searchTerm[13] = {'\0'};
  char paragraph[] =
      "we hold these truths to be self-evident, that all men are created "
      "equal, that they are endowed by their creator with certain unalienable "
      "rights, that among these are life, liberty and the pursuit of "
      "happiness.";

  printf("input: ");
  scanf("%s", searchTerm);

  if (searchTerm[12] != '\0') {
    printf("indexOf: -1\n");
    return 0;
  }

  // paragraph 内に searchTerm が存在するかどうかを判定する
  for (int i = 0; i < sizeof(paragraph); i++) {
    if (paragraph[i] != searchTerm[0]) continue;

    index = i;
    for (int j = 0; j < sizeof(searchTerm); j++) {
      if (searchTerm[j] == '\0') break;

      if (paragraph[i + j] != searchTerm[j]) {
        index = -1;
        break;
      }
    }

    if (index != -1) break;
  }

  printf("indexOf: %d\n", index);

  return 0;
}