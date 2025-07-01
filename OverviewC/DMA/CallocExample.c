//Program to find the sum of n different numbers by using calloc function for DMA
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,i,*a,sum=0;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    a=(int *)calloc(n,sizeof(int));
    printf("Enter %d numbers\n",n);

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