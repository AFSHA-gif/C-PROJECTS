#include <stdio.h>
#include <math.h>

int main() {
    int choice;
    double num1, num2, result;

    while (1) {
        printf("\n====== Calculator ======\n");
        printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Square\n6. Cube\n7. Power\n8. Square Root\n9. Exit\nEnter choice: ");
        scanf("%d", &choice);

        if(choice == 9) break;

        if(choice >=1 && choice <=4 || choice ==7) {
            printf("Enter first number: ");
            scanf("%lf", &num1);
            printf("Enter second number: ");
            scanf("%lf", &num2);
        } else if(choice >=5 && choice <=8) {
            printf("Enter number: ");
            scanf("%lf", &num1);
        }

        switch(choice) {
            case 1:
                result = num1 + num2;
                printf("Result: %.2lf\n", result);
                break;
            case 2:
                result = num1 - num2;
                printf("Result: %.2lf\n", result);
                break;
            case 3:
                result = num1 * num2;
                printf("Result: %.2lf\n", result);
                break;
            case 4:
                if(num2 != 0) {
                    result = num1 / num2;
                    printf("Result: %.2lf\n", result);
                } else {
                    printf("Cannot divide by zero!\n");
                }
                break;
            case 5:
                printf("Square: %.2lf\n", num1*num1);
                break;
            case 6:
                printf("Cube: %.2lf\n", num1*num1*num1);
                break;
            case 7:
                printf("Power: %.2lf\n", pow(num1,num2));
                break;
            case 8:
                if(num1 >=0) printf("Square Root: %.2lf\n", sqrt(num1));
                else printf("Invalid Input!\n");
                break;
            default:
                printf("Invalid Choice!\n");
        }
    }
    return 0;
}
