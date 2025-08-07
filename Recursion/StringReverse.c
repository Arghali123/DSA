#include<stdio.h>
void Reverse();
int main()
{
    printf("Enter a sentence: ");
    Reverse();
    return 0;
}
void Reverse()
{
    char ch;
    scanf("%c",&ch);
    if(ch!='\n')
    {
        Reverse();
    }
    printf("%c",ch);
}