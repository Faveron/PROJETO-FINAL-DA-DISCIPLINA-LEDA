#define MAXCARC 50

typedef struct NO
{
    char nome[MAXCARC];
    char paisOrigem[MAXCARC];
    char tipoUva[MAXCARC];
    int safra[3];
    long int tempo;
    struct NO *next;
}NO;

typedef struct PILHA
{
    NO *topo;
    int qty;
}PILHA;

void inicializacaoPilha(PILHA *p)
{
    p->topo = NULL;
    p->qty = 0;
}

void empilhar(NO *dado, PILHA *p)
{
    NO *aux = (NO*) malloc(sizeof(NO));
    int i;
    if(aux == NULL)
    {
        printf("\n\tErro de alocação de nó.\n");
        return;
    }
    else
    {
        strcpy(aux->nome, dado->nome);
        strcpy(aux->paisOrigem, dado->paisOrigem);
        strcpy(aux->tipoUva, dado->tipoUva);
        for(i = 0; i < 3; i++)
        {
            aux->safra[i] = dado->safra[i];
        }
        aux->tempo = 13 + 11*30 + 2022*365 - dado->tempo;
        aux->next = p->topo;
        p->topo = aux;
        p->qty ++;
        printf("\n\tCadastro efetuado com sucesso");
    }
}

void desempilhar(NO *dado, PILHA *p)
{
    NO* aux = p->topo;
    int i;
    if(aux == NULL)
    {
        printf("\n\tEstoque Vazio\n");
        return;
    }
    else
    {
        p->topo = aux->next;
        aux->next = NULL;
        strcpy(dado->nome, aux->nome);
        strcpy(dado->paisOrigem, aux->paisOrigem);
        strcpy(dado->tipoUva, aux->tipoUva);
        for(i = 0; i < 3; i++)
        {
            dado->safra[i] = aux->safra[i];
        }
        dado->tempo = aux->tempo;
        p->qty --;
        free(aux);
    }
}

void imprimePilha(PILHA *p)
{
    NO *aux = p->topo;
    if(aux == NULL)
    {
        printf("\n\tEstoque Vazio!!\n");
        return;
    }
    else
    {
        while(aux != NULL)
        {
            printf("\n\nNome do produto: %s ", aux->nome);
            printf("\nPaís de origem: %s ", aux->paisOrigem);
            printf("\nTipo de uva: %s ", aux->tipoUva);
            printf("\nSafra: %2d/%2d/%d ", aux->safra[0], aux->safra[1], aux->safra[2]);
            printf("\nTempo: %d anos, %d meses e %d dias ", aux->tempo/365, (aux->tempo%365)/30, (aux->tempo%365)%30);
            aux = aux->next;
        }
    }
}
