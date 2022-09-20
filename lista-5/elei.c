#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EXCH(A, B){item t=B; B=A; A=t;}
#define CMPEXCH(A, B){if(LESS(B, A)) EXCH(A, B)}
#define LESS(A, B) (A.key == B.key? A.num > B.num : A.key>B.key) 

struct Item{
    int key;
    int num;
}typedef item;

item ht[100000];

int separa(item *v, int l, int r){
    item c = v[r];
    int i=l;
    for(int j=l;j<r;j++){
        if (LESS(v[j], c))
        {
            EXCH(v[j], v[i]);
            i++;
        }
    }
    EXCH(v[i], v[r])
    return i;
}
void quicksort(item *v, int l, int r){
    if(r-l<=32) return;
    CMPEXCH(v[(l+r)/2], v[r])
        CMPEXCH(v[l], v[(l+r)/2])
            CMPEXCH(v[r], v[(l+r)/2])
    int j=separa(v, l, r);
    quicksort(v, l, j-1);
    quicksort(v, j+1, r);
}
void insertionsort(item *v, int l, int r)
{
    for (int i=l+1, j; i<=r; i++)
    {
        item c = v[i];
        for (j = i; j > 0 && LESS(c, v[j - 1]); j--)
            v[j] = v[j - 1];
        v[j] = c;
    }
}
void quicksort1(item *v, int l, int r){
    quicksort(v, l, r);
    insertionsort(v, l, r);
}
int main(void){
    int s, f, e;
    int qtdp=0, qtdr=0, qtdnulos=0;
    int n, num;
    item presida[91], senador[901], federal[9001], estadual[90001];
    scanf("%d %d %d",&s, &f, &e );
    memset(ht, 0, 100000*sizeof(item));
    while(scanf("%d%n", &n, &num)==1){
        if(n<0){
             qtdnulos++;
        }
        else{
            switch(num){
                case(3):
                    ht[n].key++;
                    ht[n].num=n;
                    qtdp++;
                    break;
                case(4):
                    ht[n].key++;
                    ht[n].num=n;
                    qtdr++;
                    break;
                case(5):
                    ht[n].key++;
                    ht[n].num=n;
                    qtdr++;
                    break;
                default:
                    ht[n].key++;
                    ht[n].num=n;
                    qtdr++;
                    break;
            }
        }
    }
    int kp=0, ks=0,kf=0, ke=0, i;
    for(i=10;i<=99;i++){
        if(ht[i].key) presida[kp++]=ht[i];
    }
    for(i=100;i<=999;i++){
        if(ht[i].key) senador[ks++]=ht[i];
    }
    for(i=1000;i<=9999;i++){
        if(ht[i].key) federal[kf++]=ht[i];
    }
    for(i=10000;i<=99999;i++){
        if(ht[i].key) estadual[ke++]=ht[i];
    }
    quicksort1(presida, 0, kp-1);
    quicksort1(senador, 0, ks-1);
    quicksort1(federal, 0, kf-1);
    quicksort1(estadual, 0, ke-1);

    printf("%d %d\n", qtdp+(qtdr), qtdnulos);

    if(presida[0].key>qtdp/2) printf("%d\n", presida[0].num);
    else printf("Segundo turno\n");

    for(i=0; i<s;i++){
        printf("%d", senador[i].num);
        if(i!=s-1) printf(" ");
    }
    printf("\n");
    for(i=0; i<f;i++){
        printf("%d", federal[i].num);
        if(i!=f-1) printf(" ");
    }
    printf("\n");
    for(i=0; i<e;i++){
        printf("%d", estadual[i].num);
        if(i!=e-1) printf(" ");
    }
    printf("\n");
}