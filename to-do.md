## TO-DO

- Completar arvore.h e implementar em arvore.c:
    - struct Node;
        - possui campos: string palavra, Node* esquerda, Node* direita, e int linha;
    - void addNo(Node* no);
    - int buscaArvore(string palavra);

- Completar lista.h e implementar em lista.c:
    - struct Item;
        - possui campos: string palavra, char* proximo, char* primeiro;
    - void addItem(Item* item);
    - int buscaLista(string palavra);

- Fazer com que a lista de linhas de dentro da lista ligada seja ela uma lista ligada também. Precisamos que seja dinâmica pois não sabemos a quantidade de vezes que uma palavra aparece.
    - int pos; struct _linha_ * proximo; 
        - Ordenar os numeros;
        - Remover duplicatas.