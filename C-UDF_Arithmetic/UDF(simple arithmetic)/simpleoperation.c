#include<stdio.h>

float add(int n1,int n2){		
	return n1+n2;
}
float sub(int n1,int n2){
	return n1-n2;
}
float mul(int n1,int n2){
	return n1*n2;
}
float div(int n1,int n2){
	if(n2!=0){
		return (float)n1/n2;
	}
	else{
		printf("\nCannot Divided by Zero !!!!");
	}
}
int mod(int n1,int n2){
	if(n2!=0){
		return n1%n2;
	}
	else{
		printf("\nCannot perfor modulation !!!!");
	}
}



int main(){
    
    float num1,num2,result=0;
    char again = 'y',n;
    int choice;
    printf("=+=+=+=+=+=+=Simple Calculator Using UDF Function=+=+=+=+=+=+=\n \n");
    
    while (again == 'y' || again == 'Y') {
    
    printf("\n================================================= \n");
    
    printf("Enter Your First Value   :   ");
    scanf("%f",&num1);
    
     printf("\n================================================= \n");
    
    printf("Enter Your Second Value   :   ");
    scanf("%f",&num2);
    
     printf("\n================================================= \n");
    
    printf("Press 1 fr Add (+) \n");
    printf("Press 2 fr Subtract (-) \n");
    printf("Press 3 fr Multiply (*) \n");
    printf("Press 4 fr Divide (/) \n");
    printf("Press 5 fr Modulus (%)\n");
    printf("Press 6 to Exit  \n");
    
     printf("\n================================================= \n");

    printf("Enter Your Choice   :   ");
    scanf("%d",&choice);
    
    if (choice == 6) {
        printf("Exiting the calculator...\n");
        break;
    }
    
    switch(choice) {
            case 1:
                result = add(num1, num2);
                printf("Result For Addition ss = %f\n", result);
                break;
            case 2:
                result = sub(num1, num2);
                printf("Result For Subtraction ss= %f\n", result);
                break;
            case 3:
                result = mul(num1, num2);
                printf("Result For Multiplication is = %f\n", result);
                break;
            case 4:
                result = div(num1, num2);
                printf("Result For Divison is= %f\n", result);
                break;
            case 5:
                result = mod(num1, num2);
                printf("Result For Modulo is  = %f\n", result);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
        
        printf("\nDo you want to continue? (y/n): ");
        scanf(" %c", &again); 
    }
        
        if(choice=n){
             printf("\n================================================= \n");
            printf("Thank you for calculating!\n");
        }
    

    }

