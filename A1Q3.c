#include <stdio.h>
#include <string.h>

struct Student
{
    int roll_no;
    char name[50];
    float marks;
};

int main()
{
    int num, i;
    printf("enter number of students:");
    scanf("%d", &num);
    struct Student students[num];

    for (i = 0; i < num; i++)
    {
        printf("enter roll. no. of student %d:\n", i + 1);
        scanf("%d", &students[i].roll_no);

        printf("enter name of student %d:\n", i + 1);
        scanf(" %[^\n]", students[i].name);

        printf("enter marks of student %d:\n", i + 1);
        scanf("%f", &students[i].marks);
    }
    printf("-------------------------------------------------------------------\n");
    printf("Student Details:\n");
    printf("-------------------------------------------------------------------\n");
    printf("%-10s %-20s %-10s\n", "Roll no.", "Name", "Marks");
    printf("-------------------------------------------------------------------\n");
    for (int i = 0; i < num; i++)
    {
        printf("%-10d %-20s %-10.2f\n", students[i].roll_no, students[i].name, students[i].marks);
    }
}

