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

    clock_t start_time, end_time;
    double cpu_time_used;
	Lista* lista;
	Arvore* arvore;
	FILE* in;
	char* linha;
	char* copia_ponteiro_linha;
	char* quebra_de_linha;
	char* palavra;	
	int i;
	int contador_linha;
	int tipo;
	//Quando for passado apenas o arquivo do texto
	//Exemplo: .\EP texto.txt
	if(argc == 2) {

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

			while( (palavra = strsep(&copia_ponteiro_linha, " ,.-")) ){

				// antes de guardar a palavra em algum tipo de estrutura usada
				// para implementar o índice, será necessário fazer uma copia
				// da mesma, uma vez que o ponteiro 'palavra' aponta para uma 
				// substring dentro da string 'linha', e a cada nova linha lida
				// o conteúdo da linha anterior é sobreescrito.

				printf("\t   '%s'\n", palavra);
			}

			contador_linha++;
		}

		printf(">>>>> Arquivo carregado!\n");
		printf("linhas: %i", contador_linha);
		return 0;
	}

	//Quando for passado o arquivo do texto e o tipo da busca
	//Exemplo: .\EP texto.txt lista
	if(argc == 3){

		start_time = clock();
		in = fopen(argv[1], "r");

		tipo = 0;
		if(strcmp(argv[2], "lista") == 0){
				tipo = 1;
				lista = cria_lista();
				
		} else if(strcmp(argv[2], "arvore") == 0){
				tipo = 2;
				arvore = cria_arvore();
			}

		contador_linha = 0;
 		linha = (char *) malloc((TAMANHO + 1) * sizeof(char));

		//Conta as linhas do arquivo e cria o array
		while(in && fgets(linha, TAMANHO, in)){
			contador_linha++;
		}
		fclose(in);


		char** linhas = (char**) malloc(sizeof(char*) * contador_linha);

		in = fopen(argv[1], "r");
		contador_linha = 0;

		//Cria a lista efetivamente
		while(in && fgets(linha, TAMANHO, in)){

		
			if( (quebra_de_linha = strrchr(linha, '\n')) ) *quebra_de_linha = 0;


			// ADICIONAR OS PRINTS NA POSIÇÃO posicao_na_lista!!!!!!!!
			linhas[contador_linha] = strdup(linha);
			
			// TO DO: usar esse while para guardar as linhas
			
			copia_ponteiro_linha = linha;
			
			while( (palavra = strsep(&copia_ponteiro_linha, " ,.-")) ){

				for (int i = 0; i < strlen(palavra); i++){
					if (!isalpha(palavra[i])) palavra[i] = '\0';
				}
				if ((*palavra == '\0')) {
					continue;
				}

				if(tipo == 1){
					printf("palavra:%s\n", palavra);
					insere(lista, palavra, contador_linha+1);
				} else if(tipo == 2){

				}
				
			}

			contador_linha++;
		}
		end_time = clock();
		cpu_time_used = ((double)(end_time - start_time)) * 1000.0 / CLOCKS_PER_SEC;
		imprime_lista(lista);
		//Apresentacao das informacoes
		printf("Tipo de indice: '%s'\n", argv[2]);
		printf("Arquivo texto: '%s'\n", argv[1]);
		printf("Numero de linhas no arquivo: %i\n", contador_linha);
		printf("Tempo para carregar o arquivo e construir o indice: %05.0f ms\n", cpu_time_used);


		//Busca
		char comando[64];
		char palavraBuscada[58];
		char verifica[6] = "busca ";
		int buscaCorreta;
		
		No* info;

		while(1){
			//Comeca com palavrabuscada nula
			for (i = 0; i < 58; i++){
				palavraBuscada[i] = '\0';
			}

			//Leitura da entrada
			printf("> ");
			fgets(comando, 64, stdin);

			//Finalizar programa
			if(!strcmp(comando, "fim\n")) return 0;

			//Verifica se "busca " foi digitada
			buscaCorreta = 1;
			for(i = 0; i < 6; i++){
				if(verifica[i] != comando[i]) {
					buscaCorreta = 0;
					break;
				}
			}
			if (!buscaCorreta){
				printf("Opcao invalida!!\n");
				continue;
			}

			//Verifica se foi inserido uma palavra
			if(!isalpha(comando[6]) || !isalnum(comando[6])){
				printf("Opcao invalida\n");
				continue;
			}

			start_time = clock();
			//Registra a palavra a ser buscado
			for(i = 6; !(comando[i] == ' ' || comando[i] == '\0'); i++){
			 	palavraBuscada[i-6] = comando[i];
			}
			//printf("%s", palavraBuscada);
			palavraBuscada[strlen(palavraBuscada)-1] = '\0';
			info = busca(lista, palavraBuscada);
			if (info != NULL){
				printf("Existem %i ocorrencias da palavra '%s' na(s) seguinte(s) linha(s):\n", info->qntd, palavraBuscada);
				imprime_linhas(info->linha, linhas);
			}
			else{
				printf("Palavra '%s' nao encontrada.\n", palavraBuscada);
			}
			end_time = clock();
			cpu_time_used = ((double)(end_time - start_time)) * 1000.0 / CLOCKS_PER_SEC;
			printf("Tempo de execucao: %.5f ms\n", cpu_time_used);
		}

		return 0;
	}

	return 1;
}