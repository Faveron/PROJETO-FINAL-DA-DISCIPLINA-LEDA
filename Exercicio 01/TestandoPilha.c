#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "Pilha.h"

int main()

{
    setlocale(LC_ALL, "");
    PILHA *p1 = (PILHA*)malloc(sizeof(PILHA));
    if(p1 == NULL)
    {
        printf("\n\tErro de alocação da pilha.\n");
        return -1;
    }
    else
    {
        inicializacaoPilha(p1);
        int opc, n;

        printf("\t\t\t\tTESTE DO ALGORTIMO DE PILHA");
        do
        {
            opc = lista_operacoes();
            switch (opc)
            {
                case 0:
                    break;
                /*
                    A opção abaixo atende o requisito
                        - Empilhar (inserir) um novo elemento na pilha
                */
                case 1:
                    printf("\nDigite um número a ser inserido: ");
                    fflush(stdin); scanf("%d",&n);
                    empilhar(n, p1);
                    break;
                /*
                    A opção abaixo atende o requisito
                        - Desempilhar (retirar) um elemento da pilha
                */
                case 2:
                    if(p1->qty == 0)
                    {
                        printf("\n\tOpção inválida, a pilha está vazia!");
                    }
                    else
                    {
                        n = desempilhar(p1);
                        printf("\n\tValor retirado da pilha: %d", n);
                    }
                    break;
                /*
                    A opção abaixo atende o requisito
                        - Exibir os elementos presentes na pilha
                */
                case 3:
                    imprimePilha(p1);
                    break;
                /*
                    A opção abaixo atende os requisitos
                        - Retornar a quantidade de elementos contidos na pilha
                        - Verificar se a pilha está cheia
                        - Verificar se a pilha está vazia
                */
                case 4:
                    verificaPilha(p1);
                    break;
                /*
                    A opção abaixo atende o requisito
                        - Verificar se um elemento está presente na pilha
                */
                case 5:
                    if(p1->qty == 0)
                    {
                        printf("\n\tOpção inválida, a pilha está vazia!");
                    }
                    else
                    {
                        printf("\nDigite um número a ser buscado: ");
                        fflush(stdin); scanf("%d",&n);
                        buscaElementoNaPilha(n, p1);
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
           "\n  1 - Inserir nó na pilha"
           "\n  2 - Retirar nó da pilha"
           "\n  3 - Imprimir a pilha"
           "\n  4 - Verifica situação da pilha"
           "\n  5 - Busca nó na pilha"
           "\n  0 - Sair\n");
    printf("\nDigite o número da opção desejada: ");
    fflush(stdin);scanf("%d", &n);
    return n;
}
