typedef struct NOFILA
{
    int number;
    struct NOFILA *next;
}NOFILA;

typedef struct FILA
{
    NOFILA *inicio;
    NOFILA *fim;
    int qty;
}FILA;

void inicializacaoFila(FILA *f)
{
    f->inicio = NULL;
    f->fim = NULL;
    f->qty = 0;
}

void enfileirar(int dado, FILA *f)
{
    NOFILA *aux = (NOFILA*) malloc(sizeof(NOFILA));
    if(aux == NULL)
    {
        printf("\n\tErro de alocação de nó.\n");
        return;
    }
    else
    {
        aux->number = dado;
        aux->next = NULL;
        if(f->inicio == NULL)
        {
            f->inicio = aux;
        }
        else
        {
            f->fim->next = aux;
        }
        f->fim = aux;
        f->qty++;
    }
}

int desenfileirar(FILA *f)
{
    NOFILA* aux = f->inicio;
    int dado;
    if(aux == NULL)
    {
        printf("\n\tFila vazia!\n");
        return;
    }
    else
    {
        f->inicio = aux->next;
        aux->next = NULL;
        dado = aux->number;
        f->qty--;
        free(aux);
        if(f->inicio == NULL)
        {
            f->fim = NULL;
        }
        return dado;
    }
}

void imprimirFila(FILA *f)
{
    NOFILA *aux = f->inicio;
    if(aux == NULL)
    {
        printf("\n\tFila vazia!\n");
        return;
    }
    else
    {
        printf("\n  |-INÍCIO\n");
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

void verificaFila(FILA *f)
{
   if(f->qty == 0)
   {
        printf("\n\tFila Vazia!!\n");
   }
   else if(f->qty == 1)
   {
        printf("\n\tExiste %d nó na fila!!\n", f->qty);
   }
   else
   {
        printf("\n\tExistem %d nós na fila!!\n", f->qty);
   }
}

void buscaElementoNaFila(int valor, FILA *f)
{
    NOFILA *aux = f->inicio;
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
