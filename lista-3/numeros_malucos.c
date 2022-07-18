#include <stdio.h>
#include <stdlib.h>

int *intercala(int *vetor, int l1, int r1, int *v2, int l2, int r2){
    int *c = malloc(sizeof(int)*(r2-l2+1+r1-l1+1));
    int k=0;
    while(l1<=r1 && l2<=r2){
        if(vetor[l1]<=v2[l2]){
            c[k++]=vetor[l1++];
        }
        else{
            c[k++]=v2[l2++];
        }
    }
    while(l1<=r1){
        c[k++]=vetor[l1++];
    }
    while(l2<=r2){
        c[k++]=v2[l2++];
    }
    return c;
}
void merge(int *vetor, int l, int m, int r){
    int *c = malloc(sizeof(int)*(r-l+1));
    int k=0, i=l, j=m+1;

    while(i<=m && j<=r){
        if(vetor[i]<=vetor[j]){
            c[k++]=vetor[i++];
        }
        else{
            c[k++]=vetor[j++];
        }
    }
    while(i<=m){
        c[k++]=vetor[i++];
    }
    while(j<=r){
        c[k++]=vetor[j++];
    }
    k=0;
    for(int i=l;i<=r;i++){
        vetor[i]=c[k++];
    }
    free(c);
}
void mergesort(int *vetor, int l, int r){
    if(l>=r) return;
    int m = (l+r)/2;
    mergesort(vetor, l, m);
    mergesort(vetor, m+1, r);
    merge(vetor, l, m, r);
}

int busca_binaria(int *vetor, int l, int r, int num){     
    int meio=(l+r)/2;
    if(num==vetor[meio]) return meio;
    if(l>=r){
        return -1;
    }
    if(num<vetor[meio]) busca_binaria(vetor, l, meio, num);  
    else busca_binaria(vetor, meio+1, r, num);                                            
}
int main(void){
    int N, num;
    scanf("%d", &N);
    int vetor[2000000];
    for(int i=0;i<N;i++){
        scanf("%d", &vetor[i]);
    }
    mergesort(vetor, 0, N-1);
    int i2=0;
    for(int i=1;i<N;i++){
        if(vetor[i]!=vetor[i2]){
            vetor[++i2]=vetor[i];
        }
    }
    int count=i2;
    if((count%2)==0){
        vetor[++count]=1000000000;
    }
    int nums[66000];
    int nmvi=-1;

    for(int i=0;i<=count;i+=2){
        nums[++nmvi]=vetor[i]+vetor[i+1];
        if(busca_binaria(vetor, 0, count, nums[nmvi])!=-1){
            nmvi--;
        }
    }
    int *c = intercala(vetor, 0, count, nums, 0, nmvi);

    for(int i=0;i<=(count+nmvi+1);i+=4){
        printf("%d\n", c[i]);
    }

    printf("Elementos: %d\n", (count+nmvi+2));
}