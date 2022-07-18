#include <stdio.h>

void selectionsort(int *v, int l, int r){
    for(int i=l;i<r; i++){
        int menor = i;
        for(int j=i+1; j<=r;j++){
            if(v[j]<v[menor]){
                menor = j;
            }
        }
    int temp = v[i];
    v[i] = v[menor];
    v[menor] = temp;
    }
}
int main(void){
    int numero, count=0;
    int v[1000];
    while(scanf("%d", &numero)!=EOF){
        count++;
        v[count-1] = numero;
    }
    selectionsort(v, 0, count-1);

    for(int i=0;i<count;i++){
        printf("%d", v[i]);
        if(i==count-1)  printf("\n");
        else printf(" ");
    }
}