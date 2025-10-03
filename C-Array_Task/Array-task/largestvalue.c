// largest value in the given array
#include <stdio.h>

int main() {
    
    int i,j;
    
    int matrix[2][3] = {  
        {0,2,3},
        {4,5,16}  
    };
    
    int max = matrix[0][0];
    
    for(i=0;i<2;i++){
        for(j=0;j<=2;j++){
             if(matrix[i][j]>max){
                 max = matrix[i][j];
             }
        }
    }
    
    printf("%d",max);
    
    
}
