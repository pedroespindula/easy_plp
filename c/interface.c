#include <string.h>
// CONSTANT MESSAGES
char* get_msg_welcome(void) {
    char* msg = 
        "[1] Testar diretorio atual\n"
        "[2] Baixar exercício\n"
        "[3] Configurações\n"
        "[4] Ajuda\n"
        "[5] Sair\n";

    return msg;
};

char* get_msg_help(void);
char* get_msg_exit(void) {
	char* msg =
		"Obrigado por utilizar a nossa ferramenta!";
	
	return msg;
};
char* get_msg_invalid_command(void) {
  char* msg =
    "Comando inválido! Insira um número apenas entre 1 e 5.\n";

  return msg;
}

// HEADERS
char* get_header_easy_plp(void) {
	char* msg =
    "==========================\n"
		"         EASY_PLP         \n"
    "==========================\n";

	return msg;
};

char* get_header_exercise_info(void) {
	char* msg = 
		"- Informações do exercício:\n";

	return msg;
};

char* get_header_exercise_results(void) {
	char* msg =
		"- Execução dos testes:\n";

	return msg;
};

char* get_header_exercise_download(void) {
	char* msg =
		"- Baixando o exercicio:\n";

	return msg;
}

// FORMATED MESSAGES
char* get_fmsg_exercise_info(void) {
	char* msg = 
		"Id: %s\n";

    return msg;
};

char* get_fmsg_exercise_results(void) {
	char* msg = 
		"Arquivo: %s\n"
		"Linguagem usada: %s\n"
		"Resultado dos testes: %s\n";

    return msg;
};

char* get_fmsg_exercise_download(void) {
	char* msg = 
		"ID do exercício: %s\n";

    return msg;
};

// PROMPTS
char* get_prompt_select_option(void) {
    char* msg = 
        "Selecione a opção desejada: ";

    return msg;
};
char* get_prompt_download_exercise(void) {
    char* msg = 
        "Digite o ID do exercicio a ser baixado: ";

	return msg;
};

char* get_prompt_config_name(void) {
	char* msg = 
		"Digite o seu nome: ";
	
	return msg;
};

char* get_prompt_config_registry(void) {
	char* msg = 
		"Digite a sua matricula: ";

	return msg;
};
char* get_prompt_config_exercises_path(void) {
	char* msg =
		"Digite onde os exercícios serão baixados: ";
	
	return msg;
};

