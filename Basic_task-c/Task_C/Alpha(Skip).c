// skip the 3 alphabet and print after that

#include<stdio.h>

int main(){
	
	int i;
	char a=97;
	
	printf("=================================================================== \n");
	printf("-- Alphabet Skipper -- \n\n");
	
	do{
		printf("%c,",a);
		a += 4;
		i++;
	}while(i<=6);
}
