#include <stdio.h>

struct Box {
    double length;
    double width;
    double height;
};

double calculateVolume(struct Box *box) {
    return box->length * box->width * box->height;
}

double calculateSurfaceArea(struct Box *box) {
    return 2 * (box->length * box->width + box->length * box->height + box->width * box->height);
}

int main() {
    struct Box myBox;
    myBox.length = 5.0;
    myBox.width = 3.0;
    myBox.height = 4.0;

    // Accessing structure members using the (*) asterisk and (.) dot operator
    printf("Using (*). to access structure members:\n");
    printf("Length: %.2f\n", (*(&myBox)).length);
    printf("Width: %.2f\n", (*(&myBox)).width);
    printf("Height: %.2f\n", (*(&myBox)).height);

    // Accessing structure members using the (->) arrow operator with pointer representation
    struct Box *boxPtr = &myBox;
    printf("\nUsing -> with pointer representation:\n");
    printf("Length: %.2f\n", boxPtr->length);
    printf("Width: %.2f\n", boxPtr->width);
    printf("Height: %.2f\n", boxPtr->height);

    // Accessing structure members using the (->) arrow operator with dot representation
    printf("\nUsing -> with dot representation:\n");
    printf("Length: %.2f\n", (*boxPtr).length);
    printf("Width: %.2f\n", (*boxPtr).width);
    printf("Height: %.2f\n", (*boxPtr).height);

    // Calculating volume and total surface area of the box
    double volume = calculateVolume(&myBox);
    double surfaceArea = calculateSurfaceArea(&myBox);

    printf("\nVolume: %.2f\n", volume);
    printf("Total Surface Area: %.2f\n", surfaceArea);

    return 0;
}
