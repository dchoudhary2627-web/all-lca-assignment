#include <stdio.h>

int main() {
    int choice;
    float a, b;

    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n");
    printf("Enter your choice: ");
    if (scanf("%d", &choice) != 1) {
        printf("Invalid input! Enter numbers only.\n");
        return 1;
    }

    printf("Enter two numbers: ");
    if (scanf("%f %f", &a, &b) != 2) {
        printf("Invalid input! Enter numbers only.\n");
        return 1;
    }

    switch (choice) {
        case 1:
            printf("Result = %.2f\n", a + b);
            break;
        case 2:
            printf("Result = %.2f\n", a - b);
            break;
        case 3:
            printf("Result = %.2f\n", a * b);
            break;
        case 4:
            if (b == 0)
                printf("Cannot divide by zero!\n");
            else
                printf("Result = %.2f\n", a / b);
            break;
        default:
            printf("Invalid choice!\n");
    }
    return 0;
}