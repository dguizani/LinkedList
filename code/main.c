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
                    printf("\n Digite.\n");
                    printf("\n Valor: ");
                    scanf(" %[^\n]s", valor);

                    if (addFirstList(&lista, atoi(valor)))
                        printf("\n Elemento adicionado.\n");
                    
                    else
                        printf("\n Impossivel adicionar.\n");
                }

                else if (opcao == '2')
                {
                    printf("\n Digite.\n");
                    printf("\n Valor: ");
                    scanf(" %[^\n]s", valor);

                    if (addLastList(&lista, atoi(valor)))
                        printf("\n Elemento adicionado.\n");
                    
                    else
                        printf("\n Impossivel adicionar.\n");
                }

                else if (opcao == '3')
                {
                    printf("\n Digite.\n");
                    printf("\n Valor: ");
                    scanf(" %[^\n]s", valor);
                    
                    printf(" Posicao: ");
                    scanf(" %[^\n]s", posX);

                    if (addIndexList(&lista, atoi(valor), atoi(posX)))
                        printf("\n Elemento adicionado.\n");
                    
                    else
                        printf("\n Impossivel adicionar.\n");
                }

                if (opcao != '0')
                {
                    printf("\n\n ");
                    pausar();
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
                printf("\n | 4 | Todos                         |");
                printf("\n | 0 | Voltar                        |");
                printf("\n +---+-------------------------------+");

                do
                {
                    opcao = getch();
                } while (!(opcao >= '0' && opcao <= '4'));

                limparTela();

                if (opcao == '1')
                {
                    if (delFirstList(&lista))
                        printf("\n Elemento Removido.\n");
                    else
                        printf("\n Impossivel remover.\n");
                }

                else if (opcao == '2')
                {
                    if (delLastList(&lista))
                        printf("\n Elemento Removido.\n");
                    else
                        printf("\n Impossivel remover.\n");
                }

                else if (opcao == '3')
                {
                    printf("\n Digite.\n");
                    printf(" Posicao: ");
                    scanf(" %[^\n]s", posX);

                    if (delIndexList(&lista, atoi(posX)))
                        printf("\n Elemento Removido.\n");
                    else
                        printf("\n Impossivel remover.\n");
                }

                else if (opcao == '4')
                {
                    printf("\n %d elementos removidos.\n", delAllList(&lista));
                }

                if (opcao != '0')
                {
                    printf("\n\n ");
                    pausar();
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
                    int index = 0;
                    for (EList *aux = lista; aux != NULL; aux = aux -> next)
                        printf("\n %03d: %d", index++, aux -> value);
                }

                else if (opcao == '2')
                {
                    printf("\n Digite.\n");
                    printf("\n Posicao: ");
                    scanf(" %[^\n]s", posX);

                    int index = atoi(posX);

                    EList *aux = lista;
                    for (int i = 0; i < index && aux != NULL; i++)
                        aux = aux -> next;

                    if (aux != NULL)
                        printf("\n %03d: %d", index, aux -> value);
                    else
                        printf("\n Index inexistente.");
                }

                else if (opcao == '3')
                {
                    printf("\n Digite.\n");
                    printf("\n Quantidade de elementos: ");
                    scanf(" %[^\n]s", posX);

                    int index = atoi(posX);

                    EList *aux = lista;
                    for (int i = 0; i < index && aux != NULL; i++)
                    {
                        printf("\n %03d: %d", i, aux -> value);
                        aux = aux -> next;
                    }
                }

                if (opcao != '0')
                {
                    printf("\n\n ");
                    pausar();
                }

                limparTela();

            } while (opcao != '0');

            opcao = ' ';
        }

    } while (opcao != '0');

    return 0;
}
