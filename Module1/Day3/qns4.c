#include <stdio.h>

void findMinMaxDigits(int n, int numbers[]) {
    int smallestDigit = 9;
    int largestDigit = 0;
    int validDigitsFound = 0;

    for (int i = 0; i < n; i++) {
        int num = numbers[i];

        while (num != 0) {
            int digit = num % 10;

            if (digit < smallestDigit) {
                smallestDigit = digit;
            }

            if (digit > largestDigit) {
                largestDigit = digit;
            }

            num /= 10;
            validDigitsFound = 1;
        }
    }

    if (!validDigitsFound) {
        printf("Not Valid\n");
    } else {
        printf("Smallest digit: %d\n", smallestDigit);
        printf("Largest digit: %d\n", largestDigit);
    }
}

int main() {
    int n = 3;
    int numbers[] = {8, 156, 123450};
    findMinMaxDigits(n, numbers);

    return 0;
}
