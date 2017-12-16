#include <stdio.h>
#include <math.h>
#include <string.h>

#define M 10000001

int vet[M];

int f(int n)
{
    if(n<=3) return n;
    return f(n/2) + f(n/3) + n;
}

int din(int n)
{
    if(n<=3) return n;
    if(vet[n]==0)
        return vet[n] = din(n/2)+din(n/3)+n;
    return vet[n];
}

int bottonUp(int n){
    int i;

    vet[0]=0;
    vet[1]=1;
    vet[2]=2;
    vet[3]=3;

    for(i=4;i<=n;i++){
        vet[i] = vet[i/3] + vet[i/2] + i;
    }

    return vet[n];

}


int main()
{
    memset(vet,0,M);
    printf("%d\n",bottonUp(10000000));

    return 0;
}
