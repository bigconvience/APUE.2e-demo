CC=gcc
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=path_alloc_test.c path_alloc.c myerr.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=path_alloc_test.out

all:$(SOURCES) $(EXECUTABLE)

$(EXECUTABLE):$(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@
