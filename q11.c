#include<stdio.h>
#include<set>
#include<stdlib.h>
#include <iostream>

std::set<int> s; 	//estrutura que nao aceita chaves repetidas, faz as inserções em O(logn)
					//usei para substituir um vetor auxiliar, pois vai consumir menos memoria.

void intercala (int v[],int p,int q,int r)
{
    int i,j,k = 0;
    int w[r-p];
    i = p;
    j = q;
    while(i < q && j < r)
    {
        if(v[i] <= v[j])
            w[k++] = v[i++];
        else
        {
            w[k++] = v[j++];
        }
    }
    while(i < q) w[k++] = v[i++];
    while(j < r) w[k++] = v[j++];
    for (i = p; i < r; i++)
        v[i] = w[i-p];

}

void mergesort (int v[],int p,int r)
{
    int q;
    if(p < r-1)
    {
        q = (p+r)/2;
        mergesort(v,p,q);
        mergesort(v,q,r);
        intercala(v,p,q,r);

    }
   
}

int remover_duplicatas(int *v,int tam){
	
	int i;

	for (i = 0; i < tam; i++)
	{
			s.insert(v[i]);
	}

	return s.size();

}

int main()
{
	int n;
	int i = 0;

	printf("Insira Tamanho do vetor: \n");
	scanf("%d",&n);
	
	int *v = (int*)malloc(n*sizeof(int)*n);
	
	printf("preencha o vetor com %d posições: \n",n);
	for(i=0;i<n;i++)
		scanf("%d",&v[i]);

	mergesort(v,0,n);

	n = remover_duplicatas(v,n);

	v = (int*) realloc(v,n*sizeof(int));



	printf("Novo tamanho do vetor: %d\n",n );

	std::set<int>::const_iterator sit (s.begin()), send(s.end()); //são iteradores para pecorrer o estrutura set
																  //s.begin() é o ponteiro para o inicio e
																  //s.end() é o ponteiro para o final
	
	i=0;

	 for(;sit!=send;++sit) 
		v[i++]=*sit;

    for(i=0;i<n;i++)
    	printf("%d ",v[i]);
	
	return 0;
}