/*
    Hash table example
    Zack McKevitt

    Reads large file of random words.
    Stores number of occurrences of each unique word
    and writes this data to a file.

    TODO:
    All of it lol
*/
#include <stdio.h>
#include <stdlib.h>
#include "../hashtable.h"

#define HT_SIZE 16

int main() {
    struct ht hashtable = ht_create(HT_SIZE);
    ht_destroy(&hashtable);
    return 0;
}
