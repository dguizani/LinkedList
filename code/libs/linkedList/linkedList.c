#include <stdlib.h>
#include "../bool/bool.c"

typedef struct linkedList
{
    int value;
    struct linkedList *next;
} EList;

/*
 * Função para iniciar uma nova lista
 * 
 * return NULL: sempre
*/
EList *newLinkedList()
{
    return NULL;
}
