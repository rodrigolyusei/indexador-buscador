# Indexador e Buscador de Palavras
Programa desenvolvido com o objetivo de estudar estrutura de dados e comparar seus desempenhos, considerando a implementação nas diferentes linguagens. Tem como funcionamento receber um arquivo de texto e armazenar em uma lista ligada ou uma árvore binária. Depois recebe uma palavra da entrada a ser buscada na estrutura e apresenta o resultado de ocorrências junto com o tempo de execução da busca.

![Go](https://img.shields.io/badge/language-c-lightblue)
![JavaScript](https://img.shields.io/badge/language-java-red)
![Python](https://img.shields.io/badge/language-python-blue)

## Compilar pelo compilador

### Compilação em C

```
cd src/c/
gcc -Wall main.c arvore.c lista.c extra.c -o ../../indexador
cd ../../
```
### Compilação em Java

```
cd src/java/
javac Indexador.java -d ../../
cd ../../
```

## Compilar pelo Makefile

Caso tenha o Makefile, a compilação é mais simples, basta indicar se está no Linux ou Windows.\
É possível instalar o Makefile no Windows pelo gerenciador de pacotes ou coleção de ferramentas.\
E para a execução, basta seguir pelos mesmos comandos acima.

```
make lin
```
```
make win
```

## Execução

Adicione os arquivos de texto a ser usado em `/data` e substitua o `teste`.\
Indique a estrutura de dados usada no final, sendo `lista` ou `arvore`.\
Depois use o comando `busca` seguido de uma palavra para ser procurada no texto.\
Para finalizar o programa digite `fim`.\
Caso não indique a estrutura, o programa irá apenas imprimir as palavras do texto.

```
./indexador.exe data/teste.txt
```
```
./indexador.exe data/teste.txt lista
```
```
./indexador.exe data/teste.txt arvore
```
