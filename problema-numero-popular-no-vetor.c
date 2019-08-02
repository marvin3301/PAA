#include <stdio.h>
#include <stdlib.h>

int q1,q2;
int aux;

void selecao(int piv, int tam, int *vet)
{

    q1= -1, q2 = tam - 1;
    int i = 0;

    int aux;

    while(i < q2)
    {

        if (vet[i] < piv)
        {
            q1++;
            aux = vet[i];
            vet[i] = vet[q1];
            vet[q1] = aux ;

            i++;
        }
        else if (vet[i] > piv)
        {
            aux = vet[i];
            vet[i] = vet[q2];
            vet[q2] = aux;

            q2--;

        }
        else if (vet[i] == piv)
        {
            i++;
        }
    }
}

int popular(int tam, int a, int b, int*vet)
{

    if ((q2-q1) > (tam/3))

    {
        return vet[q1 +1];
    }
    else if (q1 - a > tam/3)
    {
        selecao(vet[0],q1-a,vet);

        if (q1-a > tam/3)
        {
            return vet[a+1];
        }
    }
    else if (b - q2 > tam/3)
    {
        selecao (q2,b - q2,vet);
    }
    else return 0;
}
int main()
{
    int vet[]= {1,6,9,1,4,1,1,9,4,3,2};

    printf("%d\n",popular(12, 0, 11, vet));

    return 0;
}
