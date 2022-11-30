typedef struct NO
{
    int number;
    struct NO *next;
}NO;

typedef struct FILA
{
    NO *inicio;
    NO *fim;
    int max_items;
    int qty;
}FILA;

void inicializacaoFila(FILA *f)
{
    f->inicio = NULL;
    f->fim = NULL;
    f->max_items = 10;
    f->qty = 0;
}

void enfileirar(int dado, FILA *f)
{
    NO *aux = (NO*) malloc(sizeof(NO));
    if(aux == NULL)
    {
        printf("\n\tErro de alocação de nó.\n");
        return;
    }
    else if(f->qty >= f->max_items)
    {
        printf("\n\tFila cheia. Não é possível inserir mais nós\n");
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
    NO* aux = f->inicio;
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
    NO *aux = f->inicio;
    if(aux == NULL)
    {
        printf("\n\tFila vazia!\n");
        return;
    }
    else
    {
        printf("\n\t\t\tFILA\n");
        printf("  |-INÍCIO\n");
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
   if(f->qty == f->max_items)
   {
        printf("\n\tFila cheia. Existem %d nós na fila\n", f->qty);
   }else if(f->qty == 0)
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
    NO *aux = f->inicio;
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
