#include<stdio.h>
int main()
{
    int n;
    long int facto;
    long int factorial(int n);
    printf("Enter the value of n: ");
    scanf("%d",&n);
    facto=factorial(n);
    printf("%d!= %ld",n,facto);
    return 0;
}
long int factorial(int n)
{
    if(n==0)
    {
        return 1;
    }else
    {
        return n*factorial(n-1);
    }
}