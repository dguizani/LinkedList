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

/*
 * Função para testar se a posição da lista está vazia
 * 
 * param elementList: referencia para um ponteiro de um elemento da lista
 * 
 * return true: se está vazia
 * return false: se não está vazia
*/
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
    EList *new = (EList *) malloc(sizeof(EList));

    if (listIsEmpty(&new))
        return false;
    
    new -> value = value;

    if (listIsEmpty(elementList))
    {
        new -> next = NULL;
        *elementList = new;

        return true;
    }

    new -> next = *elementList;

    *elementList = new;

    return true;
}
