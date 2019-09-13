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

char* compile_file_java(char* path) {
    int len_command = 6 * sizeof(char);
    char* command = malloc(strlen(path) + len_command + 1);

    strcat(command, "javac ");
    strcat(command, path);

    system(command);
    return "out.class";
};

char* compile_file_haskell(char* path) {
    int len_command = 11 * sizeof(char);
    char* command = malloc(strlen(path) + len_command + 1);

    strcat(command, "ghc ");
    strcat(command, path);
    strcat(command, " -o out");

    system(command);
    return "out";
};
