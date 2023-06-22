#include <stdio.h>

#define SIZE 4

int main() {
    int arr[SIZE];
    int i, min, max;

    printf("Enter %d elements in the array:\n", SIZE);
    for (i = 0; i < SIZE; i++) {
        scanf("%d", &arr[i]);
    }

    min = arr[0];  // Assume the first element as minimum
    max = arr[0];  // Assume the first element as maximum

    for (i = 1; i < SIZE; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    printf("Minimum value: %d\n", min);
    printf("Maximum value: %d\n", max);

    return 0;
}
