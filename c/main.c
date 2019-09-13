/*
 * easy_plp
 *
 * Anderson Clemente, Arthur Guedes, Bruno Siqueira, João Pedro Espíndula
 */

#include <curl/curl.h>
#include "main.h"

int main(int argc, char **argv) {
  CURL *curl;
  CURLcode res;

  printf("Printing args\n");
  curl = curl_easy_init();

  for (int i = 0; i < argc; i++) {
    printf("%s\n", argv[i]);
  }

  char result[256];
  run_file("./exec/dobro/hello.c", result);

  printf("result: %s\n", result);

  return 0;
}
