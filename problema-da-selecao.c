#include <stdio.h>
#include <stdlib.h>

int q1,q2;

void swap(int *v,int a,int b)
{
    int aux = v[a];
    v[a] = v[b];
    v[b] = aux;
}

void selecao(int *vet,int piv, int tam)
{

    q1= -1, q2 = tam-1;
    int i = 0;

    while(i <= q2)
    {
        if (vet[i] < piv)
        {
            q1++;
            swap(vet,q1,i);
            i++;
        }
        else if (vet[i] > piv)
        {
            swap(vet,q2,i);
            q2--;
        }
        else if (vet[i] == piv)
        {
            i++;
        }
    }
}

int main()
{
    int n; // era bom que o n fosse > 3.
    int i = 0,pivo = 1;

    printf("Tamanho do vetor: \n");
    scanf("%d",&n);

    int *v;

    v = malloc(n*sizeof(int));

    printf("Elementos do vetor: \n");
    for(i=0; i<n; i++)
        scanf("%d",&v[i]);

    printf("\nPIVO = ");
    scanf("%d",&pivo);

    selecao(v,pivo,n);
	
    printf("\n");
    i=0;
    while(i<n)
    {
        printf("%d ",v[i++]);

    }

    printf("\n");
    i=0;

    while(i<n)
    {
        if(i == q1 || i == q2) printf("^ ");
        else printf("  ");
        i++;

    }
    printf("\n");
    i=0;

    while(i<n)
    {
        if(i == q1 == q2)
        {
            printf("=");
            break;
        }
        if(i == q1) printf("q1");
        else if(i == q2)
        {
            printf("q2");
            break;
        }
        else printf("  ");
        i++;
    }

    printf("\n\n");

    printf("Q1 = %d <-> Q2 = %d\n",q1,q2);

    free(v); //se e somente se vc nao for mais precisar usar os elementos do vetor

    return 0;
}
