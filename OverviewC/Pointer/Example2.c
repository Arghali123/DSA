//Program to display the content of the variable their address using pointer variable.
#include<stdio.h>
int main()
{
    int num,*intptr;
    float x,*floatptr;
    char c,*charptr;

    num=123;
    x=12.23;
    c='A';

    intptr=&num;
    floatptr=&x;
    charptr=&c;

    printf("Number: %d stored at address: %p\n",*intptr,intptr);
    printf("Value %f stored at address: %p\n",*floatptr,floatptr);
    printf("Character: %c stored at address: %p\n",*charptr,charptr);

    return 0;
}