#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ul unsigned long

Item lista[109]; // Revisar
int sizeTable = 0;
int pilhaTam = 0;

typedef struct {
    ul no, ant, prox;
    char visitado;
} Item;

struct Node{
    ul PTR;
    struct Node *prox;
};
typedef struct Node node;

int Hash(Item *key) {
    int h=0;
    h += key->no*(1LL);
    return (h*19) % 101;
} // Revisar para ver se funciona

void insert(Item *item) {
    int h = Hash(item);

    for (int j=0; j<20; j++) {
        int i=(h+(j*j)+23LL*j) % 101;
        if (*lista[i] == NULL) {
            sizeTable++;
            break;
        }
    }
} // Revisar

void inicia(node *PILHA) {
    PILHA->prox = NULL;
    pilhaTam=0;
}

int vazia(node *PILHA) {
    if(PILHA->prox == NULL)
    return 1;
    else
    return 0;
}

node *aloca(ul *PTR) {
    node *novo=(node *) malloc(sizeof(node));
    novo->PTR=PTR;

    if(!novo){
    printf("Sem memoria disponivel!\n");
    exit(1);
    }else{
    printf("Novo elemento: "); scanf("%lx", &novo->PTR);
    return novo;
    }
}

void push(node *PILHA, ul ptr) {
    node *novo=aloca(ptr);
    novo->prox = NULL;

    if(vazia(PILHA))
    PILHA->prox=novo;
    else{
    node *tmp = PILHA->prox;

    while(tmp->prox != NULL)
    tmp = tmp->prox;

    tmp->prox = novo;
    }
    pilhaTam++;
}

node *pop(node *PILHA) {
    if(PILHA->prox == NULL){
    printf("PILHA ja vazia\n\n");
    return NULL;
    }else{
    node *ultimo = PILHA->prox,
                *penultimo = PILHA;

    while(ultimo->prox != NULL){
    penultimo = ultimo;
    ultimo = ultimo->prox;
    }

    penultimo->prox = NULL;
    pilhaTam--;
    return ultimo;
    }
}

int saudavel(ul PTR1, ul PTR2) {
    node *p;
    inicia(p);

    ul aux = PTR1;
    while (aux!=NULL && aux!=PTR2){
        push(p, aux);
        Item *n = busca(lista, n);
        if (n->visitado!=0) return 0;
        n->visitado=1;
        aux= n->prox;
    }
    if (aux==PTR2) push(p, aux);
    else return 0;

    while(aux!=NULL && aux!=PTR1) {
        if(aux!=pop(p)) return 0;

        ul ant = busca_anterior(lista, aux);

        aux=ant;
    }

    if (aux!=pop(p)) return 0;
    if (vazia(p)) return 1;
    else return 0;
}

int main() {
    Item PTR1, PTR2, tmp;

    scanf("%lx %lx %lx", &PTR1.no, &PTR1.ant, &PTR1.prox);
    scanf("%lx %lx %lx", &PTR2.no, &PTR2.ant, &PTR2.prox);

    insere(&lista, PTR1); 
    insere(&lista, PTR2);
    while (scanf("%lx %lx %lx", &tmp.no, &tmp.ant, &tmp.prox)==3){
        insere(&lista, tmp);
    }

    int s = saudavel(PTR1.no, PTR2.no);
    printf("%d\n", s);
}
