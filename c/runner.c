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

  char* a[4];
  a[0] = "8";
  a[1] = "63";
  a[2] = "1024";
  a[3] = "2053";

  char* b[4];
  b[0] = "16";
  b[1] = "126";
  b[2] = "2048";
  b[3] = "4106";

  strcat(command, "./");
  strcat(command, o);

  int total = sizeof(a)/sizeof(a[0]);
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


    sprintf(input, "%s\n", a[i]);
    write(pipein[1], input, sizeof(input));
    read(pipeout[0], output, 256);

    if (strcmp(output, b[i]) == 0) {
      strcat(result, ".");
    } else {
      strcat(result, "f");
    }

  }

  return result;
}

