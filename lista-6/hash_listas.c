#include <stdio.h>
#include <stdlib.h>
#define size 7
#define HTNULL -1
typedef struct no{
    int ch;
    struct no *prox;
}
typedef struct lista_st{
    no *head;
}lista_st;

struct HT_st{
    int *ht;
}typedef HT_st;

void LEinit(lista_st *lista){
    lista->head = NULL;
}
void LEinsert(lista_st *lista, int ch){
    no *l = malloc(sizeof(no));
    l->ch=ch;
    l->prox=lista->head;
    lista->head=l;

}
int hash(int ch){
    return ch % size;
}

void HTinit(HT_st *ht){
    ht.ht=malloc(sizeof(int)*size)
    for(int i=0;i<size;i++){
        HT.ht[i]=HTNULL;
    }
}
void HTinsert(HT_st *HT, int x){
    int hashv = hash(x);
    LEinsert(&HT->ht[hashv].x);
}
int main(){
    HT_st hashtable;
    HTinit(&hashtable);
    return 0;
}