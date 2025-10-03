#include <stdio.h>

int main() {
    int i, j;
    int matrix[3][3] = {
        {2, 3, 8},
        {4, 5, 2},
        {1, 4, 6}
    };

    int rowSum = 0, colSum = 0;
    int rowIndex, colIndex;

    // Print the matrix
    printf("Matrix:\n");
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Take row and column index from user
    printf("\nEnter row index (0-2): ");
    scanf("%d", &rowIndex);

    printf("Enter column index (0-2): ");
    scanf("%d", &colIndex);

    // Sum of given row
    for(j = 0; j < 3; j++) {
        rowSum += matrix[rowIndex][j];
    }

    // Sum of given column
    for(i = 0; i < 3; i++) {
        colSum += matrix[i][colIndex];
    }

    printf("\nSum of row %d: %d\n", rowIndex, rowSum);
    printf("Sum of column %d: %d\n", colIndex, colSum);

    return 0;
}

