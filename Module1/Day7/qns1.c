#include <stdio.h>

int main() {
    FILE *sourceFile, *targetFile;
    char sourceFileName[100], targetFileName[100];
    char ch;

    // Get the source file name from the user
    printf("Enter the source file name: ");
    scanf("%s", sourceFileName);

    // Open the source file in read mode
    sourceFile = fopen(sourceFileName, "r");

    if (sourceFile == NULL) {
        printf("Error opening the source file.\n");
        return 1;
    }

    // Get the target file name from the user
    printf("Enter the target file name: ");
    scanf("%s", targetFileName);

    // Open the target file in write mode
    targetFile = fopen(targetFileName, "w");

    if (targetFile == NULL) {
        printf("Error opening the target file.\n");
        fclose(sourceFile);
        return 1;
    }

    // Copy the contents of the source file to the target file
    while ((ch = fgetc(sourceFile)) != EOF) {
        fputc(ch, targetFile);
    }

    printf("File copied successfully.\n");

    // Close the files
    fclose(sourceFile);
    fclose(targetFile);

    return 0;
}
