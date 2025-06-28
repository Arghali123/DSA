#include<stdio.h>
struct Person
{
    char name[20];
    int age;
};
struct Student
{
    int roll;
    char sec;
    struct Person p;
};
int main()
{
    struct Student s;
    printf("Enter the name of the student: ");
    gets(s.p.name);
    printf("Enter age: ");
    scanf("%d",&s.p.age);
    printf("Enter the roll no: ");
    scanf("%d",&s.roll);
    printf("Enter the section of a student: ");
    scanf(" %c",&s.sec);

    //displaying all the records 
    printf("Name: %s\nAge: %d\nRoll no: %d\nSection: %c",s.p.name,s.p.age,s.roll,s.sec);
    return 0;
}
