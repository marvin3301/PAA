#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int verifica(int x,int i,int n, int vet[]){
	if(n == i) return 0;
	if(vet[i]+vet[n] == x) return 1;
	if(vet[i]+vet[n] > x) return verifica(x,i,n-1,vet);
	if(vet[i]+vet[n] < x) return verifica(x,i+1,n,vet);	
}

int cmp(int a,int b)
{
    return a<b;

}

int main()
{

    int vet[]= {42,4,2,24,4,25,7,5,35,35,3,10},i;
    sort(vet,vet+12,cmp);

    cout << verifica(7,0,11,vet) << endl;
 
    return 0;
}
