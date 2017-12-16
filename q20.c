#include <stdio.h>

int stops(int n, int st[],int tam)
{
    int c = 0,i;
    int tanque = n-st[0];

    if(tanque < 0) return 0;

    for(i=0; i < tam - 1; i++)
    {
        if(tanque - (st[i+1]-st[i]) >= 0)
        {
            tanque-=st[i+1]-st[i];
        }
        else
        {
            c++;
            tanque = n;
            printf("parei no KM: %d\n",st[i]);
            if(tanque - (st[i+1]-st[i]) >= 0)
            {
                tanque-=st[i+1]-st[i];
            }
            else {
                printf("Nao funcionou\n");
                return -1;
            }
        }
    }
    return c;
}

int main()
{

    int vet[]= {4,7,13,17,20};

    printf("\nparou %d vezes\n",stops(8,vet,5));

    return 0;
}
