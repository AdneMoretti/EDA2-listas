#include <stdio.h>

void insertionsort(int *v, int l, int r){
    for(int i=l;i<=r; i++){
        for(int j=i; j>l;j--){
            if(v[j-1]>v[j]){
                int temp = v[j];
                v[j] = v[j-1];
                v[j-1] = temp;
            }
        }
    }
}
int main(void){
    int numero, count=0;
    int v[1000];
    while(scanf("%d", &numero)!=EOF){
        count++;
        v[count-1] = numero;
    }
    insertionsort(v, 0, count-1);

    for(int i=0;i<count;i++){
        printf("%d", v[i]);
        if(i==count-1)  printf("\n");
        else printf(" ");
    }
}