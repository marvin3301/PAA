#include<stdio.h>
int v[] = {3,2,8,7,2,3,4,1,3};

int l,j;

void sep(int p, int r,int indice){
int b, piv = v[indice], a ;
l=0,j=p;
for(b = p; b < r-1; b++){
  if(v[b] <= piv){
    a = v[b];
    v[b]=v[j];
    v[j] = a;
    j++;
    }
}
  v[r-1] = v[j];
  v[j] = piv;
  piv = v[j];

 for(b = 0; b < j; b++){
    if(v[b] < piv){
    a = v[b];
    v[b]=v[l];
    v[l] = a;
    l++;
    }

  }

}

int main(){
int i = 0;
    sep(0,9,8);
    printf("%d %d\n",l,j);


return;
}

