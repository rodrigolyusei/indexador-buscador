#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "lista.h"
#include "arvore.h"
#include "windows.h"

#define TAMANHO 1000

int main(int argc, char ** argv){

	FILE * in;
	char * linha;
	char * copia_ponteiro_linha;
	char * quebra_de_linha;
	char * palavra;	
	int contador_linha, i;
	int posicao_na_lista;

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
				for (int i = 0; i < strlen(palavra); i++){
					if (!isalpha(palavra[i])) palavra[i] = '\0';
				}
				if ((*palavra == '\0')) {
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

	//Quando for passado o arquivo do texto e o tipo da busca
	//Exemplo: .\EP texto.txt lista
	if(argc == 3){
		char c;
		in = fopen(argv[1], "r");

		contador_linha = 0;
 		linha = (char *) malloc((TAMANHO + 1) * sizeof(char));

		while(in && fgets(linha, TAMANHO, in)){
			contador_linha++;
		}

		/*
		while(in && fgets(linha, TAMANHO, in)){
			
			if( (quebra_de_linha = strrchr(linha, '\n')) ) *quebra_de_linha = 0;

			// ADICIONAR OS PRINTS NA POSIÇÃO posicao_na_lista!!!!!!!!
			printf("linha %03d: '%s'\n", posicao_na_lista + 1, linha);

			// TO DO: usar esse while para guardar as linhas

			copia_ponteiro_linha = linha;

			
			while( (palavra = strsep(&copia_ponteiro_linha, " ,.-")) ){

				for (int i = 0; i < strlen(palavra); i++){
					if (!isalpha(palavra[i])) palavra[i] = '\0';
				}
				if ((*palavra == '\0')) {
					continue;
				}

				// usar esse print para guardar as palavras na lista de palavras;
				printf("\t   '%s'\n", palavra);
			}

			contador_linha++;
		}

			posicao_na_lista++;
		}*/

		//Apresentacao das informacoes
		printf("Tipo de indice: '%s'\n", argv[2]);
		printf("Arquivo texto: '%s'\n", argv[1]);
		printf("Numero de linhas no arquivo: %i\n", contador_linha);
		printf("Tempo para carregar o arquivo e construir o indice: %5i\n", contador_linha);

		//Busca
		char comando[64];
		char verifica[6] = "busca ";
		int buscaCorreta;
		char* palavraBuscada = (char*) malloc(sizeof(char) * 58);



		while(1){
			for (i = 0; i < 58; i++){
				palavraBuscada[i] = '\0';
			}
			printf("> ");
			fgets(comando, 64, stdin);
			if(!strcmp(comando, "fim\n")) return 0;

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

			if(!isalpha(comando[6]) || !isalnum(comando[6])){
				printf("Opcao invalida\n");
				continue;
			}
			for(i = 6; !(comando[i] == ' ' || comando[i] == '\0'); i++){
			 	palavraBuscada[i-6] = comando[i];
			}
			printf("%s", palavraBuscada);

		}

		return 0;
	}

	return 1;
}