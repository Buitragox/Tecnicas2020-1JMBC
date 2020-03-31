all : programa

programa: main funciones
	gcc main.o funciones.o -o TallerGrupal

main: main.c funciones.h
	gcc -c main.c

funciones: funciones.c funciones.h
	gcc -c funciones.c
	