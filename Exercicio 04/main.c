#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "Fila.h"

/*
  Fun��o que gera valores aleat�rios para a fila e j� traz ordenado os valores dentro dela
*/
void geraValoresParaFila(FILA *f);

/*
    Fun��o que ordena os valores de uma fila
*/
void ordenaFila(FILA *f);

/*
    M�todo de ordena��o escolhido, Selection Sort
*/
void selectionsort(int v[],int n);

int main()

{
    setlocale(LC_ALL, "");

    FILA *f1 = (FILA*)malloc(sizeof(FILA));
    FILA *f2 = (FILA*)malloc(sizeof(FILA));
    FILA *f3 = (FILA*)malloc(sizeof(FILA));
    if(f1 == NULL || f2 == NULL || f3 == NULL)
    {
        printf("\n\tErro de aloca��o da pilha.\n");
        return -1;
    }
    else
    {
        inicializacaoFila(f1);
        geraValoresParaFila(f1);
        printf("1� Fila");
        imprimirFila(f1);

        inicializacaoFila(f2);
        geraValoresParaFila(f2);
        printf("2� Fila");
        imprimirFila(f2);

        inicializacaoFila(f3);
        while(f1->inicio != NULL || f2->inicio != NULL)
        {
            if(f1->inicio == NULL && f2->inicio != NULL)
            {
                enfileirar(desenfileirar(f2), f3);
            }
            else
            {
                if(f2->inicio == NULL && f1->inicio != NULL)
                {
                    enfileirar(desenfileirar(f1), f3);
                }
                else
                {
                    if(f1->inicio->number < f2->inicio->number )
                    {
                        enfileirar(desenfileirar(f1), f3);
                    }
                    else
                    {
                        enfileirar(desenfileirar(f2), f3);
                    }
                }
            }
        }
        printf("\n3� Fila");
        imprimirFila(f3);

        /*
            Estou imprimindo as duas primeiras filas para verificar que de fato os valores delas
            foram atribuidos a 3� fila e elas est�o vazias
        */
        printf("\n1� Fila");
        imprimirFila(f1);
        printf("\n2� Fila");
        imprimirFila(f2);
    }
    return 0;
}

void geraValoresParaFila(FILA *f)
{
    int i;
    for(i = 0; i < f->max_items/2; i++)
    {
        enfileirar(rand() % 101, f);
    }
    ordenaFila(f);
}

void ordenaFila(FILA *f)
{
    int n[f->max_items], i, qtd;
    qtd = f->qty;

    for(i = 0; i < qtd; i++)
    {
        n[i] = desenfileirar(f);
    }

    selectionsort(n, qtd);

    for(i = 0; i < qtd; i++)
    {
        enfileirar(n[i], f);
    }
}

void selectionsort(int v[],int n) {
  int i, j, max, aux;

  for (i = 0; i < (n - 1); i++) {
    max = i;
    for (j = i+1; j < n; j++) {
      if (v[j] < v[max]) {
        max = j;
      }
    }
    if (i != max) {
      aux = v[i];
      v[i] = v[max];
      v[max] = aux;
    }
  }
}

