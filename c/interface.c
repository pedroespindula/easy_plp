#include <string.h>
// CONSTANT MESSAGES
char* get_msg_welcome(void) {
    char* msg = 
        "[1] Testar diretorio atual\n"
        "[2] Baixar exercício\n"
        "[3] Configurações\n"
        "[4] Ajuda\n"
        "[5] Sair";

    return msg;
};

char* get_msg_help(void) {
	char* msg =
		"Opção 1 - Testar diretorio atual: "
		"Testa o diretorio atual exibindo o nome do exercicio, o seu ID, o arquivo testado, a linguagem do arquivo e o resultado dos testes\n"
		"CLI: easy_plp <Caminho do diretório a ser testado>\n"
		"\nOpção 2 - Baixar exercício: "
		"Baixa o exercício a partir do ID\n"
		"CLI (Por parâmetro): easy_plp download <ID do exercício>\n"
		"CLI (Por flag): easy_plp -d <ID do exercício>\n"
		"\nOpção 3 - Configurações: "
		"Define configurações do usuario (Matrícula, nome e local dos exercícios)\n"
		"CLI (Por parâmetro): easy_plp config <Nome do usuario> <Matricula do usuario>\n"
		"CLI (Por flag): easy_plp -c <Nome do usuario> <Matricula do usuario>\n"
		"\nOpção 4 - Ajuda: "
		"Mostra os modos de execução, suas configurações e parametros\n"
		"\nOpção 5 - Sair: "
		"Para a execução do programa";

	return msg;
}

char* get_msg_exit(void) {
	char* msg =
		"Obrigado por utilizar a nossa ferramenta!";
	
	return msg;
};

// HEADERS
char* get_header_easy_plp(void) {
	char* msg =
		"EASY_PLP";

	return msg;
};

char* get_header_exercise_info(void) {
	char* msg = 
		"- Informações do exercício:";

	return msg;
};

char* get_header_exercise_results(void) {
	char* msg =
		"- Execução dos testes";

	return msg;
};

char* get_header_exercise_download(void) {
	char* msg =
		"- Baixando o exercicio:";

	return msg;
}

// FORMATED MESSAGES
char* get_fmsg_exercise_info(void) {
	char* msg = 
		"Id: %s";

    return msg;
};

char* get_fmsg_exercise_results(void) {
	char* msg = 
		"Arquivo: %s\n"
		"Linguagem usada: %s\n"
		"Resultado dos testes: %s";

    return msg;
};

char* get_fmsg_exercise_download(void) {
	char* msg = 
		"ID do exercício: %s";

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
		"Digite o seu nome: ";

	return msg;
};
char* get_prompt_config_exercises_path(void) {
	char* msg =
		"Digite a sua matricula: ";
	
	return msg;
};

