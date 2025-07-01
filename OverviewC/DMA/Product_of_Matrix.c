#include<stdio.h>
#include<stdlib.h>
int main()
{
    int **a,i,j;
    int r1,c1;
    printf("Enter size of a matrix: ");
    scanf("%d%d",&r1,&c1);
    for(i=0;i<r1;i++)
    {
        *(a+i)=(int *)malloc(sizeof(int)*c1);
    }

    printf("Enter the elements of matrix:\n");
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
            scanf("%d",*(a+i)+j);
        }
    }
    printf("The matrix is:\n");
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
            printf("%d\t",*(*(a+i)+j));
        }
        printf("\n");
    }
    return 0;
}