#include <stdio.h>

#define null NULL


int bitonico(int vet[],int i,int f)
{
    int m = (f+i)/2;
    if(f-i == 0) return vet[i];
    if(vet[i]<vet[m])
    {
        if(vet[m]>vet[m-1])
            return bitonico(vet,m,f);
        else
            return bitonico(vet,i,m);
    }
    else if(vet[m]<vet[m+1])
        return bitonico(vet,m,f);
    else
        return bitonico(vet,i,m);
    return null;
}


int main()
{
    int v[]= {1,2,7,6,5,4,3,2,1,0};
    int v1[]={1,2,3,4,6,5,3,2,1,0};
    int v2[]={1,8,7,6,5,4,3,2,1,0};

    printf("%d\n",bitonico(v2,0,10));



    return 0;
}
