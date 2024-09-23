#include <stdio.h>

int potencia(int x, int n);

int main()
{
    int x = 3, n = 2;

    printf("O resultado eh: %d\n", potencia(x,n));

    return 1;
}

int potencia(int x, int n)
{
    if(n==1) //parada
        return x;

    return x*potencia(x, n-1);
}
