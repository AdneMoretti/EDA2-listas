#include <stdio.h>
#include <stdlib.h>

void merge(int *v, int l, int m, int r){
    int *novo = malloc((r-l+1)*sizeof(int));
    int i = l;
    int j = m + 1;
    int k = 0;

    while(i<=m && j<=r){
      if(v[i] <= v[j]){
        novo[k] = v[i];
        k++, i++;
      }
      else{
          novo[k] = v[j];
          k++, j++;
      }
    }
    while(i<=m){
        novo[k] = v[i];
        k++, i++;
    }
    while(j<=r){
        novo[k] = v[j];
        k++, j++;
    }
    k = 0;
    for(i = l; i<=r; i++){
        v[i] = novo[k];
        k++;
    }
    free(novo);
}
void mergesort(int *v, int l, int r){
    if(l>=r)
      return;
    int m = (l+r)/2;
    mergesort(v, l, m);
    mergesort(v, m+1, r);
    merge(v, l, m, r);
}

int main(){
    int numero, cont =0;
    scanf("%d", &numero);
    int *v = malloc(sizeof(int)*numero);
    for(int i=0;i<numero;i++){
        scanf("%d", &v[i]);
    }
    mergesort(v, 0, numero-1);
    for(int j = 0; j<numero; j++){
        if(v[j] != v[j+1]) cont++;
    }
    printf("%d\n", cont);
    return 0;
}