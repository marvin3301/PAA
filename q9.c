#include <stdio.h>
#define MAX 0x3f3f3f3f

// problema do troco com minimas moedas

int min(int a, int b)
{
    return a < b ? a : b;
}

int bottonUp(int total, int *v, int n)
{
    int t[total+1], r[total+1];
    t[0] = 0;
    for(int i=1; i<=total; i++)
    {
        t[i] = MAX;
        r[i] = -1;
    }
    for(int j=0; j<n; j++)
        for(int i=1; i<=total; i++)
            if((i-v[j]>=0) && t[i-v[j]] + 1 < t[i])
            {
                t[i] = t[i-v[j]] + 1;
                r[i] = j;
            }
    print(r,v,total);
    return t[total];
}

void print(int *r, int *v, int total)
{
    printf("Valor: %i\nMoedas: ",total);
    if(r[total] == -1) return;
    int start = total;
    while(start != 0)
    {
        int j = r[start];
        printf("%i ",v[j]);
        start = start - v[j];
    }
}

void main()
{
    int n = 3, c = 7;
    int v[] = {1,3,5};
    printf("\n\nTamanho sequencia minima: %i\n",bottonUp(c,v,n));
}
