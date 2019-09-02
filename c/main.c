/*
 * easy_plp
 *
 * Anderson Clemente, Arthur Guedes, Bruno Siqueira, João Pedro Espíndula
 */

#include "main.h"

int main(int argc, char **argv) {
  printf("Printing args\n");

  for (int i = 0; i < argc; i++) {
    printf("%s\n", argv[i]);
  }

  hello_world();
  return 0;
}
