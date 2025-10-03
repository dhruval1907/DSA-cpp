#include <stdio.h>

int main() {
    int math, science, english, total;
    float percentage;
    char grade;
    const char *comment; // no const

    // Input subject marks
    printf("Enter marks for Math (out of 100): ");
    scanf("%d", &math);

    printf("Enter marks for Science (out of 100): ");
    scanf("%d", &science);

    printf("Enter marks for English (out of 100): ");
    scanf("%d", &english);

    // Check for invalid input
    if (math < 0 || math > 100 || science < 0 || science > 100 || english < 0 || english > 100) {
        printf("Invalid input! Marks must be between 0 and 100.\n");
        return 0;
    }

    // Calculate total and percentage
    total = math + science + english;
    percentage = total / 3.0;

    // Grade assignment using ternary operator
    grade = (percentage >= 90) ? 'A' :
            (percentage >= 80) ? 'B' :
            (percentage >= 70) ? 'C' :
            (percentage >= 60) ? 'D' :
            (percentage >= 33) ? 'E' : 'F';

    // Comment using switch-case
    switch (grade) {
        case 'A': comment = "Excellent Performance"; break;
        case 'B': comment = "Very Good"; break;
        case 'C': comment = "Good Effort"; break;
        case 'D': comment = "Needs Improvement"; break;
        case 'E': comment = "Just Passed"; break;
        case 'F': comment = "Failed. Try Again"; break;
        default: comment = "Invalid Grade";
    }

    // Eligibility using if-else
    printf("\nEligibility: ");
    if (grade != 'F') {
        printf("You are eligible for the next level.\n");
    } else {
        printf("You are not eligible for the next level.\n");
    }

    // Display result
    printf("\n============== REPORT CARD ==============\n");
    printf("Math      : %d\n", math);
    printf("Science   : %d\n", science);
    printf("English   : %d\n", english);
    printf("-----------------------------------------\n");
    printf("Total     : %d / 300\n", total);
    printf("Percentage: %.2f%%\n", percentage);
    printf("Grade     : %c\n", grade);
    printf("Comment   : %s\n", comment);
    printf("=========================================\n");

    return 0;
}

