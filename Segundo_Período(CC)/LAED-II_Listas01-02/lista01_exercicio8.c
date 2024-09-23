/*
>>Exercício 07
Escreva um código em C que faça a inserção de valores informados pelo usuário em um vetor. Primeiramente, seu código deve solicitar
o número de valores que serão inseridos,em seguida você deve alocar a memória dinamicamente para que estes valores
possam ser inseridos no vetor.

>>Exercício 08
Calcule a média, através de uma função, dos valores presentes no vetor do Exercício 07.
*/
#include <stdio.h>
#include <stdlib.h>

int *alocaVetor(int tam); //quando quero alocar a memoria ela deve devolver para o main depois
void preencheVetor(int *v, int tam);
float mediaVetor(int *v, int tam);

int main()
{
    int tamanho, *v;
    printf(">>Digite o tamanho do seu vetor:");
    scanf("%d", &tamanho);

    v = alocaVetor(tamanho);
    preencheVetor(v, tamanho);
    printf("\n>>A media do valores do vetor eh: %2.2f\n", mediaVetor(v, tamanho));

    free(v); //limpa o buffer apos a alocacao de memoria pra que a memoria n seja queimada, e como destamos alocando a memoria no v os damos um free em v
    //damos o free no main, e n dentro da funcao aloca, para que a alocacao nao seja feita novamente
    return 1;
}

int *alocaVetor(int tam)
{
    int *v = (int *) malloc(sizeof(int)*tam);
    //por ser uma funcao de ponteiro de inteiro ent necessita retornar um ponteiro de inteiro
    //CASTING -> dart um tipo para o RETORNO do malloc, NAO É OBRIGATORIO MAAS eh o recomendado
    if(v==NULL)
    {
        printf("Erro na alocacao!!!!!");
        exit(0);
    }

    return v;
}

void preencheVetor(int *v, int tam) //*v == v[]
{
    for(int i=0; i<tam; i++)
    {
        printf("\n>Digite o valor da posicao %d:", i);
        scanf("%d", &v[i]);
    }
}

float mediaVetor(int *v, int tam)
{
    int soma=0;
    for(int i=0; i<tam;i++)
        soma+=v[i];

    return soma/tam;
}
