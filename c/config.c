#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define PATH_LINE 1
#define USERNAME_LINE 2
#define REGISTRY_LINE 3
#define CONFIG_CHAR_MAX 140

char* save_dir = "teste";

char* get_n_line(int n){
	char* result = malloc(CONFIG_CHAR_MAX * sizeof(char));
	FILE *file_config;
	file_config = fopen(save_dir,"r");

	int cont = 1;
	while(fgets(result, CONFIG_CHAR_MAX, file_config) != NULL && cont < n) {
		cont++;
    }
	
	fclose(file_config);
	return result;
};

char* get_config_exercises_path(void){
	return get_n_line(PATH_LINE);
};

char* get_config_exercises_username(void){
	return get_n_line(USERNAME_LINE);
};

char* get_config_exercises_registry(void){
	return get_n_line(REGISTRY_LINE);
};


void write_on_config(char* path, char* username, char* registry){
	char* text_complete = malloc(strlen(path)+strlen(username)+strlen(registry)+5);
	strcpy(text_complete, path);
	strcat(text_complete, "\n");
	strcat(text_complete, username);
	strcat(text_complete, "\n");
	strcat(text_complete, registry);	


	FILE *file_config;	
	file_config = fopen(save_dir,"w");
	fwrite(text_complete, 1, strlen(text_complete),file_config);	
	fclose(file_config);
}

void set_config(char* path, char* username, char* registry){
	if (strcmp(path, "---") == 0) {
		path = get_config_exercises_path();	
	}

	write_on_config(path, username, registry);
};
