#include<stdio.h>
int GCD(int,int);
int main()
{
 int a,b,g;
 printf("Enter two numbers: ");
 scanf("%d%d",&a,&b);
 g=GCD(a,b);
 printf("GCD of given two numbers: %d",g);
 return 0;
}

int GCD(int x,int y)
{
    if(y==0)
    {
        return x;
    }else
    {
        return (GCD(y,x%y));
    }
}