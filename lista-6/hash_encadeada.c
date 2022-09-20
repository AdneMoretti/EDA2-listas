#include <stdio.h>
#include <stdlib.h>
#define hash(a) (a.chave % 20);
#define hash2(a) (a % 20);
struct no{
    int  ch; 
    struct no *prox;
}typedef no;

int calcula_hash(int a){
    int h = hash2(a);
    return h;
}
void insere_hash(int ch){
    no *p = malloc(sizeof(no));
    p->ch = ch;
    p->prox=tb->prox;
    tb->prox=p;
}
// void contabiliza (int ch){
//     no *p;
//     p = tb;
//     while(p != NULL && p->chave != ch)
//        p = p->prox;
//     if(p != NULL) 
//        printf("achou");
//     else{
//        p = malloc(sizeof(no));
//        p->chave = ch;
//        p->prox = tb;       
//        tb = p; 
//        printf("inseriiu");   
//     }   
// }
int main(void){
    for(int i=0;i<5;i++){
        ht[i]->prox = NULL;
    }
    int num1;
    for(int i=0;i<3;i++){
        scanf("%d", &num1);
        int h = calcula_hash(num1);
        tb = ht[h];
        insere_hash(num1);
    }
    for(int i=0;i<5;i++){
        if(ht[i]->prox!=NULL){
            no *p = ht[i]->prox;
            while(p!=NULL){
                printf("%d", p->ch);
                p=p->prox;
            }
        }
    }
}