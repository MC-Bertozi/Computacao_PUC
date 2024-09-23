#include <stdio.h>

int conversao(int ano, int *pontDias);

int main()
{
    int ano, dias;

    printf("Digite um numero de anos:");
    scanf("%d", &ano);

    printf("\nO numero de meses eh: %d", conversao(ano, &dias));
    printf("\nO numero de dias eh: %d", dias);

return 0;
}

int conversao(int ano, int *pontDias)
{
    int meses= 12 * ano;
    int dias= meses * 30;
    *pontDias=dias;
    return meses;
}
