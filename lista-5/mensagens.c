#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define hash(c)(c.key % 1048576)
#define hash_int(c)(c%1048576)

struct item{
    unsigned key;
    char c;
}typedef item;

item ht[10485760];

int hash2(unsigned hash1, int j){
    unsigned hash2 = (hash1 + (j*j) + (33 *j))%1048576;
    return hash2;
}

int procura(item s){
    unsigned h1=hash(s);
    if(ht[h1].key==s.key){
        return 1;
    }
    else{
        for(int i=1;i<10;i++){
            unsigned h2 = hash2(h1, i);
            if(ht[h2].key==s.key) return 1;
        }
    }
    return 0;
}
char procura_int(int s){
    unsigned h1=hash_int(s);
    if(ht[h1].key==s){
        return ht[h1].c;
    }
    else{
        for(int i=1;i<10;i++){
            unsigned h2 = hash2(h1, i);
            if(ht[h2].key==s) return ht[h2].c;
        }
    }
    return ' ';
}
void insere_hash(item s){
    unsigned h1=hash(s);
    if(procura(s)==1) return;
    if(!ht[h1].key){
        ht[h1]=s;
    }
    else{
        for(int i=1;i<10;i++){
            unsigned h2 = hash2(h1, i);
            if(!ht[h2].key){
                ht[h2]=s;
                break;
            }
        }
    }
}

int main(){
    long int S;
    char entrada;
    item novo;
    int menor=1048577;
    int maior=0;
    while(scanf("%u %c", &novo.key, &novo.c)!=EOF){ 
        insere_hash(novo);  
        if(novo.key<menor){
            menor=novo.key;
        } 
        if(novo.key>maior){
            maior=novo.key;
        }

    }
    for(int i=menor;i<=maior;i++){
        char resp = procura_int(i);
        if(resp!=' '){
            printf("%c", resp);
        }
    }
    printf("\n");
    return 0;
}