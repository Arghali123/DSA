#include<stdio.h>
#include<conio.h>
void display(int[10][10],int,int);
void main()
{
  int a[10][10],b[10][10],result[10][10],i,j,r,c;
  printf("Enter the size of matrix\n");
  scanf("%d%d",&r,&c);

  printf("Enter the elements of first matrix:\n");
  for(int i=0;i<r;i++)
  {
    for(int j=0;j<c;j++)
    {
        scanf("%d",&a[i][j]);
    }
  }

  printf("Enter the elements of second matrix:\n");
  for(int i=0;i<r;i++)
  {
    for(int j=0;j<c;j++)
    {
        scanf("%d",&b[i][j]);
    }
  }

  for(int i=0;i<r;i++)
  {
    for(int j=0;j<c;j++)
    {
        result[i][j]=a[i][j]+b[i][j];
    }
  }

  printf("The First matrix is:\n");
  display(a,r,c);

  printf("The second matrix is:\n");
  display(b,r,c);
  
  printf("The resulting matrix is:\n");
  display(result,r,c);
  getch();
}

void display(int d[10][10],int r,int c)
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("%d\t",d[i][j]);
        }
        printf("\n");
    }
}