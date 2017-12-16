#include <stdio.h>

int m[100][100];

int func10(int *v,int capacidade,int n)
{
    int r[capacidade];
    for(int i=0; i<=n; i++) m[i][0]=0;
    for(int i=0; i<=capacidade; i++) m[0][i]=0;

    for(int i=1; i<=n; i++) //Vetor das moedas
        for(int j=0; j<=capacidade; j++) //Vetor do que trocar
        {
            if(v[i]<=j)
            {
                r[j] = v[i];
                m[i][j] = v[i] + m[i-1][j-v[i]];
            }
            else
            {
                m[i][j] = m[i-1][j];
            }
        }

    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=capacidade; j++)
        {
            printf("%d ",m[i][j]);
        }
        printf("\n");
    }
    if(m[n][capacidade] == capacidade)
        print(r,n,capacidade,capacidade);

    return m[n][capacidade];
}

void print(int *v,int a,int b,int valor)
{
    printf("%d ",v[b]);
    b-=v[b];
    while(b>0)
    {
        printf("%d ",v[b]);
        b-=v[b];
    }
    printf("\n");
}

int main()
{
    int vet[]= {-1,1,3,5};
    printf("%d\n",func10(vet,8,3));

    return 0;
}
