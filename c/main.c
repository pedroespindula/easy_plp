/*
 * easy_plp
 *
 * Anderson Clemente, Arthur Guedes, Bruno Siqueira, João Pedro Espíndula
 */

#include <curl/curl.h>
#include "main.h"

int COMANDO_SAIDA = 5;

void exec_test(void) {
  printf("%s", get_header_exercise_info());
  printf(get_fmsg_exercise_info(), "Nome do exercicio");
  printf("\n%s\n", get_header_exercise_results());

  for (int i = 0; i < 10; i++) {
    char* file_name = "Dobra.py";
    char* language = "Python";
    char* test_results = "....f..f";

    printf(get_fmsg_exercise_results(), file_name, language, test_results);
    printf("\n");
  }
}

void exec_download(void) {
  char* id = malloc(sizeof(char) * 20);

  printf("%s", get_prompt_download_exercise());
  scanf("%s", id);

  printf("\n%s", get_header_exercise_download());
  printf(get_fmsg_exercise_download(), id);

  char* path = "./";
  dl_exercise(id, path);

  printf("\n");
}

void exec_config(void) {
  char* name = malloc(sizeof(char) * 20);
  char* registry = malloc(sizeof(char) * 20);
  char* exercises_path = malloc(sizeof(char) * 20);

  printf("%s", get_prompt_config_name());
  scanf("%s", name);

  printf("%s", get_prompt_config_registry());
  scanf("%s", registry);

  printf("%s", get_prompt_config_exercises_path());
  scanf("%s", exercises_path);

  /* set_config_username(name); */  
  /* set_config_registry(registry); */  
  /* set_config_exercises_path(exercises_path); */  

  printf("\n");
}

void exec_help(void) {
  printf("%s\n", get_msg_help());
}

void exec_exit(void) {
  printf("%s\n", get_msg_exit());
}

void exec_invalid(void) {
  printf("%s\n", get_msg_invalid_command());
}

int menu(void) {
  int result = 0;

  printf("%s\n", get_header_easy_plp());
  printf("%s\n", get_msg_welcome());
  printf("%s", get_prompt_select_option());
  scanf("%d", &result);
  printf("\n");

  return result;
}

int main(int argc, char **argv) {

  int comando = 0;
  while (comando != COMANDO_SAIDA) {
    comando = menu();

    switch (comando) {
      case 1: exec_test(); break;
      case 2: exec_download(); break;
      case 3: exec_config(); break;
      case 4: exec_help(); break;
      case 5: exec_exit(); break;
      default: exec_invalid(); break;
    }
  }


  return 0;
}
