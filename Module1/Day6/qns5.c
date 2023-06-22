#include <stdio.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void searchByName(struct Student *students, int n, const char *searchName) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(students[i].name, searchName) == 0) {
            printf("Student found!\n");
            printf("Roll No: %d\n", students[i].rollno);
            printf("Name: %s\n", students[i].name);
            printf("Marks: %.2f\n", students[i].marks);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student not found.\n");
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

    // Assume the array of structures is already populated with data

    char searchName[20];
    printf("Enter the name of the student to search: ");
    scanf("%s", searchName);

    searchByName(students, n, searchName);

    free(students);

    return 0;
}
