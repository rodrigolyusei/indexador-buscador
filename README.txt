## Instruções para execução

-Para compilar, use os comandos:
gcc -c indexador.c -o indexador.o
gcc -c arvore.c -o arvore.o
gcc -c lista.c -o lista.o
gcc indexador.o arvore.o lista.o -o executavel

-Para executar, use um dos três comandos:
.\executavel.exe data/teste.txt
.\executavel.exe data/teste.txt lista
.\executavel.exe data/teste.txt arvore

Os arquivos de texto podem ser adicionados na pasta "data".
Para usar no programa basta substituir o trecho "teste" pelo nome do arquivo.
A função de busca é feito adicionando no comando o nome "lista" ou "arvore".




## Intruções para execução no windows

Há função, como no caso do "strsep", que não é padrão na biblioteca string.h do windows.
Nesse caso, colocamos uma implementação no arquivo windows.c e deve ser compilado como:
gcc -c indexador.c -o indexador.o
gcc -c arvore.c -o arvore.o
gcc -c lista.c -o lista.o
gcc -c windows.c -o windows.o
gcc indexador.o arvore.o lista.o windows.o -o executavel

E executado da mesma forma do caso anterior.