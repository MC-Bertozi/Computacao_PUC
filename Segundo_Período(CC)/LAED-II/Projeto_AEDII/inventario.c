#include <stdio.h>
#include <stdlib.h>
#include "inventario.h"

int main(){
    Lista l;
    Inventario i;
    int n, id;

    FILE *f = fopen("inventario.txt", "r");
    if(f == NULL){
        printf("Erro ao abrir o inventario(arquivo)!!\n");
        exit(1);
    }

    cria(&l);

    while(leItem(f, &i) > 0)
        insereItem(&l, i);

    fclose(f);

    printf("INVENTARIO");

    do{
        opcoes();

        printf("\n>>O que deseja fazer? (use somente os numeros das opcoes): ");
        scanf("%d", &n);

        switch(n){
        case 1: i = cadastraItem();
                insereItem(&l, i);
            break;

        case 2:
            mostra(l);
            break;

        case 3:
            printf("\nDigite o ID do Item a ser retirado: ");
            scanf("%d", &id);
            retiraItem(&l, id);
            break;

        case 4:
            salvaInventario(&l, "inventario.txt");
            exit(1);
            break;
        }
    }while(1);

    fclose(f);

    return 0;
}
