all: main.c a.c
	gcc a.c -c
	gcc main.c -c
	gcc a.o main.o -o main


run: main
	./main