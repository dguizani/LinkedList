#include <stdio.h>
#include <conio.h>
#include "./libs/linkedList/linkedList.c"

#define limparTela() system("cls")
#define pausar() system("pause")

#define Q_DIGITOS 10

int main(int argc, char const *argv[])
{
    char opcao, posX[Q_DIGITOS + 1], valor[Q_DIGITOS + 1];

    EList *lista = newList();

    do
    {
        printf("\n +-----------------------------------+");
        printf("\n |          Lista Encadeada          |");
        printf("\n +---+-------------------------------+");
        printf("\n | 1 | Adicionar elemento            |");
        printf("\n | 2 | Remover elemento              |");
        printf("\n | 3 | Imprimir                      |");
        printf("\n | 0 | Sair                          |");
        printf("\n +---+-------------------------------+");

        do
        {
            opcao = getch();
        } while (!(opcao >= '0' && opcao <= '3'));

        limparTela();

        if (opcao == '1')
        {
            do
            {
                printf("\n +-----------------------------------+");
                printf("\n |        Adicionar Elemento         |");
                printf("\n +---+-------------------------------+");
                printf("\n | 1 | No inicio                     |");
                printf("\n | 2 | No fim                        |");
                printf("\n | 3 | No index                      |");
                printf("\n | 0 | Voltar                        |");
                printf("\n +---+-------------------------------+");

                do
                {
                    opcao = getch();
                } while (!(opcao >= '0' && opcao <= '3'));

                limparTela();

                if (opcao == '1')
                {
                    printf("\n Digite o valor a ser adicionado: ");
                    scanf(" %[^\n]s", valor);

                    if (addFirstList(&lista, atoi(valor)))
                        printf("\n Elemento adicionado.\n");
                    
                    else
                        printf("\n Impossivel adicionar.\n");
                }

                else if (opcao == '2')
                {
                    printf("\n Digite o valor a ser adicionado: ");
                    scanf(" %[^\n]s", valor);

                    if (addLastList(&lista, atoi(valor)))
                        printf("\n Elemento adicionado.\n");
                    
                    else
                        printf("\n Impossivel adicionar.\n");
                }

                else if (opcao == '3')
                {
                    printf("\n Digite o valor a ser adicionado: ");
                    scanf(" %[^\n]s", valor);
                    
                    printf("\n Digite a posicao a ser adicionada: ");
                    scanf(" %[^\n]s", posX);

                    if (addIndexList(&lista, atoi(valor), atoi(posX)))
                        printf("\n Elemento adicionado.\n");
                    
                    else
                        printf("\n Impossivel adicionar.\n");
                }

                limparTela();

            } while (opcao != '0');

            opcao = ' ';
        }

        else if (opcao == '2')
        {
            do
            {
                printf("\n +-----------------------------------+");
                printf("\n |         Remover Elemento          |");
                printf("\n +---+-------------------------------+");
                printf("\n | 1 | Do inicio                     |");
                printf("\n | 2 | Do fim                        |");
                printf("\n | 3 | Do index                      |");
                printf("\n | 0 | Voltar                        |");
                printf("\n +---+-------------------------------+");

                do
                {
                    opcao = getch();
                } while (!(opcao >= '0' && opcao <= '3'));

                limparTela();

                if (opcao == '1')
                {

                }

                else if (opcao == '2')
                {

                }

                else if (opcao == '3')
                {

                }

                limparTela();

            } while (opcao != '0');

            opcao = ' ';
        }

        else if (opcao == '3')
        {
            do
            {
                printf("\n +-----------------------------------+");
                printf("\n |             Imprimir              |");
                printf("\n +---+-------------------------------+");
                printf("\n | 1 | Todos elementos               |");
                printf("\n | 2 | Um elemento                   |");
                printf("\n | 3 | X primeiros elementos         |");
                printf("\n | 0 | Voltar                        |");
                printf("\n +---+-------------------------------+");

                do
                {
                    opcao = getch();
                } while (!(opcao >= '0' && opcao <= '3'));

                limparTela();

                if (opcao == '1')
                {
                    for (EList *aux = lista; aux != NULL; aux = aux -> next)
                        printf("\n %p: %d", aux, aux -> value);

                    printf("\n\n ");
                    pausar();
                }

                else if (opcao == '2')
                {

                }

                else if (opcao == '3')
                {

                }

                limparTela();

            } while (opcao != '0');

            opcao = ' ';
        }

    } while (opcao != '0');

    return 0;
}
