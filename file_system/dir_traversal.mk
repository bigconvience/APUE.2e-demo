CC=gcc
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=dir_traversal.c path_alloc.c myerr.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=dir_traversal.out

all:$(SOURCES) $(EXECUTABLE)

$(EXECUTABLE):$(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@
	
clean:
	rm $(OBJECTS) $(EXECUTABLE)
