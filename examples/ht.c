#include <stdio.h>
#include <stdlib.h>
#include "../hashtable.h"

#define HT_SIZE 16

int main() {
    struct ht hashtable = ht_create(HT_SIZE);
    ht_destroy(&hashtable);
    return 0;
}
