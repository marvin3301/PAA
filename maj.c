#include<stdio.h>
  int v[] = {6,4,6,6,3,6,3,6};
  int j = 0;

int *maj(int a, int b){
   int n = (b + a);
   if(a == b)
      return &v[a];

     if(a < b){
     int q = n/2;
     int *x, *y;
       x = maj(a,q);
       y = maj(q+1,b);

   if(x!=0){
     int i = a, count = 0;
      for( i = a; i <= b; i ++){
          if(v[i] == *x)
             count++;
            }

         if(count > (b+1-a)/2)
            return x;
       }
      if(y!=0){
      int i = a, count = 0;
      for( i = a; i <= b; i ++){
          if(v[i]==*y)
             count++;
        }

	if(count > (b+1-a)/2)
	   return y;
      }

    return NULL;
   }
 }

int main(){
 int *c = maj(0,7);
 if(c != NULL)
 printf("\n O majoritario é elemento %d \n\n",*c);
else
  printf(" \n O vetor não tem majoritario \n\n");

return 0;

}