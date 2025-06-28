#include<stdio.h>
int main()
{
    int a[100];
    int i,j=0,n;
    int *ptr;
    printf("Enter the number of elements of the array: ");
    scanf("%d",&n);

    printf("Enter the array elements:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    printf("Array elements are: ");
    for(ptr=a;ptr<(a+n);ptr++)
    {
     printf("Value of a[%d]: %d stored at address %u\n",j,*ptr,ptr);
     j++;
    }
    return 0;
}