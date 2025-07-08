#include<stdio.h>
int main()
{
    int array[100],n;
    int i,j,k,increment,temp;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    printf("Enter %d elements:\n",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&array[i]);
    }

    for(increment=n/2;increment>0;increment/=2)
    {
        for(i=increment;i<n;i++)
        {
            temp=array[i];
            for(j=i;j>=increment;j=j-increment)
            {
                if(temp<array[j-increment])
                {
                    array[j]=array[j-increment];
                }else
                {
                    break;
                }
            }
            array[j]=temp;
        }
    }

    printf("After sorting: ");
    for(k=0;k<n;k++)
    {
        printf("%d\t",array[k]);
    }
    return 0;

}