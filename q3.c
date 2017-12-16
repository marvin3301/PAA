#include<stdio.h>

int max(int a, int b)
{
    if(a >= b) return a;
    else return b;
}

int getIndiceMaiorSoma(int *rastreio, int n)
{
    int maior = 0;
    for(int i=1; i<n; i++)
        if(rastreio[maior] < rastreio[i])
            maior = i;
    return maior;
}

int soma_maxima_contigua(int *s, int n)
{
    int rastreio[n], somaMaxima = s[0];
    rastreio[0] = s[0];
    for(int i=1; i<n; i++)
    {
        if(s[i] < somaMaxima+s[i])
        {
            somaMaxima += s[i];
            rastreio[i] = rastreio[i-1] + s[i];
        }
        else
        {
            somaMaxima = s[i];
            rastreio[i] = s[i];
        }
    }

    int maior = getIndiceMaiorSoma(rastreio,n);

    print(rastreio,s,n,maior);
    return rastreio[maior];
}

void print(int *rastreio, int *s, int n, int maior)
{
    while(rastreio[maior] > 0)
    {
        printf("%i ",s[maior]);
        maior--;
    }
}

void main()
{
    int n = 7, s[] = {5 ,15 ,-30 ,10 ,-5 ,40 ,10};
    printf("\nSoma maxima eh: %i",soma_maxima_contigua(s,n));
}
