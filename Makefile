CC = gcc
CFLAGS = -Wall
foo = $1

all: $(foo)

lin:
	$(CC) $(CFLAGS) src/main.c src/arvore.c src/lista.c -o indexador

win:
	$(CC) $(CFLAGS) src/main.c src/arvore.c src/lista.c src/windows.c -o indexador