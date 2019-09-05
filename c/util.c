#include <stdio.h>
#include <string.h>
#include <libgen.h>
#include <stdlib.h>
#include <dirent.h>
#include <stdbool.h>

char* get_file_extension(char* path) {
    const char ch = '.';    
    return strrchr(path, ch) + 1;
}

char* get_file_name(char* path) {
    char* basec = strdup(path);
    char* bname = basename(basec);
    const char ch = '.';
    int n = strlen(bname) - strlen(strrchr(path, ch));
    char* result = malloc(sizeof(char));
    strncpy(result, bname, n);
    
    return result;
}

char* get_dir_path(char* path) {
    char* dirc = strdup(path);
    return dirname(dirc);
}

int count_files (char * path) {
    DIR *dir;
    struct dirent *lsdir;
    dir = opendir(path);

    int files = 0;
    while((lsdir = readdir(dir)) != NULL) {
         if (!strcmp(lsdir -> d_name, ".") || !strcmp(lsdir -> d_name, "..")) {
            continue;
        }

        files++;
    }

    closedir(dir);

    return files;
}

void get_dir_files (char* path, char *result[]) {
    DIR *dir;
    struct dirent *lsdir;
    dir = opendir(path);

    int index = 0;
    while((lsdir = readdir(dir)) != NULL) {
         if (!strcmp(lsdir -> d_name, ".") || !strcmp(lsdir -> d_name, "..")) {
            continue;
        }

        result[index] = lsdir -> d_name;
        index++;
    }

    closedir(dir);
}