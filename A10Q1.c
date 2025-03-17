#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 100
#define MAX_DEPT_LENGTH 50

struct Student {
    char name[MAX_NAME_LENGTH];
    int rollNo;
    char department[MAX_DEPT_LENGTH];
};

void readRecords(const char *filename, struct Student **students, int *numStudents) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Unable to open file!\n");
        return;
    }

    *numStudents = 0;
    while (!feof(file)) {
        struct Student student;
        fscanf(file, " %[^,],%d,%[^\n]", student.name, &student.rollNo, student.department);
        (*students) = realloc(*students, (*numStudents + 1) * sizeof(struct Student));
        (*students)[*numStudents] = student;
        (*numStudents)++;
    }

    fclose(file);
}

void bubbleSort(struct Student *students, int numStudents) {
    for (int i = 0; i < numStudents - 1; i++) {
        for (int j = 0; j < numStudents - i - 1; j++) {
            if (strcmp(students[j].name, students[j + 1].name) > 0 || 
                (strcmp(students[j].name, students[j + 1].name) == 0 && students[j].rollNo > students[j + 1].rollNo)) {
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

void binarySearch(struct Student *students, int numStudents, const char *searchName) {
    int left = 0, right = numStudents - 1;
    int found = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (strcmp(students[mid].name, searchName) == 0) {
            found = 1;
            int start = mid;
            while (start > 0 && strcmp(students[start - 1].name, searchName) == 0) {
                start--;
            }
            for (int i = start; i < numStudents && strcmp(students[i].name, searchName) == 0; i++) {
                printf("%s, %d, %s\n", students[i].name, students[i].rollNo, students[i].department);
            }
            break;
        }
        
        if (strcmp(students[mid].name, searchName) < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (!found) {
        printf("No student found with the name: %s\n", searchName);
    }
}

int main() {
    struct Student *students = NULL;
    int numStudents = 0;
    int option;
    char searchName[MAX_NAME_LENGTH];

    readRecords("student.txt", &students, &numStudents);

    do {
        printf("\nMenu:\n");
        printf("1. Bubble Sort\n");
        printf("2. Binary Search\n");
        printf("3. Quit\n");
        printf("Enter your option: ");
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                bubbleSort(students, numStudents);
                printf("\nSorted student records:\n");
                for (int i = 0; i < numStudents; i++) {
                    printf("%s, %d, %s\n", students[i].name, students[i].rollNo, students[i].department);
                }
                break;

            case 2:
                printf("Enter student name to search: ");
                getchar();  
                fgets(searchName, MAX_NAME_LENGTH, stdin);
                searchName[strcspn(searchName, "\n")] = 0;  
                binarySearch(students, numStudents, searchName);
                break;

            case 3:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (option != 3);

    free(students);
    
    return 0;
}
