//Program to input any two numbers and find their product by using the concept of pointer,
#include<stdio.h>
int main()
{
    float a,b,*p,*q,product;
    printf("Enter two numbers: ");
    scanf("%f%f",&a,&b);

    p=&a;
    q=&b;
    product=*p**q;
    printf("The product of two numbers is: %.3f",product);
    return 0;
}