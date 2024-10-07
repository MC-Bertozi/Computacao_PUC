/*
Nessa atividade, iremos simular o funcionamento de uma fila de banco de forma simplificada. Para tal, iremos definir uma Struct Pessoa,
que irá atuar como o dado a ser inserido na fila. Recorde que a implementação de Filas de referência considera dados do tipo int; neste caso,
nosso dado é do tipo Pessoa. Uma pessoa possui: seu nome (string),  cpf (string) e uma senha (int).

A partir do código acima, faça os ajustes necessários nas estruturas e funções referentes a fila,
lembrando de trocar o tipo do dado nos dois casos. A seguir, limpe o main() e faça uma implementação que siga os seguintes passos:

Instancie e inicialize uma fila;
Faça uma estrutura de repetição que execute 20 vezes;
A cada passo da repetição, gere um número aleatório de 1 a 100. ->caso se a fila estiver vazia
Se esse número for menor ou igual a 60, uma nova pessoa chega na fila: você deverá instanciar uma Pessoa e colher seus dados com scanf() e/ou gets().
Por fim, essa pessoa deverá ser inserida na fila (exiba uma mensagem que essa pessoa entrou na fila com sucesso).
Se esse número for maior que 60 e existirem pessoas na fila, você deverá remover uma Pessoa da fila, e exibir seus dados.
Caso a fila esteja vazia, exiba uma mensagem alertando esse fato.
Após terminar a execução da repetição, se a fila não estiver vazia, ou seja, ainda houverem pessoas nela, termine de desenfileirar todas.

*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct pessoa
{
    char nome[50];
    int cpf[12];
    int senha;
} Pessoa;

typedef struct no
{
    Pessoa dado;
    struct no *prox;
} No;

typedef struct
{
    No *inicio;
    No *fim;
    int tamFila;
} Fila;

void cria(Fila *q);
int insere(Fila *q, Pessoa dado);
int retira(Fila *q, Pessoa *dado);

int estaVazia(Fila q);
Pessoa getInicio(Fila q);
Pessoa getFim(Fila q);
int getTamanho(Fila q);
void mostra(Fila q);

int main()
{
    Fila q;
    Pessoa lista;
    int num = 0;
    int random = 0;
    int sucesso;
    srand(time(NULL));

    cria(&q);

    while(num <= 20)
    {
        random =  rand()%100 +1;

        if(random <= 60)
        {
            printf("Digite seu NOME, CPF e SENHA:");
            scanf("%s %d %d", lista.nome, lista.cpf, lista.senha);

            if(insere(&q, lista))
                printf("\nParabens!!Voce entrou na fila, agora espere\n\n");
        }


        if(num>60 && !estaVazia(q))
        {
            retira(&q, &lista);
        }
    }

    while(!estaVazia(q)){
        sucesso = retira(&q, &lista);
        if(sucesso){
            printf("\nINFO PESSOA Q SAIU DA FILA:\n");
            printf("Nome: %s CPF: %d  Senha: %d\n", lista.nome, lista.cpf, lista.senha);
        }
        else
            printf("\nFila Vazia!!\n\n");
    }

}

void cria(Fila *q)
{
    q->inicio = NULL;
    q->fim = NULL;
    q->tamFila = 0;
}

int insere(Fila *q, Pessoa dado)
{
    No *aux;
    aux = (No *) malloc(sizeof(No));
    if(aux == NULL) //
        return 0;

    aux->dado = dado;
    aux->prox = NULL;

    q->tamFila++;

    if(q->inicio == NULL)
    {
        q->inicio = aux;
        q->fim = aux;
        return 1;
    }

    q->fim->prox = aux;
    q->fim = aux;
    return 1;
}

int retira(Fila *q, Pessoa *dado)
{
    No *aux;
    aux = q->inicio;
    if(aux == NULL)
        return 0;

    *dado = aux->dado;
    q->tamFila--;
    q->inicio = aux->prox;

    if(q->inicio == NULL)
        q->fim = NULL;
    free(aux);

    return 1;
}

int estaVazia(Fila q)
{
    if(q.inicio == NULL)
        return 1;

    return 0;
}

Pessoa getInicio(Fila q)
{
    return q.inicio->dado;
}

Pessoa getFim(Fila q)
{
    return q.fim->dado;
}

int getTamanho(Fila q)
{
    return q.tamFila;
}

void mostra(Fila q)
{
    No *aux;
    aux = q.inicio;
    if (aux == NULL)
    {
        printf("Fila vazia!\n");
    }

    while(aux != NULL)
    {
        printf("NOME: %s", aux->dado.nome);
        printf("CPF: %d", aux->dado.cpf);
        printf("SENHA: %d", aux->dado.senha);
        aux = aux->prox;
    }
}

