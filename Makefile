CC = gcc
CFLAGS = -Wall

all:
	$(CC) $(CFLAGS) src/main.c src/arvore.c src/lista.c src/windows.c -o indexador

exec:
	./indexador

clean:
	rm -rf indexador
	rm -rf *.exe
	rm -rf *.o