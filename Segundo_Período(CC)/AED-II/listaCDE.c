#include<stdio.h>
#include<stdlib.h>

typedef struct no {

    int dado;
    struct no *ant;
    struct no *prox;

} No;

typedef struct {

    No *inicio;
    No *fim;
    int tam;

} ListaCDE;

//funcoes de manipulacao
void cria(ListaCDE *l);
int insere(ListaCDE *l, int dado);
int insereOrdenado(ListaCDE *l, int dado);
int retira(ListaCDE *l, int dado);

//funcoes de visualizacao
int estaVazia(ListaCDE l);
int getInicio(ListaCDE l);
int getFim(ListaCDE l);
int getTamanho(ListaCDE l);
void mostra(ListaCDE, int sentido);


int main(){

    ListaCDE l;
    int dado, sucesso, opcao;

    cria(&l);

    /* INSERINDO DESORDENADO
    sucesso = insere(&l, 400); // eu optei por nao verificar se houve sucesso na insercao
    sucesso = insere(&l, 250);
    sucesso = insere(&l, 666);
    sucesso = insere(&l, 5000);
    sucesso = insere(&l, 10); */

    /* INSERINDO ORDENADO */
    sucesso = insereOrdenado(&l, 400); // eu optei por nao verificar se houve sucesso na insercao
    sucesso = insereOrdenado(&l, 250);
    sucesso = insereOrdenado(&l, 666);
    sucesso = insereOrdenado(&l, 5000);
    sucesso = insereOrdenado(&l, 10);

    if(!estaVazia(l)){ //exibindo a lista
        printf("\n-------------------------------------------------\n");
        printf("Deseja ver os dados a partir de onde?\n1 - inicio \n2 - fim\n");
        scanf("%d", &opcao);
        mostra(l, opcao);
    }

    opcao = 1;
    while(opcao == 1){ // remover ate o usuario nao querer mais
        printf("\n-------------------------------------------------\n");
        printf("Qual dado deseja remover? ");
        scanf("%d", &dado);

        sucesso = retira(&l, dado); // removo o elemento solicitado pelo usuario
        if(!sucesso)
            printf("FALHA EM REMOVER: %d\n\n", dado);

        mostra(l, 1); // exibo a lista atualizada

        printf("\nDeseja remover mais algum elemento? \n1 - sim \n2 - nao\n");
        scanf("%d", &opcao);
    }

    // liberando memoria...
    while(!estaVazia(l)){
        sucesso = retira(&l, getInicio(l)); //retirando sempre o primeiro elemento
    }
}

void cria(ListaCDE *l){

    l->inicio = NULL;
    l->fim = NULL;
    l->tam = 0;
}

int insere(ListaCDE *l, int dado){

    // alocando no na memoria e checando se deu certo
    No *aux = (No *) malloc(sizeof(No));
    if(aux == NULL)
        return 0;

    // guardando o dado e incrementando o tamanho da lista
    aux->dado = dado;
    l->tam++;

    // 1o caso: primeiro elemento
    if(l->inicio == NULL){

        //todos apontam para o unico no existente
        l->inicio = aux;
        l->fim = aux;
        aux->ant = l->fim;
        aux->prox = l->inicio;

        return 1;
    }

    // 2o caso: ja ha elementos, insere no fim

    aux->ant = l->fim; //ant do novo fim aponta para antigo fim
    aux->prox = l->inicio; //prox do novo fim aponta pra inicio
    l->fim->prox = aux; //prox do antigo fim aponta para novo fim
    l->fim = aux; //l->fim aponta para novo fim
    l->inicio->ant = l->fim; //ant do inicio aponta para novo fim

    return 1;
}


