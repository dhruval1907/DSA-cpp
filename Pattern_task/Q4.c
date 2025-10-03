#include<stdio.h>

int main(){
	
	int i, j;
	int num;
	
	for(i = 1; i <= 5; i++){
		for(j = 1; j < i; j++){
			printf(" ");
		}

		for(num = i; num <= 5; num++){
			int val;

			if(num % 2 == 0)
				val = 0;
			else
				val = 1;

			printf("%d", !val);  
		}
		printf("\n");
	}
	
	return 0;
}

