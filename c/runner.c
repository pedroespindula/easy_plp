#include "main.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>
#define MAX_PATH 256

char* compile_file_c(char* path) {
    char command[256];
    char rpath[MAX_PATH];
    char pathdup[256];

    char* ptr = realpath(strdup(path), rpath);
    char* dir = dirname(strdup(rpath));
    char* outpath = strcat(dir, "/out.o");

    strcat(command, "gcc ");
    strcat(command, rpath);
    strcat(command, " -o ");
    strcat(command, outpath);

    int e = system(command);
    if (e != 0) {
      printf("Compilacao falhou.");
      exit(1);
    }

    return outpath;
};

void run_file(char* path, char* result) {
  char* o = compile_file_c(path);
  char* command = malloc(strlen(o) + strlen("./"));
  result[0] = '\0';
  command[0] = '\0';

  pid_t pid = 0;
  int pipein[2];
  int pipeout[2];
  char csv[512];

  find_csv(path, csv);

  char* ins[512];
  char* outs[512];

  int total = read_test_input(csv, ins);
  read_test_output(csv, outs);
  strcat(command, o);

  for (int i = 0; i < total; i++) {
    char* input = malloc(512);
    char* output = malloc(512);
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

    output[0] = '\0';
    sprintf(input, "%s\n", ins[i]);
    write(pipein[1], input, sizeof(input));
    read(pipeout[0], output, sizeof(output));

    if (strcmp(output, outs[i]) == 0) {
      strcat(result, ".");
    } else {
      strcat(result, "f");
    }

    free(input);
    free(output);
  }
}
