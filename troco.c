#include <stdio.h>
#define TAM 100000
#define min(a,b) (a<b)?a:b

int pd[TAM];
int r[TAM];
int pos=0;

int troco(int N, int M, int * m)
{
    pd[0] = 0;

    for(int i=1; i<=N; i++)
    {
        pd[i] = 1000000;

        for(int j=0; j<M; j++)
        {
            if(i-m[j] >= 0)
            {
                pd[i] = min(pd[i], pd[ i-m[j] ]+1);
                r[i] = j;
                pos++;
            }
        }
    }

    return pd[N];
}

void print(int vet[]){
    while(pos!=0){
      int aux = r[pos-1];
      printf("%d ",vet[aux]);
      pos-=vet[aux];
    }
}

int main()
{
    int vet[] = {1,3,4};

    printf("%d\n",troco(6,3,vet));

    return 0;
}
