#include<stdio.h>
int s[1000], c;

int quad(int n)
{
    int i;
    for(i = 0; i < n; i++)
        if(i*i == n)return 1;
    return 0;
}

int cub(int n)
{
    int i;
    for(i = 0; i < n; i++)
        if(i*i*i == n)return 1;
    return 0;
}

int func(int v[],int n)
{
    c = 0;
    int i, j, num = 0;
    for(i = 0; i < n; i++)
    {
       if(quad(v[i]) || cub(v[i]))
        {
            s[c++] = v[i]
        }
        else
        {
            num = (10*(v[i-1])+v[i])
           for(j = i - 1;j > 0; j++){
              if(num)
           }
        }
    }
    if(quad(v[i]) || cub(v[i])) return 1;
    if(quad(num) || cub(num)) return 1;
    return 0;
}

int main()
{
    int v[] = {1,6}, i;

    for(i = 0; i < 1000; i++)
        s[i] = 0;

}
