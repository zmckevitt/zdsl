#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

struct ht {
    size_t size;
    struct sll* table;
};

struct ht ht_create(size_t size) {
    struct ht new_ht;
    new_ht.size = size;
    new_ht.table = malloc(size * sizeof(struct sll));
    return new_ht;
};

int ht_destroy(struct ht* hashtable) {
    int status = 0;
    for(size_t i=0; i<hashtable->size; ++i) {
        status = sll_destroy(&hashtable->table[i]);
    }
    free(hashtable->table);
    return status;
}

#endif // HASHTABLE_H
