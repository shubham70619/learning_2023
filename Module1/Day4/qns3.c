#include <stdio.h>

#define SIZE 10

void reverseArray(int arr[], int size) {
    int start = 0;
    int end = size - 1;
    int temp;

    while (start < end) {
        // Swap elements at start and end indices
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        // Move the start and end indices towards the center
        start++;
        end--;
    }
}

int main() {
    int arr[SIZE];
    int i;

    printf("Enter %d elements in the array:\n", SIZE);
    for (i = 0; i < SIZE; i++) {
        scanf("%d", &arr[i]);
    }

    // Reverse the array
    reverseArray(arr, SIZE);

    printf("Reversed array:\n");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

