// Left half traingle pattern using nested for loop

#include<stdio.h>

int main(){
	
	int i,j,k;
				
	for(i=1;i<=5;i++){
		for(k=1;k<=5-i;k++){
			printf("  ");
		}
		for(j=6-i;j<=5;j++){
			printf("%d ", j);
		}
		printf("\n");
	}
}
