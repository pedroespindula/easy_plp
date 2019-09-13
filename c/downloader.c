#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

int dl_exercise(char* exercise_id, char* dest_dir){
	
	char* urlExercicios = "https://raw.githubusercontent.com/pedroespindula/easy_plp/master/exercicios/";
	char* urlCompleta;
	char* extensao = ".csv";

	urlCompleta = malloc(strlen(urlExercicios)+strlen(exercise_id)+strlen(extensao) + 1);
	strcpy(urlCompleta, urlExercicios);
	strcat(urlCompleta, exercise_id);
	strcat(urlCompleta, extensao);

	char* path_final = malloc(strlen(dest_dir) + strlen(exercise_id) + strlen(extensao) + 1);
	char* mkdir_cmd = malloc(512);

	strcpy(path_final, dest_dir);
	strcat(path_final, "/");
	strcat(path_final, exercise_id);

  strcat(mkdir_cmd, "mkdir -p ");
  strcat(mkdir_cmd, path_final);

  system(mkdir_cmd);

	strcat(path_final, "/");
	strcat(path_final, exercise_id);
	strcat(path_final, extensao);

	CURL *curl;
	FILE *fp;
	CURLcode res;
  long response_code;
	
	curl = curl_easy_init();
	if (curl) {
    printf("Baixando exercicio para: %s\n", path_final);
		fp = fopen(path_final,"wb");
		curl_easy_setopt(curl, CURLOPT_URL, urlCompleta);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
		res = curl_easy_perform(curl);
    if (res == CURLE_OK) {
      curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
    }
		curl_easy_cleanup(curl);
		fclose(fp);

    if (response_code == 404) {
      remove(path_final);
    }
	}

	return response_code != 404;
};

