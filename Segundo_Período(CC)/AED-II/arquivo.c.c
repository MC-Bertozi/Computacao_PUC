#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *f;

    char filename[50] = "teste.txt"; //só o nome do arquivo
                                      //a extensão (.txt) não muda nada, pode-se colocar qualquer extensão mas ainda sim vai
                                      //ser um arquivo textual

    char texto[100];
    int tam;

    f = fopen(filename, "w"); /*1- string, nome do arquivo; 2- string (char *), diz o modo de abertura (modo leitura OU modo escrita)*/
                              /*modo de escrita = "w" (reescreve o arquivo) ou "a" (abre o arquivo e insere no final, append);*/
                              //w (write) -> salva por cima; a (append) -> salva mantendo o que foi salvo anteriormente

    printf("Digite uma mensagem: ");
    fgets(texto, 100, stdin); //ele guarda o \n da string
    tam = strlen(texto);
    if(tam > 0 && texto[tam-1] == '\n') //pra ver se existe mesmo o \n
        texto[tam-1] = '\0'; //para que o fgets nao guarde o \n e substitua-o por \0, que indica o final da string

    for(int i =0; i<strlen(texto); i++){ //usamos o strlen já que trocamos o tam da string no if anterior
        fputc(texto[i], f); //para salvar no arquivo o texto escrito
        /*1- inteiro (tabela ASCII); 2- arquivo buffer*/
    }
    fputc('\n', f);

    printf("Digite uma segunda mensagem: ");
    fgets(texto, 100, stdin);

    fputs(texto, f); //espera um  char e um arquivo


    fclose(f); //mesma coisa que o free(), libera o ponteiro de arquivos || fecha o buffer de arquivo

    return 0;
}
