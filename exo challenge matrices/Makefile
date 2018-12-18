CC = gcc
CCFLAGS = -Wall

all: main

algebre.o : algebre.h algebre.c
	$(CC) $(CCFLAGS) -c algebre.c

main.o : main.c
	$(CC) $(CCFLAGS) -c main.c

main : main.o algebre.o
	$(CC) $(CCFLAGS) -o main main.o algebre.o

clear :
	rm *.o ; rm main
