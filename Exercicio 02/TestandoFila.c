#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "Fila.h"

int main()

{
    setlocale(LC_ALL, "");
    FILA *f1 = (FILA*)malloc(sizeof(FILA));
    if(f1 == NULL)
    {
        printf("\n\tErro de aloca��o da fila.\n");
        return -1;
    }
    else
    {
        inicializacaoFila(f1);
        int opc, n;

        printf("\t\t\t\tTESTE DO ALGORTIMO DE FILA");
        do
        {
            opc = lista_operacoes();
            switch (opc)
            {
                case 0:
                    break;
                /*
                    A op��o abaixo atende o requisito
                        - Inserir um elemento na fila
                */
                case 1:
                    printf("\nDigite um n�mero a ser inserido: ");
                    fflush(stdin); scanf("%d",&n);
                    enfileirar(n, f1);
                    break;
                /*
                    A op��o abaixo atende o requisito
                        - Retirar um elemento da fila
                */
                case 2:
                    if(f1->qty == 0)
                    {
                        printf("\n\tOp��o inv�lida, a fila est� vazia!");
                    }
                    else
                    {
                        n = desenfileirar(f1);
                        printf("\n\tValor retirado da fila: %d", n);
                    }
                    break;
                /*
                    A op��o abaixo atende o requisito
                        - Exibir os elementos presentes na fila
                */
                case 3:
                    imprimirFila(f1);
                    break;
                /*
                    A op��o abaixo atende os requisitos
                        - Retornar a quantidade de elementos contidos na fila
                        - Verificar se a fila est� cheia
                        - Verificar se a fila est� vazia
                */
                case 4:
                    verificaFila(f1);
                    break;
                /*
                    A op��o abaixo atende o requisito
                        - Verificar se um elemento est� presente na fila
                */
                case 5:
                    if(f1->qty == 0)
                    {
                        printf("\n\tOp��o inv�lida, a fila est� vazia!");
                    }
                    else
                    {
                        printf("\nDigite um n�mero a ser buscado: ");
                        fflush(stdin); scanf("%d",&n);
                        buscaElementoNaFila(n, f1);
                    }
                    break;
                default:
                    printf("\nC�digo( %d )inv�lido.\n", opc);
            }
        }while (opc != 0);
    }
    return 0;
}

int lista_operacoes()
{
    int n;
    printf("\n\n\t  MENU\n"
           "\n  1 - Inserir n� na fila"
           "\n  2 - Retirar n� da fila"
           "\n  3 - Imprimir a fila"
           "\n  4 - Verifica situa��o da fila"
           "\n  5 - Busca n� na fila"
           "\n  0 - Sair\n");
    printf("\nDigite o n�mero da op��o desejada: ");
    fflush(stdin);scanf("%d", &n);
    return n;
}
