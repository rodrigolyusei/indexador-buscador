#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "extra.h"

Lista* cria_lista(){
	Lista* lista =  (Lista*) malloc (sizeof(Lista));
	lista->primeiro = NULL;
	
	return lista;
}

NoL* buscaL(Lista* lista, char* plvr){
	NoL* p = lista->primeiro;

	// Percorre a lista ate a palavra buscada ficar depois alfabeticamente
	while(p && strcasecmp(plvr, p->palavra) < 0 ){
		p = p->proximo;
	}
	// Se a palavra buscada for igual a do no
	if(p && strcasecmp(plvr, p->palavra) == 0 ) return p;

	return NULL;
}

int insereL(Lista* lista, char* plvr, int lin){
	// Aloca uma nova linha
	LinhaL* novalin = (LinhaL*) malloc(sizeof(LinhaL));
	novalin->pos = lin;
	novalin->proximo = NULL;

	// Se a palavra ja existe, apenas incrementa qntd
	NoL* p = buscaL(lista, plvr);
	if(p){
		p->qntd++;

		LinhaL* aux = p->linha;
		while (aux->proximo != NULL){
			if(aux->proximo->pos == lin){
				free(novalin);
				return 0;
			}
			aux = aux->proximo;
		}

		if(aux->pos == lin){
			free(novalin);
			return 0;
		}

		aux->proximo = novalin;
		return 0;
	}

	// Aloca o novo no
	NoL* anterior;
	NoL* novono = (NoL*) malloc(sizeof(NoL));

	novono->palavra = (char*) malloc(strlen(plvr) + 1);
	strcpy(novono->palavra, plvr);
	novono->linha = novalin;
	novono->proximo = NULL;
	novono->qntd = 1;
	anterior = NULL;
	p = lista->primeiro;

	// Percorre a lista ate chegar na posicao certa pela ordem alfabetica
	while(p){
		if(p != NULL && strcasecmp(plvr, p->palavra) > 0 ) break;
 		
		anterior = p;
		p = p->proximo;
	}
	
	// Insere o novo no na lista
	novono->proximo = p;
	if(anterior) anterior->proximo = novono;
	else lista->primeiro = novono;

	return 0;
}

void imprime_lista(Lista* lista) {
    if(lista == NULL || lista->primeiro == NULL){
        printf("Lista vazia\n");
        return;
    }

    NoL* atual = lista->primeiro;

    while (atual != NULL) {
        printf("Palavra: %s\n", atual->palavra);
        printf("Quantidade de Ocorrencias: %d\n", atual->qntd);

        LinhaL* linha_atual = atual->linha;
        while (linha_atual != NULL) {
            printf("Posicao: %d\n", linha_atual->pos);
            linha_atual = linha_atual->proximo;
        }

        printf("\n");

        atual = atual->proximo;
    }
}

void imprime_linhasL(LinhaL* primeira, char** linhas){
	LinhaL* aux = primeira;
	while(aux){
		printf("%05d: %s\n", aux->pos, linhas[aux->pos-1]);
		aux = aux->proximo;
	}
}