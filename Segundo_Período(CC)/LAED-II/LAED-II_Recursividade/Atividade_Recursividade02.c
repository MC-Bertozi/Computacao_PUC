/*
Faça uma função recursiva que calcula o resto da divisão, MOD, de x por y,
 dois números inteiros positivos, usando a seguinte definição:
MOD(x,y) = MOD(x - y, y) se x > y
MOD(x,y) = x se x < y
MOD(x,y) = 0 se x = y
*/
#include <stdio.h>

int MOD(int x, int y);

int main()
{
    int x= 7, y=3;

    printf("O resto da divisao: %d\n", MOD(x,y));
}

int MOD(int x, int y)
{
    if(x > y) //parada
        return MOD(x-y, y);

    if(x==y)
        return 0;

    if(x<y)
        return x;
}
