#include<stdio.h>
#include<stdlib.h>

int *s;

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

	int i,count=0;

	for (i = 0; i < tam; i++)
	{
			if(v[i]!=v[i+1])
				s[count++] = v[i];

	}

	return count;

}

int main()
{
	int n;
	int *v;
	int i = 0;

	printf("Insira Tamanho do vetor: \n");
	scanf("%d",&n);

	v = (int*)malloc(n*sizeof(int));
	s = (int*)malloc(n*sizeof(int));

	printf("preencha o vetor com %d posições: \n",n);
	for(i=0;i<n;i++)
		scanf("%d",&v[i]);

	mergesort(v,0,n);

	n = remover_duplicatas(v,n);

	v = (int*) realloc(v,n*sizeof(int));

	printf("Novo tamanho do vetor: %d\n",n );

	for(i=0;i<n;i++)
		v[i] =  s[i];

	free(s);

    for(i=0;i<n;i++)
    	printf("%d ",v[i]);

    printf("\n");

	return 0;
}
