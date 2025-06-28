#include<stdio.h>
int main()
{
    int n,a[100];
    int i,*p;
    float sum=0.0,avg;
    printf("Enter the size of n: ");
    scanf("%d",&n);
    printf("Enter %d elements\n",n);
    p=a;
    for(i=0;i<n;i++)
    {
        scanf("%d",(p+i));
        sum=sum+*(p+i);
    }
    avg=sum/n;
    printf("Sum: %f\nAverage: %f\n",sum,avg);
    return 0;

}