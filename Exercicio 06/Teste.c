#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "Pilha.h"

void getDados(NO *dados);
void getData(int data[]);

int main()
{
    setlocale(LC_ALL, "");

    PILHA *estoque = (PILHA*)malloc(sizeof(PILHA));
    NO *dadosVinho = (NO*) malloc(sizeof(NO));
    if(estoque == NULL || dados == NULL)
    {
        printf("\n\tErro de aloca��o.\n");
        return -1;
    }
    else
    {
        inicializacaoPilha(estoque);
        int opc, n;

        printf("\t\t\t\tADEGA DE VINHOS");
        do
        {
            opc = lista_operacoes();
            switch (opc)
            {
                case 0:
                    break;
                case 1:
                    getDados(dadosVinho);
                    empilhar(dadosVinho, estoque);
                    break;
                case 2:
                    printf("\nOp��o 02");
                    break;
                case 3:
                    printf("\nOp��o 03");
                    break;
                case 4:
                    printf("\nOp��o 04");
                    break;
                case 5:
                    printf("\nOp��o 05");
                    break;
                default:
                    printf("\nOp��o( %d )inv�lido.\n", opc);
            }
        }while (opc != 0);
    }
    return 0;
}

int lista_operacoes()
{
    int n;
    printf("\n\n\t  MENU\n"
           "\n  1 - Cadastrar vinho"
           "\n  2 - Retira Vinho para ocasi�o especial"
           "\n  3 - Retira Vinho para ocasi�o N�O especial"
           "\n  4 - cinco aquisi��es mais antigas"
           "\n  5 - cinco aquisi��es mais recentes"
           "\n  0 - Sair\n");
    printf("\nDigite o n�mero da op��o desejada: ");
    fflush(stdin);scanf("%d", &n);
    return n;
}

void getDados(NO *dados)
{
    printf("\n\tDIGITE OS DADOS DO VINHO\n");

    printf("\nNome do produto: ");
    fflush(stdin); scanf("%s",dados->nome);

    printf("Pa�s de origem: ");
    fflush(stdin); scanf("%s",dados->paisOrigem);

    printf("Tipo de uva: ");
    fflush(stdin); scanf("%s",dados->tipoUva);

    printf("Safra\n");
    getData(dados->safra);

    dados->tempo = (dados->safra[0]-1) + (dados->safra[1]-1)*30 + (dados->safra[2])*365;
}

void getData(int data[])
{
    int verifica;

    do
    {
        verifica = 0;
        printf("Dia: ");
        fflush(stdin); scanf("%d", &data[0]);
        if(data[0] > 31 || data[0] < 1)
        {
            printf("Valor inv�lido\n");
            verifica = 1;
        }
    }while(verifica != 0);

    do
    {
        verifica = 0;
        printf("M�s: ");
        fflush(stdin); scanf("%d", &data[1]);
        if(data[1] > 12 || data[1] < 1)
        {
            printf("Valor inv�lido\n");
            verifica = 1;
        }
    }while(verifica != 0);

    do
    {
        verifica = 0;
        printf("Ano: ");
        fflush(stdin); scanf("%d", &data[2]);
        if(data[2] > 2022 || data[2] < 0)
        {
            printf("Valor inv�lido\n");
            verifica = 1;
        }
    }while(verifica != 0);
}
