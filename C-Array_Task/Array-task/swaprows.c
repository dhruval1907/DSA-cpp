//the row become column

#include <stdio.h>

int main() {
    int i, j;

    // Original matrix
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int array[3][3];
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            array[j][i] = matrix[i][j];  
        }
    }

    
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

    return 0;
}

