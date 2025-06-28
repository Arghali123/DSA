#include<stdio.h>
struct Student
{
    char name[20];
    int roll;
    char sec;
    float marks;
};
int main()
{
    struct Student s[3];
    int i;
    for(i=0;i<3;i++)
    {
        printf("Enter the name of a student: ");
        gets(s[i].name);
        printf("Enter the roll no of a student: ");
        scanf("%d",&s[i].roll);
        printf("Enter the sec of a student: ");
        scanf(" %c",&s[i].sec);
        printf("Enter the marks of a student: ");
        scanf("%f",&s[i].marks);
        getchar();
    }

    //displaying all the records
    for(i=0;i<3;i++)
    {
        printf("Name: %s\nRoll no: %d\nSection: %c\nMarks: %.2f\n",s[i].name,s[i].roll,s[i].sec,s[i].marks);
    }
    return 0;
}