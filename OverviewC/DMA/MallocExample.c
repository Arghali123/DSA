//Program to find the sum of n different numbers by using malloc function for DMA

#include<stdio.h>
#include<conio.h>
#include<malloc.h>
int main()
{
    int n,i,*a,sum=0;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    a=(int *)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
    {
        scanf("%d",(a+i));
    }
    printf("Sum of given numbers is: ");
    for(i=0;i<n;i++)
    {
        sum=sum+*(a+i);
    }
    printf("%d",sum);
    return 0;
}