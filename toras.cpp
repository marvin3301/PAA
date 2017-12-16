#include <bits/stdc++.h>

#define INF 9999999

using namespace std;

int pd[1234][1234];
string rastreio[1234][1234];

string NumberToString ( int Number ) //converter um inteiro para string
{
    stringstream ss;
    ss << Number;
    return ss.str();
}

int BuscarminimoimoCorte(int* marcados,int n)
{

    memset(pd,0,sizeof(pd)); //inicializa todos os elementos da matriz com 0

    for (int indice = 1; indice <= n; ++indice)
    {
        for (int i = 0;; ++i)
        {
            int j = i + indice + 1;
            if (j >= n+2)
                break;

            int minimo = INF;
            int corte = marcados[j] - marcados[i];
            rastreio[i][j] = "";

            for (int k = i + 1; k <= j - 1; ++k)
            {
                if(minimo>pd[i][k] + pd[k][j] + corte)
                {
                    minimo=pd[i][k] + pd[k][j] + corte;
                    rastreio[i][j] = NumberToString(marcados[k]) + " " + rastreio[i][k]+rastreio[k][j];
                }
            }
            pd[i][j] = minimo;
        }
    }

    printf("sequencia = %s\n",rastreio[0][n+1].c_str());
    return pd[0][n+1];
}


int main()
{
    int vet[]= {0,2,4,7,10};

    printf("valor minimo = %d\n",BuscarminimoimoCorte(vet,3));

}
