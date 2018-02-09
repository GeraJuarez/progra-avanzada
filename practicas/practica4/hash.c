#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hash.h"

unsigned long
doHash(unsigned char* str, int size)
{
    unsigned long hash = 5381;
    int c;

    while (c = *str++) {
        hash = ((hash << 5) + hash) + c;
    }

    return hash % size;
}

void hashInit(HashInt* hash, int size) {
    hash->size = size;
    hash->data = (HashElement*) calloc( size, sizeof(HashElement) );
}

void hashInsert(HashInt* h, char* k, int v) {
    int index = doHash(k, h->size);

    if( h->data[index].elements == NULL ) {
        // TODO: Remove hardcoded size 4
        h->data[index].elements = (Element*) malloc( 4 * sizeof(Element) );
        h->data[index].count = 0;
    }
    h->data[index].elements[ h->data[index].count ].key = strdup(k);    // Duplicate just in case the pointer is changed later
    h->data[index].elements[ h->data[index].count ].value = v;
    h->data[index].count += 1;
    //h->size += 1;
}