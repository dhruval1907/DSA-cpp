//Floyd's traingle using a nested for loop

#include<stdio.h>

int main(){

	int i,j;
	int count = 11;
	
	for(i=0;i<=3;i++){
		for(j=0;j<=i;j++){
			printf(" %d ",count);
			count++;
		}
		printf("\n");
	}
	
}
