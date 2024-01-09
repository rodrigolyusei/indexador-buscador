#ifndef LISTA_H
#define LISTA_H

typedef struct node {

	char * palavra;
    int * linhas;
    int qntd;
	struct node * proximo;

} No;

typedef struct {
	
	No * primeiro;

} Lista;

Lista * cria_lista();
No * busca(Lista * lista, char * plvr);
int insere(Lista * lista, char * plvr);

#endif