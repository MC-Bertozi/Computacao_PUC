/*
1) Fa�a um programa que conta quantas vezes um determinado caractere aparece em um arquivo.
 O programa deve solicitar para o usu�rio o caractere que ele deseja contar.

2) Fa�a um programa que l� um arquivo com v�rias mensagens, cada uma separada em uma linha, e exibe somente
 as mensagens que s�o maiores que um n�mero arbitr�rio de caracteres. O programa deve solicitar esse n�mero para o usu�rio.

3) Fa�a um programa que l� um arquivo textual por completo, substitui o caractere " " por "_",
e salva o resultado sobrescrevendo o arquivo anterior.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char texto[100];
    char letra, repete;

    int count, tam;

    char filename[20] = "Questao01.txt";

    FILE *f;

    f = fopen(filename, "r");

    //verifica se abriu o arquivo
    if(f == NULL){
        printf("Problemas para abrir o arquivo 01!!!");
        exit(1);
    }

    printf(">>Digite a letra que deseja contar quantas vezes ela repete: ");
    scanf("%c", &repete);

    count = 0;
    while(1){
        letra = fgetc(f);

        if(letra == repete)
            count++;

        if(feof(f))
            break;
    }
     texto[count] = '\0';
     printf("\n>>A letra '%c' repete %d vezes.", repete, count);

     printf("\n>>O conteudo do arquivo eh: %s\n", texto);
}
