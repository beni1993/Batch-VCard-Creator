# Makefile
# Author: Benjamin Hedert
name=bvcard-creator
Programm: main.o specials.o
	gcc main.o specials.o -o $(name)
main.o: main.c
	gcc -c main.c -o main.o
specials.o: specials.c specials.h
	gcc -c specials.c -o specials.o
clear:
	rm *.o
test:
	gcc main.c specials.c -D TEST -o $(name)
