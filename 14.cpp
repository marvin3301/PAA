#include <iostream>
#include <algorithm>

using namespace std;

int cmp(int a, int b){
    return a<b;

}

int duplicata(int vet[],int i,int f){

    for (i = 0; i < f; ++i)
    {
        
    }
}



int main(){
    int n=12;
    int vet[n]={3,1,4,8,6,7,3,3,1,1,1,4},i=0;

    sort(vet,vet+n,cmp);

    n = duplicata(vet,0,n);


    while(i < n){
        cout<<vet[i++]<<endl;
    }

    return 0;
}