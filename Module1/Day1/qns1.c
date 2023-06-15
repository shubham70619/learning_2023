#include <stdio.h>

int findMaxIfElse(int num1, int num2) {
    if (num1 > num2) {
        return num1;
    } else {
        return num2;
    }
}

int findMaxTernaryOperator(int num1, int num2) {
    return (num1 > num2) ? num1 : num2;
}

int main() {
    int num1, num2;
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);
    
    int maxIfElse = findMaxIfElse(num1, num2);
    printf("Using if-else, the biggest number is: %d\n", maxIfElse);
    
    int maxTernary = findMaxTernaryOperator(num1, num2);
    printf("Using ternary operator, the biggest number is: %d\n", maxTernary);
    
    return 0;
}