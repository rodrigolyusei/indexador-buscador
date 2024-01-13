#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "lista.h"
#include "arvore.h"
#include "windows.h"

#define TAMANHO 1000

int main(int argc, char ** argv){

	FILE* in;
	Lista* lista;
	Arvore* arvore;
    clock_t start_time, end_time;
    double cpu_time_used;
	char* linha;
	char* copia_ponteiro_linha;
	char* quebra_de_linha;
	char* palavra;
	char** linhas;
	int i;
	int contador_linha;
	int tipo;

	// Se for passado apenas o arquivo de texto
	// Exemplo: .\EP data\texto.txt
	if(argc == 2){

		in = fopen(argv[1], "r");

		printf(">>>>> Carregando arquivo...\n");

		contador_linha = 0;
 		linha = (char *) malloc((TAMANHO + 1) * sizeof(char));

		while(in && fgets(linha, TAMANHO, in)){
			
			if( (quebra_de_linha = strrchr(linha, '\n')) ) *quebra_de_linha = 0;

			printf("linha %03d: \"%s\"\n", contador_linha + 1, linha);

			// fazemos uma copia do endereço que corresponde ao array de chars 
			// usado para armazenar cada linha lida do arquivo pois a função 'strsep' 
			// modifica o endereço do ponteiro a cada chamada feita a esta função (e 
			// não queremos que 'linha' deixe de apontar para o inicio do array).

			copia_ponteiro_linha = linha;

			while( (palavra = strsep(&copia_ponteiro_linha, " ,.-/")) ){

				// antes de guardar a palavra em algum tipo de estrutura usada
				// para implementar o índice, será necessário fazer uma copia
				// da mesma, uma vez que o ponteiro 'palavra' aponta para uma 
				// substring dentro da string 'linha', e a cada nova linha lida
				// o conteúdo da linha anterior é sobreescrito.
				
				for(int i = 0; i < strlen(palavra); i++){
					if (!isalpha(palavra[i])) palavra[i] = '\0';
				}
				if((*palavra == '\0')){
					continue;
				}

				printf("\t   '%s'\n", palavra);
			}

			contador_linha++;
		}

		printf(">>>>> Arquivo carregado!\n");
		printf("linhas: %i", contador_linha);
		return 0;
	}

	// Se for passado o arquivo de texto e o tipo da busca
	// Exemplo: .\EP data\texto.txt lista
	if(argc == 3){
		// Comeca a contagem do tempo de execucao
		start_time = clock();

		// Define o tipo de indexador a ser criado
		tipo = 0;
		if(strcmp(argv[2], "lista") == 0){
				tipo = 1;
				lista = cria_lista();
				
		}else if(strcmp(argv[2], "arvore") == 0){
				tipo = 2;
				arvore = cria_arvore();
		}

		// Abre, armazena o arquivo de texto do parametro e conta as linhas
		in = fopen(argv[1], "r");
		contador_linha = 0;
		linha = (char *) malloc((TAMANHO + 1) * sizeof(char));
		while(in && fgets(linha, TAMANHO, in)){
			contador_linha++;
		}
		fclose(in);

		// Aloca o array das linhas e o string para linha
		linhas = (char**) malloc(sizeof(char*) * contador_linha);

		// Abre novamente o arquivo e realiza a indexacao
		in = fopen(argv[1], "r");
		contador_linha = 0;
		while(in && fgets(linha, TAMANHO, in)){
			// Substitui as quebras de linhas por nulo
			if( (quebra_de_linha = strrchr(linha, '\n')) ) *quebra_de_linha = 0;

			// Salva cada linha no array das linhas
			linhas[contador_linha] = strdup(linha);
			
			// Para cada linha salva as palavras
			copia_ponteiro_linha = linha;
			while( (palavra = strsep(&copia_ponteiro_linha, " ,.-/")) ){
				// Elimina caracteres especiais
				for(int i = 0; i < strlen(palavra); i++){
					if(!isalpha(palavra[i])) palavra[i] = '\0';
				}
				if((*palavra == '\0')){
					continue;
				}

				// Insere de acordo com o tipo de indexacao escolhida
				if(tipo == 1){
					insereL(lista, palavra, contador_linha+1);
				}else if(tipo == 2){
					if(arvore->raiz == NULL){
						LinhaA* novalin = (LinhaA*) malloc(sizeof(LinhaA));
						novalin->pos = contador_linha+1;
						novalin->proximo = NULL;
						NoA* novono = (NoA*) malloc(sizeof(NoA));
						novono->palavra = (char*) malloc(strlen(palavra) + 1);
						strcpy(novono->palavra, palavra);
						novono->linha = novalin;
						novono->esquerda = NULL;
						novono->direita = NULL;
						novono->qntd = 1;

						arvore->raiz = novono;
					}else{
						insereA(arvore->raiz, palavra, contador_linha+1);
					}
				}
			}
			contador_linha++;
		}

		// Termina a contagem do tempo de execucao
		end_time = clock();
		cpu_time_used = ((double)(end_time - start_time)) * 1000.0 / CLOCKS_PER_SEC;

		// Apresentacao das informacoes
		printf("Tipo de indice: '%s'\n", argv[2]);
		printf("Arquivo texto: '%s'\n", argv[1]);
		printf("Numero de linhas no arquivo: %i\n", contador_linha);
		printf("Tempo para carregar o arquivo e construir o indice: %05.0f ms\n", cpu_time_used);

		// Para caso de teste e verificacao
		// imprime_lista(lista);
		// imprime_arvore(arvore);

		// Busca
		char comando[64];
		char palavraBuscada[58];
		char verifica[6] = "busca ";
		int buscaCorreta;
		NoL* auxL;
		NoA* auxA;

		while(1){
			// Comeca com palavrabuscada anulada
			for(i = 0; i < 58; i++){
				palavraBuscada[i] = '\0';
			}

			// Leitura da entrada
			printf("> ");
			fgets(comando, 64, stdin);

			// Finalizar programa
			if(!strcmp(comando, "fim\n")) return 0;

			// Verifica se "busca " foi digitada
			buscaCorreta = 1;
			for(i = 0; i < 6; i++){
				if(verifica[i] != comando[i]){
					buscaCorreta = 0;
					break;
				}
			}
			if(!buscaCorreta){
				printf("Opcao invalida!\n");
				continue;
			}

			// Verifica se foi inserido uma palavra
			if(!isalpha(comando[6]) || !isalnum(comando[6])){
				printf("Opcao invalida!\n");
				continue;
			}

			// Comeca a contagem para busca
			start_time = clock();

			// Registra a palavra a ser buscado
			for(i = 6; !(comando[i] == ' ' || comando[i] == '\0'); i++){
			 	palavraBuscada[i-6] = comando[i];
			}
			palavraBuscada[strlen(palavraBuscada)-1] = '\0';

			// Busca a palavra na estrutura e imprime o resultado
			if(tipo == 1){
				auxL = buscaL(lista, palavraBuscada);
				if(auxL){
					printf("Existe(m) %i ocorrencia(s) da palavra '%s' na(s) seguinte(s) linha(s):\n", auxL->qntd, palavraBuscada);
					imprime_linhasL(auxL->linha, linhas);
				}
				else{
					printf("Palavra '%s' nao encontrada.\n", palavraBuscada);
				}
			}else if(tipo == 2){
				auxA = buscaA(arvore->raiz, palavraBuscada);
				if(auxA){
					printf("Existe(m) %i ocorrencia(s) da palavra '%s' na(s) seguinte(s) linha(s):\n", auxA->qntd, palavraBuscada);
					imprime_linhasA(auxA->linha, linhas);
				}
				else{
					printf("Palavra '%s' nao encontrada.\n", palavraBuscada);
				}
			}
			
			// Termina a contagem para busca e imprime
			end_time = clock();
			cpu_time_used = ((double)(end_time - start_time)) * 1000.0 / CLOCKS_PER_SEC;
			printf("Tempo de busca: %05.0f ms\n", cpu_time_used);
		}

		return 0;
	}
	return 1;
}