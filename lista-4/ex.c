#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ull unsigned long long
// #define Item int
// #define key(x) (x)
#define less(a, b) (a.value == b.value ? a.key < b.key : a.value < b.value)
#define less2(a, b) (a.key == b.key ? a.value < b.value : a.key < b.key)
#define swap(a, b)  \
    {               \
        Item t = a; \
        a = b;      \
        b = t;      \
    }
#define cmpswap(a, b) \
    if (less(b, a))   \
    swap(a, b)
#define cmpswap2(a, b) \
    if (less2(b, a))   \
    swap(a, b)

typedef struct
{
    long long key;
    int value;
} Item;

int partition(Item *v, int l, int r)
{
    Item pivot = v[r];
    int j = l;
    for (int k = l; k < r; k++)
        if (less(v[k], pivot))
        {
            swap(v[k], v[j]);
            j++;
        }
    swap(v[j], v[r]);
    return j;
}

void quickselect(Item *v, int l, int r, int i)
{
    cmpswap(v[(l + r) / 2], v[r]);
    cmpswap(v[l], v[(l + r) / 2]);
    cmpswap(v[r], v[(l + r) / 2]);

    int m = partition(v, l, r);
    if (m > i)
        quickselect(v, l, m - 1, i);
    else if (m < i)
        quickselect(v, m + 1, r, i);
}

Item v[10000001];
void imprimetopn(Item *v, int l, int r, int n){
    quickselect(v, l, r, l+n-1);
    mergesort(v, l, l+n-1);
    for(int i=l;i<=l+n-1;i++){
        printf("%d %d\n", v[i].S, v[i].N);
    }
}

int main(void)
{
    int n, i=0;
    scanf("%d", &n);
    while(scanf("%d %d", &sementes[i].S, &sementes[i].N) !=EOF) i++;
    // for(int j=0;j<=i-1;j++){
    //     printf("%d %d\n", sementes[j].S, sementes[j].N);
    // }
    imprimetopn(sementes, 0, i-1, n); 
}