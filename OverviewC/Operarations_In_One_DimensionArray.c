#include<stdio.h>
#include<conio.h>
#include<process.h>

void create(int[100],int *);
void insert(int[100],int *);
void delete(int[100],int *);
void update(int[100],int *);
void traverse(int[100],int *);
void searching(int[100],int *);
void merging(int[100],int[100],int *,int *);

int main()
{
    int a[100],b[100],m,nel,pos,i;
    int n;
    int choice;

    printf("\nMenu for program:\n");
    printf("1:Create\n2:Insert\n3:Delete\n4:Update\n5:Traverse\n6:Searching\n7:Merging\n");

    do
    {
      printf("Enter your choice: ");
      scanf("%d",&choice);

      switch(choice)
      {
        case 1:
        printf("Enter the number of elements in first array: ");
        scanf("%d",&n);
        create(a,&n);
        break;

        case 2:
        insert(a,&n);
        break;

        case 3:
        delete(a,&n);
        break;

        case 4:
        update(a,&n);
        break;

        case 5:
        traverse(a,&n);
        break;

        case 6:
        searching(a,&n);
        break;

        case 7:
        printf("Enter the size of second array: ");
        scanf("%d",&m);
        merging(a,b,&n,&m);
        break;

        default:
        printf("Invalid choice");
      }
    }while(choice<8);
    return 0;
}

void create(int a[100],int *n)
{
    int i;
    printf("Enter %d elements: ",*n);
    for(i=0;i<*n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\n");
}

void insert(int a[100],int *n)
{
    int pos,nel,i;
    printf("Enter position at which you want to insert new element: ");
    scanf("%d",&pos);
    printf("Enter the new element: ");
    scanf("%d",&nel);
    for(i=*n-1;i>=pos;i--)
    {
        a[i+1]=a[i];
    }
    a[pos]=nel;
    *n=*n+1;
}

void delete(int a[100],int *n)
{
    int pos,i;
    printf("Enter the position you want to delete: ");
    scanf("%d",&pos);
    for(i=pos;i<*n;i++)
    {
        a[i]=a[i+1];
    }
    *n=*n-1;
}

void update(int a[100],int *n)
{
    int pos,num;
    printf("Enter the position you want to update: ");
    scanf("%d",&pos);
    printf("Enter new element: ");
    scanf("%d",&num);
    a[pos]=num;
}

void traverse(int a[100],int *n)
{
    int i;
    printf("Current Elements of array are: ");
    for(i=0;i<*n;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\n");
}

void searching(int a[100],int *n)
{
    int k,i;
    printf("Enter searched item: ");
    scanf("%d",&k);
    for(i=0;i<*n;i++)
    {
        if(k==a[i])
        {
            printf("Search Sucessful\n");
            break;
        }
    }
    if(i==*n)
    {
        printf("Search unsuccessful\n");
    }
}

void merging(int a[100],int b[100],int *n,int *m)
{
    int i,j=*n;
    printf("Enter the second array:\n");
    for(int i=0;i<*m;i++)
    {
        scanf("%d",&b[i]);
        a[j]=b[i];
        j++;
        *n=*n+1;
    }
}