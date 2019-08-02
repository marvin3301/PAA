#include <stdio.h>
#include <math.h>
#include <string.h>

#define M 100000000

int vet[M];

int rec(int n)
{
    if(n<5) return 0;

    return rec(n/2) + rec((n/2)+1) + rec((n/2)+2) + n;
}

int din(int n)
{
    if(n<5) return 0;
    if(vet[n]==0)
    {
        vet[n] = din(n/2) + din((n/2)+1) + din((n/2)+2) + n;
        return vet[n];
    }
    else
    {
        return vet[n];
    }
}

int bottonUp(int n)
{
    int i=0;
    vet[0]=vet[1]=vet[2]=vet[3]=vet[4]=0;
    int q=(n/2)+2;

    for(i=5; i<=q; i++)
        vet[i] = vet[i/2]+vet[(i/2)+1]+vet[(i/2)+2] + i;

    return vet[q]+vet[q-1]+vet[q-2] + n;

}

int main()
{

    memset(vet,0,M);

    printf("%d\n",din(1000000));


    return 0;
}
