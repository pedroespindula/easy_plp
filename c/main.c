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

  if (curl) {
    // Taken from https://curl.haxx.se/libcurl/c/simple.html
    curl_easy_setopt(curl, CURLOPT_URL, "https://example.com");
    /* example.com is redirected, so we tell libcurl to follow redirection */
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

    /* Perform the request, res will get the return code */
    res = curl_easy_perform(curl);
    /* Check for errors */
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
          curl_easy_strerror(res));

    /* always cleanup */
    curl_easy_cleanup(curl);
  }

  hello_world();
  return 0;
}
