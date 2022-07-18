#include <stdio.h>
#include <string.h> 

int main(){
    char c[4];
    int soma=0, count=0, aux=0;

    while(scanf(" %s", c)!= EOF){
        if(c[0] == 's') aux+=1;
        count++;
        if (count == 10){
            count=0;
            if (aux>=2) soma+=1;
            aux=0;
        }
    }
    printf("%d\n", soma);
    return 0;
}
