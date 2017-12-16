#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INF 9999999

int pd[1234][1234];
char rastreio[1234][1234];

int BuscarMinimoCorte(int* marcados,int n)
{

    memset(pd,0,sizeof(pd)); //inicializa todos os elementos da matriz com 0

    for (int indice = 1; indice <= n; ++indice)
    {
        for (int i = 0;; ++i)
        {
            int j = i + indice + 1;
            if (j >= n+2)
                break;

            int min = INF;
            int corte = marcados[j] - marcados[i];
            rastreio[i][j] = "";

            for (int k = i + 1; k <= j - 1; ++k)
            {
                if(min>pd[i][k] + pd[k][j] + corte)
                {
                    min=pd[i][k] + pd[k][j] + corte;
                    rastreio[i][j] = marcados[k] + rastreio[i][k] + rastreio[k][j];
                }
            }
            pd[i][j] = min;
        }
    }
    //printf("%s\n",rastreio[0][n+1]); c nao te dar suporte para uso de strings, dificultando a concatenacao;

    return pd[0][n+1];
}


int main()
{
    int vet[]= {0,2,4,7,10};
    printf("\n%d\n",BuscarMinimoCorte(vet,3));

}
