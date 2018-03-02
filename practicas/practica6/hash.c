#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hash.h"

#define strEquals(s1, s2) (strcmp(s1, s2) == 0)
#define HASH_DEBUG "HASH_DEBUG"

void printDebug(char* message) {
    char* hashDebug = getenv(HASH_DEBUG);
    if ( hashDebug != NULL && strEquals(hashDebug, "y") )
    {
        printf("%s\n", message);
    }
}



unsigned
doHash(unsigned char* str, int size)
{
    unsigned hash = 5381;
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

static void hashDoInsert(HashInt* h, char* k, int v) {
    printDebug("INIT INSERT");
    unsigned index = doHash(k, h->size);
    HashElement* currentHashElement = &(h->data[index]);

    // Debug variables
    char errorMsg[255];
    sprintf(errorMsg, "index %d", index);
    printDebug(errorMsg);

    printDebug("END INIT INSERT");
    if ( currentHashElement->elements == NULL ) {
        
        currentHashElement->elements = (Element*) malloc( 2 * sizeof(Element) );
        currentHashElement->count = 0;
        currentHashElement->length = 2;
    }
    if ( currentHashElement->length == currentHashElement->count )
    {
        currentHashElement->length *= 2;
        currentHashElement->elements = (Element*) realloc( currentHashElement->elements,
                                                currentHashElement->length * sizeof(Element) );
    }
    printDebug("INSERT ASSIGNING");
    currentHashElement->elements[currentHashElement->count].key = strdup(k);   // Duplicate just in case the pointer is changed later
    currentHashElement->elements[currentHashElement->count].value = v;
    currentHashElement->count += 1;
    printDebug("INSERT COMPLETED");
}

static void hashDoUpdate(HashInt* h, char* k, int v) {
    int pos = doHash(k, h->size);
    int i;
    Element* currentElements = h->data[pos].elements;
    int currentElementsLength = h->data[pos].count;

    for (i = 0; i < currentElementsLength; i++)
    {
        if (strEquals(k, currentElements[i].key))
        {
            currentElements[i].value = v;
            break;
        }
    }
}

void hashInsert(HashInt* h, char* k, int v) 
{
    int* oldValue = hashGet(h, k);
    if (oldValue == NULL)
    {
        hashDoInsert(h, k, v);
    }
    else
    {
        hashDoUpdate(h, k, v);
    }
}

int* hashGet(HashInt* h, char* k) {
    int pos = doHash(k, h->size);
    int i;
    Element* currentElements = h->data[pos].elements;
    int currentElementsLength = h->data[pos].count;
    int* value = NULL;

    for (i = 0; i < currentElementsLength; i++)
    {
        if (strEquals(k, currentElements[i].key))
        {
            value = (int*) malloc(sizeof(int));
            *value = currentElements[i].value;
            break;
        }
    }
    return value;
}