CC=gcc

all: ll ht

ll: examples/ll.c linkedlist.h
	$(CC) examples/ll.c linkedlist.h -o examples/ll

ht: examples/ht.c linkedlist.h hashtable.h
	$(CC) examples/ht.c linkedlist.h hashtable.h -o examples/ht

.PHONY: clean

clean:
	rm -rf examples/ll
	rm -rf examples/ht
