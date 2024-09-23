#include <stdio.h>

int divisao(int a, int b,int *resto);

int main()
{
    int a, b, resto, quo;

    printf("Digite dois numeros (dividendo e divisor):");
    scanf("%d %d", &a, &b);

    printf(">>O quociente eh: %d", divisao(a, b, &resto));
    printf("\n>>O resto eh: %d", resto);

    return 1;
}

int divisao(int a, int b,int *resto)
{
    if(b==0)
        printf("\n>>Calculo impossivel!!\n");

    *resto = a % b;

    return a/b;
}
