//#ifndef LISTA_H
//#define ARVORE_H

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
int insere(Lista * lista, char * plvr);
No * busca(Lista * lista, char * plvr);