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
        printf("\n\tErro de alocação da fila.\n");
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
                    A opção abaixo atende o requisito
                        - Inserir um elemento na fila
                */
                case 1:
                    printf("\nDigite um número a ser inserido: ");
                    fflush(stdin); scanf("%d",&n);
                    enfileirar(n, f1);
                    break;
                /*
                    A opção abaixo atende o requisito
                        - Retirar um elemento da fila
                */
                case 2:
                    if(f1->qty == 0)
                    {
                        printf("\n\tOpção inválida, a fila está vazia!");
                    }
                    else
                    {
                        n = desenfileirar(f1);
                        printf("\n\tValor retirado da fila: %d", n);
                    }
                    break;
                /*
                    A opção abaixo atende o requisito
                        - Exibir os elementos presentes na fila
                */
                case 3:
                    imprimirFila(f1);
                    break;
                /*
                    A opção abaixo atende os requisitos
                        - Retornar a quantidade de elementos contidos na fila
                        - Verificar se a fila está cheia
                        - Verificar se a fila está vazia
                */
                case 4:
                    verificaFila(f1);
                    break;
                /*
                    A opção abaixo atende o requisito
                        - Verificar se um elemento está presente na fila
                */
                case 5:
                    if(f1->qty == 0)
                    {
                        printf("\n\tOpção inválida, a fila está vazia!");
                    }
                    else
                    {
                        printf("\nDigite um número a ser buscado: ");
                        fflush(stdin); scanf("%d",&n);
                        buscaElementoNaFila(n, f1);
                    }
                    break;
                default:
                    printf("\nCódigo( %d )inválido.\n", opc);
            }
        }while (opc != 0);
    }
    return 0;
}

int lista_operacoes()
{
    int n;
    printf("\n\n\t  MENU\n"
           "\n  1 - Inserir nó na fila"
           "\n  2 - Retirar nó da fila"
           "\n  3 - Imprimir a fila"
           "\n  4 - Verifica situação da fila"
           "\n  5 - Busca nó na fila"
           "\n  0 - Sair\n");
    printf("\nDigite o número da opção desejada: ");
    fflush(stdin);scanf("%d", &n);
    return n;
}
