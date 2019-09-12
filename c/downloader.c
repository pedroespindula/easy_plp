#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

char* dl_exercise(char* exercise_id, char* dest_dir){
	
	char* urlExercicios = "https://raw.githubusercontent.com/pedroespindula/easy_plp/master/exercicios/";
	char* urlCompleta;
    char* extensao = ".csv";

	urlCompleta = malloc(strlen(urlExercicios)+strlen(exercise_id)+strlen(extensao) + 1);
	strcpy(urlCompleta, urlExercicios);
	strcat(urlCompleta, exercise_id);
	strcat(urlCompleta, extensao);

    char* path_final = malloc(strlen(dest_dir) + strlen(exercise_id) + strlen(extensao) + 1);

    strcpy(path_final, dest_dir);
    strcat(path_final, exercise_id);
    strcat(path_final, extensao);

	CURL *curl;
	FILE *fp;
	CURLcode res;
	
	curl = curl_easy_init();
	if (curl) {
       	fp = fopen(path_final,"wb");
       	curl_easy_setopt(curl, CURLOPT_URL, urlCompleta);
       	curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
       	res = curl_easy_perform(curl);
       	curl_easy_cleanup(curl);
       	fclose(fp);
 	}

    return path_final;
};

