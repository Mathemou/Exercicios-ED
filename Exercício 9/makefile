# MAKEFILE
#gcc -g -o exect *.c

# Nome do compilador
CC = gcc

# Wildcards eh utilizado para listar os arquivos fonte no diretorio atual
FONTES = $(wildcard *.c)

# Gera a lista dos arquivos objeto usando a lista de arquivo fonte
OBJETOS = $(FONTES: .c=.o)

# Nome do arquivo executavel
EXECUTAVEL = main

# all: prog
all: $(EXECUTAVEL)

$(EXECUTAVEL): $(OBJETOS)
	$(CC) -g -o $@ $^ -lm

%.o: %.c
	$(CC) -c $(CFLAGS) $^

clean:
	rm -rf $(EXECUTAVEL)

rmproper: clean
	rm -rf $(EXECUTAVEL)

run: $(EXECUTAVEL)
	./$(EXECUTAVEL)

valgrind: $(EXECUTAVEL)
	valgrind ./$(EXECUTAVEL)