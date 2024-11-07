#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//ARQUIVO DE LEITURAAAA

int main(){
    FILE *f;

    char filename[50] = "teste.txt";
    char texto[100];
    char letra;
    int contador = 0, tam;

    f = fopen(filename, "r"); //modo r (read)

    //LEITURA DE STRING POR CARACTERES

    //EOF -> end of file, flag (ou 0 ou 1). Enquanto estiver lendo EOF = 0, e quando chega no FINAL EOF = 1.
    while(1){
        letra = fgetc(f); //le um char e guarda na var letra

        if(feof(f)) //se for fim do arquivo quebra o while
            break;

        texto[contador] = letra;
        contador++;
    }

    texto[contador] = '\0';
    printf("O conteudo do arquivo eh: %s", texto);

    //LEITURA DE STRING POR COMPLETO

    rewind(f); //rebobinar. EOF volta a ser 0 para que a string seja lida novamente

    contador = 1;
    while(fgets(texto, 100, f) != NULL){
        tam = strlen(texto);
        if(tam > 0 && texto[tam-1] == '\n') //só limpando o \n e substituindo-o por \0
            texto[tam-1] = '\0';

        printf("\nMensagem %d: %s", contador, texto);
        contador++;
    }
    printf("\n");

    fclose(f);

    return 0;
}
