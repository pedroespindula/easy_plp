#include <stdio.h>

char* get_msg_welcome(void);
char* get_msg_help(void);
char* get_msg_exit(void);

char* get_fmsg_exercise_info(char* exercise_id);
char* get_fmsg_exercise_results(char* file_path, char* language, char* test_results);
char* get_fmsg_download_exercise(char* exercise_id);

char* get_prompt_select_option(void);
char* get_prompt_download_exercise(void);
char* get_prompt_config_name(void);
char* get_prompt_config_registry(void);
char* get_prompt_config_exercises_path(void);
