#include<stdio.h>
int main()
{
    int n;
    int sum_natural(int);
    printf("Enter value of n: ");
    scanf("%d",&n);
    printf("Sum of %d natural numbers: %d",n,sum_natural(n));
    return 0;
}
int sum_natural(int n)
{
 if(n==1)
 {
    return 1;
 }else
 {
    return n+sum_natural(n-1);
 }
}