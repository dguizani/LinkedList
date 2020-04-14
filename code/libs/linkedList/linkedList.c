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

/*
 * Função para adicionar um elemento no fim da lista
 * 
 * param elementList: referencia para um ponteiro de um elemento da lista
 * param value: valor a ser adicionado na lista
 * 
 * return true: se conseguiu adicionar
 * return false: se não conseguiu adicionar
*/
Bool addLastList(EList **elementList, int value)
{
    if (listIsEmpty(elementList))
        return addFirstList(elementList, value);
    
    EList *new = (EList *) malloc(sizeof(EList));

    if (listIsEmpty(&new))
        return false;
    
    new -> value = value;
    new -> next = NULL;

    EList *aux = *elementList;
    for (aux; aux -> next != NULL; aux = aux -> next);
    
    aux -> next = new;

    return true;
}

/*
 * Função para adicionar um elemento na posição desejada da lista
 * 
 * param elementList: referencia para um ponteiro de um elemento da lista
 * param value: valor a ser adicionado na lista
 * param posX: posição a ser adicionado o elemento na lista
 * 
 * return true: se conseguiu adicionar
 * return false: se não conseguiu adicionar
*/
Bool addIndexList(EList **elementList, int value, unsigned int posX)
{
    if (listIsEmpty(elementList) || posX == 0)
        return addFirstList(elementList, value);
    
    EList *new = (EList *) malloc(sizeof(EList));

    if (listIsEmpty(&new))
        return false;

    EList *current = *elementList;
    for (current; current -> next != NULL || posX == 1; current = current -> next)
        posX -= 1;

    new -> value = value;
    new -> next = current -> next;

    current -> next = new;

    return true;
}
