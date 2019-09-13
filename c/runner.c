#include "main.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>

char* compile_file_c(char* path) {
    int len_command = 30 * sizeof(char);
    char* command = malloc(strlen(path) + len_command + 1);
    char* dir = dirname(path);
    char* outpath = strcat(dir, "/out.o");

    strcat(command, "gcc ");
    strcat(command, path);
    strcat(command, " -o");
    strcat(command, outpath);

    system(command);
    return outpath;
};

char* run_file(char* path) {
  char* o = compile_file_c(path);
  char* command = malloc(strlen(o) + strlen("./"));

  pid_t pid = 0;
  int pipein[2];
  int pipeout[2];
  char input[256];
  char output[256];
  char csv[256];

  find_csv(path, csv);

  char* ins[256];
  char* outs[256];

  int total = read_test_input(csv, ins);
  read_test_output(csv, outs);
  strcat(command, "./");
  strcat(command, o);

  static char result[256];

  for (int i = 0; i < total; i++) {
    pipe(pipein);
    pipe(pipeout);

    pid = fork();

    if (pid == 0) {
      // Child
      dup2(pipein[0], STDIN_FILENO);
      dup2(pipeout[1], STDOUT_FILENO);
      dup2(pipeout[1], STDERR_FILENO);

      //prctl(PR_SET_PDEATHSIG, SIGTERM);

      //replace tee with your process
      execl(command, "o", NULL);
      // Nothing below this line should be executed by child process. If so,
      // it means that the execl function wasn't successfull, so lets exit:
      exit(1);
    }


    printf("input aqui: %s\n", ins[i]);
    printf("out aqui: %s\n", outs[i]);
    sprintf(input, "%s\n", ins[i]);
    write(pipein[1], input, sizeof(input));
    read(pipeout[0], output, 256);

    if (strcmp(output, outs[i]) == 0) {
      strcat(result, ".");
    } else {
      strcat(result, "f");
    }
  }

  return result;
}

