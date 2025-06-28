#include<stdio.h>
int main()
{
    int *ptr;
    int num;
    num=45;
    ptr=&num;
    printf("Number is %d\n",num);
    printf("The num pointer: %d\n",ptr);
    printf("The value pointer: %d",*ptr);
    return 0;
}