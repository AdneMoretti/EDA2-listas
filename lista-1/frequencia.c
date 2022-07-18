#include <stdio.h>
#include <stdlib.h> 

int main(){
    int numero, registro=0, aux=0, temp=1;
    scanf("%d", &numero);
    int *v = malloc(sizeof(int)*numero);
    scanf("%d", &registro);
    v[0]=registro;
    for(int i=1;i<numero;i++){          
        scanf("%d", &registro);
        for(int j=temp;j>0;j--){
            if(registro==v[j]) aux=1;
        }
        if(aux==0){
            v[temp] = registro;
            temp++;
        }
    }
    
    printf("%d\n", temp);
    return 0;
}
