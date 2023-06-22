#include <stdio.h>

#define SIZE 10

int main() {
    int arr[SIZE];
    int i, sum = 0;
    float average;

    printf("Enter %d elements in the array:\n", SIZE);
    for (i = 0; i < SIZE; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    average = (float)sum / SIZE;

    printf("Sum of array elements: %d\n", sum);
    printf("Average of array elements: %.2f\n", average);

    return 0;
}
