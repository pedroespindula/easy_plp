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


  /* printf("%s\n",dl_exercise("dobro", "./")); */

  read_test_input("dobro.csv");
  read_test_output("dobro.csv");


  return 0;
}
