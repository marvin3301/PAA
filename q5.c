#include<stdio.h>
int m[100][100];
int s[100][100];


int f(char v[], int n)
{
    int i, j;
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            m[i][j] = 0;


}

int main()
{
    int i , j;
    for(i = 0; i<100; i++)
        for(j = 0; j<100; j++)
            s[i][j] = -3;

    char v[] = {'A','C','G','T','G','T','C','A','A','A','A','T','C','G'};
    printf("%d", f(v,0,13));


}
