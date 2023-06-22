#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void parseString(const char *str, struct Student *students, int n) {
    int i = 0;
    char *token;

    token = strtok(str, " ");
    while (token != NULL && i < n) {
        students[i].rollno = atoi(token);
        token = strtok(NULL, " ");
        strcpy(students[i].name, token);
        token = strtok(NULL, " ");
        students[i].marks = atof(token);

        i++;
        token = strtok(NULL, " ");
    }
}

int main() {
    int n;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    struct Student *students = (struct Student *)malloc(n * sizeof(struct Student));

    if (students == NULL) {
        printf("Memory allocation failed. Exiting program.\n");
        return 1;
    }

    getchar(); // Consume newline character

    char input[100];
    printf("Enter the input string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove newline character

    parseString(input, students, n);

    printf("\nArray of structures initialized:\n");
    for (int i = 0; i < n; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }

    free(students);

    return 0;
}

