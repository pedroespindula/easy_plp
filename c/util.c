#include <stdio.h>
#include <string.h>
#include <libgen.h>
#include <stdlib.h>
#include <dirent.h>

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

    int num_files = 0;
    while((lsdir = readdir(dir)) != NULL) {
         if (!strcmp(lsdir -> d_name, ".") || !strcmp(lsdir -> d_name, "..")) {
            continue;
        }

        num_files++;
    }

    closedir(dir);

    return num_files;
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

char* get_input_from_csv_line(char* csv_line) {
  char* delimiter = ",";
  char *ptr = strtok(csv_line, delimiter);

  return ptr;
}

char* get_output_from_csv_line(char* csv_line) {
  char* delimiter = ",";
  char *ptr = strtok(csv_line, delimiter);

  ptr = strtok(NULL, delimiter);

  return ptr;
}

char* read_test_input(char* test_file_path, char* inputs[]) {
  char buffer[255];
  FILE  *file_pointer;

  if ((file_pointer = fopen(test_file_path, "r")) == NULL) {
    printf("Erro lendo arquivo de teste.");
    exit(1);
  }

  int i = 0;
  while (fgets(buffer, 255, file_pointer)) {
    inputs[i] = get_input_from_csv_line(buffer);
    i += 1;
  }

  return "";
}

char* read_test_output(char* test_file_path, char* outputs[]) {
  char buffer[255];
  FILE  *file_pointer;

  if ((file_pointer = fopen(test_file_path, "r")) == NULL) {
    printf("Erro lendo arquivo de teste.");
    exit(1);
  }

  int i = 0;
  while (fgets(buffer, 255, file_pointer)) {
    outputs[i] = get_output_from_csv_line(buffer);
    i += 1;
  }

  return "";
}
