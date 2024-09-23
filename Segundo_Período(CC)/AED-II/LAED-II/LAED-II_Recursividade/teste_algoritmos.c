#include<stdio.h>
#include<stdlib.h>
#include <time.h>

void trocar(int *v, int i, int j);
int *alocaVetor(int tam);
void preencheVetor(int *v, int tam);
void imprimeVetor(int *v, int tam);

void bubblesort(int *v, int tam);
int particiona(int *v, int esq, int dir);
void quicksort(int *v, int esq, int dir);

int main()
{
    srand(time(NULL));
    clock_t inicio, fim;
    float secs = 0;

    int *v1, *v2, tam; //v1 -> bubble ; v2->quick

    printf(">>Digite o tamanho do vetor:");
    scanf("%d", &tam);

    v1 = alocaVetor(tam);
    v2 = alocaVetor(tam);

    preencheVetor(v1, tam);
    preencheVetor(v2, tam);

    /*printf("\n>>Vetores v1 e v2, respectivamente, antes do bubble e quick:\n");
    imprimeVetor(v1, tam);
    imprimeVetor(v2, tam);*/

    //antes dos algoritmos
    inicio = clock();
    bubblesort(v1, tam);
    fim = clock();
    secs = (float) (fim - inicio)/CLOCKS_PER_SEC;
    printf("\n>>Tempo exe do bubble: %f\n", secs);
    secs = 0;

    inicio = clock();
    quicksort(v2, 0, tam-1);
    fim = clock();
    secs = (float) (fim - inicio)/CLOCKS_PER_SEC;
    printf("\n>>Tempo exe do quick: %f\n", secs);

    free(v1);
    free(v2);
    return 0;
}

void trocar(int *v, int i, int j)
{
    int aux;
    aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

int *alocaVetor(int tam)
{
    int *v;
    v = (int *) malloc(sizeof(int)*tam);
    if(v==NULL)
    {
        printf("Puts...Fudeu!");
        exit(1);
    }

    return v;
}

void preencheVetor(int *v, int tam)
{
    for(int i=0; i<tam; i++)
    {
        v[i] = rand() % 100;
    }
}

void imprimeVetor(int *v, int tam)
{
    for(int i=0; i<tam; i++)
    {
        printf("%d\t", v[i]);
    }
    printf("\n");
}

void bubblesort(int *v, int tam)
{
    for(int i = 0; i < tam-1; i++)
    {
        for(int j = 0; j < tam-1-i; j++)
        {
            if(v[j] > v[j+1])
                trocar(v, j, j+1);
        }
    }
}

int particiona(int *v, int esq, int dir)
{

    int i = esq, j = dir, x = v[esq];

    while(i < j)
    {
        while ((v[i] <= x) && (i < dir))
            i++;
        while ((v[j] > x))
            j--;
        if (i < j)
            trocar(v, i, j);
    }
    trocar(v, esq, j);

    return j;
}

void quicksort(int *v, int esq, int dir)
{
    if(esq >= dir)
        return;

    int pivo = particiona(v, esq, dir);
    quicksort(v, esq, pivo - 1);
    quicksort(v, pivo + 1, dir);
}
