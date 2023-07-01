#include <stdio.h>
#include <stdlib.h>

#define PNG_SIGNATURE_SIZE 8

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
  unsigned char png_signature[PNG_SIGNATURE_SIZE] = {137, 80, 78, 71,
                                                     13,  10, 26, 10};
  unsigned char file_signature[PNG_SIGNATURE_SIZE];

  fread(file_signature, 1, PNG_SIGNATURE_SIZE, file);

  for (int i = 0; i < PNG_SIGNATURE_SIZE; i++) {
    if (file_signature[i] != png_signature[i]) return 0;
  }

  return 1;
}

int read_png_header(FILE* file, PNGHeader* header) {
  // 幅と高さの情報を読み取る
  fread(&header->width, 4, 1, file);
  fread(&header->height, 4, 1, file);

  // ビット深度の情報を読み取る
  int depth;
  fread(&depth, 1, 1, file);
  header->depth = depth;

  // カラーモードの情報を読み取る
  int color_type;
  fread(&color_type, 1, 1, file);
  header->color_type = color_type;

  // その他の情報は読み取らない
  fseek(file, 2, SEEK_CUR);

  return 1;
}

void read_png(FILE* file, Image* image) {
  // ヘッダー情報を解析してイメージの幅、高さ、カラーモードを取得する処理を実装する
  read_png_header(file, &image->header);
  printf("width: %d\n", image->header.width);
  printf("height: %d\n", image->header.height);
  printf("depth: %d\n", image->header.depth);
  printf("color_type: %d\n", image->header.color_type);

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

  Image image;
  read_png(file, &image);

  // イメージの幅、高さ、ピクセルデータなどを使用して処理を行う

  fclose(file);
  return 0;
}
