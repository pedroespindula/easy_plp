#include <stdlib.h>
#include <string.h>

char* compile_file_c(char* path) {
    int len_command = 13 * sizeof(char);
    char* command = malloc(strlen(path) + len_command + 1);

    strcat(command, "gcc ");
    strcat(command, path);
    strcat(command, " -o out.o");

    system(command);
    return "out.o";
};

