all : programa

programa: main funciones
	gcc main.o funcionesCC.o -o parcial2

main: main.c funcionesCC.h
	gcc -c main.c

funciones: funcionesCC.c funcionesCC.h
	gcc -c funcionesCC.c
	