/*
Um mecanismo muito conhecido para determinar o maior divisor comum entre dois inteiros e positivos é o Algoritmo de Euclides. Segundo esse algoritmo, a função mdc é definida da seguinte forma:

mdc(x,y) = y , se y <= x e x%y = 0;
mdc(x,y) = mdc(y,x), se x < y;
mdc(x,y) = mdc(y,x % y), caso contrário.

Implemente uma função recursiva que calcule o mdc entre dois números inteiros e positivos, utilizando o Algoritmo de Euclides.
*/

#include <stdio.h>

int mdc(int x, int y);

int main()
{
    int x, y;
    printf("Digite dois numeros:");
    scanf("%d %d", &x, &y);

    printf("\nO MDC entre %d e %d eh: %d\n", x, y, mdc(x,y));

    return 1;
}

int mdc(int x, int y)
{
    if((y<= x) && (x%y==0))
        return y; //resultado do mdc
    if(x<y)
        return mdc(y,x); //troca o x com o y pra deixar o y sempre menor que o x

    return mdc(y,x % y); //resultado do mdc , calculo qque sera feito recursivamente
}
