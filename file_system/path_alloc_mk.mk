CC=gcc
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=path_alloc_text.c path_alloc.c myerr.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=path_alloc.out

all:$(SOURCES) $(EXECUTABLE)

$(EXECUTABLE):$(OBJECTS)
	$(CC) $(LDFLAGS) $(CFLAGS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm $(OBJECTS) $(EXECUTABLE)

