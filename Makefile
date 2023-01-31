all: main.c lista.c
	gcc lista.c -c
	gcc main.c -c
	gcc lista.o main.o -o main


run: main
	./main