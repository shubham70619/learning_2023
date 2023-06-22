#include <stdio.h>

#define SIZE 10

int calculateDifference(int arr[], int size) {
    int evenSum = 0;
    int oddSum = 0;
    int i;

    for (i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            evenSum += arr[i];  // Add even numbers to evenSum
        } else {
            oddSum += arr[i];  // Add odd numbers to oddSum
        }
    }

    return evenSum - oddSum;  // Calculate the difference
}

int main() {
    int arr[SIZE];
    int i;

    printf("Enter %d elements in the array:\n", SIZE);
    for (i = 0; i < SIZE; i++) {
        scanf("%d", &arr[i]);
    }

    int difference = calculateDifference(arr, SIZE);

    printf("Difference between sum of even numbers and sum of odd numbers: %d\n", difference);

    return 0;
}
