#include<stdio.h>
int main()
{
    int *ptr1,*ptr2;
    int a,b,c,x,y,z;
    a=30,b=6;

    ptr1=&a;
    ptr2=&b;

    x=*ptr1+*ptr2-6;
    y = 6 - *ptr1 / *ptr2 + 30; 

    printf("Address of a: %u\n",ptr1);
    printf("Address of b: %u\n",ptr2);

    printf("a: %d ,b: %d\n",a,b);
    printf("x: %d ,y: %d\n",x,y);
    

    ptr1=ptr1+70;
    // ptr2=ptr1;
    printf("a= %d ,b= %d\n",a,b);

   return 0; 

}