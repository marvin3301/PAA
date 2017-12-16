#include <stdio.h>
#include <stdlib.h>

static int cont;
static int n;

void intercala (int v[],int p,int q,int r)
{
    int i,j,k = 0;
    int w[r-p];
    i = p;
    j = q;
    while(i < q && j < r)
    {
        if(v[i] < v[j])
            w[k++] = v[i++];
        else if(v[i]>v[j])
        {
            w[k++] = v[j++];
        }
        else{
            cont++;
            w[k++]=v[j++];
        }
    }
    while(i < q) w[k++] = v[i++];
    while(j < r) w[k++] = v[j++];
    for (i = p; i < r; i++)
        v[i] = w[i-p];
}

void Mergesort(int v[],int p,int r)
{
    int q;
    if(p < r-1)
    {
        q = (p+r)/2;
        Mergesort(v,p,q);
        Mergesort(v,q,r);
        intercala(v,p,q,r);

    }

}

void removerDuplicata(int *v,int i,int f){
    int k=0,j,aux;
    int *p = v;
    v = (int*)realloc(v,cont * sizeof(int));

    for(j=i;j<f-1;j++){
        if(p[i]!=p[i+1]){
            v[k++]=p[i];
        }
    }

    n=cont;

}

int main(int argc, char const *argv[])
{
    int vet[]={1,1,2,2,4,4,3,3,6,6,5,5,7,8,8,7,9,9,10,10},i;
    n=20;
    Mergesort(vet,0,n);

    removerDuplicata(vet,0,n);

    for(i=0;i<n;i++)
        printf("%d\n",vet[i] );

    
    return 0;
}