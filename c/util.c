#include <stdio.h> /* printf */
#include <string.h> /* strrchr */
#include <libgen.h>
#include <stdlib.h>

char* get_file_extension(char* path) {
    const char ch = '.';    
    return strrchr(path, ch) + 1;
}

char* get_file_name(char* path) {
    char* basec = strdup(path);
    char* bname = basename(basec);
    const char ch = '.';
    int n = strlen(bname) - strlen(strrchr(path, ch));
    char* result;
    result = malloc(sizeof(char));
    strncpy(result, bname, n);
    
    return result;
}

char* get_dir_path(char* path) {
    char* dirc = strdup(path);
    return dirname(dirc);
}