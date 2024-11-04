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

void cria(No **t);
int insere(No **t, int dado);
No *encontraMaxDireita(No **t);
int retira(No **t, int dado);
int maiorDireita(No *t);
int alturaArvore(No *t);
int contaNos(No *t);

void preOrdem(No *t);
void emOrdem(No *t);
void posOrdem(No *t);

int main(){
    No *arvore;
    int sucesso;

    cria(&arvore);

    sucesso = insere(&arvore, 30);
    sucesso = insere(&arvore, 10);
    sucesso = insere(&arvore, 70);
    sucesso = insere(&arvore, 100);
    sucesso = insere(&arvore, 5);
    sucesso = insere(&arvore, 20);
    sucesso = insere(&arvore, 15);
    sucesso = insere(&arvore, 13);
    sucesso = insere(&arvore, 19);
    sucesso = insere(&arvore, 17);
    sucesso = insere(&arvore, 527);

    printf("PRE ORDEM: ");
    preOrdem(arvore);

    printf("\n\nMAIOR VALOR NA ARVORE: %d\n", maiorDireita(arvore));
    printf("\nALTURA DA ARVORE: %d\n", alturaArvore(arvore));
    printf("\nQUANT. DE NOS NA ARVORE: %d\n", contaNos(arvore));
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

//retorna o maior valor na arvore binaria
int maiorDireita(No *t){
    if(t != NULL){
      if(t->dir != NULL)
        return maiorDireita(t->dir);
      return t->dado;
    }

    return -1;
}

int alturaArvore(No *t){
    if(t == NULL)
        return -1;

    int esq = alturaArvore(t->esq);
    int dir = alturaArvore(t->dir);

    if(dir > esq)
        return dir+1;

    return esq+1;
}

int contaNos(No *t){
    if(t == NULL)
        return 0;

    return contaNos(t->esq) + contaNos(t->dir) +1;
}
