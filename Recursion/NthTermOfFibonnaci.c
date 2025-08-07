#include<stdio.h>
int main()
{
    int n,i;
    int fib(int);
    printf("Enter the value of n: ");
    scanf("%d",&n);
    printf("nth Fibonnaci term is: %d",fib(n));
    return 0;
}
int fib(int k)
{
    if(k==0 || k==1)
    {
        return k;
    }else
    {
        return fib(k-1)+fib(k-2);
    }
}