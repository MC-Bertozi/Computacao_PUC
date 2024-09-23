#include <stdio.h>
#include <stdlib.h>

//o srand e rand so da valores int

typedef struct no
{
    float dado;
    struct no *prox;
} No;

No *aloca(float dado);
float maiordado(No *v);
float menordado(No *v);

int main()
{
    No *n0, *n1, *n2, *n3, *n4;
    float result, menor;

    //os ponteiros sao alocados na hap e recebem seus valores
    n0 = aloca(0.05);
    n1 = aloca(0.9);
    n2 = aloca(2.5);
    n3 = aloca(9.8);
    n4 = aloca(67.5);

    //ligando os ponteiros e fazendo os nos
    n0 -> prox = n1;
    n1 -> prox = n2;
    n2 -> prox = n3;
    n3 -> prox = n4;

    printf(">>O maior e menor dado usando No<<\n");
    printf("===================================\n\n");
    result = maiordado(n0);
    printf(">>O maior dado eh: %2.4f\n", result);

    menor = menordado(n0);
    printf(">>O maior dado eh: %2.4f\n", menor);

    //free do malloc
    free(n0);
    free(n1);
    free(n2);
    free(n3);
    free(n4);
}

No *aloca(float dado)
{
    No *aux;
    aux = (No *) malloc(sizeof(No));
    if(aux == NULL)
    {
        printf("Puts, a alocacao nao deu certo...");
        exit(0);
    }
    aux->dado = dado;
    aux->prox = NULL;

    return aux;
}

float maiordado(No *v)
{
    float maior = v->dado;

    while(v != NULL)
    {
      if(v->dado > maior)
      {
          maior = v->dado;
      }
      v = v->prox;
    }

    return maior;
}

float menordado(No *v)
{
    float menor = v->dado;

    while(v != NULL)
    {
      if(v->dado < menor)
      {
          menor = v->dado;
      }
      v = v->prox;
    }

    return menor;
}
