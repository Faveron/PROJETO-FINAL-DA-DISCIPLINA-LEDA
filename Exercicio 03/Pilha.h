typedef struct NO
{
    int number;
    struct NO *next;
}NO;

typedef struct PILHA
{
    NO *topo;
    int max_items;
    int qty;
}PILHA;

void inicializacaoPilha(PILHA *p)
{
    p->topo = NULL;
    p->max_items = 10;
    p->qty = 0;
}

void empilhar(int dado, PILHA *p)
{
    NO *aux = (NO*) malloc(sizeof(NO));
    if(aux == NULL)
    {
        printf("\n\tErro de alocação de nó.\n");
        return;
    }
    else if(p->qty >= p->max_items)
    {
        printf("\n\tPilha cheia. Não é possível inserir mais nós\n");
        return;
    }
    else
    {
        aux->number = dado;
        aux->next = p->topo;
        p->topo = aux;
        p->qty ++;
    }
}

int desempilhar(PILHA *p)
{
    NO* aux = p->topo;
    int dado;
    if(aux == NULL)
    {
        printf("\n\tPilha Vazia\n");
        return;
    }
    else
    {
        p->topo = aux->next;
        aux->next = NULL;
        dado = aux->number;
        p->qty --;
        free(aux);
        return dado;
    }
}

void imprimePilha(PILHA *p)
{
    NO *aux = p->topo;
    if(aux == NULL)
    {
        printf("\n\tPilha Vazia!!\n");
        return;
    }
    else
    {
        printf("\n  |-TOPO\n");
        printf("  v\n");
        printf("[ ");
        while(aux != NULL)
        {
            printf("%d ", aux->number);
            aux = aux->next;
        }
        printf("]\n");
    }
}

void verificaPilha(PILHA *p)
{
   if(p->qty == p->max_items)
   {
        printf("\n\tPilha cheia. Existem %d nós na pilha\n", p->qty);
   }else if(p->qty == 0)
   {
        printf("\n\tPilha Vazia!!\n");
   }
   else if(p->qty == 1)
   {
        printf("\n\tExiste %d nó na pilha!!\n", p->qty);
   }
   else
   {
        printf("\n\tExistem %d nós na pilha!!\n", p->qty);
   }
}

void buscaElementoNaPilha(int valor, PILHA *p)
{
    NO *aux = p->topo;
    if(aux == NULL)
    {
        printf("\n\tPilha Vazia!!\n");
        return;
    }
    else
    {
        while(aux != NULL)
        {
            if(aux->number == valor)
            {
                printf("\n\tValor %d encontrado!!\n", valor);
                return;
            }
            aux = aux->next;
        }
        printf("\n\tValor %d NÃO encontrado!!\n", valor);
    }
}
