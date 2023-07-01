#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  uint32_t width;
  uint32_t height;
  uint32_t depth;
  uint8_t color_type;
} PNGHeader;

typedef struct {
  unsigned int width;
  unsigned int height;
  unsigned int channels;
  unsigned char* image_data;
  PNGHeader header;
} Image;

int check_png_signature(FILE* file) {
  unsigned char png_signature[] = {0x89, 0x50, 0x4E, 0x47,
                                   0x0D, 0x0A, 0x1A, 0x0A};
  unsigned char file_signature[8];

  fread(file_signature, 1, 8, file);

  for (int i = 0; i < 8; i++) {
    if (file_signature[i] != png_signature[i]) return 0;
  }

  return 1;
}

int skip_until_ihdr(FILE* file) {
  // 0x49, 0x48, 0x44, 0x52 が見つかるまで読み込む
  unsigned char ihdr_signature[] = {0x49, 0x48, 0x44, 0x52};
  unsigned char signature[4];
  while (1) {
    fread(signature, 1, 4, file);
    if (signature[0] == ihdr_signature[0] &&
        signature[1] == ihdr_signature[1] &&
        signature[2] == ihdr_signature[2] &&
        signature[3] == ihdr_signature[3]) {
      break;
    }
  }

  return 1;
}

int skip_until_idat(FILE* file) {
  // 0x49, 0x48, 0x44, 0x52 が見つかるまで読み込む
  unsigned char ihat_signature[] = {0x49, 0x44, 0x41, 0x54};
  unsigned char signature[4];
  while (1) {
    fread(signature, 1, 4, file);
    if (signature[0] == ihat_signature[0] &&
        signature[1] == ihat_signature[1] &&
        signature[2] == ihat_signature[2] &&
        signature[3] == ihat_signature[3]) {
      break;
    }
  }

  return 1;
}

void read_ihdr(FILE* file, Image* image) {
  // 4バイトの幅、4バイトの高さ、1バイトのビット深度、1バイトのカラータイプを読み込む
  unsigned char width[4];
  unsigned char height[4];
  unsigned char depth[1];
  unsigned char color_type[1];

  fread(width, 1, 4, file);
  fread(height, 1, 4, file);
  fread(depth, 1, 1, file);
  fread(color_type, 1, 1, file);

  int width_int = 0;
  for (int i = 0; i < 4; i++) width_int += width[i] << (8 * (3 - i));
  image->header.width = width_int;

  int height_int = 0;
  for (int i = 0; i < 4; i++) height_int += height[i] << (8 * (3 - i));
  image->header.height = height_int;

  image->header.depth = depth[0];

  image->header.color_type = color_type[0];
}

void read_data(FILE* file, Image* image) {
}

void read_png(FILE* file, Image* image) {
  // イメージの幅、高さ、カラーモードを取得する
  read_ihdr(file, image);
  printf("width: %d\n", image->header.width);
  printf("height: %d\n", image->header.height);
  printf("depth: %d\n", image->header.depth);
  printf("color_type: %d\n", image->header.color_type);

  skip_until_idat(file);

  read_data(file, image);

  // データ部分を解凍（デコード）する処理を実装する
  // イメージデータを生成し、image構造体にセットする処理を実装する
  // 必要な形式に変換する処理を実装する
}

int main() {
  const char* filename = "image.png";
  FILE* file = fopen(filename, "rb");
  if (file == NULL) {
    printf("Failed to open file: %s\n", filename);
    return 1;
  }

  if (!check_png_signature(file)) {
    printf("File is not a valid PNG image.\n");
    fclose(file);
    return 1;
  }

  skip_until_ihdr(file);

  Image image;
  read_png(file, &image);

  // イメージの幅、高さ、ピクセルデータなどを使用して処理を行う

  fclose(file);
  return 0;
}
