// addtion of first & last 
#include <stdio.h>

int main() {
    int num, temp;
	int first, last;

	printf("================================================================================= \n\n");
	printf("-- digit addition of first & last --\n\n");
    printf("Enter a number   :  ");
    scanf("%d", &num);

    last = num % 10;  

    for(temp = num; temp >= 10; temp = temp / 10) {
    	
    }

    first = temp;  

    printf("\nSum = %d\n\n\n", first + last);
	
	printf("================================================================================= \n\n");

}

