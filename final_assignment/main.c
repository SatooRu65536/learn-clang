#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>

#define ANSI_CLEAR "\033[2J"
#define ANSI_RESET "\033[0m"

#define ANSI_BLACK "\033[30m"
#define ANSI_RED "\033[31m"
#define ANSI_GREEN "\033[32m"
#define ANSI_YERROW "\033[33m"
#define ANSI_BLUE "\033[34m"
#define ANSI_MAGENTA "\033[35m"
#define ANSI_CYAAN "\033[36m"
#define ANSI_WHITE "\033[37m"

#define ANSI_BG_BLACK "\033[40m"
#define ANSI_BG_RED "\033[41m"
#define ANSI_BG_GREEN "\033[42m"
#define ANSI_BG_YERROW "\033[43m"
#define ANSI_BG_BLUE "\033[44m"
#define ANSI_BG_MAGENTA "\033[45m"
#define ANSI_BG_CYAAN "\033[46m"
#define ANSI_BG_WHITE "\033[47m"

void getWindowSize(int *rows, int *columns);
void putColor(int x, int y, char str, char ansiBgColor[]);
void clearScreen();
void moveCursor(int x, int y);
void drawCaterp(int (*caterp)[100][2], int caterpLen);
void moveCaterp(int (*caterp)[100][2], int caterpLen, int *caterpDir, int rows,
                int cols);

int main() {
  // ターミナルのサイズを取得する
  int rows, columns;
  getWindowSize(&rows, &columns);

  // 芋虫の位置を保存する
  int caterp[100][2];
  // 芋虫の初期位置を設定する
  caterp[0][0] = 3;
  caterp[0][1] = 1;
  caterp[1][0] = 1;
  caterp[1][1] = 1;
  // 芋虫の長さを保存する
  int caterpLen = 2;
  // 芋虫の向きを保存する(0: 上, 1: 右, 2: 下, 3: 左)
  int caterpDir = 1;

  // ゲームループ
  while (1) {
    clearScreen();
    getWindowSize(&rows, &columns);
    moveCaterp(&caterp, caterpLen, &caterpDir, rows, columns);
    drawCaterp(&caterp, caterpLen);

    fflush(stdout);
    usleep(100000);
  }

  return 0;
}

// 芋虫を移動させる
void moveCaterp(int (*caterp)[100][2], int caterpLen, int *caterpDir, int rows,
                int cols) {
  int pos[2] = {*caterp[0][0], *caterp[0][1]};

  switch (*caterpDir) {
    case 0:
      pos[1]--;
      if (pos[1] > 0) break;

      pos[1]++;

      if (rand() > 0.5) {
        pos[0] += 2;
        *caterpDir = 1;
      } else {
        pos[0] -= 2;
        *caterpDir = 3;
      }

      if (pos[0] < 0) {
        pos[0]++;
        *caterpDir = 1;
      } else if (pos[0] >= cols) {
        pos[0]--;
        *caterpDir = 3;
      }
      break;

    case 1:
      pos[0] += 2;
      if (pos[0] <= cols) break;

      pos[0] -= 2;

      if (rand() > 0.5) {
        pos[1]++;
        *caterpDir = 2;
      } else {
        pos[1]--;
        *caterpDir = 0;
      }

      if (pos[1] < 0) {
        pos[1]++;
        *caterpDir = 2;
      } else if (pos[1] >= rows) {
        pos[1]--;
        *caterpDir = 0;
      }
      break;

    case 2:
      pos[1]++;
      if (pos[1] <= rows) break;

      pos[1]--;

      if (rand() > 0.5) {
        pos[0] += 2;
        *caterpDir = 1;
      } else {
        pos[0] -= 2;
        *caterpDir = 3;
      }

      if (pos[0] < 0) {
        pos[0] += 2;
        *caterpDir = 1;
      } else if (pos[0] >= cols) {
        pos[0] -= 2;
        *caterpDir = 3;
      }
      break;

    case 3:
      pos[0] -= 2;
      if (pos[0] >= 0) break;

      pos[0] += 2;

      if (rand() > 0.5) {
        pos[1]++;
        *caterpDir = 2;
      } else {
        pos[1]--;
        *caterpDir = 0;
      }

      if (pos[1] < 0) {
        pos[1]++;
        *caterpDir = 2;
      } else if (pos[1] >= rows) {
        pos[1]--;
        *caterpDir = 0;
      }
      break;
  }

  int tmp[2] = {*caterp[0][0], *caterp[0][1]};
  for (int i = caterpLen - 1; i > 0; i--) {
    *caterp[i][0] = *caterp[i - 1][0];
    *caterp[i][1] = *caterp[i - 1][1];
  }
  // 芋虫の頭を更新する
  *caterp[0][0] = pos[0];
  *caterp[0][1] = pos[1];
}

// 毛虫を描画する
void drawCaterp(int (*caterp)[100][2], int caterpLen) {
  for (int i = 0; i < caterpLen; i++) {
    moveCursor(*caterp[i][0], *caterp[i][1]);
    printf("%s", i == 0 ? "🟡" : "🟢");
  }
}

// 画面をクリアする
void clearScreen() { printf(ANSI_CLEAR); }

// 指定位置に色を描画する
void putColor(int x, int y, char str, char ansiBgColor[]) {
  moveCursor(x, y);
  printf("%s%c" ANSI_RESET, ansiBgColor, str);
}

// カーソルを移動する
void moveCursor(int x, int y) { printf("\033[%d;%dH", y, x); }

// ターミナルのサイズを取得する
void getWindowSize(int *rows, int *columns) {
  struct winsize window;
  ioctl(0, TIOCGWINSZ, &window);

  *rows = window.ws_row;
  *columns = window.ws_col;
}
