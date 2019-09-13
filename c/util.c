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

int get_dir_files (char* path, char *result[]) {
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
    return index;
}

char* get_input_from_csv_line(char* csv_line) {
  char* delimiter = ",";
  char *ptr = strtok(csv_line, delimiter);

  return strdup(ptr);
}

char* get_output_from_csv_line(char* csv_line) {
  char* delimiter = ",";
  char* ptr = strtok(csv_line, delimiter);

  ptr = strtok(NULL, delimiter);

  return strdup(ptr);
}

int read_test_input(char* test_file_path, char* inputs[]) {
  char buffer[256];
  FILE  *file_pointer = fopen("/Users/bruno/easy_plp/c/exec/dobro/dobro.csv", "r");

  if (file_pointer == NULL) {
    printf("Erro lendo arquivo (in) de teste: %s\n", test_file_path);
    exit(1);
  }

  int i = 0;
  while (fgets(buffer, 256, file_pointer)) {
    inputs[i] = strdup(get_output_from_csv_line(buffer));
    i += 1;
  }

  fclose(file_pointer);

  return i;
}

int read_test_output(char* test_file_path, char* outputs[]) {
  char buffer[256];
  FILE  *file_pointer = fopen("/Users/bruno/easy_plp/c/exec/dobro/dobro.csv", "r");

  if (file_pointer == NULL) {
    printf("Erro lendo arquivo de (out) teste: %s\n", test_file_path);
    exit(1);
  }

  int i = 0;
  while (fgets(buffer, 256, file_pointer)) {
    outputs[i] = strdup(get_output_from_csv_line(buffer));
    i += 1;
  }

  fclose(file_pointer);

  return i;
}

void find_csv(char* dir, char* path) {
  char* files[256];
  char absolute[256];
  realpath(dir, absolute);
  char* d = dirname(absolute);
  strcat(path, d);
  strcat(path, "/");

  int n = get_dir_files(d, files);

  for (int i = 0; i < n; i++) {
    char* f = files[i];
    if (strcmp(get_file_extension(f), "csv") == 0) {
      strcat(path, f);
    }
  }
}
