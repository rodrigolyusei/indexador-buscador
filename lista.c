#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

Lista * cria_lista(){
	Lista * lista =  (Lista *) malloc (sizeof(Lista));
	lista->primeiro = NULL;
	
	return lista;
}

No * busca(Lista * lista, char * plvr){
	int i = 0;
	No * p = lista->primeiro;

	while(p && strcasecmp(plvr, p->palavra) <= 0 ){
		p = p->proximo;
        if( strcasecmp(plvr, p->palavra) == 0 ) return p;
	}

	return NULL;
}

int insere(Lista * lista, char * plvr){
	//Se a palavra ja existe, apenas incrementa qntd
	No * p = busca(lista, plvr);
	if(p != NULL) {
		p->qntd++;
		return 0;
	}

	//Aloca o novo no
	No * anterior;
	No * novo = (No *) malloc(sizeof(No));

	novo->palavra = plvr;
	anterior = NULL;
	p = lista->primeiro;

	//Percorre a lista ate chegar na posicao certa
	//de acordo com a ordem alfabetica (ASCII)
	while(p){
		if( strcasecmp(plvr, p->palavra) > 0 ) break;
 		
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