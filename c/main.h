#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// FUNÇÕES DO DOWNLOADER
// downloader.c
char* dl_exercise(char* exercise_id, char* dest_dir);

// FUNÇÕES DO RUNNER
// runner.c
char* compile_file_c(char* path);
char* compile_file_java(char* path);
char* compile_file_haskell(char* path);
char* run_dir(char* dir);
void run_file(char* file, char* result);

// FUNÇÕES DE CONFIGURAÇÃO
// config.c
char* get_path(char* path);
char* get_config_exercises_path(void);
char* get_config_username(void);
char* get_config_registry(void);

char* set_config(char* new_path, char* new_username, char* new_registry);

// FUNÇÕES DE INTERFACE
// interface.c
char* get_msg_welcome(void);
char* get_msg_help(void);
char* get_msg_exit(void);
char* get_msg_download_success(void);
char* get_msg_download_failure(void);
char* get_msg_config_save_last(void);
char* get_msg_invalid_command(void);

char* get_header_easy_plp(void);
char* get_header_exercise_info(void);
char* get_header_exercise_results(void);
char* get_header_exercise_download(void);

char* get_fmsg_exercise_info(void);
char* get_fmsg_exercise_results(void);
char* get_fmsg_exercise_download(void);

char* get_prompt_select_option(void);
char* get_prompt_download_exercise(void);
char* get_prompt_config_name(void);
char* get_prompt_config_registry(void);
char* get_prompt_config_exercises_path(void);

// FUNÇÕES UTIL
// util.c
char* get_file_name(char* path);
char* get_file_extension(char* path);
int count_files(char* path);
int get_dir_files(char* path, char *result[]);
int read_test_input(char* test_file_path, char* inputs[]);
int read_test_output(char* test_file_path, char* outputs[]);
void find_csv(char* dir, char* path);
