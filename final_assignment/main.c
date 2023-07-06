#include <curl/curl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// コールバック関数: レスポンスのデータを受け取る
void write_callback(void* contents, size_t size, size_t nmemb, char** output) {
  size_t realsize = size * nmemb;
  *output = realloc(*output, realsize + 1);
  if (*output == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    return;
  }
  memcpy(*output, contents, realsize);
  (*output)[realsize] = 0;

  return;
}

int main(void) {
  CURL* curl;
  CURLcode res;

  char* url = "https://api.github.com/users/SatooRu65536/";
  char* username = "satooru65536";
  char* output = NULL;

  // libcurlの初期化
  curl_global_init(CURL_GLOBAL_DEFAULT);

  // CURLオブジェクトの作成
  curl = curl_easy_init();
  if (curl) {
    // URLの設定
    char request_url[100];
    sprintf(request_url, url, username);
    curl_easy_setopt(curl, CURLOPT_URL, request_url);

    // データの受け取り先の設定
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &output);

    // リクエストの送信
    res = curl_easy_perform(curl);

    // リクエストの結果を処理
    if (res != CURLE_OK) {
      fprintf(stderr, "Request failed: %s\n", curl_easy_strerror(res));
    } else {
      // レスポンスの処理
      printf("Response: %s\n", output);
      // ここでレスポンスのJSONデータを解析して草の数を取得する処理を行います
    }

    // CURLオブジェクトの解放
    curl_easy_cleanup(curl);
  }

  // libcurlの終了
  curl_global_cleanup();

  // 出力の解放
  free(output);

  return 0;
}