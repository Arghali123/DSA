//Addition to integer values to pointer
#include<stdio.h>
int main()
{
    int *p,x;
    x=30;
    p=&x;
    printf("Value of pointer before the operation is %u\n",p);
    p=p+1;
    printf("Value of pointer after addition operation is %u\n",p);
    p=p-2;
    printf("Value of pointer after subtraction operation is %u\n",p);
    return 0;
}