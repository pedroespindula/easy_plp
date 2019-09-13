/*
 * easy_plp
 *
 * Anderson Clemente, Arthur Guedes, Bruno Siqueira, João Pedro Espíndula
 */

#include <curl/curl.h>
#include "main.h"

// WRAPPERS DAS FUNCIONALIDADES
void exec_test(char* path) {
  printf("%s", get_header_exercise_info());
  printf(get_fmsg_exercise_info(), "Nome do exercicio");
  printf("\n%s\n", get_header_exercise_results());
}

void exec_download(char* id) {
  printf("\n%s", get_header_exercise_download());
  printf(get_fmsg_exercise_download(), id);
  printf("\n");

  int status = dl_exercise(id, "./");
  if (status) {
    printf("%s\n", get_msg_download_success());
  } else {
    printf("%s\n", get_msg_download_failure());
  }

}

void exec_config(char* name, char* registry, char* path) {
  /* set_config_username(name); */
  /* set_config_registry(registry); */
  /* set_config_exercises_path(path); */
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

// WRAPPERS DAS CHAMADAS COM STDIN
void exec_test_stdin(void) {
  exec_test("./");
}

void exec_download_stdin(void) {
  char* id = malloc(sizeof(char) * 20);

  printf("%s", get_prompt_download_exercise());
  scanf("%s", id);

  exec_download(id);
}

void exec_config_stdin(void) {
  char* name = malloc(sizeof(char) * 20);
  char* registry = malloc(sizeof(char) * 20);
  char* exercises_path = malloc(sizeof(char) * 20);

  printf("%s", get_msg_config_save_last());
  printf("%s", get_prompt_config_name());
  scanf("%s", name);

  printf("%s", get_prompt_config_registry());
  scanf("%s", registry);

  printf("%s", get_prompt_config_exercises_path());
  scanf("%s", exercises_path);
  printf("\n");

  exec_config(name, registry, exercises_path);
}

// WRAPPERS DAS CHAMADAS POR COMMAND LINE
void exec_test_cl(int size, char** args) {
  char* path = args[2];
  exec_test(path);
}

void exec_download_cl(int size, char** args) {
  if (size >= 3) {
    char* id = args[2];
    exec_download(id);
  } else {
    exec_invalid();
  }
}

void exec_config_cl(int size, char** args) {
  if (size >= 5) {
    char* name = args[3];
    char* registry = args[4];
    char* path = args[5];
    exec_config(name, registry, path);
  } else {
    exec_invalid();
  }
}

// MENU
int menu(void) {
  int result = 0;

  printf("%s\n", get_header_easy_plp());
  printf("%s\n", get_msg_welcome());
  printf("%s", get_prompt_select_option());
  scanf("%d", &result);
  printf("\n");

  return result;
}

// MAIN
int main(int argc, char **argv) {
  int COMANDO_SAIDA = 5;


  if (argc == 1) {
    int comando = 0;
    while (comando != COMANDO_SAIDA) {
      comando = menu();

      switch (comando) {
        case 1: exec_test_stdin(); break;
        case 2: exec_download_stdin(); break;
        case 3: exec_config_stdin(); break;
        case 4: exec_help(); break;
        case 5: exec_exit(); break;
        default: exec_invalid(); break;
      }
    }

  } else {
    char* comando = argv[1];
    if (strcmp(comando, "help") == 0 || strcmp(comando, "-h") == 0) {
      exec_help();
    } else if (strcmp(comando, "download") == 0 || strcmp(comando, "-d") == 0) {
      exec_download_cl(argc, argv);
    } else if (strcmp(comando, "config") == 0 || strcmp(comando, "-c") == 0) {
      exec_config_cl(argc, argv);
    } else if (argc == 2) {
      exec_test_cl(argc, argv);
    } else {
      exec_invalid();
    }
  }

  return 0;
}
