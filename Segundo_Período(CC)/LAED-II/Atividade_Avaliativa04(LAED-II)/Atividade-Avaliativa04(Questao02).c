/*
2) Faça um programa que lê um arquivo com várias mensagens, cada uma separada em uma linha, e exibe somente
 as mensagens que são maiores que um número arbitrário de caracteres. O programa deve solicitar esse número para o usuário.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char arquivo[20] = "Questao02.txt";
    char texto[200];

    int num_character;

    FILE *a;
    a = fopen(arquivo, "r");

    //verifica se abriu o arquivo
    if(a == NULL){
        printf("Problemas para abrir o arquivo 02");
        exit(1);
    }

    printf("Digite a quantidade de caracteres para filtrar mensagens: "); //45
    scanf("%d", &num_character);

    while(fgets(texto, 200, a)!=NULL){
            if(strlen(texto) > num_character)
                 printf("\n%s\n", texto);
    }

    fclose(a);
}