int insereOrdenado(ListaCDE *l, int dado){

    // alocando no na memoria e checando se deu certo
    No *aux = (No *) malloc(sizeof(No));
    if(aux == NULL)
        return 0;

    // guardando o dado e incrementando o tamanho da lista
    aux->dado = dado;
    l->tam++;

    /* 1o caso: primeiro elemento */
    if(l->inicio == NULL){

        //todos apontam para o unico no existente
        l->inicio = aux;
        l->fim = aux;
        aux->ant = l->fim;
        aux->prox = l->inicio;

        return 1;
    }

    /* 2o caso: dado menor que o dado do inicio, insere no inicio */
    if(dado < l->inicio->dado){

        aux->ant = l->fim; //ant do novo inicio aponta para fim
        aux->prox = l->inicio; //prox do novo inicio aponta para antigo inicio
        l->inicio->ant = aux; // anterior do antigo inicio aponta para novo inicio
        l->inicio = aux; //l->inicio aponta para novo inicio
        l->fim->prox = l->inicio; //proximo do fim aponta para novo inicio

        return 1;
    }

    /* 3o caso: dado maior que o dado do fim, insere no fim */
    if(dado > l->fim->dado){

        aux->ant = l->fim; //ant do novo fim aponta para antigo fim
        aux->prox = l->inicio; //prox do novo fim aponta pra inicio
        l->fim->prox = aux; //prox do antigo fim aponta para novo fim
        l->fim = aux; //l->fim aponta para novo fim
        l->inicio->ant = l->fim; //ant do inicio aponta para novo fim

        return 1;
    }

    /* 4o caso: insercao ordenada no meio */

    // inicializa-se dois nos no comeco da lista, que serao responsaveis por percorre-la
    No *anterior = l->inicio;
    No *atual = anterior->prox;

    while(dado > atual->dado){

        // percorro a lista ate achar a posicao certa
        anterior = atual;
        atual = atual->prox;
    }
    // insiro o no entre anterior e atual
    aux->ant = anterior; // ant do novo no aponta para anterior
    aux->prox = atual; // prox do novo no aponta para atual
    anterior->prox = aux; // prox do anterior aponta para o novo no
    atual->ant = aux; // ant do atual aponta para o novo no

    return 1;
}

int retira(ListaCDE *l, int dado){

    No *aux;

    if(l->inicio == NULL){
        printf("Lista vazia\n");
        return 0;
    }

    /* 1o caso: lista unitaria */
    if((dado == l->inicio->dado) && (l->inicio == l->fim)) {
        aux = l->inicio; // aux aponta para o no que vou remover
        l->inicio = NULL; //inicio aponta pra null
        l->fim = NULL; // fim aponta pra null
        free(aux); // libero a memoria
        l->tam--;

        return 1;
    }

    /* 2o caso: removendo primeiro elemento */
    if(dado == l->inicio->dado) {
        aux = l->inicio; // aux aponta para o no que vou remover
        l->inicio = aux->prox; //inicio aponta para o novo inicio (o segundo elemento)
        l->inicio->ant = l->fim; // o anterior do novo inicio aponta para o fim
        l->fim->prox = l->inicio; // o proximo do fim aponta para o novo inicio
        free(aux); //libero memoria
        l->tam--;

        return 1;
    }

    /* 3o caso: removendo ultimo elemento */
    if(dado == l->fim->dado) {
        aux = l->fim; // aux aponta para o no que vou remover
        l->fim = aux->ant; //fim aponta para o novo fim (penultimo elemento)
        l->fim->prox = l->inicio; // o proximo do novo fim aponta para o inicio
        l->inicio->ant = l->fim; // o anterior do inicio aponta para o novo fim
        free(aux); //libero a memoria
        l->tam--;

        return 1;
    }

    /* 4o caso: removendo um elemento no meio */
    aux = l->inicio->prox; // aux aponta para o segundo elemento

    //percorro a lista ate achar o elemento, ou chegar no fim
    while((dado != aux->dado) && (aux != l->fim))
        aux = aux->prox;

    if(aux == l->fim){ // se cheguei ao fim, nao encontrei o elemento
        printf("O elemento %d nao esta na lista.\n", dado);
        return 0;
    }

    //se encontrei o elemento, removo ele
    aux->prox->ant = aux->ant; // o anterior do proximo a aux aponta para o elemento anterior a aux
    aux->ant->prox = aux->prox; // o proximo do anterior a aux aponta para o proximo elemento em relacao a aux
    free(aux); //libero a memoria
    l->tam--;

    return 1;
}

int estaVazia(ListaCDE l){

    if(l.inicio == NULL)
        return 1;

    return 0;
}

int getInicio(ListaCDE l){

    return l.inicio->dado;
}


int getFim(ListaCDE l){

    return l.fim->dado;
}

int getTamanho(ListaCDE l){

    return l.tam;
}

/*
    Exibe os elementos da lista, dependendo do sentido:
    1 - exibe do inicio ao fim
    2 - exibe do fim ao inicio
*/
void mostra(ListaCDE l, int sentido){

    No *aux;

    if(l.inicio == NULL) // lista vazia, nao mostra nada
            printf("Lista vazia!\n");

    else { // lista possui elementos, mostra dependendo do sentido

        if(sentido == 1){ // percorrendo do inicio ao fim

            printf("\nExibindo lista do inicio ao fim:\n\n");
            aux = l.inicio;
            do {
                printf("Dado: %d\n", aux->dado);
                aux = aux->prox;
            }while(aux != l.inicio);
        }

        else { // percorrendo do fim ao inicio

            printf("\nExibindo lista do fim ao inicio:\n\n");
            aux = l.fim;
            do {
                printf("Dado: %d\n", aux->dado);
                aux = aux->ant;
            } while(aux != l.fim);
        }
    }
}
