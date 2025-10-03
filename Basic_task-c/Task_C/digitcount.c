// digit counter 

#include <stdio.h>

int main() {
    int num, digit = 0;

    printf("==================================================================== \n");
    printf("-- Digit Counter -- \n\n");
    printf("Enter The Number  :   ");
    scanf("%d", &num);

    int temp = num;  
    
    for(temp=num;temp!= 0; temp /= 10){
        digit = digit+1;
    }

    printf("\nDigits In The Number is: %d \n\n", digit);
    printf("Your value is %d bucks", num);  

    printf("\n\n=================================================================== \n\n\n\n\n");

    return 0;
}

