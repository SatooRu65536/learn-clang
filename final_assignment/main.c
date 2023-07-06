#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* getEnv(char *varname);
void loadEnvFile(char filename[]);

int main(char argc, char *argv[]) {
  // 引数から
  loadEnvFile(".env");
  char* github_token = getEnv("GITHUB_TOKEN");
  char* github_user = getEnv("GITHUB_USER_NAME");

  printf("GITHUB_TOKEN: %s\n", github_token);
  printf("GITHUB_USER_NAME: %s\n", github_user);

  return 0;
}

char* getEnv(char *varname) {
  char* value = getenv(varname);

  // 環境変数が存在しない場合
  if (value == NULL) {
    printf("環境変数 %s が設定されていません。\n", varname);
    exit(1);
  }

  return value;
}

// ファイルから環境変数を読み込む
void loadEnvFile(char filename[]) {
  FILE* file = fopen(filename, "r");

  if (file == NULL) {
    printf("ファイルを開けませんでした。\n");
    return;
  }

  // ファイルから行ごとに読み込み、環境変数に設定
  char line[256];
  while (fgets(line, sizeof(line), file) != NULL) {
    // 改行文字を削除
    line[strcspn(line, "\n")] = '\0';

    // イコール文字を探し、変数名と値を切り分ける
    char* equal = strchr(line, '=');
    if (equal != NULL) {
      *equal = '\0';
      char* varname = line;
      char* value = equal + 1;
      setenv(varname, value, 1);  // 環境変数に設定
    }
  }

  // ファイルを閉じる
  fclose(file);
}