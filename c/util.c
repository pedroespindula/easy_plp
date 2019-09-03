#include <stdio.h> /* printf */
#include <string.h> /* strrchr */
#include <libgen.h>
#define _GNU_SOURCE

char* get_file_extension(char* path) {
    const char ch = '.';    
    return strrchr(path, ch);
}

char* get_file_name(char* path) {
    char* basec = strdup(path);
    return basename(basec);
}

char* get_dir_files(char* path) {
    char* dirc = strdup(path);
    return dirname(dirc);
}

// For temporary tests
int main () {
    printf("%s\n", get_file_extension("/a/b/c/teste.c")); // .c
    printf("%s\n", get_file_name("/a/b/c/teste.c")); //teste.c
    printf("%s\n", get_dir_files("/a/b/c/teste.c")); //  /a/b/c
    return(0);
}