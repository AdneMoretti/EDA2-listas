#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct item{
    int id;
    char fn[1000];
    char ln[1000]
    char bd[10];
    char pn[20];
}
int qtd;
int string_hash2(char s[16], int hash1, int j){
    int hash2 = (hash1 + (j*j) + (23 *j))%101;
    return hash2;
}
int string_hash(char s[16]) {
    int h = 0;
    for (int i = 0; s[i] != '\0'; i++){
        h = h + s[i]*(i+1);
    }
    h = (19*h)%101;
    return h;
}

int insere_hash(char s[16]){
    int h1=string_hash(s);
    if(strcmp(ht[h1], s)==0) return 0;
    if(*ht[h1]=='\0'){
        qtd++;
        strcpy(ht[h1], s);
    }
    else{
        int h2;
        for(int i=1;i<20;i++){
            h2 = string_hash2(s, h1, i);
            if(strcmp(ht[h2], s)==0) return 0;
            if(*ht[h2]=='\0'){
                qtd++;
                strcpy(ht[h2], s);
            }
        }
    }
}
int remove_hash(char s[16]){
    int h1=string_hash(s);
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
    char comando[6];
    item ht_id[10000];
    item ht_fn[10000];
    item ht_ln[10000];
    while((" %s", comando)!=EOF){
        switch(){
            case ("add"):
                scanf(" %s%s%s%s", )
            case "query":
            case "del":
        }
    }
    return 0;
}

