#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "windows.h"

Lista* cria_lista(){
	Lista* lista =  (Lista*) malloc (sizeof(Lista));
	lista->primeiro = NULL;
	
	return lista;
}

No* busca(Lista* lista, char* plvr){
	No* p = lista->primeiro;

	while(p && strcasecmp(plvr, p->palavra) < 0 ){
		p = p->proximo;
        
	}
	if(p && strcasecmp(plvr, p->palavra) == 0 ) return p;

	return NULL;
}

int insere(Lista* lista, char* plvr, int lin){
	//Se a palavra ja existe, apenas incrementa qntd
	No* p = busca(lista, plvr);

	Linha* result = (Linha*) malloc(sizeof(Linha));
	result->pos = lin;
	result->proximo = NULL;

	if(p != NULL) {
		p->qntd++;

		Linha* aux = p->linha;
		while (aux->proximo != NULL){
			if (aux->proximo->pos == lin){
				free(result);
				return 0;
			}
			aux = aux->proximo;
		}

		aux->proximo = result;
		return 0;
	}

	//Aloca o novo no
	No* anterior;
	No* novo = (No*) malloc(sizeof(No));
	
	//novo->palavra = plvr;
	novo->palavra = (char*)malloc(strlen(plvr) + 1);
	strcpy(novo->palavra, plvr);

	novo->linha = result;
	novo->proximo = NULL;
	anterior = NULL;
	p = lista->primeiro;

	//Percorre a lista ate chegar na posicao certa
	//de acordo com a ordem alfabetica (ASCII)
	while(p){
		if(p != NULL & strcasecmp(plvr, p->palavra) > 0 ) break;
 		
		anterior = p;
		p = p->proximo;
	}
	
	//Insere o novo no na lista
	novo->proximo = p;
	if(anterior) anterior->proximo = novo;
	else lista->primeiro = novo;
	novo->qntd++;

    return 0;
}

void imprime_lista(Lista* lista) {
    if (lista == NULL || lista->primeiro == NULL) {
        printf("Lista vazia\n");
        return;
    }

    No* atual = lista->primeiro;

    while (atual != NULL) {
        printf("Palavra: %s\n", atual->palavra);
        printf("Quantidade de Ocorrencias: %d\n", atual->qntd);

        Linha* linha_atual = atual->linha;
        while (linha_atual != NULL) {
            printf("Posicao: %d\n", linha_atual->pos);
            linha_atual = linha_atual->proximo;
        }

        printf("\n");

        atual = atual->proximo;
    }
}
void imprime_linhas(Linha* primeira, char** linhas){
	Linha* aux = primeira;
	while(aux != NULL){
		printf("%04d : %s\n", aux->pos, linhas[aux->pos-1]);
		aux = aux->proximo;
	}
}