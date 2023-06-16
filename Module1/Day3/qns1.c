#include <stdio.h>

void printForward(int n) {
    for (int i = 1; i <= n; i++) {
        printf("%d", i);
    }
}

void printSpaces(int n) {
    for (int i = 1; i <= (n - 2); i++) {
        printf(" ");
    }
}

void printBackward(int n) {
    for (int i = n; i >= 1; i--) {
        printf("%d", i);
    }
}

void printPattern(int n) {
    for (int i = n; i >= 1; i--) {
        printForward(i);
        printSpaces(i);
        printBackward(i);
        printf("\n");
    }
}

int main() {
    int n = 5;
    printPattern(n);

    return 0;
}
