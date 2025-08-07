#include<stdio.h>
int power(int,int);
int main()
{
    int x,n,p;
    printf("Enter the value of x and p: ");
    scanf("%d%d",&x,&n);
    p=power(x,n);
    printf("The result of x^n is %d",p);
    return 0;
}
int power(int x,int n)
{
    if(n==0)
    {
        return 1;
    }else
    {
        return (x*power(x,n-1));
    }
}