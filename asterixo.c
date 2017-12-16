#include <stdio.h>

void ast(int n){
	if(n>1){
		printf("***\n");
		ast(n/5);
		ast(n/5);
		ast(n/5);
		ast(n/5);
		ast(n/5);
		
	}
}

int main(int argc, char const *argv[])
{
	int n;
	while(1){
		scanf("%d",&n);
		ast(n);
	}

	return 0;
}