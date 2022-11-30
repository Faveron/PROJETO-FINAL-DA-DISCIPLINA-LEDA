#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "Pilha.h"
#include "Fila.h"

/*
  Função que gera valores aleatórios para a pilha
*/
void geraValoresParaPilha(PILHA *p);

int main()

{
    setlocale(LC_ALL, "");

    PILHA *p1 = (PILHA*)malloc(sizeof(PILHA));
    FILA *f1 = (FILA*)malloc(sizeof(FILA));
    FILA *f2 = (FILA*)malloc(sizeof(FILA));
    if(p1 == NULL || f1 == NULL || f2 == NULL)
    {
        printf("\n\tErro de alocação.\n");
        return -1;
    }
    else
    {
        int n;

        inicializacaoPilha(p1);
        geraValoresParaPilha(p1);
        printf("\t\tPILHA\n");
        imprimePilha(p1);

        inicializacaoFila(f1);
        inicializacaoFila(f2);
        while(p1->topo != NULL)
        {
            n = desempilhar(p1);
            if(n % 2 == 0)
            {
                enfileirar(n, f1);
            }
            else
            {
                enfileirar(n, f2);
            }
        }
        printf("\n\t\t1º FILA - PARES\n");
        imprimirFila(f1);
        printf("\n\t\t2º FILA - IMPARES\n");
        imprimirFila(f2);
    }
    return 0;
}

void geraValoresParaPilha(PILHA *p)
{
    int n = rand() % 101;
    while( n != 0)
    {
        empilhar(n, p);
        n = rand() % 101;
    }
}
