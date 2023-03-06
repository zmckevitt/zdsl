/*
    Hash table implementation
    Zack McKevitt
*/

// TODO
// need hash table with better typing, perhaps implicit?
// For now, just doing string prototype
// Unions to emulate polymorphism?
// https://stackoverflow.com/questions/10718150/c-unions-and-polymorphism

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "linkedlist.h"

struct ht {
    size_t size;
    struct sll* table;
};

struct ht ht_create(size_t size) {
    struct ht new_ht;
    new_ht.size = size;
    new_ht.table = malloc(size * sizeof(struct sll));

    for(size_t i=0; i<size; ++i) {
        struct sll sll_ht = sll_create();
        new_ht.table[i] = sll_ht;
    }

    return new_ht;
};

/*
    HASH FUNCTIONS
*/

/*
    djb2 hash function:
    http://www.cse.yorku.ca/~oz/hash.html
*/
uint32_t djb2_hash(const char* str) {
    uint32_t hash = 5381;
    int c;
    
    while(c = *str++)
        hash = ((hash << 5) + hash) + c;
    return hash;
}

int ht_destroy(struct ht* hashtable) {
    int status = 0;
    for(size_t i=0; i<hashtable->size; ++i) {
        status = sll_destroy(&hashtable->table[i]);
    }
    free(hashtable->table);
    return status;
}

#endif // HASHTABLE_H
