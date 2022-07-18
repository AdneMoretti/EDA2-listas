#include <stdio.h>
#include <stdlib.h>

void soma_string(){
    char b[101];
    int soma=0;
    scanf(" %s", b);
    int i=0;
    while(b[i]!= '\0'){
        if(b[i]>= '0' && b[i]<= '9'){
            soma += b[i]-'0';
        }
        i++;
    }
    printf("%d\n", soma);
}
int main(void){
    int x;
    scanf("%d", &x);
    char b[101];
    for(int i=0;i<x;i++){
        soma_string();
    }
}