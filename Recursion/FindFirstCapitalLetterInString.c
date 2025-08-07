#include<stdio.h>
#include<ctype.h>

char findFirstCapital(char *str,int index)
{
    if(str[index]=='\0')
    {
        return '\0';
    }

    if(isupper(str[index]))
    {
        return str[index];
    }
    return findFirstCapital(str,index+1);
}
int main()
{
    char myString[100];
    printf("Enter a string: ");
    scanf("%s",myString);

    char firstCapital=findFirstCapital(myString,0);
    if(firstCapital!='\0')
    {
        printf("The first capital letter is: %c\n",firstCapital);
    }else
    {
        printf("No capital letter found in the string.\n");
    }
    return 0;
}