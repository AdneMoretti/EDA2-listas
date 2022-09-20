#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ht[101][16];
int qtd;
int string_hash2(char s[16], int hash1, int j){
    int hash2 = (hash1 + (j*j) + (23 *j))%101;
    return hash2;
}
int hash(char s[16]) {
    int h = 0;
    for (int i = 0; s[i] != '\0'; i++){
        h = h + s[i]*(i+1);
    }
    return (19*h)%101;
}
int procura(int h1, char s[16]){
    if(strcmp(ht[h1], s)==0){
        return 1;
    }
    else{
        int h2;
        for(int i=1;i<20;i++){
            h2 = string_hash2(s, h1, i);
            if(strcmp(ht[h2], s)==0) return 1;
        }
    }
    return 0;
}
void insere_hash(char s[16]){
    int h1=hash(s);
    if(procura(h1,s)==1) return;
    if(*ht[h1]=='\0'){
        qtd++;
        strcpy(ht[h1], s);
    }
    else{
        int h2;
        for(int i=1;i<20;i++){
            h2 = string_hash2(s, h1, i);
            if(*ht[h2]=='\0'){
                qtd++;
                strcpy(ht[h2], s);
                break;
            }
        }
    }
}
int remove_hash(char s[16]){
    int h1=hash(s);
    if(strcmp(ht[h1],s)==0){
        qtd--;
        *ht[h1]='\0';
    }
    else{
        for(int i=1;i<20;i++){
            int h2=string_hash2(s, h1, i);
            if(strcmp(ht[h2],s)==0){
                qtd--;
                *ht[h2]='\0';
                break;
            }
        }
    }
}
int main(){
    char str[16], entrada[4];
    int casos, oper;
    scanf("%d", &casos);
    for(int i=0;i<casos;i++){
        qtd=0;
        for(int i=0;i<101;i++){
            *ht[i]='\0';
        }
        scanf("%d", &oper);
        for(int j=0;j<oper;j++){
            scanf(" %s:%s", entrada, str);
            if(entrada[0]=='A'){
                insere_hash(str);
            }
            else{
                remove_hash(str);
            }
        }
        printf("%d\n", qtd);
        for(int i=0;i<101;i++){
            if(*ht[i]!='\0') printf("%d:%s\n", i, ht[i]);
    }
    }
    return 0;
}

