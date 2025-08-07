#include<stdio.h>
int main()
{
    int n,i;
    int fibo(int);
    printf("Enter n: ");
    scanf("%d",&n);
    printf("Fibonacci numbers upto %d terms:\n",n);
    for(i=0;i<=n;i++)
    {
        printf("%d ",fibo(i));
    }
    return 0;
}
int fibo(int k)
{
    if(k==0 || k==1)
    {
        return k;
    }
    else
    {
        return fibo(k-1)+fibo(k-2);
    }
}