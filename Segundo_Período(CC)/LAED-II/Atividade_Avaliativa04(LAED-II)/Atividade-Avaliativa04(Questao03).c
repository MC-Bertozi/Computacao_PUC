/*
3) Faça um programa que lê um arquivo textual por completo, substitui o caractere " " por "_",
e salva o resultado sobrescrevendo o arquivo anterior.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char texto[1000], letra;
    char nomeArquivo[200] = "Questao03.txt";
    int count = 0;

    FILE *n;

    n = fopen(nomeArquivo, "r");

    if(n == NULL){
        printf("Problemas para abrir o arquivo 01!!!");
        exit(1);
    }

    while(1){
        letra = fgetc(n);

        if(feof(n))
            break;

        if(letra == ' ')
            letra = '_';

        texto[count] = letra;
        count++;
    }
    fclose(n);

    n = fopen(nomeArquivo, "w");
    fputs(texto,n);

    fclose(n);
}
