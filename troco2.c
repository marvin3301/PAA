#include <stdio.h>
#define MIN -999
#define MAX 999

/*
    Autor: Mardônio Vieira - 2017.2 - Cadeira: PAA (CANA)
    Estudante de Sistemas de Informação da UFC - Crateus
*/

int min(int a, int b){
    return a < b ? a : b;
}

void imprimirMatriz(int n, int c, int m[n][c+1]){
    for(int i=1;i<n;i++){
        printf("\n(%i)",i);
        for(int j=0;j<=c;j++)
            printf(" %i",m[i][j]);
    }
    printf("\n\n\n\tm[%i][%i] = %i\n",n-1,c,m[n-1][c]);
}

int bottonUp(int *v, int n, int c){
    int i, j, k, m[n][c+1];
    for(i=1;i<n;i++) // caso base
        m[i][0] = 0;
    for(j=1;j<=c;j++) // caso base
        m[1][j] = j;
    for(i=2;i<n;i++){ // controlador da lista
        for(j=1;j<=c;j++){ // controlador de c
            m[i][j] = MAX;
            if(j >= v[i])
                m[i][j] = 1 + m[i][j-v[i]];
            m[i][j] = min(m[i][j],m[i-1][j]);
        }
    }
    imprimirMatriz(n,c,m);
    return m[n-1][c];
}

void main(){
    int n = 4, c = 7;
    int v[] = {MAX,1,3,5}; // para nao usar o indice zero
    printf("\n\nQuantidade minima de moedas: %i\n",bottonUp(v,n,c));
}
