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

Bool listIsEmpty(EList **elementList)
{
    if (*elementList == NULL)
        return true;
    
    return false;
}

/*
 * Função para adicionar um elemento no inicio da lista
 * 
 * param elementList: referencia para um ponteiro de um elemento da lista
 * param value: valor a ser adicionado na lista
 * 
 * return true: se conseguiu adicionar
 * return false: se não conseguiu adicionar
*/
Bool addFirstList(EList **elementList, int value)
{

}
