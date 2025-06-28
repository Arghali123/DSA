#include<stdio.h>
int main()
{
    struct Student
    {
        char name[20];
        int roll;
        char sec;
        float marks;
    };

    struct Student s1;
    printf("Enter the name of the student: ");
    gets(s1.name);
    printf("Enter the roll number of student: ");
    scanf("%d",&s1.roll);
    printf("Enter the section of a student: ");
    scanf(" %c",&s1.sec);
    printf("Enter the marks of a student: ");
    scanf("%f",&s1.marks);

    printf("Name: %s\nRollno: %d\nSection: %c\nMarks: %.2f",s1.name,s1.roll,s1.sec,s1.marks);
    return 0;
}