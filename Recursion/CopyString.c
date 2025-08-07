#include<stdio.h>
void copyStringRecursive(char *source,char *destination,int index)
{
 if(source[index]=='\0')
 {
    destination[index]='\0';
    return;
 }
 destination[index]=source[index];
 copyStringRecursive(source,destination,index+1);
}

int main()
{
    char sourceString[100];
    char destinationString[100];
    printf("Enter a string: ");
    scanf("%s",sourceString);

    copyStringRecursive(sourceString,destinationString,0);
    printf("Original string: %s\n",sourceString);
    printf("Copied String: %s\n",destinationString);
    return 0;
}