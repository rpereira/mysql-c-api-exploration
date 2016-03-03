CC=gcc
CFLAGS=-Wall -std=c99 `mysql_config --cflags --libs`

exe1: exe1.c utils.c
	$(CC) -o exe1 exe1.o utils.o
