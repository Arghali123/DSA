#include<stdio.h>
void swap(int,int);//function prototype
int main()
{
    int x,y;
    x=10;
    y=20;
    printf("Before swap value of x=%d,y= %d\n",x,y);
    swap(x,y);//calling the function
    printf("After swap value of x=%d,y=%d",x,y);
    return 0;
}

void swap(int x,int y)//function definition
{
 int temp;
 temp=x;
 x=y;
 y=temp;
}