#include <stdio.h>

// FUNÇÕES DO DOWNLOADER
// downloader.c
char* dl_exercise(char* exercise_id, char* dest_dir);

// FUNÇÕES DO RUNNER
// runner.c
char* run_dir(char* dir);
char* run_file(char* file);

// FUNÇÕES DE CONFIGURAÇÃO
// config.c
char* get_config_exercises_path(void);
char* get_config_username(void);
char* get_config_registry(void);

char* set_config_exercises_path(char* new_path);
char* set_config_username(char* new_name);
char* set_config_registry(char* new_registry);

// FUNÇÕES DE INTERFACE
// interface.c
char* get_msg_welcome(void);
char* get_msg_help(void);
char* get_msg_exit(void);

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
char* get_dir_files(char* path);
