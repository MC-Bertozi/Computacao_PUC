/* implemente funções que resolvem os seguintes problemas:

1-Encontrar o maior elemento da árvore de busca binária (enquanto direita tiver filho, recursivo).
2-Encontrar a altura da árvore (altura = filho mais longe; arvore vazia = -1, um No =0; recursivo).
3-Contar a quantidade de elementos dessa árvore. (criterio de parada arvore == NULL devolve 0, desce esquerda+direita+pai)
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct no {

    int dado;
    struct no *esq;
    struct no *dir;
} No;

//funcoes de manipulacao
void cria(No **t);
int insere(No **t, int dado);
No *encontraMaxDireita(No **t);
int retira(No **t, int dado);
int maiorDireita(No *t);
int alturaArvore(No *t);

//funcoes de visualizacao
void preOrdem(No *t);
void emOrdem(No *t);
void posOrdem(No *t);

int main(){

    No *arvore;
    int sucesso;

    cria(&arvore);

    sucesso = insere(&arvore, 12);
    sucesso = insere(&arvore, 5);
    sucesso = insere(&arvore, 4);
    sucesso = insere(&arvore, 3);
    sucesso = insere(&arvore, 9);
    sucesso = insere(&arvore, 50);
    sucesso = insere(&arvore, 6);
    sucesso = insere(&arvore, 11);
    sucesso = insere(&arvore, 8);
    sucesso = insere(&arvore, 7);
    sucesso = insere(&arvore, 15);
    sucesso = insere(&arvore, 20);

    printf("PRE ORDEM: ");
    preOrdem(arvore);

    /*
    printf("\n\nEM ORDEM: ");
    emOrdem(arvore);

    printf("\n\nPRE ORDEM: ");
    posOrdem(arvore);
    */
/*
    printf("\n\nREMOVENDO NO 1 - caso 1, sem filhos:\n");
    sucesso = retira(&arvore, 1);
    printf("PRE ORDEM: ");
    preOrdem(arvore);

    printf("\n\nREMOVENDO NO 4: caso 2, filho a esquerda:\n");
    sucesso = retira(&arvore, 4);
    printf("PRE ORDEM: ");
    preOrdem(arvore);

    printf("\n\nREMOVENDO NO 15: caso 3, filho a direita:\n");
    sucesso = retira(&arvore, 15);
    printf("PRE ORDEM: ");
    preOrdem(arvore);

    printf("\n\nREMOVENDO NO 9: caso 4, dois filhos:\n");
    sucesso = retira(&arvore, 9);
    printf("PRE ORDEM: ");
    preOrdem(arvore);*/

    maiorDireita(arvore);
    printf("Altura: %d", alturaArvore(arvore));
}

void cria(No **t){

    *t = NULL;
}

int insere(No **t, int dado){

    if(*t == NULL) {
        *t = (No *) malloc(sizeof(No));
        if(*t == NULL)
            return 0;

        (*t)->dado = dado; //atribuo o dado ao novo No
        (*t)->esq = NULL; // esq do meu novo No eh NULL
        (*t)->dir = NULL; // dir do meu novo No eh NULL

        return 1;
    }

    if(dado < (*t)->dado) //se o dado eh menor que o dado do No corrente
        return insere(&(*t)->esq, dado); // chamo a funcao recursivamente para o No da esquerda

    return insere(&(*t)->dir, dado); // senao, chamo recursivamente para o No da direita
}

No *encontraMaxDireita(No **t){
    if((*t)->dir != NULL) // enquanto nao chegar no No mais a direita, vou descendo para a direita
        return encontraMaxDireita(&(*t)->dir);

    No *aux = *t;
    if((*t)->esq != NULL) // se meu no escolhido tiver um filho a esquerda
        *t = (*t)->esq; // eu movo ele para a sua antiga posicao
    else
        *t = NULL; // se o escolhido nao tem filho, entao quem esta apontando pra ele deve apontar pra NULL

    return aux; // devolvo o no escolhido

}

int retira(No **t, int dado){

    if(*t == NULL){ // se cheguei em um no vazio, sinal que o dado nao existe, retorno FALHA
        printf("Elemento inexistente: %d\n\n", dado);
        return 0;
    }

    if(dado < (*t)-> dado) // dado menor, movo pra subarvore da esquerda
        return retira(&(*t)->esq, dado);

    if(dado > (*t)->dado) // dado maior, movo para subarvore da direita
        return retira(&(*t)->dir, dado);

    No *aux = *t; // aux guarda o no a ser removido

    /* 1o caso: nao tenho filhos */
    if(((*t)->esq == NULL) && ((*t)->dir == NULL)) {
        *t = NULL; // o ponteiro para o no a ser removido recebe null
        free(aux); // libero a memoria
        return 1;
    }

    /* 2o caso: tenho somente o filho da esquerda */
    if((*t)->dir == NULL) {
        *t = (*t)->esq; // o ponteiro para o no a ser removido passa a apontar para o filho esquerdo
        free(aux); // libero a memoria
        return 1;
    }

    /* 3o caso: tenho somente o filho da direita */
    if((*t)->esq == NULL) {
        *t = (*t)->dir; // o ponteiro para o no a ser removido passa a apontar para o filho direito
        free(aux);
        return 1;
    }

    No *substituto = encontraMaxDireita(&(*t)->esq); // encontro o no substituto (no mais a direita da subarvore a esquerda)
    substituto->esq = (*t)->esq; // substituto recebe o filho a esquerda do no a ser removido
    substituto->dir = (*t)->dir; // substituto recebe o filho a direita do no a ser removido
    *t = substituto; // o ponteiro para o no a ser removido passa a apontar para o no substituto
    free(aux); // libero a memoria
    return 1;

}

void preOrdem(No *t) {

    if(t != NULL) {
        printf("%d ", t->dado);
        preOrdem(t->esq);
        preOrdem(t->dir);
    }
}

void emOrdem(No *t) {

    if(t != NULL) {
        emOrdem(t->esq);
        printf("%d ", t->dado);
        emOrdem(t->dir);
    }
}

void posOrdem(No *t) {

    if(t != NULL) {
        posOrdem(t->esq);
        posOrdem(t->dir);
        printf("%d ", t->dado);
    }
}

int maiorDireita(No *t){
    if(t->dir != NULL)
        return maiorDireita(t->dir);

    printf("\nMaior valor: %d\n", t->dado);
}

int alturaArvore(No *t){
    int esq = alturaArvore(t->esq);
    int dir = alturaArvore(t->dir);

    if(esq > dir)
        return esq++;
    if(dir > esq)
        return dir++;
}
