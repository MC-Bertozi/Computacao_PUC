/*
Faça uma função recursiva que inverte um string. A função deve receber
como parâmetro o string e as posições a serem trocadas, começando das extremidades do string.
*/
#include <stdio.h>
#include <strings.h>

void inverteString(char *v, int esq, int dir);

int main()
{
    char nome[50] = "batata";
    printf(">>O nome original: %s\n", nome);
    inverteString(nome, 0, strlen(nome)-1);
    printf(">>O nome inverso eh: %s\n\n", nome);
}

void inverteString(char *v, int esq, int dir)
{
    if(esq < dir)
    {
        char aux = v[esq];
        v[esq] = v[dir];
        v[dir] = aux;
        inverteString(v, esq+1, dir-1);
    }
  //tem um criterio de parada implicito ja q a funcao eh chamada em loop ate que o if pare de funcionar
}
