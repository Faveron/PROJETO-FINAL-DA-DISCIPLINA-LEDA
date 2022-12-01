#define MAXCARC 50

typedef struct NO
{
    char nome[MAXCARC];
    char paisOrigem[MAXCARC];
    char tipoUva[MAXCARC];
    int safra;
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
        aux->safra = dado->safra;
        aux->next = p->topo;
        p->topo = aux;
        p->qty ++;
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
        dado->safra = aux->safra;
        p->qty --;
        free(aux);
    }
}

void imprimePilha(PILHA *p, int n)
{
    NO *aux = p->topo;
    int i;
    if(aux == NULL)
    {
        printf("\n\tEstoque Vazio!!\n");
        return;
    }
    else
    {
        if (n == 5)
        {
            for (i = 0; i < 5 && aux != NULL; i++)
            {
                printf("\n\nNome do produto: %s ", aux->nome);
                printf("\nPaís de origem: %s ", aux->paisOrigem);
                printf("\nTipo de uva: %s ", aux->tipoUva);
                printf("\nSafra: %d ", aux->safra);
                aux = aux->next;
            }
        }
        else
        {
            while(aux != NULL)
            {
                printf("\n\nNome do produto: %s ", aux->nome);
                printf("\nPaís de origem: %s ", aux->paisOrigem);
                printf("\nTipo de uva: %s ", aux->tipoUva);
                printf("\nSafra: %d ", aux->safra);
                aux = aux->next;
            }
        }
    }
}
