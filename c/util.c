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

char* getfield(char* line, int num)
{
    char* tok;
    for (tok = strtok(line, ","); tok && *tok; tok = strtok(NULL, ",\n")) {
        if (!--num) {
          return tok;
        }
    }
    return NULL;
}

char* get_input_from_csv_line(char* csv_line) {
  char* tmp = strdup(csv_line);
  char* ret = getfield(csv_line, 2);
  free(tmp);
  return strdup(ret);
}

char* get_output_from_csv_line(char* csv_line) {
  char* tmp = strdup(csv_line);
  char* ret = getfield(csv_line, 3);
  free(tmp);
  return strdup(ret);
}

int read_test_input(char* test_file_path, char* inputs[]) {
  char *line = NULL;
  size_t len = 0;
  ssize_t read;
  FILE *file_pointer = fopen(test_file_path, "r");

  if (file_pointer == NULL) {
    printf("Erro lendo arquivo (in) de teste: %s\n", test_file_path);
    exit(1);
  }

  int i = 0;
  while (read = getline(&line, &len, file_pointer) != -1) {
    inputs[i] = '\0';
    inputs[i] = get_input_from_csv_line(line);
    i += 1;
  }

  fclose(file_pointer);

  return i;
}

int read_test_output(char* test_file_path, char* outputs[]) {
  char *line = NULL;
  size_t len = 0;
  ssize_t read;
  FILE *file_pointer = fopen(test_file_path, "r");

  if (file_pointer == NULL) {
    printf("Erro lendo arquivo (out) de teste: %s\n", test_file_path);
    exit(1);
  }

  int i = 0;
  while (read = getline(&line, &len, file_pointer) != -1) {
    outputs[i] = '\0';
    outputs[i] = get_output_from_csv_line(line);
    i += 1;
  }

  fclose(file_pointer);

  return i;
}

void find_csv(char* dir, char* path) {
  path[0] = '\0';
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
