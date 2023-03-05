CC=gcc

ll: examples/ll.c linkedlist/linkedlist.c
	$(CC) examples/ll.c linkedlist/linkedlist.c -o examples/ll

.PHONY: clean

clean:
	rm -rf examples/ll
