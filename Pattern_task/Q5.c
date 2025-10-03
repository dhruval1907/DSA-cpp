// Full Pyramid using nested for loop

#include <stdio.h>

int main() {
    int i, j;

    for(i = 0; i < 5; i++) {
        for(j = 0; j < 4 - i; j++) {
            printf("  ");
        }

        int num;
        for(num = 5 - i; num <= 5; num++) {
            printf("%d ", num);
        }

        int limit = 5 - i;
        for(num = limit; num < 5; num++) {
            printf("%d ", 5 - (num - limit + 1));
        }

        printf("\n");
    }
}
