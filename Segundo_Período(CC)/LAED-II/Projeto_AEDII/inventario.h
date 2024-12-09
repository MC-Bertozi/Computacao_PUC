#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int id;
    int quantidade;
    char nome[20];
    char funcaoItem[50];

}Inventario;

typedef struct no{
    Inventario dado;
    struct no *prox;
    struct no *ant;
}No;

typedef struct{
    No *inicio;
    No *fim;
    int tam;
}Lista;

void opcoes();

//funcao arquivo
Inventario cadastraItem();
int leItem(FILE *f, Inventario *i);
int salvaInventario(Lista *l, char *filename);//le a lista e salvar por cima

//cria,insere, registra e mostra lista
void cria(Lista *l);
int insereItem(Lista *l, Inventario dado);
int retiraItem(Lista *l, int id);
int listaVazia(Lista l);
void mostra(Lista l);

void opcoes(){
    printf("\n-------------------------------------------\n");
    printf("Opcao 1: Guardar Item no Inventario;\n");
    printf("Opcao 2: Mostrar Inventario Atual;\n");
    printf("Opcao 3: Remover um Item do Inventario;\n");
    printf("Opcao 4: Fechar Inventario.\n");
    printf("-------------------------------------------\n");
}

//FUNCOES ARQUIVO

Inventario cadastraItem(){
    Inventario i;

    printf("\n-Digite as informacoes do Item: ");
    printf("\nId: ");
    scanf("%d", &i.id);
    getchar();
    printf("Nome do Item: ");
    scanf("%s", i.nome);
    printf("Caracteristicas do Item: ");
    scanf("%s", i.funcaoItem);
    printf("Quantidade: ");
    scanf("%d", &i.quantidade);

    return i;
}

int leItem(FILE *f, Inventario *i){

    return fscanf(f, "%d %s %s %d", &i->id, i->nome, i->funcaoItem, &i->quantidade);
}

int salvaInventario(Lista *l, char *filename){
    FILE *f = fopen(filename, "w");
    if(f == NULL){
        printf("Erro ao abrir o arquivo!!\n");
        exit(1);
    }

    No *aux;
    aux = l->inicio;
    do{

        printf("%s", aux->dado.nome);
        int n = fprintf(f, "%d %s %s %d\n", aux->dado.id, aux->dado.nome, aux->dado.funcaoItem, aux->dado.quantidade);
        printf(" %d", n);
        aux = aux->prox;
    } while(aux != NULL);

    fclose(f);
}

//FUNCOES LISTA (LDE)

void cria(Lista *l){
    l->inicio = NULL;
    l->fim = NULL;
    l->tam = 0;
}

int insereItem(Lista *l, Inventario dado){
    No *aux = (No *)malloc(sizeof(No));
    if(aux == NULL){
        printf("ERRO NA ALOCACAO DE MEMORIA!!");
        return 0;
    }

    aux->dado = dado;
    aux->prox = NULL;
    aux->ant = NULL;

    //1-o primeiro elemento
    if(l->inicio == NULL){
        l->inicio = aux;
        l->fim = aux;
        return 1;
    }

    //2-insercao no final
    l->fim->prox = aux;
    aux->ant = l->fim;
    l->fim = aux;

    l->tam++;
    return 1;
}

int retiraItem(Lista *l, int id){  //retira ponto da lista pelo Id
    No *aux;

    if(l->inicio == NULL){
        printf("LISTA VAZIA!!!");
        return 0;
    }

    //1-Lista unitaria
    if((id == l->inicio->dado.id) && (l->inicio == l->fim)) {
        aux = l->inicio;
        l->inicio = NULL;
        l->fim = NULL;
        free(aux);

        return 1;
    }

    //2-Retira no inicio (primeiro item)
    if(id == l->inicio->dado.id){
        aux = l->inicio;
        l->inicio = aux->prox;
        l->inicio->ant = NULL;
        free(aux);

        return 1;
    }
    //3- Retira no fim
    if (id == l->fim->dado.id) {
        aux = l->fim;
        l->fim = aux->ant;
        l->fim->prox = NULL;
        free(l->fim);

        return 1;
    }
    //4- Retira no meio
    aux = l->inicio;
    while (aux != NULL && aux->dado.id != id) {
        aux = aux->prox;
    }

    if (aux->dado.id != id) {
        printf("DADO NAO ENCONTRADO!!\n");
        return 0;
    }

    if (aux->ant != NULL) {
        aux->ant->prox = aux->prox;
    }

    if (aux->prox != NULL) {
        aux->prox->ant = aux->ant;
    }

    free(aux);
    return 1;
}

int listaVazia(Lista l){
    if(l.inicio == NULL)
        return 1;

    return 0;
}

void mostra(Lista l){

    No *aux;

    if(l.inicio == NULL)
            printf("LISTA VAZIA!!\n");

    else {
            printf("\nExibindo Inventario:\n\n");
            aux = l.inicio;
            while (aux != NULL) {
                printf("Id: %d\n", aux->dado.id);
                printf("Nome: %s\n", aux->dado.nome);
                printf("Caracteristica: %s\n", aux->dado.funcaoItem);
                printf("Quantidade: %d\n", aux->dado.quantidade);
                aux = aux->prox;
            }
        }
}
