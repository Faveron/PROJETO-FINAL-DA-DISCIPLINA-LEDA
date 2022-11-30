#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "Pilha.h"

/*
  Fun��o que gera valores aleat�rios para a pilha e j� traz ordenado os valores dentro dela
*/
void geraValoresParaPilha(PILHA *p);

/*
    Fun��o que ordena os valores de uma pilha
*/
void ordenaPilha(PILHA *p);

/*
    M�todo de ordena��o escolhido, Selection Sort
*/
void selectionsort(int v[],int n);

int main()

{
    setlocale(LC_ALL, "");

    PILHA *p1 = (PILHA*)malloc(sizeof(PILHA));
    PILHA *p2 = (PILHA*)malloc(sizeof(PILHA));
    PILHA *p3 = (PILHA*)malloc(sizeof(PILHA));
    if(p1 == NULL || p2 == NULL || p3 == NULL)
    {
        printf("\n\tErro de aloca��o da pilha.\n");
        return -1;
    }
    else
    {
        inicializacaoPilha(p1);
        geraValoresParaPilha(p1);
        printf("1� Pilha");
        imprimePilha(p1);

        inicializacaoPilha(p2);
        geraValoresParaPilha(p2);
        printf("2� Pilha");
        imprimePilha(p2);

        inicializacaoPilha(p3);
        while(p1->topo != NULL || p2->topo != NULL)
        {
            if(p1->topo == NULL && p2->topo != NULL)
            {
                empilhar(desempilhar(p2), p3);
            }
            else
            {
                if(p2->topo == NULL && p1->topo != NULL)
                {
                    empilhar(desempilhar(p1), p3);
                }
                else
                {
                    if(p1->topo->number < p2->topo->number )
                    {
                        empilhar(desempilhar(p1), p3);
                    }
                    else
                    {
                        empilhar(desempilhar(p2), p3);
                    }
                }
            }
        }
        printf("\n3� Pilha");
        imprimePilha(p3);

        /*
            Estou imprimindo as duas primeiras pilhas para verificar que de fato os valores delas
            foram atribuidos a 3� pilha e elas est�o vazias
        */
        printf("\n1� Pilha");
        imprimePilha(p1);
        printf("\n2� Pilha");
        imprimePilha(p2);
    }
    return 0;
}

void geraValoresParaPilha(PILHA *p)
{
    int i;
    for(i = 0; i < p->max_items/2; i++)
    {
        empilhar(rand() % 101, p);
    }
    ordenaPilha(p);
}

void ordenaPilha(PILHA *p)
{
    int n[p->max_items], i, qtd;
    qtd = p->qty;

    for(i = 0; i < qtd; i++)
    {
        n[i] = desempilhar(p);
    }

    selectionsort(n, qtd);

    for(i = 0; i < qtd; i++)
    {
        empilhar(n[i], p);
    }
}

void selectionsort(int v[],int n) {
  int i, j, max, aux;

  for (i = 0; i < (n - 1); i++) {
    max = i;
    for (j = i+1; j < n; j++) {
      if (v[j] > v[max]) {
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
