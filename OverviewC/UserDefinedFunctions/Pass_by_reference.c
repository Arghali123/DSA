#include<stdio.h>
void swap(int*,int*);
int main()
{
    int x,y;
    x=10;
    y=20;
    printf("Before swap values of x=%d,y=%d\n",x,y);
    swap(&x,&y);
    printf("After swap values of x=%d,y=%d",x,y);
    return 0;
}
void swap(int *x,int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}