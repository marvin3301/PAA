#include <stdio.h>
#include <math.h>
#define MIN -999

int m[20][20];

int cubo(int n)
{
    int i;
    for(i = 0; pow(i,3) <= n; i++)
        if(pow(i,3)==n)
            return 1;
    return 0;
}

int quadrado(int n)
{
    int i;
    for(i = 0; pow(i,2) <= n; i++)
        if(pow(i,2)==n)
            return 1;
    return 0;
}

int getNumeroDoIntervalo(int *s, int i, int j)
{
    int n = j-i+1,a=i,b=j, num=0; // num é o numero formado pelos indices i..j
    if(n == 0) num = s[i];
    while(n>0)
    {
        num += s[i++] * pow(10,n-1);
        n--;
    }
    return num;
}

int perfeito(int *s, int i, int j)
{
    int num = getNumeroDoIntervalo(s,i,j); // j nao entra
    if(quadrado(num) || cubo(num))
        return 1;
    else return 0;
}

int bottonUp(int *s, int n)
{
    int i,j, rastreio[n];
    for(i=0; i<n; i++)
    {
        m[i][i+1] = perfeito(s,i,i+1);
        m[i][i] = perfeito(s,i,i);
        rastreio[i] = MIN;
    }
    for(i=n-1; i>=0; i--)
    {
        for(j=i; j<n-1; j++)
        {
            if(m[i][j]==1 && m[j+1][n-1]==1)
            {
                m[i][n-1] = 1;
                break;
            }
            else m[i][n-1] = 0;
        }
        rastreio[i] = j;
    }
    print(rastreio,s,n);
    return m[0][n-1];
}

void print(int *rastreio, int *s, int n)
{
    int i = 0;
    printf("\n\nRastreio:\n");
    while(1)
    {
        int num = getNumeroDoIntervalo(s,i,rastreio[i]);
        if(i >= n) break;
        printf(" %i ",num);
        i = rastreio[i]+1;
    }
}

void main()
{
    int n = 15;
    int s[] = {1,2,5,2,7,1,0,0,3,6,1,4,4,8,1};
    printf("\n\nBottonUp: %i",bottonUp(s,n));
}
