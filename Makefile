CC     = gcc
CFLAGS = -g -O2 -Wall -Wextra -pedantic -std=c99

SOURCES = $(wildcard src/*.c)

# Options needed for compiling or linking
MYSQL_I = `mysql_config --cflags`
MYSQL_L = `mysql_config --libs`

client: $(SOURCES)
	@mkdir -p bin
	$(CC) $(CFLAGS) -o bin/client $(SOURCES) $(MYSQL_I) $(MYSQL_L)
