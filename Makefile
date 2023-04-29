CC = gcc
CFLAGS = -Wall -Werror -std=c99 -I.

LIB_SOURCES = linked_list.c
LIB_OBJECTS = $(LIB_SOURCES:.c=.o)
LIBRARY = liblinkedlist.a

TEST_SOURCES = test_linked_list.c
TEST_OBJECTS = $(TEST_SOURCES:.c=.o)
TEST_PROGRAM = test_linked_list

all: $(LIBRARY) $(TEST_PROGRAM)

$(LIBRARY): $(LIB_OBJECTS)
	ar rcs $(LIBRARY) $(LIB_OBJECTS)

$(TEST_PROGRAM): $(TEST_OBJECTS) $(LIBRARY)
	$(CC) -o $(TEST_PROGRAM) $(TEST_OBJECTS) -L. -llinkedlist

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(LIBRARY) $(LIB_OBJECTS) $(TEST_PROGRAM) $(TEST_OBJECTS)

run: $(TEST_PROGRAM)
	./$(TEST_PROGRAM)

