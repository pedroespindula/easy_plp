#include <stdio.h>
#include <string.h>
#include <curl/curl.h>

char* dl_exercise(char* exercise_id, char* dest_dir){
	
	char* urlExercicios = "https://raw.githubusercontent.com/pedroespindula/easy_plp/master/exercicios/";
	char* urlCompleta;

	urlCompleta = malloc(strlen(urlExercicios)+strlen(exercise_id)+1);
	strcpy(urlCompleta, urlExercicios);
	strcat(urlCompleta, exercise_id);

	CURL *curl;
	FILE *fp;
	CURLcode res;
	
	curl = curl_easy_init();
	if (curl) {
       	fp = fopen(dest_dir,"wb");
       	curl_easy_setopt(curl, CURLOPT_URL, urlCompleta);
       	curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
       	res = curl_easy_perform(curl);
       	curl_easy_cleanup(curl);
       	fclose(fp);
 	}
};

int main(){
	dl_exercise("dobro.csv","../exercicios/teste1.csv");
	return 0;
}

