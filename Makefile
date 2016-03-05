CC = gcc
SOURCES = $(wildcard src/*.c)

# Options needed for compiling or linking
MYSQL_I = `mysql_config --cflags`
MYSQL_L = `mysql_config --libs`

client: $(SOURCES)
	@mkdir -p bin
	$(CC) -o bin/client $(SOURCES) -O2 -Wall -Wextra -std=c99 $(MYSQL_I) $(MYSQL_L)
