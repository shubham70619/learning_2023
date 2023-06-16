#include <stdio.h>

int deleteDigit(int num) {
    int largest = 0;
    int divisor = 1;

    while (divisor <= num) {
        int remaining = (num / (divisor * 10)) * divisor + (num % divisor);

        if (remaining > largest) {
            largest = remaining;
        }

        divisor *= 10;
    }

    return largest;
}

int main() {
    int num;
    printf("Enter a 4-digit number: ");
    scanf("%d", &num);

    int largestNum = deleteDigit(num);
    printf("Largest number by deleting a single digit: %d\n", largestNum);

    return 0;
}
