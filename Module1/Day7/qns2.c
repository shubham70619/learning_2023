#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void convertToUpperCase(FILE *sourceFile, FILE *targetFile) {
    int ch;
    while ((ch = fgetc(sourceFile)) != EOF) {
        fputc(toupper(ch), targetFile);
    }
}

void convertToLowerCase(FILE *sourceFile, FILE *targetFile) {
    int ch;
    while ((ch = fgetc(sourceFile)) != EOF) {
        fputc(tolower(ch), targetFile);
    }
}

void convertToSentenceCase(FILE *sourceFile, FILE *targetFile) {
    int ch;
    int firstCharInSentence = 1;
    while ((ch = fgetc(sourceFile)) != EOF) {
        if (firstCharInSentence && isalpha(ch)) {
            fputc(toupper(ch), targetFile);
            firstCharInSentence = 0;
        } else {
            fputc(tolower(ch), targetFile);
        }
        if (ch == '.' || ch == '?' || ch == '!') {
            firstCharInSentence = 1;
        }
    }
}

void copyFile(FILE *sourceFile, FILE *targetFile) {
    int ch;
    while ((ch = fgetc(sourceFile)) != EOF) {
        fputc(ch, targetFile);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: ./cp [option] sourceFile targetFile\n");
        printf("Options:\n");
        printf("  -u\tChange file content to upper case\n");
        printf("  -l\tChange file content to lower case\n");
        printf("  -s\tChange file content to sentence case\n");
        printf("If no options are passed, performs a normal copy.\n");
        return 1;
    }

    char *option = argv[1];
    char *sourceFileName = argv[2];
    char *targetFileName = argv[3];

    FILE *sourceFile = fopen(sourceFileName, "r");
    if (sourceFile == NULL) {
        printf("Error opening the source file.\n");
        return 1;
    }

    FILE *targetFile = fopen(targetFileName, "w");
    if (targetFile == NULL) {
        printf("Error opening the target file.\n");
        fclose(sourceFile);
        return 1;
    }

    if (strcmp(option, "-u") == 0) {
        convertToUpperCase(sourceFile, targetFile);
    } else if (strcmp(option, "-l") == 0) {
        convertToLowerCase(sourceFile, targetFile);
    } else if (strcmp(option, "-s") == 0) {
        convertToSentenceCase(sourceFile, targetFile);
    } else {
        copyFile(sourceFile, targetFile);
    }

    printf("File copied successfully.\n");

    fclose(sourceFile);
    fclose(targetFile);

    return 0;
}
