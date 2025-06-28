#include<stdio.h>
int main()
{
    int m,n,i,j,matrix[10][10],traspose[10][10];
    printf("Enter the number of rows and columns of matrix: ");
    scanf("%d%d",&m,&n);

    printf("Enter the elements of matrix\n");
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&matrix[i][j]);
            traspose[j][i]=matrix[i][j];
        }
    }

    // for(int i=0;i<n;i++)
    // {
    //     for(j=0;j<m;j++)
    //     {
    //         traspose[i][j]=matrix[j][i];
    //     }
    // }

    printf("Transpose of entered matrix:\n");
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d\t",traspose[i][j]);
        }
        printf("\n");
    }
    return 0;
}