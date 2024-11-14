#include <stdio.h>
#include <stdlib.h>

//Truncate -> Apagar e resetar o arquivo
//a+ -> escrita no começo, leitura no meio / r+ -> lê primeiro, escreve no meio /w+ -> n consegue ler primeiro, ja q ele
                                                                            //le arquivo vazio, reseta e depois escreve
//usaremos o modo a+ de tipo de abertura

typedef struct{
    int id;
    char cor[20];
    float coordX;
    float coordY;
}Ponto;

int lerPonto(FILE *f, Ponto *p);
Ponto cadastraPonto();
int escrevePonto(FILE *f);

int main(){
    Ponto p;
    int n;
    FILE *f = fopen("ponto.txt", "a+");
    if(f == NULL){
        printf("Erro ao abrir o arquivo!!\n");
        exit(1);
    }

    printf("Pontos existentes no arquivo: \n");

    while(lerPonto(f, &p) > 0){
        printf("%d %s %f %f\n", p.id, p.cor, p.coordX, p.coordY);
    }

    printf("\n-------------------------------------------\n");
    printf("Registrando novo pontos...\n\n");

    printf("Quantos pontos voce deseja registrar? ");
    scanf("%d", &n);

    for(int i=0; i<n; i++)
        escrevePonto(f);


    fclose(f);

    return 0;
}

int lerPonto(FILE *f, Ponto *p){
//no fsanf() coloca primeiro o ponteiro de arquivo e depois usa da mesma maneira que um scanf normal
    //ao ler uma string no scanf nao usa &
    return fscanf(f, "%d %s %f %f", &p->id, p->cor, &p->coordX, &p->coordY);
}

Ponto cadastraPonto(){
    Ponto p;

    printf("\nDigite as informacoes do ponto: ");
    printf("\n\nId: ");
    scanf("%d", &p.id);
    getchar(); //necessario antes de ler a string para tirar o \n
    printf("Cor: ");
    scanf("%s", p.cor);
    printf("Coordenada X: ");
    scanf("%f", &p.coordX);
    printf("Coordenada Y: ");
    scanf("%f", &p.coordY);

    return p;
}

int escrevePonto(FILE *f){
    Ponto p = cadastraPonto();

    //mesma coisa do printf mas para formato de arquivo
    //registra com espaco e com\n no final
    return fprintf(f, "%d %s %2.2f %2.2f\n", p.id, p.cor, p.coordX, p.coordY);
}
