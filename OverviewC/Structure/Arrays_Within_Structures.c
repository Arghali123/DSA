#include<stdio.h>
struct Student
{
    char name[20];
    int roll;
    char sec;
    float marks[5];
};
int main()
{
    struct Student s;
    int i;
    float sum=0,avg;
    printf("Enter the name of a student: ");
    gets(s.name);
    printf("Enter the roll no of a student: ");
    scanf("%d",&s.roll);
    printf("Enter the section of a student: ");
    scanf(" %c",&s.sec);
    printf("Enter the marks obtained by the student in 5 subjects:\n");
    for(int i=0;i<5;i++)
    {
        scanf("%f",&s.marks[i]);
        sum=sum+s.marks[i];
    }
    avg=sum/5;

    //displaying the records
    printf("Name: %s\nRoll no: %d\nSection: %c\nObtained Marks: %2.f\n",s.name,s.roll,s.sec,avg);
    return 0;
}