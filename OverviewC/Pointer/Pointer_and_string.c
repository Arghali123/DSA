#include<stdio.h>
int main()
{
    char strA[80]="A string to be used for demonstration purposes";
    char strB[80];

    char *ptrA;
    char *ptrB;

    puts(strA);
    ptrA=strA;
    puts(ptrA);

    ptrB=strB;
    while(*ptrA !='\0')
    {
        *ptrB++=*ptrA++;
    }
    *ptrB='\0';
    puts(strB);
    return 0;
}